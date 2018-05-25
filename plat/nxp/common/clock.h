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

struct ccm_clk_gate_ctrl {
	uint32_t ccm_ccgr;
	uint32_t ccm_ccgr_set;
	uint32_t ccm_ccgr_clr;
	uint32_t ccm_ccgr_tog;
};

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
