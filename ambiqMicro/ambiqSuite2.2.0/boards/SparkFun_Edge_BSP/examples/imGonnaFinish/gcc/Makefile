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
# This is part of revision v2.2.0-7-g63f7c2ba1 of the AmbiqSuite Development Package.
#
#******************************************************************************
TARGET := seniorFit
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

EXECUTABLES = CC LD CP OD AR RD SIZE GCC
K := $(foreach exec,$(EXECUTABLES),\
        $(if $(shell which $($(exec)) 2>/dev/null),,\
        $(info $(exec) not found on PATH ($($(exec))).)$(exec)))
$(if $(strip $(value K)),$(info Required Program(s) $(strip $(value K)) not found))

ifneq ($(strip $(value K)),)
all clean:
	$(info Tools $(TOOLCHAIN)-$(COMPILERNAME) not installed.)
	$(RM) -rf bin
else

DEFINES = -DPART_$(PART)
DEFINES+= -DAM_PACKAGE_BGA
DEFINES+= -DAM_PART_APOLLO3
DEFINES+= -DAM_FREERTOS

INCLUDES = -I../src
INCLUDES+= -I../src/utils
INCLUDES+= -I../src/third_party/exactle/sw/stack/hci
INCLUDES+= -I../src/third_party/exactle/sw/profiles/rscp
INCLUDES+= -I../src/third_party/exactle/sw/hci/include
INCLUDES+= -I../../../bsp
INCLUDES+= -I../src/third_party/exactle/sw/profiles/hrps
INCLUDES+= -I../src/devices
INCLUDES+= -I../src/third_party/exactle/sw/apps/app/include
INCLUDES+= -I../src/third_party/exactle/sw/services
INCLUDES+= -I../src/third_party/exactle/sw/apps/fit
INCLUDES+= -I../src/third_party/exactle/sw/profiles/bas
INCLUDES+= -I../src/third_party/exactle/sw/hci/ambiq
INCLUDES+= -I../src/third_party/exactle/sw/apps/app
INCLUDES+= -I../src/third_party/FreeRTOSv10.1.1/Source/include
INCLUDES+= -I../src/third_party/exactle/ws-core/include
INCLUDES+= -I../src/third_party/exactle/sw/profiles/hid
INCLUDES+= -I../src/third_party/exactle/sw/stack/cfg
INCLUDES+= -I../src/CMSIS/AmbiqMicro/Include
INCLUDES+= -I../src/third_party/uecc/micro-ecc
INCLUDES+= -I../src/third_party/exactle/sw/sec/include
INCLUDES+= -I../src/mcu/apollo3
INCLUDES+= -I../src/third_party/exactle/sw/hci/ambiq/apollo3
INCLUDES+= -I../src/third_party/exactle/sw/profiles/uribeacon
INCLUDES+= -I../src/third_party/exactle/sw/stack/include
INCLUDES+= -I../src/third_party/exactle/ws-core/sw/util
INCLUDES+= -I../src
INCLUDES+= -I../src/third_party/exactle/sw/sec/common
INCLUDES+= -I../src/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo2
INCLUDES+= -I../src/CMSIS/ARM/Include
INCLUDES+= -I../src/third_party/exactle/apollo-host/projects/common
INCLUDES+= -I../src/third_party/exactle/ws-core/sw/wsf/include
INCLUDES+= -I../src/third_party/exactle/ws-core/sw/wsf/ambiq
#start of tensorflow
INCLUDES+= -I../src/tensorflow/lite/micro/examples/micro_speech
INCLUDES+= -I../src/micro_speech
INCLUDES+= -I../src/tensorflow/lite/experimental/microfrontend/lib
INCLUDES+= -I../src/tensorflow/lite/micro/examples/micro_speech/kissfft/tools
INCLUDES+= -I../src/tensorflow/lite/micro/examples/micro_speech/kissfft
INCLUDES+= -I../src/tensorflow/lite/micro/examples/micro_speech/gemmlowp/public
INCLUDES+= -I../src/tensorflow/lite/micro/examples/micro_speech/gemmlowp/fixedpoint
INCLUDES+= -I../src/tensorflow/lite/micro
INCLUDES+= -I../src/tensorflow/lite/micro/kernels
INCLUDES+= -I../src/tensorflow/lite/micro/kernels/internal
INCLUDES+= -I../src/tensorflow/lite/micro/memory_planner

