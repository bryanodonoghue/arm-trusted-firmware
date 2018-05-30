/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <stdint.h>

struct ccm_pll_ctrl {
	uint32_t ccm_pll_ctrl;
	uint32_t ccm_pll_ctrl_set;
	uint32_t ccm_pll_ctrl_clr;
	uint32_t ccm_pll_ctrl_tog;
};

/* Clock gate control */
struct ccm_clk_gate_ctrl {
	uint32_t ccm_ccgr;
	uint32_t ccm_ccgr_set;
	uint32_t ccm_ccgr_clr;
	uint32_t ccm_ccgr_tog;
};

#define CCM_CCGR_SETTING0_DOM_CLK_NONE		0
#define CCM_CCGR_SETTING0_DOM_CLK_RUN		BIT(0)
#define CCM_CCGR_SETTING0_DOM_CLK_RUN_WAIT	BIT(1)
#define CCM_CCGR_SETTING0_DOM_CLK_ALWAYS	(BIT(1) | BIT(0))
#define CCM_CCGR_SETTING1_DOM_CLK_NONE		0
#define CCM_CCGR_SETTING1_DOM_CLK_RUN		BIT(4)
#define CCM_CCGR_SETTING1_DOM_CLK_RUN_WAIT	BIT(5)
#define CCM_CCGR_SETTING1_DOM_CLK_ALWAYS	(BIT(5) | BIT(4))
#define CCM_CCGR_SETTING2_DOM_CLK_NONE		0
#define CCM_CCGR_SETTING2_DOM_CLK_RUN		BIT(8)
#define CCM_CCGR_SETTING2_DOM_CLK_RUN_WAIT	BIT(9)
#define CCM_CCGR_SETTING2_DOM_CLK_ALWAYS	(BIT(9) | BIT(8))
#define CCM_CCGR_SETTING3_DOM_CLK_NONE		0
#define CCM_CCGR_SETTING3_DOM_CLK_RUN		BIT(12)
#define CCM_CCGR_SETTING3_DOM_CLK_RUN_WAIT	BIT(13)
#define CCM_CCGR_SETTING3_DOM_CLK_ALWAYS	(BIT(13) | BIT(12))

