/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <io_block.h>
#include <platform_def.h>

static const io_block_spec_t fip_block_spec = {
	.offset = WARP7_FIP_BASE,
	.length = WARP7_FIP_SIZE
};

/* TODO: this structure is replicated multiple times. rationalize it ! */
struct plat_io_policy {
	uintptr_t *dev_handle;
	uintptr_t image_spec;
	int (*check)(const uintptr_t spec);
};

int plat_get_image_source(unsigned int image_id, uintptr_t *dev_handle,
			  uintptr_t *image_spec)
{
	return 0;
}
