/*
 * Copyright (c) Linaro 2018 Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <arch.h>
#include <console_macros.S>

	.globl	mxc_crash_console_init
	.globl	mxc_crash_console_putc
	.globl	mxc_crash_console_flush

	/* -----------------------------------------------
	 * int mxc_crash_console_init(uintptr_t base_addr,
	 * unsigned int uart_clk, unsigned int baud_rate)
	 * Function to initialize the console without a
	 * C Runtime to print debug information. This
	 * function will be accessed by console_init and
	 * crash reporting.
	 * In: r0 - console base address
	 *     r1 - Uart clock in Hz
	 *     r2 - Baud rate
	 * Out: return 1 on success else 0 on error
	 * Clobber list : r1, r2, r3
	 * -----------------------------------------------
	 */
func mxc_crash_console_init

endfunc mxc_crash_console_init

	/* --------------------------------------------------------
	 * int mxc_crash_console_putc(int c, uintptr_t base_addr)
	 * Function to output a character over the console. It
	 * returns the character printed on success or -1 on error.
	 * In : r0 - character to be printed
	 *      r1 - console base address
	 * Out : return -1 on error else return character.
	 * Clobber list : r2
	 * --------------------------------------------------------
	 */
func mxc_crash_console_putc

endfunc mxc_crash_console_putc

	/* ---------------------------------------------
	 * int mxc_crash_console_flush(uintptr_t base_addr)
	 * Function to force a write of all buffered
	 * data that hasn't been output.
	 * In : r0 - console base address
	 * Out : return -1 on error else return 0.
	 * Clobber list : r0, r1
	 * ---------------------------------------------
	 */
func mxc_crash_console_flush

endfunc mxc_crash_console_flush
