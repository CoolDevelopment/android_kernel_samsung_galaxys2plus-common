/*
 *  linux/mm/mempool.c
 *
 *  memory buffer pool support. Such pools are mostly used
 *  for guaranteed, deadlock-free memory allocations during
 *  extreme VM load.
 *
 *  started by Ingo Molnar, Copyright (C) 2001
 */

#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/mempool.h>
#include <linux/blkdev.h>
#include <linux/writeback.h>
#include <linux/percpu.h>

static void add_element(mempool_t *pool, void *element)
{
	BUG_ON(pool->curr_nr >= pool->min_nr);
	pool->elements[pool->curr_nr++] = element;
}

static void *remove_element(mempool_t *pool)
{
	BUG_ON(pool->curr_nr <= 0);
	return pool->elements[--pool->curr_nr];
}

/**
 * mempool_destroy - deallocate a memory pool
 * @pool:      pointer to the memory pool which was allocated via
 *             mempool_create().
 *
 * Free all reserved elements in @pool and @pool itself.  This function
 * only sleeps if the free_fn() function sleeps.
 */
void mempool_destroy(mempool_t *pool)
{
	while (pool->curr_nr) {
		void *element = remove_element(pool);
		pool->free(element, pool->pool_data);
	}
	kfree(pool->elements);
	kfree(pool);
}
EXPORT_SYMBOL(mempool_destroy);

/**
 * mempool_fill - fill a memory pool
 *  <at> pool:	memory pool to fill
 *  <at> gfp_mask:	allocation mask to use
 *
 * Allocate new elements with  <at> gfp_mask and fill  <at> pool so that it has
 *  <at> pool->min_nr elements.  Returns 0 on success, -errno on failure.
 */
static int mempool_fill(mempool_t *pool, gfp_t gfp_mask)
{
	/*
	 * If curr_nr == min_nr is visible, we're correct regardless of
	 * locking.
	 */
	while (pool->curr_nr < pool->min_nr) {
		void *elem;
		unsigned long flags;

		elem = pool->alloc(gfp_mask, pool->pool_data);
		if (unlikely(!elem))
			return -ENOMEM;

		spin_lock_irqsave(&pool->lock, flags);
		if (pool->curr_nr < pool->min_nr) {
			add_element(pool, elem);
			elem = NULL;
		}
		spin_unlock_irqrestore(&pool->lock, flags);

		if (elem) {
			pool->free(elem, pool->pool_data);
			return 0;
		}
	}
	return 0;
}

/**
 * mempool_create - create a memory pool
 * @min_nr:    the minimum number of elements guaranteed to be
 *             allocated for this pool.
 * @alloc_fn:  user-defined element-allocation function.
 * @free_fn:   user-defined element-freeing function.
 * @pool_data: optional private data available to the user-defined functions.
 *
 * this function creates and allocates a guaranteed size, preallocated
 * memory pool. The pool can be used from the mempool_alloc() and mempool_free()
 * functions. This function might sleep. Both the alloc_fn() and the free_fn()
 * functions might sleep - as long as the mempool_alloc() function is not called
 * from IRQ contexts.
 */
mempool_t *mempool_create(int min_nr, mempool_alloc_t *alloc_fn,
				mempool_free_t *free_fn, void *pool_data)
{
	return  mempool_create_node(min_nr,alloc_fn,free_fn, pool_data,-1);
}
EXPORT_SYMBOL(mempool_create);

static mempool_t *__mempool_create(int min_nr, mempool_alloc_t *alloc_fn,
                                   mempool_free_t *free_fn, void *pool_data,
                                   int node_id, size_t mempool_bytes) 
{
	mempool_t *pool;

       pool = kmalloc_node(mempool_bytes, GFP_KERNEL | __GFP_ZERO, node_id); 
	if (!pool)
		return NULL;
	pool->elements = kmalloc_node(min_nr * sizeof(void *),
					GFP_KERNEL, node_id);
	if (!pool->elements) {
		kfree(pool);
		return NULL;
	}
	spin_lock_init(&pool->lock);
	pool->min_nr = min_nr;
	pool->pool_data = pool_data;
	init_waitqueue_head(&pool->wait);
	pool->alloc = alloc_fn;
	pool->free = free_fn;

	 return pool;
}