VPATH = ../src/third_party/exactle/sw/services
VPATH+=:../src
VPATH+=:../src/micro_speech
VPATH+=:../src/third_party/FreeRTOSv10.1.1/Source
VPATH+=:../src/third_party/exactle/sw/apps/fit
VPATH+=:../src/third_party/exactle/sw/profiles/bas
VPATH+=:../src/third_party/exactle/sw/hci/ambiq
VPATH+=:../src/utils
VPATH+=:../src/third_party/exactle/sw/apps/app
VPATH+=:../src/third_party/exactle/sw/stack/hci
VPATH+=:../src/third_party/uecc/micro-ecc
VPATH+=:../src/third_party/exactle/sw/profiles/hid
VPATH+=:../src/third_party/exactle/ws-core/sw/wsf/common
VPATH+=:../src/third_party/exactle/sw/stack/cfg
VPATH+=:../src/third_party/exactle/sw/hci/ambiq/apollo3
VPATH+=:../src/third_party/exactle/sw/profiles/rscp
VPATH+=:../src/third_party/exactle/ws-core/sw/util
VPATH+=:../src/third_party/exactle/sw/sec/common
VPATH+=:../src/third_party/exactle/sw/profiles/hrps
VPATH+=:../src/third_party/exactle/sw/apps/hidapp
VPATH+=:../src/devices
VPATH+=:../src/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo2
VPATH+=:../src/third_party/FreeRTOSv10.1.1/Source/portable/MemMang
VPATH+=:../src/third_party/exactle/sw/apps/app/generic
VPATH+=:../src/third_party/exactle/ws-core/sw/wsf/ambiq
#start of tensor libraries
VPATH+=:../src/tensorflow/lite/micro/examples/micro_speech
VPATH+=:../src/tensorflow/lite/micro/examples/micro_speech/micro_features
VPATH+=:../src/tensorflow/lite/micro/examples/micro_speech/sparkfun_edge
VPATH+=:../src/tensorflow/lite/c
VPATH+=:../src/tensorflow/lite/core/api
VPATH+=:../src/tensorflow/lite/kernels
VPATH+=:../src/tensorflow/lite/kernels/internal
VPATH+=:../src/tensorflow/lite/micro
VPATH+=:../src/tensorflow/lite/micro/memory_planner
VPATH+=:../src/tensorflow/lite/apollo3evb
VPATH+=:../src/tensorflow/lite/experimental/microfrontend/lib
VPATH+=:../src/tensorflow/lite/micro/examples/micro_speech/kissfft
VPATH+=:../src/tensorflow/lite/micro/examples/micro_speech/kissfft/tools

SRC = ble_freertos_fit_lp.c
SRC += radio_task.c
SRC += rtos.c
SRC += fit_main.c
SRC += bas_main.c
SRC += hci_cmd.c
SRC += hci_core.c
SRC += hci_core_ps.c
SRC += hci_evt.c
SRC += hci_tr.c
SRC += hci_vs.c
SRC += hci_main.c
SRC += hid_main.c
SRC += wsf_buf.c
SRC += wsf_efs.c
SRC += wsf_msg.c
SRC += wsf_queue.c
SRC += wsf_timer.c
SRC += cfg_stack.c
SRC += hci_drv_apollo3.c
SRC += rscps_main.c
SRC += bda.c
SRC += bstream.c
SRC += calc128.c
SRC += crc32.c
SRC += print.c
SRC += terminal.c
SRC += wstr.c
SRC += sec_aes.c 
SRC += sec_cmac.c # 
SRC += sec_ecc_hci.c 
SRC += sec_main.c# 
SRC += hrps_main.c
SRC += hidapp_main.c# 
SRC += port.c
SRC += app_db.c
SRC += app_hw.c
SRC += app_ui.c
SRC += wsf_assert.c
SRC += wsf_math.c
SRC += wsf_os.c
SRC += wsf_trace.c 
SRC += svc_batt.c
SRC += svc_bps.c # 
SRC += svc_core.c
SRC += svc_cps.c# 
SRC += svc_cscs.c# 
SRC += svc_dis.c
SRC += svc_gls.c# 
SRC += svc_gyro.c# 
SRC += svc_hid.c
SRC += svc_hrs.c
SRC += svc_hts.c# 
SRC += svc_ipss.c# 
SRC += svc_plxs.c# 
SRC += svc_px.c# 
SRC += svc_rscs.c# 
SRC += svc_scpss.c# 
SRC += svc_temp.c# 
SRC += svc_uricfg.c# 
SRC += svc_wdxs.c# 
SRC += svc_wp.c# 
SRC += svc_wss.c# 
SRC += heap_2.c
SRC += event_groups.c
SRC += list.c
SRC += queue.c
SRC += tasks.c
SRC += timers.c
SRC += am_util_ble.c
SRC += am_util_debug.c# 
SRC += am_util_delay.c# 
SRC += am_util_faultisr.c# 
SRC += am_util_id.c# 
SRC += am_util_stdio.c# 
SRC += am_devices_button.c# doesn't have
SRC += am_devices_led.c# doesn't have
SRC += app_disc.c# doesn't have
SRC += app_main.c
SRC += app_master.c# doesn't have
SRC += app_master_leg.c# doesn't have
SRC += app_server.c
SRC += app_slave.c
SRC += app_slave_leg.c# 
SRC += app_terminal.c
SRC += startup_gcc.c
#IMPORTS FROM TENSORFLOW
SRC += tense.cc
SRC += main_functions.cc
SRC += audio_provider.cc
SRC += feature_provider.cc
SRC += no_micro_features_data.cc
SRC += yes_micro_features_data.cc
SRC += tiny_conv_micro_features_model_data.cc
SRC += recognize_commands.cc
#from micro folder
SRC += micro_interpreter.cc
SRC += micro_allocator.cc
SRC += memory_helpers.cc
SRC += simple_memory_allocator.cc
#from apollo3evb
SRC += command_responder.cc
#from micro_features folder
SRC += micro_features_generator.cc
SRC += micro_model_settings.cc
# from frontend folder
SRC += frontend.c
SRC += frontend_util.c
SRC += log_lut.c
SRC += log_scale.c
SRC += log_scale_util.c
SRC += fft.c
SRC += fft_util.cc
SRC += filterbank.c
SRC += filterbank_util.c
SRC += noise_reduction.c
SRC += noise_reduction_util.c
SRC += pcan_gain_control.c
SRC += pcan_gain_control_util.c
SRC += window.c
SRC += window_util.c
#from kissfft folder
SRC += kiss_fft.c
SRC += kiss_fftr.c
#from core api
SRC += tensor_utils.cc
SRC += op_resolver.cc
SRC += error_reporter.cc
SRC += flatbuffer_conversions.cc
# from memory_planner
SRC += greedy_memory_planner.cc
#from kernels
SRC += quantization_util.cc
SRC += kernel_util.cc
SRC += depthwise_conv.cc

