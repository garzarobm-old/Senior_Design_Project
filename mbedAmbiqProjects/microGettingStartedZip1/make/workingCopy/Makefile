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
 		