mempool_t *mempool_create_node(int min_nr, mempool_alloc_t *alloc_fn,
                               mempool_free_t *free_fn, void *pool_data,
                               int node_id)
{
        mempool_t *pool;

        pool = __mempool_create(min_nr, alloc_fn, free_fn, pool_data, node_id,
                                sizeof(*pool));

        /* Pre-allocate the guaranteed number of buffers */ 
	 if (mempool_fill(pool, GFP_KERNEL)) {
		mempool_destroy(pool);
		return NULL;
		}
	return pool;
}
EXPORT_SYMBOL(mempool_create_node);

/**
 * mempool_resize - resize an existing memory pool
 * @pool:       pointer to the memory pool which was allocated via
 *              mempool_create().
 * @new_min_nr: the new minimum number of elements guaranteed to be
 *              allocated for this pool.
 * @gfp_mask:   the usual allocation bitmask.
 *
 * This function shrinks/grows the pool. In the case of growing,
 * it cannot be guaranteed that the pool will be grown to the new
 * size immediately, but new mempool_free() calls will refill it.
 *
 * Note, the caller must guarantee that no mempool_destroy is called
 * while this function is running. mempool_alloc() & mempool_free()
 * might be called (eg. from IRQ contexts) while this function executes.
 */
int mempool_resize(mempool_t *pool, int new_min_nr, gfp_t gfp_mask)
{
	void *element;
	void **new_elements;
	unsigned long flags;

	BUG_ON(new_min_nr <= 0);

	spin_lock_irqsave(&pool->lock, flags);
	if (new_min_nr <= pool->min_nr) {
		while (new_min_nr < pool->curr_nr) {
			element = remove_element(pool);
			spin_unlock_irqrestore(&pool->lock, flags);
			pool->free(element, pool->pool_data);
			spin_lock_irqsave(&pool->lock, flags);
		}
		pool->min_nr = new_min_nr;
		spin_unlock_irqrestore(&pool->lock, flags);
		return 0;
	}
	spin_unlock_irqrestore(&pool->lock, flags);

	/* Grow the pool */
	new_elements = kmalloc(new_min_nr * sizeof(*new_elements), gfp_mask);
	if (!new_elements)
		return -ENOMEM;

	spin_lock_irqsave(&pool->lock, flags);
	if (unlikely(new_min_nr <= pool->min_nr)) {
		/* Raced, other resize will do our work */
		spin_unlock_irqrestore(&pool->lock, flags);
		kfree(new_elements);
		return 0;
	}
	memcpy(new_elements, pool->elements,
			pool->curr_nr * sizeof(*new_elements));
	kfree(pool->elements);
	pool->elements = new_elements;
	pool->min_nr = new_min_nr;
	spin_unlock_irqrestore(&pool->lock, flags);
	
	mempool_fill(pool, gfp_mask);

	return 0;
}
EXPORT_SYMBOL(mempool_resize);

/**
 * mempool_alloc - allocate an element from a specific memory pool
 * @pool:      pointer to the memory pool which was allocated via
 *             mempool_create().
 * @gfp_mask:  the usual allocation bitmask.
 *
 * this function only sleeps if the alloc_fn() function sleeps or
 * returns NULL. Note that due to preallocation, this function
 * *never* fails when called from process contexts. (it might
 * fail if called from an IRQ context.)
 */
void * mempool_alloc(mempool_t *pool, gfp_t gfp_mask)
{
	void *element;
	unsigned long flags;
	wait_queue_t wait;
	gfp_t gfp_temp;

	might_sleep_if(gfp_mask & __GFP_WAIT);

	gfp_mask |= __GFP_NOMEMALLOC;	/* don't allocate emergency reserves */
	gfp_mask |= __GFP_NORETRY;	/* don't loop in __alloc_pages */
	gfp_mask |= __GFP_NOWARN;	/* failures are OK */

	gfp_temp = gfp_mask & ~(__GFP_WAIT|__GFP_IO);

repeat_alloc:

	element = pool->alloc(gfp_temp, pool->pool_data);
	if (likely(element != NULL))
		return element;

	spin_lock_irqsave(&pool->lock, flags);
	if (likely(pool->curr_nr)) {
		element = remove_element(pool);
		spin_unlock_irqrestore(&pool->lock, flags);
		/* paired with rmb in mempool_free(), read comment there */
		smp_wmb();
		return element;
	}

	/*
	 * We use gfp mask w/o __GFP_WAIT or IO for the first round.  If
	 * alloc failed with that and @pool was empty, retry immediately.
	 */
	if (gfp_temp != gfp_mask) {
		spin_unlock_irqrestore(&pool->lock, flags);
		gfp_temp = gfp_mask;
		goto repeat_alloc;
	}

	/* We must not sleep if !__GFP_WAIT */
	if (!(gfp_mask & __GFP_WAIT)) {
		spin_unlock_irqrestore(&pool->lock, flags);
		return NULL;
	}

	/* Let's wait for someone else to return an element to @pool */
	init_wait(&wait);
	prepare_to_wait(&pool->wait, &wait, TASK_UNINTERRUPTIBLE);

	spin_unlock_irqrestore(&pool->lock, flags);

	/*
	 * FIXME: this should be io_schedule().  The timeout is there as a
	 * workaround for some DM problems in 2.6.18.
	 */
	io_schedule_timeout(5*HZ);

	finish_wait(&pool->wait, &wait);
	goto repeat_alloc;
}
EXPORT_SYMBOL(mempool_alloc);

