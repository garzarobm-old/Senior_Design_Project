#******************************************************************************
#
# Makefile - Rules for building the libraries, examples and docs.
#
# Copyright (c) 2019, Ambiq Micro
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
# 
# 3. Neither the name of the copyright holder nor the names of its
# contributors may be used to endorse or promote products derived from this
# software without specific prior written permission.
# 
# Third party software included in this distribution is subject to the
# additional license terms as defined in the /docs/licenses directory.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# This is part of revision 2.1.0 of the AmbiqSuite Development Package.
#
#******************************************************************************

#******************************************************************************
#
# This is an example makefile for SparkFun Apollo3 boards as used in the 
#   AmbiqSuite SDK.
#
# Recommended usage
#   make
#   make bootload_svl (uses the SparkFun Variable Loader to upload code)
#   make bootload_asb (uses the Ambiq Secure Bootlaoder to upload code)
#   make clean
#
# Filepaths
#   You can relocate this makefile easily by providing the path to the root of
#   the AmbiqSuite SDK. If that path is not specified then this file will 
#   assume that it is located in 
#   <AmbiqSDKRoot>/boards/<your_board>/examples/<your_example>/gcc
#   and use relative paths
#
# User Configuration
#   You must also specify which COM_PORT to use if you want to use the 
#   'bootlaoder' targets. 
#     Windows example: 	COM_PORT=COM4
#     *nix example: 	COM_PORT=/dev/usbserialxxxx
#
# Python vs. Executable
#   For simplicity the upload tools are called as Python scripts by default.
#   Make sure PYTHON is set to the appropriate command to run Python3 from the
#   command line.
#
#******************************************************************************


#******************************************************************************
#
# User Options
#
#******************************************************************************


#******************************************************************************
#
# Warning Messages
#
#******************************************************************************
### Bootloader Tools

TARGET := seniorFitBle
COMPILERNAME := gcc
PROJECT := ble_freertos_fit_lp_gcc
CONFIG := bin


SHELL:=/bin/bash
SERIAL_PORT ?= '/dev/ttyUSB0'# Or perhaps a Unix-like machine might put '/dev/cu.usbserial-1410' 
#### Setup ####

TOOLCHAIN ?= arm-none-eabi
PART = apollo3
CPU = cortex-m4
FPU = fpv4-sp-d16
# Default to FPU hardware calling convention.  However, some customers and/or
# applications may need the software calling convention.
#FABI = softfp
FABI = hard


LINKER_FILE := ./ble_freertos_fit_lp.ld
STARTUP_FILE := ./startup_$(COMPILERNAME).c

#### Required Executables ####
CC = $(TOOLCHAIN)-gcc
GCC = $(TOOLCHAIN)-gcc
CPP = $(TOOLCHAIN)-cpp
CXX = $(TOOLCHAIN)-g++
LD = $(TOOLCHAIN)-ld
CP = $(TOOLCHAIN)-objcopy
OD = $(TOOLCHAIN)-objdump
RD = $(TOOLCHAIN)-readelf
AR = $(TOOLCHAIN)-ar
SIZE = $(TOOLCHAIN)-size
RM = $(shell which rm 2>/dev/null)

EXECUTABLES = CC LD CP OD AR RD SIZE GCC CXX
K := $(foreach exec,$(EXECUTABLES),\
        $(if $(shell which $($(exec)) 2>/dev/null),,\
        $(info $(exec) not found on PATH ($($(exec))).)$(exec)))
$(if $(strip $(value K)),$(info Required Program(s) $(strip $(value K)) not found))

ifneq ($(strip $(value K)),)
all clean:
	$(info Tools $(TOOLCHAIN)-$(COMPILERNAME) not installed.)
	$(RM) -rf bin
else




#******************************************************************************
#
# User Defines / Includes / Sources / Libraries
#
#******************************************************************************

