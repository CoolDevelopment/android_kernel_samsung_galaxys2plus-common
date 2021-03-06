/************************************************************************************************/
/*                                                                                              */
/*  Copyright 2011  Broadcom Corporation                                                        */
/*                                                                                              */
/*     Unless you and Broadcom execute a separate written software license agreement governing  */
/*     use of this software, this software is licensed to you under the terms of the GNU        */
/*     General Public License version 2 (the GPL), available at                                 */
/*                                                                                              */
/*          http://www.broadcom.com/licenses/GPLv2.php                                          */
/*                                                                                              */
/*     with the following added to such license:                                                */
/*                                                                                              */
/*     As a special exception, the copyright holders of this software give you permission to    */
/*     link this software with independent modules, and to copy and distribute the resulting    */
/*     executable under terms of your choice, provided that you also meet, for each linked      */
/*     independent module, the terms and conditions of the license of that module.              */
/*     An independent module is a module which is not derived from this software.  The special  */
/*     exception does not apply to any modifications of the software.                           */
/*                                                                                              */
/*     Notwithstanding the above, under no circumstances may you combine this software in any   */
/*     way with any other Broadcom software provided under a license other than the GPL,        */
/*     without Broadcom's express prior written consent.                                        */
/*                                                                                              */
/************************************************************************************************/

#ifndef __CHIP_PINMUX_H__
#define __CHIP_PINMUX_H__

/*
 * Define ball name, to match what's generated in RDB
 */
enum PIN_NAME {

//	/* DUMMY 32 */ PN_MPHI_DATA15,
//	/* DUMMY 31 */ PN_MPHI_DATA14,
//	/* DUMMY 30 */ PN_MPHI_DATA13,
//	/* DUMMY 29 */ PN_MPHI_DATA12,
//	/* DUMMY 28 */ PN_MPHI_DATA11,
//	/* DUMMY 27 */ PN_MPHI_DATA10,
//	/* DUMMY 26 */ PN_MPHI_DATA09,
//	/* DUMMY 25 */ PN_MPHI_DATA08,
//	/* DUMMY 24 */ PN_MPHI_DATA07,
//	/* DUMMY 23 */ PN_MPHI_DATA06,
//	/* DUMMY 22 */ PN_MPHI_DATA05,
//	/* DUMMY 21 */ PN_MPHI_DATA04,
//	/* DUMMY 20 */ PN_MPHI_DATA03,
//	/* DUMMY 19 */ PN_MPHI_DATA02,
//	/* DUMMY 20 */ PN_MPHI_HCE1_N,
//	/* DUMMY 19 */ PN_MPHI_HCE0_N,

