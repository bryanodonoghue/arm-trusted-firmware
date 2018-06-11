/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch_helpers.h>
#include <assert.h>
#include <bl_common.h>
#include <console.h>
#include <debug.h>
#include <desc_image_load.h>
#include <optee_utils.h>
#include <platform_def.h>
#include <xlat_mmu_helpers.h>
#include <xlat_tables_defs.h>
#include <aips.h>
#include <clock.h>
#include <mxc_console.h>
#include "warp7_private.h"

#define UART1_CLK_SELECT (CCM_TARGET_ROOT_ENABLE |\
			  CCM_TRGT_MUX_UART1_CLK_ROOT_OSC_24M)

uintptr_t plat_get_ns_image_entrypoint(void)
{
	return WARP7_UBOOT_BASE;
}

static uint32_t warp7_get_spsr_for_bl32_entry(void)
{
	return SPSR_MODE32(MODE32_svc, SPSR_T_ARM, SPSR_E_LITTLE,
			   DISABLE_ALL_EXCEPTIONS);
}

static uint32_t warp7_get_spsr_for_bl33_entry(void)
{
	return SPSR_MODE32(MODE32_svc,
			   plat_get_ns_image_entrypoint() & 0x1,
			   SPSR_E_LITTLE, DISABLE_ALL_EXCEPTIONS);
}

#ifndef AARCH32_SP_OPTEE
#error "Must build with OPTEE support included"
#endif

int bl2_plat_handle_post_image_load(unsigned int image_id)
{
	int err = 0;
	bl_mem_params_node_t *bl_mem_params = get_bl_mem_params_node(image_id);

	bl_mem_params_node_t *pager_mem_params = NULL;
	bl_mem_params_node_t *paged_mem_params = NULL;

	assert(bl_mem_params);

	switch (image_id) {
	case BL32_IMAGE_ID:
		pager_mem_params = get_bl_mem_params_node(BL32_EXTRA1_IMAGE_ID);
		assert(pager_mem_params);

		paged_mem_params = get_bl_mem_params_node(BL32_EXTRA2_IMAGE_ID);
		assert(paged_mem_params);

		err = parse_optee_header(&bl_mem_params->ep_info,
					 &pager_mem_params->image_info,
					 &paged_mem_params->image_info);
		if (err != 0)
			WARN("OPTEE header parse error.\n");

		/*
		 * When ATF loads the DTB the address of the DTB is passed in
		 * arg2, however for the WaRP7 we will have u-boot load the DTB
		 * directly and therefore we won't be modifying the DTB in
		 * OPTEE.
		 * Just leave arg2 @ 0 for now - unless we deicide to switch up
		 * the responsibility for loading DTB from u-boot to ATF
		 */
		bl_mem_params->ep_info.args.arg0 =
					bl_mem_params->ep_info.args.arg1;
		bl_mem_params->ep_info.args.arg1 = 0;
		bl_mem_params->ep_info.args.arg2 = 0;
		bl_mem_params->ep_info.args.arg3 = 0;
		bl_mem_params->ep_info.spsr = warp7_get_spsr_for_bl32_entry();
		break;

	case BL33_IMAGE_ID:
		/* AArch32 only core: OP-TEE expects NSec EP in register LR */
		pager_mem_params = get_bl_mem_params_node(BL32_IMAGE_ID);
		assert(pager_mem_params);
		pager_mem_params->ep_info.lr_svc = bl_mem_params->ep_info.pc;

		/* BL33 expects to receive the primary CPU MPID (through r0) */
		bl_mem_params->ep_info.args.arg0 = 0xffff & read_mpidr();
		bl_mem_params->ep_info.spsr = warp7_get_spsr_for_bl33_entry();
		break;

	default:
		/* Do nothing in default case */
		break;
	}

	return err;
}

void bl2_el3_plat_arch_setup(void)
{
	/* Setup the MMU here */
}

/*
 * bl2_early_platform_setup()
 * MMU off
 */
void bl2_el3_early_platform_setup(u_register_t arg1, u_register_t arg2,
				  u_register_t arg3, u_register_t arg4)
{
	uint32_t uart_en_bits = (uint32_t)UART1_CLK_SELECT;

	/* Initialize the AIPS */
	aips_init();

	/* Initialize clocks, regulators, pin-muxes etc */
	clock_init();
	clock_enable_uart(0, uart_en_bits);

	/* Init UART, storage and friends */
	console_init(PLAT_WARP7_BOOT_UART_BASE, PLAT_WARP7_BOOT_UART_CLK_IN_HZ,
		     PLAT_WARP7_CONSOLE_BAUDRATE);

	/* Open handles to persistent storage */
	plat_warp7_io_setup();
}

/*
 * bl2_platform_setup()
 * MMU on - enabled by bl2_el3_plat_arch_setup()
 */
void bl2_platform_setup(void)
{
}