enum {
	CCM_CCGR_ID_ADC = 32,
	CCM_CCGR_ID_AIPS1TZ = 10,
	CCM_CCGR_ID_AIPS2TZ = 11,
	CCM_CCGR_ID_AIPS3TZ = 12,
	CCM_CCGR_ID_APBHDMA = 20,
	CCM_CCGR_ID_CAAM = 36,
	CCM_CCGR_ID_CM4 = 1,
	CCM_CCGR_ID_CSI = 73,
	CCM_CCGR_ID_CSU = 45,
	CCM_CCGR_ID_DAP = 47,
	CCM_CCGR_ID_DBGMON = 46,
	CCM_CCGR_ID_DDRC = 19,
	CCM_CCGR_ID_ECSPI1 = 120,
	CCM_CCGR_ID_ECSPI2 = 121,
	CCM_CCGR_ID_ECSPI3 = 122,
	CCM_CCGR_ID_ECSPI4 = 123,
	CCM_CCGR_ID_EIM = 22,
	CCM_CCGR_ID_ENET1 = 112,
	CCM_CCGR_ID_ENET2 = 113,
	CCM_CCGR_ID_EPDC = 74,
	CCM_CCGR_ID_FLEXCAN1 = 116,
	CCM_CCGR_ID_FLEXCAN2 = 117,
	CCM_CCGR_ID_FLEXTIMER1 = 128,
	CCM_CCGR_ID_FLEXTIMER2 = 129,
	CCM_CCGR_ID_GPIO1 = 160,
	CCM_CCGR_ID_GPIO2 = 161,
	CCM_CCGR_ID_GPIO3 = 162,
	CCM_CCGR_ID_GPIO4 = 163,
	CCM_CCGR_ID_GPIO5 = 164,
	CCM_CCGR_ID_GPIO6 = 165,
	CCM_CCGR_ID_GPIO7 = 166,
	CCM_CCGR_ID_GPT1 = 124,
	CCM_CCGR_ID_GPT2 = 125,
	CCM_CCGR_ID_GPT3 = 126,
	CCM_CCGR_ID_GPT4 = 127,
	CCM_CCGR_ID_I2C1 = 136,
	CCM_CCGR_ID_I2C2 = 137,
	CCM_CCGR_ID_I2C3 = 138,
	CCM_CCGR_ID_I2C4 = 139,
	CCM_CCGR_ID_IOMUXC1 = 168,
	CCM_CCGR_ID_IOMUXC2 = 169,
	CCM_CCGR_ID_KPP = 120,
	CCM_CCGR_ID_LCDIF = 75,
	CCM_CCGR_ID_MIPI_CSI = 100,
	CCM_CCGR_ID_MIPI_DSI = 101,
	CCM_CCGR_ID_MIPI_PHY = 102,
	CCM_CCGR_ID_MU = 39,
	CCM_CCGR_ID_OCOTP = 35,
	CCM_CCGR_ID_OCRAM = 17,
	CCM_CCGR_ID_OCRAM_S = 18,
	CCM_CCGR_ID_PCIE = 96,
	CCM_CCGR_ID_PCIE_PHY = 96,
	CCM_CCGR_ID_PERFMON1 = 68,
	CCM_CCGR_ID_PERFMON2 = 69,
	CCM_CCGR_ID_PWM1 = 132,
	CCM_CCGR_ID_PWM2 = 133,
	CCM_CCGR_ID_PWM3 = 134,
	CCM_CCGR_ID_PMM4 = 135,
	CCM_CCGR_ID_PXP = 76,
	CCM_CCGR_ID_QOS1 = 42,
	CCM_CCGR_ID_QOS2 = 43,
	CCM_CCGR_ID_QOS3 = 44,
	CCM_CCGR_ID_QUADSPI = 21,
	CCM_CCGR_ID_RDC = 38,
	CCM_CCGR_ID_ROMCP = 16,
	CCM_CCGR_ID_SAI1 = 140,
	CCM_CCGR_ID_SAI2 = 141,
	CCM_CCGR_ID_SAI3 = 142,
	CCM_CCGR_ID_SCTR = 34,
	CCM_CCGR_ID_SDMA = 72,
	CCM_CCGR_ID_SEC = 49,
	CCM_CCGR_ID_SEMA42_1 = 64,
	CCM_CCGR_ID_SEMA42_2 = 65,
	CCM_CCGR_ID_SIM_DISPLAY = 5,
	CCM_CCGR_ID_SIM_ENET = 6,
	CCM_CCGR_ID_SIM_M = 7,
	CCM_CCGR_ID_SIM_MAIN = 4,
	CCM_CCGR_ID_SIM_S = 8,
	CCM_CCGR_ID_SIM_WAKEUP = 9,
	CCM_CCGR_ID_SIM1 = 144,
	CCM_CCGR_ID_SIM2 = 145,
	CCM_CCGR_ID_SIM_NAND = 20,
	CCM_CCGR_ID_DISPLAY_CM4 = 1,
	CCM_CCGR_ID_DRAM = 19,
	CCM_CCGR_ID_SNVS = 37,
	CCM_CCGR_ID_SPBA = 12,
	CCM_CCGR_ID_TRACE = 48,
	CCM_CCGR_ID_TZASC = 19,
	CCM_CCGR_ID_UART1 = 148,
	CCM_CCGR_ID_UART2 = 149,
	CCM_CCGR_ID_UART3 = 150,
	CCM_CCGR_ID_UART4 = 151,
	CCM_CCGR_ID_UART5 = 152,
	CCM_CCGR_ID_UART6 = 153,
	CCM_CCGR_ID_UART7 = 154,
	CCM_CCGR_ID_USB_HS = 40,
	CCM_CCGR_ID_USB_IPG = 104,
	CCM_CCGR_ID_USB_PHY_480MCLK = 105,
	CCM_CCGR_ID_USB_OTG1_PHY = 106,
	CCM_CCGR_ID_USB_OTG2_PHY = 107,
	CCM_CCGR_ID_USBHDC1 = 108,
	CCM_CCGR_ID_USBHDC2 = 109,
	CCM_CCGR_ID_USBHDC3 = 110,
	CCM_CCGR_ID_WDOG1 = 156,
	CCM_CCGR_ID_WDOG2 = 157,
	CCM_CCGR_ID_WDOG3 = 158,
	CCM_CCGR_ID_WDOG4 = 159,
};