	/* GPIO 191 */ PN_SRI_C,
	/* GPIO 190 */ PN_SRI_E,
	/* GPIO 189 */ PN_SRI_D,
	/* GPIO 188 */ PN_RFST2G_MTSLOTEN3G,
	/* GPIO 187 */ PN_TXDATA3G0,
	/* GPIO 186 */ PN_RTXDATA2G_TXDATA3G1,
	/* GPIO 185 */ PN_RTXEN2G_TXDATA3G2,
	/* GPIO 184 */ PN_RXDATA3G0,
	/* GPIO 183 */ PN_RXDATA3G1,
	/* GPIO 182 */ PN_RXDATA3G2,
	/* GPIO 181 */ PN_CLK_CX8,
	/* GPIO 180 */ PN_SYSCLKEN,
	/* GPIO 179 */ PN_NORFLSH_WE_N,
	/* GPIO 178 */ PN_NORFLSH_CE1_N,
	/* GPIO 177 */ PN_NORFLSH_CE0_N,
	/* GPIO 176 */ PN_NORFLSH_OE_N,
	/* GPIO 175 */ PN_NORFLSH_ADDR_23,
	/* GPIO 174 */ PN_NORFLSH_ADDR_22,
	/* GPIO 173 */ PN_NORFLSH_ADDR_21,
	/* GPIO 172 */ PN_NORFLSH_ADDR_20,
	/* GPIO 171 */ PN_NORFLSH_ADDR_19,
	/* GPIO 170 */ PN_NORFLSH_ADDR_18,
	/* GPIO 169 */ PN_NORFLSH_ADDR_17,
	/* GPIO 168 */ PN_NORFLSH_ADDR_16,
	/* GPIO 167 */ PN_NORFLSH_AADLAT_EN,
	/* GPIO 166 */ PN_NORFLSH_ADLAT_EN,
	/* GPIO 165 */ PN_NORFLSH_AD_15,
	/* GPIO 164 */ PN_NORFLSH_AD_14,
	/* GPIO 163 */ PN_NORFLSH_AD_13,
	/* GPIO 162 */ PN_NORFLSH_AD_12,
	/* GPIO 161 */ PN_NORFLSH_AD_11,
	/* GPIO 160 */ PN_NORFLSH_AD_10,
	/* GPIO 159 */ PN_NORFLSH_AD_09,
	/* GPIO 158 */ PN_NORFLSH_AD_08,
	/* GPIO 157 */ PN_NORFLSH_AD_07,
	/* GPIO 156 */ PN_NORFLSH_AD_06,
	/* GPIO 155 */ PN_NORFLSH_AD_05,
        /* GPIO 154 */ PN_NORFLSH_AD_04,
        /* GPIO 153 */ PN_NORFLSH_AD_03,
	/* GPIO 152 */ PN_NORFLSH_AD_02,
	/* GPIO 151 */ PN_NORFLSH_AD_01,
	/* GPIO 150 */ PN_NORFLSH_AD_00,
	/* GPIO 149 */ PN_NORFLSH_RDY,
	/* GPIO 148 */ PN_NORFLSH_CLK_N,

	/* GPIO 147 */ PN_SIM_RESETN,
	/* GPIO 146 */ PN_SIM_CLK,
	/* GPIO 145 */ PN_SIM_DATA,
	/* GPIO 144 */ PN_SIM_DET,
	/* GPIO 143 */ PN_SIM2_RESETN,
	/* GPIO 142 */ PN_SIM2_CLK,
	/* GPIO 141 */ PN_SIM2_DATA,
	/* GPIO 140 */ PN_SIM2_DET,

        /* GPIO 139 */ PN_ULPI0_CLOCK,
        /* GPIO 138 */ PN_ULPI0_DATA_0,
        /* GPIO 137 */ PN_ULPI0_DATA_1,
        /* GPIO 136 */ PN_ULPI0_DATA_2,
        /* GPIO 135 */ PN_ULPI0_DATA_3,
        /* GPIO 134 */ PN_ULPI0_DATA_4,
        /* GPIO 133 */ PN_ULPI0_DATA_5,
        /* GPIO 132 */ PN_ULPI0_DATA_6,
        /* GPIO 131 */ PN_ULPI0_DATA_7,
        /* GPIO 130 */ PN_ULPI0_DIR,
        /* GPIO 129 */ PN_ULPI0_NXT,
        /* GPIO 128 */ PN_ULPI0_STP,

	/* GPIO 127 */ PN_ULPI1_CLOCK,  
        /* GPIO 126 */ PN_ULPI1_DATA_0, 
        /* GPIO 125 */ PN_ULPI1_DATA_1, 
        /* GPIO 124 */ PN_ULPI1_DATA_2, 
        /* GPIO 123 */ PN_ULPI1_DATA_3, 
        /* GPIO 122 */ PN_ULPI1_DATA_4, 
        /* GPIO 121 */ PN_ULPI1_DATA_5, 
        /* GPIO 120 */ PN_ULPI1_DATA_6, 
        /* GPIO 119 */ PN_ULPI1_DATA_7, 
        /* GPIO 118 */ PN_ULPI1_DIR,    
        /* GPIO 117 */ PN_ULPI1_NXT,    
        /* GPIO 116 */ PN_ULPI1_STP,