# Global Defines
DEFINES=  -DPART_$(PART)
DEFINES+= -DAM_CUSTOM_BDADDR
DEFINES+= -DAM_PACKAGE_BGA
DEFINES+= -DWSF_TRACE_ENABLED
DEFINES+= -DAM_DEBUG_PRINTF
DEFINES+= -DAM_PART_APOLLO3
DEFINES+=

# Includes (Add paths to where example header files are located)
INCLUDES=
INCLUDES+= -I$(PROJECTPATH)/src
INCLUDES+= -I$(BOARDPATH)/bsp
INCLUDES+= -I$(SDKPATH)
INCLUDES+= -I$(PROJECTPATH)/utils
INCLUDES+= -I$(PROJECTPATH)/devices
INCLUDES+= -I$(PROJECTPATH)/mcu/apollo3
INCLUDES+= -I$(PROJECTPATH)/CMSIS/AmbiqMicro/Include
INCLUDES+= -I$(PROJECTPATH)/CMSIS/ARM/Include
INCLUDES+=

# Compilation Units (Add all the .c files you need to compile)
SRC=
SRC+= main.cpp
SRC+= startup_gcc.c
SRC+= am_util_delay.c
SRC+= am_util_faultisr.c
SRC+= am_util_id.c
SRC+= am_util_stdio.c
SRC+=

# VPATH (Add paths to where your source files are located)
VPATH = ../src/third_party/exactle/sw/services
VPATH+=:../src
VPATH+=:../src/third_party/FreeRTOSv10.1.1/Source

# LIBS (Precompiled libraries to include in the linker step)
LIBS = ../src/third_party/exactle/projects/generic/stacklib/gcc/bin-cortex-m4/libstacklib.a
LIBS += ../src/mcu/apollo3/hal/gcc/bin/libam_hal.a
LIBS += ../../../bsp/gcc/bin/libam_bsp.a
LIBS += ../src/third_party/uecc/gcc/bin/lib_uecc.a





#******************************************************************************
#
# Machinery
#
#******************************************************************************

XSRC = $(filter %.cpp,$(SRC))
ZSRC = $(filter %.cc,$(SRC))
CSRC = $(filter %.c,$(SRC))
ASRC = $(filter %.s,$(SRC))

OBJS = $(XSRC:%.cpp=$(CONFIG)/%.o)
OBJS+= $(ZSRC:%.cc=$(CONFIG)/%.o)
OBJS+= $(CSRC:%.c=$(CONFIG)/%.o)
OBJS+= $(ASRC:%.s=$(CONFIG)/%.o)

DEPS = $(XSRC:%.cpp=$(CONFIG)/%.d)
DEPS+= $(ZSRC:%.cc=$(CONFIG)/%.d)
DEPS+= $(CSRC:%.c=$(CONFIG)/%.d)
DEPS+= $(ASRC:%.s=$(CONFIG)/%.d)

CSTD = -std=c99 

CFLAGS = -mthumb -mcpu=$(CPU) -mfpu=$(FPU) -mfloat-abi=$(FABI)
CFLAGS+= -ffunction-sections -fdata-sections
CFLAGS+= -MMD -MP $(CSTD) -Wall -g
CFLAGS+= -O0
CFLAGS+= $(DEFINES)
CFLAGS+= $(INCLUDES)
CFLAGS+= 

XSTD   = -std=gnu++11

XFLAGS = $(CFLAGS)
XFLAGS+= -fno-exceptions

LFLAGS = -mthumb -mcpu=$(CPU) -mfpu=$(FPU) -mfloat-abi=$(FABI)
LFLAGS+= -nostartfiles -static
LFLAGS+= -Wl,--gc-sections,--entry,Reset_Handler,-Map,$(CONFIG)/$(TARGET).map
LFLAGS+= -Wl,--start-group -lm -lc -lgcc $(LIBS) -Wl,--end-group
LFLAGS+= 

# Additional user specified CFLAGS
CFLAGS+=$(EXTRA_CFLAGS)

CPFLAGS = -Obinary