/**
 * mempool_free - return an element to the pool.
 * @element:   pool element pointer.
 * @pool:      pointer to the memory pool which was allocated via
 *             mempool_create().
 *
 * this function only sleeps if the free_fn() function sleeps.
 */
void mempool_free(void *element, mempool_t *pool)
{
	unsigned long flags;

	if (unlikely(element == NULL))
		return;

	/*
	 * Paired with the wmb in mempool_alloc().  The preceding read is
	 * for @element and the following @pool->curr_nr.  This ensures
	 * that the visible value of @pool->curr_nr is from after the
	 * allocation of @element.  This is necessary for fringe cases
	 * where @element was passed to this task without going through
	 * barriers.
	 *
	 * For example, assume @p is %NULL at the beginning and one task
	 * performs "p = mempool_alloc(...);" while another task is doing
	 * "while (!p) cpu_relax(); mempool_free(p, ...);".  This function
	 * may end up using curr_nr value which is from before allocation
	 * of @p without the following rmb.
	 */
	smp_rmb();

	/*
	 * For correctness, we need a test which is guaranteed to trigger
	 * if curr_nr + #allocated == min_nr.  Testing curr_nr < min_nr
	 * without locking achieves that and refilling as soon as possible
	 * is desirable.
	 *
	 * Because curr_nr visible here is always a value after the
	 * allocation of @element, any task which decremented curr_nr below
	 * min_nr is guaranteed to see curr_nr < min_nr unless curr_nr gets
	 * incremented to min_nr afterwards.  If curr_nr gets incremented
	 * to min_nr after the allocation of @element, the elements
	 * allocated after that are subject to the same guarantee.
	 *
	 * Waiters happen iff curr_nr is 0 and the above guarantee also
	 * ensures that there will be frees which return elements to the
	 * pool waking up the waiters.
	 */
	if (pool->curr_nr < pool->min_nr) {
		spin_lock_irqsave(&pool->lock, flags);
		if (pool->curr_nr < pool->min_nr) {
			add_element(pool, element);
			spin_unlock_irqrestore(&pool->lock, flags);
			wake_up(&pool->wait);
			return;
		}
		spin_unlock_irqrestore(&pool->lock, flags);
	}
	pool->free(element, pool->pool_data);
}
EXPORT_SYMBOL(mempool_free);

/*
 * A commonly used alloc and free fn.
 */
void *mempool_alloc_slab(gfp_t gfp_mask, void *pool_data)
{
	struct kmem_cache *mem = pool_data;
	return kmem_cache_alloc(mem, gfp_mask);
}
EXPORT_SYMBOL(mempool_alloc_slab);

void mempool_free_slab(void *element, void *pool_data)
{
	struct kmem_cache *mem = pool_data;
	kmem_cache_free(mem, element);
}
EXPORT_SYMBOL(mempool_free_slab);

/*
 * A commonly used alloc and free fn that kmalloc/kfrees the amount of memory
 * specified by pool_data
 */
void *mempool_kmalloc(gfp_t gfp_mask, void *pool_data)
{
	size_t size = (size_t)pool_data;
	return kmalloc(size, gfp_mask);
}
EXPORT_SYMBOL(mempool_kmalloc);

void mempool_kfree(void *element, void *pool_data)
{
	kfree(element);
}
EXPORT_SYMBOL(mempool_kfree);

/*
 * A simple mempool-backed page allocator that allocates pages
 * of the order specified by pool_data.
 */