	/* GPIO 115 */ PN_NAND_WP,
	/* GPIO 114 */ PN_NAND_CEN_0,
	/* GPIO 113 */ PN_NAND_CEN_1,
	/* GPIO 112 */ PN_NAND_RDY_0,
	/* GPIO 111 */ PN_NAND_RDY_1,
	/* GPIO 110 */ PN_NAND_CLE,
	/* GPIO 109 */ PN_NAND_ALE,
	/* GPIO 108 */ PN_NAND_OEN,
	/* GPIO 107 */ PN_NAND_WEN,
	/* GPIO 106 */ PN_NAND_AD_7,
	/* GPIO 105 */ PN_NAND_AD_6,
	/* GPIO 104 */ PN_NAND_AD_5,
	/* GPIO 103 */ PN_NAND_AD_4,
	/* GPIO 102 */ PN_NAND_AD_3,
	/* GPIO 101 */ PN_NAND_AD_2,
	/* GPIO 100 */ PN_NAND_AD_1,
	/* GPIO 99 */  PN_NAND_AD_0,

	/* GPIO 98 */  PN_UARTB4_UTXD,
	/* GPIO 97 */  PN_UARTB4_URXD,
	/* GPIO 96 */  PN_SDIO2_DATA_3,
	/* GPIO 95 */  PN_SDIO2_DATA_2,
	/* GPIO 94 */  PN_SDIO2_DATA_1,
	/* GPIO 93 */  PN_SDIO2_DATA_0,
	/* GPIO 92 */  PN_SDIO2_CMD,
	/* GPIO 91 */  PN_SDIO2_CLK,

	/* GPIO 90 */  PN_SDIO3_DATA_3,
	/* GPIO 89 */  PN_SDIO3_DATA_2,
	/* GPIO 88 */  PN_SDIO3_DATA_1,
	/* GPIO 87 */  PN_SDIO3_DATA_0,
	/* GPIO 86 */  PN_SDIO3_CMD,
	/* GPIO 85 */  PN_SDIO3_CLK,

	/* GPIO 84 */  PN_SSP0_FS,
	/* GPIO 83 */  PN_SSP0_CLK,
	/* GPIO 82 */  PN_SSP0_RXD,
	/* GPIO 81 */  PN_SSP0_TXD,

	/* GPIO 80 */  PN_SSP1_FS,
	/* GPIO 79 */  PN_SSP1_CLK,
	/* GPIO 78 */  PN_SSP1_RXD,
	/* GPIO 77 */  PN_SSP1_TXD,

	/* GPIO 76 */  PN_SSP2_FS_0,
	/* GPIO 75 */  PN_SSP2_CLK,
	/* GPIO 74 */  PN_SSP2_RXD_0,
	/* GPIO 73 */  PN_SSP2_TXD_0,
	/* GPIO 72 */  PN_SSP2_FS_1,
	/* GPIO 71 */  PN_SSP2_RXD_1,
	/* GPIO 70 */  PN_SSP2_TXD_1,
	/* GPIO 69 */  PN_SSP2_FS_2,

	/* GPIO 68 */  PN_SSP3_FS,
	/* GPIO 67 */  PN_SSP3_CLK,
	/* GPIO 66 */  PN_SSP3_RXD,
	/* GPIO 65 */  PN_SSP3_TXD,
	/* GPIO 64 */  PN_SSP3_EXTCLK,

	/* GPIO 63 */  PN_ARM_SLB_CLK,
	/* GPIO 62 */  PN_ARM_SLB_DATA,

	/* GPIO 61 */  PN_PMU_SCL,
	/* GPIO 60 */  PN_PMU_SDA,

	/* GPIO 59 */  PN_BSC2_SCL,
	/* GPIO 58 */  PN_BSC2_SDA,

	/* GPIO 57 */  PN_VC_CAM1_SCL,
	/* GPIO 56 */  PN_VC_CAM1_SDA,

	/* GPIO 55 */  PN_HDMI_SCL,
	/* GPIO 54 */  PN_HDMI_SDA,

	/* GPIO 53 */  PN_UARTB_URXD,
	/* GPIO 52 */  PN_UARTB_UTXD,
	/* GPIO 51 */  PN_UARTB_URTSN,
	/* GPIO 50 */  PN_UARTB_UCTSN,

	/* GPIO 49 */  PN_UARTB2_URXD,
	/* GPIO 48 */  PN_UARTB2_UTXD,