ODFLAGS = -S

#******************************************************************************
#
# Targets / Rules
#
#******************************************************************************
all: spark
spark: directories $(CONFIG)/$(TARGET).bin

directories:
	@mkdir -p $(CONFIG)

$(CONFIG)/%.o: %.cpp $(CONFIG)/%.d
	@echo " Compiling $(COMPILERNAME) $<" ;\
	$(CXX) -c $(XSTD) $(XFLAGS) $< -o $@

$(CONFIG)/%.o: %.cc $(CONFIG)/%.d
	@echo " Compiling $(COMPILERNAME) $<" ;\
	$(CXX) -c $(XSTD) $(XFLAGS) $< -o $@

$(CONFIG)/%.o: %.c $(CONFIG)/%.d
	@echo " Compiling $(COMPILERNAME) $<" ;\
	$(CC) -c $(CFLAGS) $< -o $@

$(CONFIG)/%.o: %.s $(CONFIG)/%.d
	@echo " Assembling $(COMPILERNAME) $<" ;\
	$(CC) -c $(CFLAGS) $< -o $@

$(CONFIG)/$(TARGET).axf: LINKER_FILE = asb_linker.ld
$(CONFIG)/$(TARGET).axf: $(OBJS) $(LIBS)
	@echo " Linking $(COMPILERNAME) $@ with script $(LINKER_FILE)";\
	$(CC) -Wl,-T,$(LINKER_FILE) -o $@ $(OBJS) $(LFLAGS)


$(CONFIG)/$(TARGET)_%.bin: $(CONFIG)/$(TARGET)_%.axf
	@echo " Copying $(COMPILERNAME) $@..." ;\
	$(CP) $(CPFLAGS) $< $@ ;\
	$(OD) $(ODFLAGS) $< > $(CONFIG)/$(TARGET).lst



clean:
	@echo "Cleaning..." ;\
	$(RM) -f $(OBJS) $(DEPS) \
	    $(CONFIG)/$(TARGET).bin $(CONFIG)/$(TARGET).axf \
	    $(CONFIG)/$(TARGET).lst $(CONFIG)/$(TARGET).map \
		$(CONFIG)/$(TARGET)_svl.bin $(CONFIG)/$(TARGET)_svl.axf \
	    $(CONFIG)/$(TARGET)_svl.lst $(CONFIG)/$(TARGET)_svl.map \
	    $(CONFIG)/$(TARGET)_asb.bin $(CONFIG)/$(TARGET)_asb.axf \
	    $(CONFIG)/$(TARGET)_asb.lst $(CONFIG)/$(TARGET)_asb.map

$(CONFIG)/%.d: ;

$../src/mcu/apollo3/hal/gcc/bin/libam_hal.a:
	$(MAKE) -C $(SDKPATH)/mcu/apollo3/hal/gcc

../src/third_party/uecc/gcc/bin/lib_uecc.a:
	$(MAKE) -C ../src/third_party/uecc

../../../bsp/gcc/bin/libam_bsp.a:
	$(MAKE) -C ../../../bsp

wired_update: all
	../src/tools/apollo3_scripts/create_cust_image_blob.py --bin $(CONFIG)/$(TARGET).bin --load-address 0xC000 --magic-num 0xCB -o $(CONFIG)/main_nonsecure_ota --version 0x0
	../src/tools/apollo3_scripts/create_cust_wireupdate_blob.py --load-address 0x20000 --bin $(CONFIG)/main_nonsecure_ota.bin -i 6 -o $(CONFIG)/main_nonsecure_wire --options 0x1


bootload: wired_update
	../../../bsp/tools/uart_wired_update_sparkfun.py -b 921600 $(SERIAL_PORT) -r 1 -f $(CONFIG)/main_nonsecure_wire.bin -i 6

boot_artemis: wired_update



# Automatically include any generated dependencies
-include $(DEPS)
endif
.PHONY: all clean directories bootload bootload_asb bootload_svl
