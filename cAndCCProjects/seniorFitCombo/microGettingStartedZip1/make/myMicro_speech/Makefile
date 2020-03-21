#START OF MY CODE 










#### Required Executables ####
CC = $(TOOLCHAIN)-gcc
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





# END OF MY CODE

#START OF TENSORFLOW CODE
SRCS := \
src/micro_error_reporter.cc src/micro_mutable_op_resolver.cc src/simple_tensor_allocator.cc src/debug_log.cc src/debug_log_numbers.cc src/micro_interpreter.cc src/kernels/depthwise_conv.cc src/kernels/softmax.cc src/kernels/all_ops_resolver.cc src/kernels/fully_connected.cc tensorflow/lite/c/c_api_internal.c src/core/error_reporter.cc src/core/flatbuffer_conversions.cc src/core/op_resolver.cc src/kernels/kernel_util.cc src/kernels/internal/quantization_util.cc  src/main.cc src/model_settings.cc src/audio_provider.cc src/feature_provider.cc src/preprocessor.cc src/no_features_data.cc src/yes_features_data.cc src/tiny_conv_model_data.cc src/recognize_commands.cc





#MYBUILDFOLDERS
CBUILD = $(filter %.c,$(SRCS))
CPPBUILD = $(filter %.s,$(SRCS))
 



OBJS := \ 
$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(SRCS)))

INCLUDES := \
-I. \
-I.third_party/gemmlowp \
-I.third_party/flatBuffers/include

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