	/* GPIO 47 */  PN_LCD_R_7,
	/* GPIO 46 */  PN_LCD_R_6,
	/* GPIO 45 */  PN_LCD_R_5,
	/* GPIO 44 */  PN_LCD_R_4,
	/* GPIO 43 */  PN_LCD_R_3,
	/* GPIO 42 */  PN_LCD_R_2,
	/* GPIO 41 */  PN_LCD_R_1,
	/* GPIO 40 */  PN_LCD_R_0,

	/* GPIO 39 */  PN_LCD_G_7,
	/* GPIO 38 */  PN_LCD_G_6,
	/* GPIO 37 */  PN_LCD_G_5,
	/* GPIO 36 */  PN_LCD_G_4,
	/* GPIO 35 */  PN_LCD_G_3,
	/* GPIO 34 */  PN_LCD_G_2,
	/* GPIO 33 */  PN_LCD_G_1,
	/* GPIO 32 */  PN_LCD_G_0,

	/* GPIO 31 */  PN_LCD_B_7,
	/* GPIO 30 */  PN_LCD_B_6,
	/* GPIO 29 */  PN_LCD_B_5,
	/* GPIO 28 */  PN_LCD_B_4,
	/* GPIO 27 */  PN_LCD_B_3,
	/* GPIO 26 */  PN_LCD_B_2,
	/* GPIO 25 */  PN_LCD_B_1,
	/* GPIO 24 */  PN_LCD_B_0,

	/* GPIO 23 */  PN_LCD_HSYNC,
	/* GPIO 22 */  PN_LCD_VSYNC,
	/* GPIO 21 */  PN_LCD_OE,
	/* GPIO 20 */  PN_LCD_PCLK,

	/* GPIO 19 */  PN_CLKREQ_IN_0,
	/* GPIO 18 */  PN_CLKREQ_IN_1,
	/* GPIO 17 */  PN_CLKOUT_0,
	/* GPIO 16 */  PN_CLKOUT_1,

	/* GPIO 15 */  PN_DIGMIC1_CLK,
	/* GPIO 14 */  PN_DIGMIC1_DQ,
	/* GPIO 13 */  PN_DIGMIC2_CLK,
	/* GPIO 12 */  PN_DIGMIC2_DQ,

	/* GPIO 11 */  PN_BAT_RM,
	/* GPIO 10 */  PN_PMU_INT,
	/* GPIO 9 */   PN_STAT_1,
	/* GPIO 8 */   PN_STAT_2,

	/* GPIO 7 */   PN_GPIO_7,
	/* GPIO 6 */   PN_GPIO_6,
	/* GPIO 5 */   PN_GPIO_5,
	/* GPIO 4 */   PN_GPIO_4,
	/* GPIO 3 */   PN_GPIO_3,
	/* GPIO 2 */   PN_GPIO_2,
	/* GPIO 1 */   PN_GPIO_1,
	/* GPIO 0 */   PN_GPIO_0,
	
	PN_TRACECLK,
	PN_TRACEDT00,
	PN_TRACEDT01,
	PN_TRACEDT02,
	PN_TRACEDT03,
	PN_TRACEDT07,
	PN_MAX
};

/* define function name */
enum PIN_FUNC {
	PF_RESERVED	=	0,
	PF_GPIO,
	PF_DUMMY,
	PF_PWM_O_0,
	PF_PWM_O_1,
	PF_PWM_O_2,
	PF_PWM_O_3,
	PF_PWM_O_4,
	PF_PWM_O_5,

