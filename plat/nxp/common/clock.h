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
#define CCM_TARGET_MUX(x)		(((x) - 1) << 24)
#define CCM_TARGET_PRE_PODF(x)		(((x) - 1) << 16)
#define CCM_TARGET_POST_PODF(x)		((x) - 1)

#define CCM_MISC_VIOLATE		BIT(8)
#define CCM_MISC_TIMEOUT		BIT(4)
#define CCM_MISC_AUTHEN_FAIL		BIT(0)

#define CCM_POST_BUSY2			BIT(31)
#define CCM_POST_SELECT_BRANCH_A	BIT(28)
#define CCM_POST_BUSY1			BIT(7)
#define CCM_POST_POST_PODF(x)		((x) - 1)

#define CCM_PRE_BUSY4			BIT(31)
#define CCM_PRE_ENABLE_A		BIT(28)
#define CCM_PRE_MUX_A(x)		(((x) - 1) << 24)
#define CCM_PRE_BUSY3			BIT(19)
#define CCM_PRE_PODF_A(x)		(((x) - 1) << 16)
#define CCM_PRE_BUSY1			BIT(15)
#define CCM_PRE_ENABLE_B		BIT(12)
#define CCM_PRE_MUX_B(x)		(((x) - 1) << 8)
#define CCM_PRE_BUSY0			BIT(3)
#define CCM_PRE_POST_PODF(x)		((x) - 1)

#define CCM_ACCESS_CTRL_LOCK		BIT(31)
#define CCM_ACCESS_SEMA_ENABLE		BIT(28)
#define CCM_ACCESS_DOM3_WHITELIST	BIT(27)
#define CCM_ACCESS_DOM2_WHITELIST	BIT(26)
#define CCM_ACCESS_DOM1_WHITELIST	BIT(25)
#define CCM_ACCESS_DOM0_WHITELIST	BIT(24)
#define CCM_ACCESS_MUTEX		BIT(20)
#define CCM_ACCESS_OWNER_ID(x)		((x) << 16)
#define CCM_ACCESS_DOM3_INFO(x)		((x) << 12)
#define CCM_ACCESS_DOM2_INFO(x)		((x) << 8)
#define CCM_ACCESS_DOM1_INFO(x)		((x) << 4)
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