void *mempool_alloc_pages(gfp_t gfp_mask, void *pool_data)
{
	int order = (int)(long)pool_data;
	return alloc_pages(gfp_mask, order);
}
EXPORT_SYMBOL(mempool_alloc_pages);

void mempool_free_pages(void *element, void *pool_data)
{
	int order = (int)(long)pool_data;
	__free_pages(element, order);
}
EXPORT_SYMBOL(mempool_free_pages);

/*
 * Mempool for percpu memory.
 */
static void *percpu_mempool_alloc_fn(gfp_t gfp_mask, void *data)
{
        struct percpu_mempool *pcpu_pool = data;
        void __percpu *p;

        /*
         * Percpu allocator doesn't do NOIO.  This makes percpu mempool
         * always try reserved elements first, which isn't such a bad idea
         * given that percpu allocator is pretty heavy and percpu areas are
         * expensive.
         */
        if ((gfp_mask & GFP_KERNEL) != GFP_KERNEL)
                return NULL;

        p = __alloc_percpu(pcpu_pool->size, pcpu_pool->align);
        return (void __kernel __force *)p;
}

static void percpu_mempool_free_fn(void *elem, void *data)
{
        void __percpu *p = (void __percpu __force *)elem;

        free_percpu(p);
}

static void percpu_mempool_refill_workfn(struct work_struct *work)
{
        struct percpu_mempool *pcpu_pool =
                container_of(work, struct percpu_mempool, refill_work);

        percpu_mempool_refill(pcpu_pool, GFP_KERNEL);
}

/**
 * percpu_mempool_create - create mempool for percpu memory
 * @min_nr:        the minimum number of elements guaranteed to be
 *                allocated for this pool.
 * @size:        size of percpu memory areas in this pool
 * @align:        alignment of percpu memory areas in this pool
 *
 * This is counterpart of mempool_create() for percpu memory areas.
 * Allocations from the pool will return @size bytes percpu memory areas
 * aligned at @align bytes.
 */
struct percpu_mempool *percpu_mempool_create(int min_nr, size_t size,
                                             size_t align)
{
        struct percpu_mempool *pcpu_pool;
        mempool_t *pool;

        BUILD_BUG_ON(offsetof(struct percpu_mempool, pool));

        pool = __mempool_create(min_nr, percpu_mempool_alloc_fn,
                                percpu_mempool_free_fn, NULL, NUMA_NO_NODE,
                                sizeof(*pcpu_pool));
        if (!pool)
                return NULL;

        /* fill in pcpu_pool part and set pool_data to self */
        pcpu_pool = container_of(pool, struct percpu_mempool, pool);
        pcpu_pool->size = size;
        pcpu_pool->align = align;
        INIT_WORK(&pcpu_pool->refill_work, percpu_mempool_refill_workfn);
        pcpu_pool->pool.pool_data = pcpu_pool;

        /* Pre-allocate the guaranteed number of buffers */
        if (mempool_fill(&pcpu_pool->pool, GFP_KERNEL)) {
                mempool_destroy(&pcpu_pool->pool);
                return NULL;
        }

        return pcpu_pool;
}
EXPORT_SYMBOL_GPL(percpu_mempool_create);

/**
 * percpu_mempool_refill - refill a percpu mempool
 * @pcpu_pool:        percpu mempool to refill
 * @gfp_mask:        allocation mask to use
 *
 * Refill @pcpu_pool upto the configured min_nr using @gfp_mask.
 *
 * Percpu memory allocation depends on %GFP_KERNEL.  If @gfp_mask doesn't
 * contain it, this function will schedule a work item to refill the pool
 * and return -%EAGAIN indicating refilling is in progress.
 */
int percpu_mempool_refill(struct percpu_mempool *pcpu_pool, gfp_t gfp_mask)
{
        if ((gfp_mask & GFP_KERNEL) == GFP_KERNEL)
                return mempool_fill(&pcpu_pool->pool, gfp_mask);

        schedule_work(&pcpu_pool->refill_work);
        return -EAGAIN;
}
EXPORT_SYMBOL_GPL(percpu_mempool_refill);

/**
 * percpu_mempool_destroy - destroy a percpu mempool
 * @pcpu_pool:        percpu mempool to destroy
 */
void percpu_mempool_destroy(struct percpu_mempool *pcpu_pool)
{
        cancel_work_sync(&pcpu_pool->refill_work);
        mempool_destroy(&pcpu_pool->pool);
}
EXPORT_SYMBOL_GPL(percpu_mempool_destroy);