	PF_VC_GPIO_0,
	PF_VC_GPIO_1,
	PF_VC_GPIO_2,
	PF_VC_GPIO_3,
	PF_VC_GPIO_4,
	PF_VC_GPIO_5,
	PF_VC_GPIO_6,
	PF_VC_GPIO_7,
	PF_VC_GPIO_8,
	PF_VC_GPIO_9,
	PF_NORFLSH_WE_N,
	PF_NORFLSH_CE1_N,
	PF_NORFLSH_CE0_N,
	PF_NORFLSH_OE_N,
	PF_NORFLSH_ADDR_23,
	PF_NORFLSH_ADDR_22,
	PF_NORFLSH_ADDR_21,
	PF_NORFLSH_ADDR_20,
	PF_NORFLSH_ADDR_19,
	PF_NORFLSH_ADDR_18,
	PF_NORFLSH_ADDR_17,
	PF_NORFLSH_ADDR_16,
	PF_NORFLSH_AADLAT_EN,
	PF_NORFLSH_ADLAT_EN,
	PF_NORFLSH_AD_15,
	PF_NORFLSH_AD_14,
	PF_NORFLSH_AD_13,
	PF_NORFLSH_AD_12,
	PF_NORFLSH_AD_11,
	PF_NORFLSH_AD_10,
	PF_NORFLSH_AD_09,
	PF_NORFLSH_AD_08,
	PF_NORFLSH_AD_07,
	PF_NORFLSH_AD_06,
	PF_NORFLSH_AD_05,
	PF_NORFLSH_AD_04,
	PF_NORFLSH_AD_03,
	PF_NORFLSH_AD_02,
	PF_NORFLSH_AD_01,
	PF_NORFLSH_AD_00,
	PF_NORFLSH_RDY,
	PF_NORFLSH_CLK_N,
	PF_NORFLSH_WP,

	PF_KP_ROW_OP_0,
	PF_KP_ROW_OP_1,
	PF_KP_ROW_OP_2,
	PF_KP_ROW_OP_3,
	PF_KP_ROW_OP_4,
	PF_KP_ROW_OP_5,
	PF_KP_ROW_OP_6,
        PF_KP_ROW_OP_7,

	PF_KP_COL_IP_0,
	PF_KP_COL_IP_1,
	PF_KP_COL_IP_2,
	PF_KP_COL_IP_3,
	PF_KP_COL_IP_4,
	PF_KP_COL_IP_5,
	PF_KP_COL_IP_6,
	PF_KP_COL_IP_7,

	PF_ULPI0_CLOCK,
	PF_ULPI0_DATA_0,
	PF_ULPI0_DATA_1,
	PF_ULPI0_DATA_2,
	PF_ULPI0_DATA_3,
	PF_ULPI0_DATA_4,
	PF_ULPI0_DATA_5,
	PF_ULPI0_DATA_6,
	PF_ULPI0_DATA_7,
	PF_ULPI0_DIR,
	PF_ULPI0_NXT,
	PF_ULPI0_STP,

	PF_ULPI1_CLOCK,
	PF_ULPI1_DATA_0,
	PF_ULPI1_DATA_1,
	PF_ULPI1_DATA_2,
	PF_ULPI1_DATA_3,
	PF_ULPI1_DATA_4,
	PF_ULPI1_DATA_5,
	PF_ULPI1_DATA_6,
	PF_ULPI1_DATA_7,
	PF_ULPI1_DIR,
	PF_ULPI1_NXT,
	PF_ULPI1_STP,

	PF_NAND_WP,
	PF_NAND_CEN_0,
	PF_NAND_CEN_1,
	PF_NAND_RDY_0,
	PF_NAND_RDY_1,
	PF_NAND_CLE,
	PF_NAND_ALE,
	PF_NAND_OEN,
	PF_NAND_WEN,

	PF_VC_TRSTB,
	PF_VC_TCK,  
	PF_VC_TDI,  
	PF_VC_TDO,  
	PF_VC_TMS,  

	PF_NAND_AD_7,
	PF_NAND_AD_6,
	PF_NAND_AD_5,
	PF_NAND_AD_4,
	PF_NAND_AD_3,
	PF_NAND_AD_2,
	PF_NAND_AD_1,
	PF_NAND_AD_0,

	PF_UARTB4_UTXD,
	PF_UARTB4_URXD,
	PF_UARTB4_URTSN,
	PF_UARTB4_UCTSN,

	PF_UARTB_UTXD,
	PF_UARTB_URXD,
	PF_UARTB_URTSN,
	PF_UARTB_UCTSN,

	PF_SDIO1_DATA_3,
	PF_SDIO1_DATA_2,
	PF_SDIO1_DATA_1,
	PF_SDIO1_DATA_0,
	PF_SDIO1_CMD,
	PF_SDIO1_CLK,
	
