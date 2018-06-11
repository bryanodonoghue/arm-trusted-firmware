/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <debug.h>
#include <io_block.h>
#include <io_memmap.h>
#include <platform_def.h>

static uintptr_t memmap_dev_handle;

static const io_block_spec_t fip_block_spec = {
	.offset = WARP7_FIP_BASE,
	.length = WARP7_FIP_SIZE
};

static int open_memmap(const uintptr_t spec);

/* TODO: this structure is replicated multiple times. rationalize it ! */
struct plat_io_policy {
	uintptr_t *dev_handle;
	uintptr_t image_spec;
	int (*check)(const uintptr_t spec);
};

static int open_memmap(const uintptr_t spec)
{
	int result;
	uintptr_t local_image_handle;

	result = io_dev_init(memmap_dev_handle, (uintptr_t)NULL);
	if (result == 0) {
		result = io_open(memmap_dev_handle, spec, &local_image_handle);
		if (result == 0) {
			VERBOSE("Using Memmap\n");
			io_close(local_image_handle);
		}
	}
	return result;
}

int plat_get_image_source(unsigned int image_id, uintptr_t *dev_handle,
			  uintptr_t *image_spec)
{
	return 0;
}