#from c
SRC += common.cc


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


LIBS = ../src/third_party/exactle/projects/generic/stacklib/gcc/bin-cortex-m4/libstacklib.a
LIBS += ../src/mcu/apollo3/hal/gcc/bin/libam_hal.a
LIBS += ../../../bsp/gcc/bin/libam_bsp.a
LIBS += ../src/third_party/uecc/gcc/bin/lib_uecc.a

CFLAGS = -mthumb -mcpu=$(CPU) -mfpu=$(FPU) -mfloat-abi=$(FABI)
CFLAGS+= -ffunction-sections -fdata-sections
CFLAGS+= -MMD -MP -std=c99 -Wall -g
CFLAGS+= -O0
CFLAGS+= $(DEFINES)
CFLAGS+= $(INCLUDES)
CFLAGS+= 

XSTD   = -std=gnu++11

XFLAGS = $(CFLAGS)
XFLAGS+= -fno-exceptions

LFLAGS = --specs=nosys.specs -mthumb -mcpu=$(CPU) -mfpu=$(FPU) -mfloat-abi=$(FABI)
LFLAGS+= -nostartfiles -static 
LFLAGS+= -Wl,--gc-sections,--entry,Reset_Handler,-Map,$(CONFIG)/$(TARGET).map
LFLAGS+= -Wl,--start-group -lm -lc -lstdc++ -lgcc $(LIBS) -Wl,--end-group
LFLAGS+= 

# Additional user specified CFLAGS
CFLAGS+=$(EXTRA_CFLAGS)

CPFLAGS = -Obinary

ODFLAGS = -S

#### Rules ####
all: directories $(CONFIG)/$(TARGET).bin

directories: $(CONFIG)

$(CONFIG):
	@mkdir -p $@

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

$(CONFIG)/$(TARGET).axf: $(OBJS) $(LIBS)
	@echo " Linking $(COMPILERNAME) $@" ;\
	$(CC) -Wl,-T,$(LINKER_FILE) -o $@ $(OBJS) $(LFLAGS)

$(CONFIG)/$(TARGET).bin: $(CONFIG)/$(TARGET).axf
	@echo " Copying $(COMPILERNAME) $@..." ;\
	$(CP) $(CPFLAGS) $< $@ ;\
	$(OD) $(ODFLAGS) $< > $(CONFIG)/$(TARGET).lst

clean:
	@echo "Cleaning..." ;\
	$(RM) -f $(OBJS) $(DEPS) \
	    $(CONFIG)/$(TARGET).bin $(CONFIG)/$(TARGET).axf \
	    $(CONFIG)/$(TARGET).lst $(CONFIG)/$(TARGET).map

$(CONFIG)/%.d: ;

../src/mcu/apollo3/hal/gcc/bin/libam_hal.a:
	$(MAKE) -C ../src/mcu/apollo3/hal

../../../bsp/gcc/bin/libam_bsp.a:
	$(MAKE) -C ../../../bsp

../src/third_party/uecc/gcc/bin/lib_uecc.a:
	$(MAKE) -C ../src/third_party/uecc

wired_update: all
	../src/tools/apollo3_scripts/create_cust_image_blob.py --bin $(CONFIG)/$(TARGET).bin --load-address 0xC000 --magic-num 0xCB -o $(CONFIG)/main_nonsecure_ota --version 0x0
	../src/tools/apollo3_scripts/create_cust_wireupdate_blob.py --load-address 0x20000 --bin $(CONFIG)/main_nonsecure_ota.bin -i 6 -o $(CONFIG)/main_nonsecure_wire --options 0x1

bootload: wired_update
	../../../bsp/tools/uart_wired_update_sparkfun.py -b 921600 $(SERIAL_PORT) -r 1 -f $(CONFIG)/main_nonsecure_wire.bin -i 6

boot_artemis: wired_update
# Automatically include any generated dependencies
-include $(DEPS)
endif
.PHONY: all clean directories