	PF_SDIO2_WP,
	PF_SDIO2_CD_N,
	PF_SDIO2_DATA_7,
   
	PF_SDIO2_DATA_6,
	PF_SDIO2_DATA_5,
	PF_SDIO2_DATA_4,
	PF_SDIO2_DATA_3,
	PF_SDIO2_DATA_2,
	PF_SDIO2_DATA_1,
	PF_SDIO2_DATA_0,
	PF_SDIO2_CMD,
	PF_SDIO2_CLK,

	PF_SDIO3_WP,
	PF_SDIO3_CD_N,
	PF_SDIO3_DATA_7,
	PF_SDIO3_DATA_6,
	PF_SDIO3_DATA_5,
	PF_SDIO3_DATA_4,
	PF_SDIO3_DATA_3,
	PF_SDIO3_DATA_2,
	PF_SDIO3_DATA_1,
	PF_SDIO3_DATA_0,
	PF_SDIO3_CMD,
	PF_SDIO3_CLK,

	PF_SDIO4_DATA_7,
	PF_SDIO4_DATA_6,
	PF_SDIO4_DATA_5,
	PF_SDIO4_DATA_4,
	PF_SDIO4_DATA_3,
	PF_SDIO4_DATA_2,
	PF_SDIO4_DATA_1,
	PF_SDIO4_DATA_0,
	PF_SDIO4_CMD,
	PF_SDIO4_CLK,

	PF_SSP0_FS,
	PF_SSP0_CLK,
	PF_SSP0_RXD,
	PF_SSP0_TXD,

	PF_UARTB2_URXD,
	PF_UARTB2_UTXD,
	PF_UARTB2_URTSN,
	PF_UARTB2_UCTSN,

	PF_SSP1_FS,
	PF_SSP1_CLK,
	PF_SSP1_RXD,
	PF_SSP1_TXD,

	PF_UARTB3_URXD,
	PF_UARTB3_UTXD,
	PF_UARTB3_URTSN,
	PF_UARTB3_UCTSN,

	PF_SSP2_FS_0,
	PF_SSP2_CLK,
	PF_SSP2_RXD_0,
	PF_SSP2_TXD_0,
	PF_SSP2_FS_1,
	PF_SSP2_RXD_1,
	PF_SSP2_TXD_1,
	PF_SSP2_FS_2,
	PF_SSP2_FS_3,


	PF_SSP3_FS,
	PF_SSP3_CLK,
	PF_SSP3_RXD,
	PF_SSP3_TXD,
	PF_SSP3_EXTCLK,
        
	PF_TRACECLK,
	PF_TRACEDT00,
	PF_TRACEDT01,
	PF_TRACEDT02,
	PF_TRACEDT03,
	PF_TRACEDT07,

	PF_MDN_DSP_TRACE_CLK,
	PF_MDN_DSP_TRACE_DAT0,
	PF_MDN_DSP_TRACE_DAT1,
	PF_MDN_DSP_TRACE_DAT2,
	PF_MDN_DSP_TRACE_DAT3,
	PF_MDN_DSP_TRACE_DAT7,
	
	PF_PMU_SCL,
	PF_PMU_SDA,

	PF_BSC1_SCL,
	PF_BSC1_SDA,
	PF_BSC1_SCL_GP,
	PF_BSC1_SDA_GP,

	PF_BSC2_SCL,
	PF_BSC2_SDA,

	PF_VC_CAM2_SCL,
	PF_VC_CAM1_SCL,
	PF_VC_CAM2_SDA,
	PF_VC_CAM1_SDA,

	PF_HDMI_SCL,
	PF_HDMI_SDA,

	PF_LCD_R_7,
	PF_LCD_R_6,
	PF_LCD_R_5,
	PF_LCD_R_4,
	PF_LCD_R_3,
	PF_LCD_R_2,
	PF_LCD_R_1,
	PF_LCD_R_0,

	PF_LCD_G_7,
	PF_LCD_G_6,
	PF_LCD_G_5,
	PF_LCD_G_4,
	PF_LCD_G_3,
	PF_LCD_G_2,
	PF_LCD_G_1,
	PF_LCD_G_0,

