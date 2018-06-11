#
# Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

# Architecture
$(eval $(call add_define,ARMV7_SUPPORTS_LARGE_PAGE_ADDRESSING))

# Tune compiler for Cortex-A7
ifeq ($(notdir $(CC)),armclang)
    TF_CFLAGS_aarch32	+=	-mcpu=cortex-a7
else ifneq ($(findstring clang,$(notdir $(CC))),)
    TF_CFLAGS_aarch32	+=	-mcpu=cortex-a7
else
    TF_CFLAGS_aarch32	+=	-mtune=cortex-a7
endif

# Platform
PLAT_INCLUDES		:=	-Iinclude/common/tbbr			\
				-Iinclude/plat/arm/common/		\
				-Iplat/nxp/common/			\
				-Iplat/nxp/imx7/warp7/include		\
				-Idrivers/nxp/uart			\
				-Iplat/nxp/imx7/include

# Translation tables library
include lib/xlat_tables_v2/xlat_tables.mk

BL2_SOURCES		+=	common/desc_image_load.c			\
				drivers/console/aarch32/console.S		\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				drivers/nxp/uart/mxc_console.c			\
				lib/aarch32/arm32_aeabi_divmod.c		\
				lib/aarch32/arm32_aeabi_divmod_a32.S		\
				lib/cpus/aarch32/cortex_a7.S			\
				plat/nxp/common/aips.c				\
				plat/nxp/common/wdog.c				\
				plat/nxp/common/clock.c				\
				plat/nxp/imx7/warp7/aarch32/warp7_helpers.S	\
				plat/nxp/imx7/warp7/warp7_bl2_el3_setup.c	\
				plat/nxp/imx7/warp7/warp7_bl2_mem_params_desc.c \
				plat/nxp/imx7/warp7/warp7_io_storage.c		\
				plat/nxp/imx7/warp7/warp7_image_load.c		\
				${XLAT_TABLES_LIB_SRCS}

# Build config flags
# ------------------

WORKAROUND_CVE_2017_5715	:= 0

# Disable the PSCI platform compatibility layer by default
ENABLE_PLAT_COMPAT		:= 0

# Enable reset to BL31 by default
RESET_TO_BL31			:= 0

# Non-TF Boot ROM
BL2_AT_EL3			:= 1

# Indicate single-core
COLD_BOOT_SINGLE_CPU		:= 1

# Have different sections for code and rodata
SEPARATE_CODE_AND_RODATA	:= 1

# Use Coherent memory
USE_COHERENT_MEM		:= 1

# Enable new version of image loading required for AArch32
LOAD_IMAGE_V2			:= 1

# Verify build config
# -------------------

ifneq (${LOAD_IMAGE_V2}, 1)
  $(error Error: warp7 needs LOAD_IMAGE_V2=1)
endif

ifeq (${ARCH},aarch64)
  $(error Error: AArch64 not supported on i.mx7)
endif
