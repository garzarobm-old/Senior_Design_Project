#checks the os system

ifneq (3.82,$(firstword $(sort $(MAKE_VERSION) 3.82)))
  $(error "Requires make version 3.82 or later (current is $(MAKE_VERSION))")
endif

MAKEFILE_DIR := tensorflow/lite/micro/tools/make

# Pull in some convenience functions.
#include $(MAKEFILE_DIR)/helper_functions.inc

# Try to figure out the host system
HOST_OS :=
ifeq ($(OS),Windows_NT)
	HOST_OS = windows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		HOST_OS := linux
	endif
	ifeq ($(UNAME_S),Darwin)
		HOST_OS := osx
	endif
endif




# Determine the host architecture, with any ix86 architecture being labelled x86_32
HOST_ARCH := $(shell if uname -m | grep -Eq 'i[345678]86'; then echo x86_32; else echo $(shell uname -m); fi)

# Override these on the make command line to target a specific architecture. For example:
# make -f tensorflow/lite/Makefile TARGET=rpi TARGET_ARCH=armv7l
TARGET := $(HOST_OS)
TARGET_ARCH := $(HOST_ARCH)

### done with os check ##

####getting compiler info ###


# Default compiler and tool names:
CXX_TOOL := g++
CC_TOOL := gcc
AR_TOOL := ar


#####end of compiler info#####

# Specify TAGS on the command line to add a particular set of specialized
# implementations, for example TAGS="CMSIS disco_f746ng" to target a Discovery
# STM32F746NG board, using the CMSIS library's implementations where possible.
ALL_TAGS := $(TAGS) $(TARGET)



RM =$(shell which rm 2>/dev/null)

TOOLCHAIN ?= arm-none-eabi


SRCS = tensorflow/lite/experimental/micro/micro_error_reporter.cc 
SRCS += tensorflow/lite/experimental/micro/micro_mutable_op_resolver.cc 
SRCS += tensorflow/lite/experimental/micro/simple_tensor_allocator.cc 
SRCS += tensorflow/lite/experimental/micro/debug_log.cc
SRCS += tensorflow/lite/experimental/micro/debug_log_numbers.cc
SRCS += tensorflow/lite/experimental/micro/micro_interpreter.cc
SRCS += tensorflow/lite/experimental/micro/kernels/depthwise_conv.cc 
SRCS += tensorflow/lite/experimental/micro/kernels/softmax.cc 
SRCS += tensorflow/lite/experimental/micro/kernels/all_ops_resolver.cc 
SRCS += tensorflow/lite/experimental/micro/kernels/fully_connected.cc 


SRCS += tensorflow/lite/c/c_api_internal.c 

SRCS += tensorflow/lite/core/api/error_reporter.cc 
SRCS += tensorflow/lite/core/api/flatbuffer_conversions.cc 
SRCS += tensorflow/lite/core/api/op_resolver.cc 


SRCS += tensorflow/lite/kernels/kernel_util.cc 
SRCS += tensorflow/lite/kernels/internal/quantization_util.cc

SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/main.cc 
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/model_settings.cc 
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/audio_provider.cc
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/feature_provider.cc
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/preprocessor.cc
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/no_features_data.cc
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/yes_features_data.cc
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/tiny_conv_model_data.cc
SRCS += tensorflow/lite/experimental/micro/examples/micro_speech/recognize_commands.cc



# inlude h files
INCLUDES := \
-I. \
-I./third_party/gemmlowp \
-I./third_party/flatbuffers/include

MICROLITE_LIBS := -lm


#Start of compiler info

# TODO(b/150240249): Add in -fno-rtti once that works for the Xtensa toolchain.
CXXFLAGS := -std=c++11 -DTF_LITE_STATIC_MEMORY
CCFLAGS  := -std=c11   -DTF_LITE_STATIC_MEMORY
ARFLAGS := -r
TARGET_TOOLCHAIN_PREFIX :=
CC_PREFIX :=

ifeq ($(BUILD_TYPE), debug)
	CXXFLAGS += -DDEBUG -g
	CCFLAGS  += -DDEBUG -g
else ifeq ($(BUILD_TYPE), release)
	CXXFLAGS += -DNDEBUG -O3 -DTF_LITE_STRIP_ERROR_STRINGS
	CCFLAGS  += -DNDEBUG -O3 -DTF_LITE_STRIP_ERROR_STRINGS
else
	CXXFLAGS += -O3
	CCFLAGS  += -O3
endif

OBJS := \
$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(SRCS)))

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
	@echo "Cleaning... "; \
	$(RM) -f $(OBJS) micro_speech \
 		