	PF_LCD_B_7,
	PF_LCD_B_6,
	PF_LCD_B_5,
	PF_LCD_B_4,
	PF_LCD_B_3,
	PF_LCD_B_2,
	PF_LCD_B_1,
	PF_LCD_B_0,

	PF_LCD_HSYNC,
	PF_LCD_VSYNC,
	PF_LCD_OE,
	PF_LCD_PCLK,

	PF_CLKREQ_IN_3,
	PF_CLKREQ_IN_2,
	PF_CLKREQ_IN_1,
	PF_CLKREQ_IN_0,
	PF_CLKOUT_3,
	PF_CLKOUT_2,
	PF_CLKOUT_1,
	PF_CLKOUT_0,

	PF_DIGMIC1_CLK,
	PF_DIGMIC1_DQ,
	PF_DIGMIC2_CLK,
	PF_DIGMIC2_DQ,

	PF_BAT_RM,
	PF_PMU_INT,
	PF_STAT_1,
	PF_STAT_2,

	PF_GPIO_7,
	PF_GPIO_6,
	PF_GPIO_5,
	PF_GPIO_4,
	PF_GPIO_3,
	PF_GPIO_2,
	PF_GPIO_1,
	PF_GPIO_0,

	PF_ARM_SLB_CLK,
	PF_ARM_SLB_DATA,

	PF_VC_PWM_1,
	PF_VC_PWM_0,
	PF_VC_CPG1,
	PF_VC_CPG0,
	PF_VC_GPCLK_0,
	PF_VC_GPCLK_1,
	PF_VC_TE2,
	PF_VC_TE1,
	PF_VC_TE0,
	PF_VC_UTXD,
	PF_VC_URXD,

	PF_VC_I2S_WSIO,
	PF_VC_I2S_SCK,
	PF_VC_I2S_SDI,
	PF_VC_I2S_SDO,
	PF_VC_TESTDEBUG_CLK,

	PF_VC_SPI_CE1_N,
	PF_VC_SPI_CE0_N,
	PF_VC_SPI_MISO,
	PF_VC_SPI_MOSI,
	PF_VC_SPI_SCLK,

	PF_SWDIOTMS,
	PF_SWDCLKTCK,

	PF_CLCD_A_5,
	PF_CLCD_A_4,
	PF_CLCD_A_3,
	PF_CLCD_A_2,
	PF_CLCD_A_1,
	PF_CLCD_A_0,

	PF_CLCD_D_17,
	PF_CLCD_D_16,
	PF_CLCD_D_15,
	PF_CLCD_D_14,
	PF_CLCD_D_13,
	PF_CLCD_D_12,
	PF_CLCD_D_11,
	PF_CLCD_D_10,
	PF_CLCD_D_9,
	PF_CLCD_D_8,
	PF_CLCD_D_7,
	PF_CLCD_D_6,
	PF_CLCD_D_5,
	PF_CLCD_D_4,
	PF_CLCD_D_3,
	PF_CLCD_D_2,
	PF_CLCD_D_1,
	PF_CLCD_D_0,

	PF_CLCD_WEN,
	PF_CLCD_OEN,

	PF_MPHI_DATA_15,
	PF_MPHI_DATA_14,
	PF_MPHI_DATA_13,
	PF_MPHI_DATA_12,
	PF_MPHI_DATA_11,
	PF_MPHI_DATA_10,
	PF_MPHI_DATA_9,
	PF_MPHI_DATA_8,
	PF_MPHI_DATA_7,
	PF_MPHI_DATA_6,
	PF_MPHI_DATA_5,
	PF_MPHI_DATA_4,
	PF_MPHI_DATA_3,
	PF_MPHI_DATA_2,
	PF_MPHI_DATA_1,
	PF_MPHI_DATA_0,
	PF_MPHI_HAT1,
	PF_MPHI_HAT0,
	PF_MPHI_HA0,
	PF_MPHI_HRD_N,
	PF_MPHI_HWR_N,
	PF_MPHI_HCE0_N,
	PF_MPHI_HCE1_N,
	PF_MPHI_RUN,

	PF_GENERIC_CLK,
	PF_SIMLDO_EN,
	PF_DW_WIRE_1,
	PF_CLASSABPWR,
	PF_RTCK,
	PF_AFCPDM,

