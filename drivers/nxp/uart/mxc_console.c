/*
 * Copyright (c) Linaro 2018 Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <arch.h>
#include <stdint.h>
#include "mxc_console.h"

int console_core_init(uintptr_t base_addr, unsigned int uart_clk,
		      unsigned int baud_rate)
{
	return 0;
}

/* --------------------------------------------------------
 * int console_core_putc(int c, uintptr_t base_addr)
 * Function to output a character over the console. It
 * returns the character printed on success or -1 on error.
 * In : r0 - character to be printed
 *      r1 - console base address
 * Out : return -1 on error else return character.
 * Clobber list : r2
 * --------------------------------------------------------
 */
int console_core_putc(int c, uintptr_t base_addr)
{
	return 0;
}

/*
 * Function to get a character from the console.
 * It returns the character grabbed on success
 * or -1 on error.
 * In : r0 - console base address
 * Clobber list : r0, r1
 * ---------------------------------------------
 */
int console_core_getc(uintptr_t base_addr)
{
	return 0;
}

/*
 * Function to force a write of all buffered
 * data that hasn't been output.
 * In : r0 - console base address
 * Out : return -1 on error else return 0.
 * Clobber list : r0, r1
 * ---------------------------------------------
 */
int console_core_flush(uintptr_t base_addr)
{
	return 0;
}

