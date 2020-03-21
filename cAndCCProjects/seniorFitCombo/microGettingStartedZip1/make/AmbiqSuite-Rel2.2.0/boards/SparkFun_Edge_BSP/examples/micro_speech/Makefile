# makefile for combining tensorflow and ambiq
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

#LINKER_FILE := ./ble_freertos_fit_lp.ld
#STARTUP_FILE := ./startup_$(COMPILERNAME).c

#### Required Executables ####
#CC = $(TOOLCHAIN)-gcc
GCC = $(TOOLCHAIN)-gcc
CPP = $(TOOLCHAIN)-cpp
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


SRCS := \
tensorflow/lite/experimental/micro/micro_error_reporter.cc tensorflow/lite/experimental/micro/micro_mutable_op_resolver.cc tensorflow/lite/experimental/micro/simple_tensor_allocator.cc tensorflow/lite/experimental/micro/debug_log.cc tensorflow/lite/experimental/micro/debug_log_numbers.cc tensorflow/lite/experimental/micro/micro_interpreter.cc tensorflow/lite/experimental/micro/kernels/depthwise_conv.cc tensorflow/lite/experimental/micro/kernels/softmax.cc tensorflow/lite/experimental/micro/kernels/all_ops_resolver.cc tensorflow/lite/experimental/micro/kernels/fully_connected.cc tensorflow/lite/c/c_api_internal.c tensorflow/lite/core/api/error_reporter.cc tensorflow/lite/core/api/flatbuffer_conversions.cc tensorflow/lite/core/api/op_resolver.cc tensorflow/lite/kernels/kernel_util.cc tensorflow/lite/kernels/internal/quantization_util.cc  tensorflow/lite/experimental/micro/examples/micro_speech/main.cc tensorflow/lite/experimental/micro/examples/micro_speech/model_settings.cc tensorflow/lite/experimental/micro/examples/micro_speech/audio_provider.cc tensorflow/lite/experimental/micro/examples/micro_speech/feature_provider.cc tensorflow/lite/experimental/micro/examples/micro_speech/preprocessor.cc tensorflow/lite/experimental/micro/examples/micro_speech/no_features_data.cc tensorflow/lite/experimental/micro/examples/micro_speech/yes_features_data.cc tensorflow/lite/experimental/micro/examples/micro_speech/tiny_conv_model_data.cc tensorflow/lite/experimental/micro/examples/micro_speech/recognize_commands.cc

OBJS := \
$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(SRCS)))

INCLUDES := \
-I. \
-I./third_party/gemmlowp \
-I./third_party/flatbuffers/include

CXXFLAGS += -O3 -DNDEBUG --std=c++11 -g -DTF_LITE_STATIC_MEMORY

LDFLAGS += -lm

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

micro_speech : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) \
	-o $@

all: micro_speech

clean: 
	@echo "Cleaning..." ;\
	$(RM) -f $(OBJS) 
endif
.PHONY: all clean directories