   PF_WCDMA_DEBUG_0,
   PF_WCDMA_DEBUG_1,
   PF_WCDMA_DEBUG_2,
   PF_WCDMA_DEBUG_3,
   PF_WCDMA_DEBUG_4,
   PF_WCDMA_DEBUG_5,
   PF_WCDMA_DEBUG_6,
   PF_WCDMA_DEBUG_7,
   PF_WCDMA_CLK1,
   PF_WCDMA_CLK2,
   PF_WCDMA_CLK3,
   PF_WCDMA_SYNC,
   PF_WCDMA_UART_TXD,
   PF_WCDMA_UART_RXD,

   PF_ACDATA,
   PF_ACFLAG,
   PF_ACREADY,
   PF_ACWAKE,
   PF_CADATA,
   PF_CAFLAG,
   PF_CAREADY,
   PF_CAWAKE,

   PF_IrRtsSd,
   PF_IrRx,
   PF_IrTx,

   PF_RFGPO_3,
   PF_RFGPO_2,
   PF_RFGPO_1,
   PF_RFGPO_0,

   PF_PTI_DAT3,
   PF_PTI_DAT2,
   PF_PTI_DAT1,
   PF_PTI_DAT0,
   PF_PTI_CLK,

   PF_PM_DEBUG0,
   PF_PM_DEBUG1,
   PF_PM_DEBUG2,
   PF_PM_DEBUG3,

   PF_DEBUG_BUS00,
   PF_DEBUG_BUS01,
   PF_DEBUG_BUS02,
   PF_DEBUG_BUS03,
   PF_DEBUG_BUS04,
   PF_DEBUG_BUS05,
   PF_DEBUG_BUS06,
   PF_DEBUG_BUS07,
   PF_DEBUG_BUS08,
   PF_DEBUG_BUS09,
   PF_DEBUG_BUS10,
   PF_DEBUG_BUS11,
   PF_DEBUG_BUS12,
   PF_DEBUG_BUS13,
   PF_DEBUG_BUS14,
   PF_DEBUG_BUS15,

   PF_IRD_OSC_0,
   PF_IRD_OSC_1,
   PF_IRD_OSC_2,
   PF_IRD_OSC_3,
   PF_IRD_OSC_4,
   PF_IRD_OSC_5,
   PF_IRD_OSC_6,
   PF_IRD_OSC_7,
   PF_IRD_OSC_8,
   PF_IRD_OSC_9,
   PF_IRD_OSC_10,
   PF_AP_RSTN,

   PF_AP_REF_2P4M_CLK,
   PF_ADC_AP_EN,
   PF_EP_AP_EN,
   PF_HS_AP_EN,
   PF_VIBRA_AP_EN,
   PF_IHF_AP_EN,
   PF_DAC_SCL_EN,
   PF_AP_ADC_DATA_O,
   PF_AP_DAC_DATA_I,
   PF_AP_IHF_DATA_I,
   PF_AP_LRCK_I,
   PF_AP_SCLK_I,

   PF_OSC1_OUT,
   PF_OSC2_OUT,

   PF_SIM_RESETN,
   PF_SIM_CLK,
   PF_SIM_DATA,
   PF_SIM_DET,
   PF_SIM2_RESETN,
   PF_SIM2_CLK,
   PF_SIM2_DATA,
   PF_SIM2_DET,

   PF_CWS_SYS_REQ1,
   PF_CWS_SYS_REQ2,
   PF_CWS_SYS_REQ3,

   PF_SRI_C,
   PF_SRI_E,
   PF_SRI_D,
   PF_GPEN03,
   PF_TXDATA3G0,
   PF_RTXDATA2G_TXDATA3G1,
   PF_RTXEN2G_TXDATA3G2,
   PF_RXDATA3G0,
   PF_RXDATA3G1,
   PF_RXDATA3G2,
   PF_CLK_CX8,
   PF_SYSCLKEN,
		
	PF_MAX
};

/* each Pin has up to 6 functions */
#define	MAX_ALT_FUNC		6

#endif /* __CHIP_PINMUX_H__ */