/* Clock target block */
struct ccm_target_root_ctrl {
	uint32_t ccm_target_root;
	uint32_t ccm_target_root_set;
	uint32_t ccm_target_root_clr;
	uint32_t ccm_target_root_tog;
	uint32_t ccm_misc;
	uint32_t ccm_misc_set;
	uint32_t ccm_misc_clr;
	uint32_t ccm_misc_tog;
	uint32_t ccm_post;
	uint32_t ccm_post_set;
	uint32_t ccm_post_clr;
	uint32_t ccm_post_tog;
	uint32_t ccm_pre;
	uint32_t ccm_pre_set;
	uint32_t ccm_pre_clr;
	uint32_t ccm_pre_tog;
	uint32_t reserved[0x0c];
	uint32_t ccm_access_ctrl;
	uint32_t ccm_access_ctrl_set;
	uint32_t ccm_access_ctrl_clr;
	uint32_t ccm_access_ctrl_tog;
};

#define CCM_TARGET_ROOT_ENABLE		BIT(28)
#define CCM_TARGET_MUX(x)		((x-1)<<24)
#define CCM_TARGET_PRE_PODF(x)		((x-1)<<16)
#define CCM_TARGET_POST_PODF(x)		(x-1)

#define CCM_MISC_VIOLATE		BIT(8)
#define CCM_MISC_TIMEOUT		BIT(4)
#define CCM_MISC_AUTHEN_FAIL		BIT(0)

#define CCM_POST_BUSY2			BIT(31)
#define CCM_POST_SELECT_BRANCH_A	BIT(28)
#define CCM_POST_BUSY1			BIT(7)
#define CCM_POST_POST_PODF(x)		(x-1)

#define CCM_PRE_BUSY4			BIT(31)
#define CCM_PRE_ENABLE_A		BIT(28)
#define CCM_PRE_MUX_A(x)		((x-1)<<24)
#define CCM_PRE_BUSY3			BIT(19)
#define CCM_PRE_PODF_A(x)		((x-1)<<16)
#define CCM_PRE_BUSY1			BIT(15)
#define CCM_PRE_ENABLE_B		BIT(12)
#define CCM_PRE_MUX_B(x)		((x-1)<<8)
#define CCM_PRE_BUSY0			BIT(3)
#define CCM_PRE_POST_PODF(x)		(x-1)

#define CCM_ACCESS_CTRL_LOCK		BIT(31)
#define CCM_ACCESS_SEMA_ENABLE		BIT(28)
#define CCM_ACCESS_DOM3_WHITELIST	BIT(27)
#define CCM_ACCESS_DOM2_WHITELIST	BIT(26)
#define CCM_ACCESS_DOM1_WHITELIST	BIT(25)
#define CCM_ACCESS_DOM0_WHITELIST	BIT(24)
#define CCM_ACCESS_MUTEX		BIT(20)
#define CCM_ACCESS_OWNER_ID(x)		(x<<16)
#define CCM_ACCESS_DOM3_INFO(x)		(x<<12)
#define CCM_ACCESS_DOM2_INFO(x)		(x<<8)
#define CCM_ACCESS_DOM1_INFO(x)		(x<<4)
#define CCM_ACCESS_DOM0_INFO(x)		(x)

#define CCM_PLL_CTRL_NUM	0x21
#define CCM_CLK_GATE_CTRL_NUM	0xbf
#define CCM_ROOT_CTRL_NUM	0x79

struct ccm {
	uint32_t ccm_gpr0;
	uint32_t ccm_gpr0_set;
	uint32_t ccm_gpr0_clr;
	uint32_t ccm_grp0_tog;
	uint32_t reserved[0x1fc];
	struct ccm_pll_ctrl ccm_pll_ctrl[CCM_PLL_CTRL_NUM];
	uint32_t reserved1[0xd7c];
	struct ccm_clk_gate_ctrl ccm_clk_gate_ctrl[CCM_CLK_GATE_CTRL_NUM];
	uint32_t reserved2[0xd04];
	struct ccm_target_root_ctrl ccm_root_ctrl[CCM_ROOT_CTRL_NUM];
};

void clock_init(void);

#endif /* __CLOCK_H__ */
