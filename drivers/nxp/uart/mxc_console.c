/*
 * Copyright (c) Linaro 2018 Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <arch.h>
#include <stdint.h>
#include "mxc_console.h"

static void write_reg(uintptr_t base, uint32_t offset, uint32_t val)
{
	mmio_write_32(base + offset, val);
}

static uint32_t read_reg(uintptr_t base, uint32_t offset)
{
	return mmio_read_32(base + offset);
}

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
	uint32_t val;

	if (c == '\n')
		console_core_putc('\r', base_addr);

	/* Write data */
	write_reg(base_addr, MXC_UART_TXD_OFFSET, c);

	/* Wait for transmit */
	do {
		val = read_reg(base_addr, MXC_UART_STAT2_OFFSET);
	} while (!(val & MXC_UART_STAT2_TXDC));

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
	uint32_t val;

	val = read_reg(base_addr, MXC_UART_TS_OFFSET);
	if (val & MXC_UART_TS_RXEMPTY)
		return -1;

	val = read_reg(base_addr, MXC_UART_RXD_OFFSET);
	return (int)(val & 0x000000FF);
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

