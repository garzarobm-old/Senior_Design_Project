
INCLUDES += \
 -I$(MAKEFILE_DIR)/downloads/kissfft 

GENERATED_PROJECT_INCLUDES += \
-I./third_party/kissfft 


PROJECT_INCLUDES +=		\
third_party/kissfft		 


KISSFFT_LIB_SRCS := \
$(MAKEFILE_DIR)/downloads/kissfft/kiss_fft.c \
$(MAKEFILE_DIR)/downloads/kissfft/tools/kiss_fftr.c 


KISSFFT_LIB_HDRS := \
$(MAKEFILE_DIR)/downloads/kissfft/COPYING \
$(MAKEFILE_DIR)/downloads/kissfft/kiss_fft.h \
$(MAKEFILE_DIR)/downloads/kissfft/_kiss_fft_guts.h \
$(MAKEFILE_DIR)/downloads/kissfft/tools/kiss_fftr.h


$(eval $(call add_third_party_download,$(KISSFFT_URL),$(KISSFFT_MD5),kissfft,patch_kissfft))

THIRD_PARTY_CC_HDRS += \
third_party/kissfft/COPYING \
third_party/kissfft/kiss_fft.h \
third_party/kissfft/_kiss_fft_guts.h \
third_party/kissfft/tools/kiss_fftr.h

MICRO_FEATURES_LIB_SRCS := \
tensorflow/lite/experimental/microfrontend/lib/fft.cc \
tensorflow/lite/experimental/microfrontend/lib/fft_util.cc \
tensorflow/lite/experimental/microfrontend/lib/filterbank.c \
tensorflow/lite/experimental/microfrontend/lib/filterbank_util.c \
tensorflow/lite/experimental/microfrontend/lib/frontend.c \
tensorflow/lite/experimental/microfrontend/lib/frontend_util.c \
tensorflow/lite/experimental/microfrontend/lib/log_lut.c \
tensorflow/lite/experimental/microfrontend/lib/log_scale.c \
tensorflow/lite/experimental/microfrontend/lib/log_scale_util.c \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction.c \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.c \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.c \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.c \
tensorflow/lite/experimental/microfrontend/lib/window.c \
tensorflow/lite/experimental/microfrontend/lib/window_util.c \
$(KISSFFT_LIB_SRCS)

MICRO_FEATURES_LIB_HDRS := \
tensorflow/lite/experimental/microfrontend/lib/bits.h \
tensorflow/lite/experimental/microfrontend/lib/fft.h \
tensorflow/lite/experimental/microfrontend/lib/fft_util.h \
tensorflow/lite/experimental/microfrontend/lib/filterbank.h \
tensorflow/lite/experimental/microfrontend/lib/filterbank_util.h \
tensorflow/lite/experimental/microfrontend/lib/frontend.h \
tensorflow/lite/experimental/microfrontend/lib/frontend_util.h \
tensorflow/lite/experimental/microfrontend/lib/log_lut.h \
tensorflow/lite/experimental/microfrontend/lib/log_scale.h \
tensorflow/lite/experimental/microfrontend/lib/log_scale_util.h \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction.h \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.h \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.h \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.h \
tensorflow/lite/experimental/microfrontend/lib/window.h \
tensorflow/lite/experimental/microfrontend/lib/window_util.h \
$(KISSFFT_LIB_HDRS)

MICRO_FEATURES_GENERATOR_SRCS := \
tensorflow/lite/micro/examples/micro_speech/micro_features/micro_features_generator.cc \
tensorflow/lite/micro/examples/micro_speech/micro_features/micro_model_settings.cc \
$(MICRO_FEATURES_LIB_SRCS)

MICRO_FEATURES_GENERATOR_HDRS := \
tensorflow/lite/micro/examples/micro_speech/micro_features/micro_features_generator.h \
tensorflow/lite/micro/examples/micro_speech/micro_features/micro_model_settings.h \
$(MICRO_FEATURES_LIB_HDRS)



MICRO_SPEECH_SRCS := \
tensorflow/lite/micro/examples/micro_speech/main.cc \
tensorflow/lite/micro/examples/micro_speech/main_functions.cc \
tensorflow/lite/micro/examples/micro_speech/audio_provider.cc \
tensorflow/lite/micro/examples/micro_speech/feature_provider.cc \
tensorflow/lite/micro/examples/micro_speech/micro_features/no_micro_features_data.cc \
tensorflow/lite/micro/examples/micro_speech/micro_features/yes_micro_features_data.cc \
tensorflow/lite/micro/examples/micro_speech/micro_features/tiny_conv_micro_features_model_data.cc \
tensorflow/lite/micro/examples/micro_speech/recognize_commands.cc \
tensorflow/lite/micro/examples/micro_speech/command_responder.cc \
$(MICRO_FEATURES_GENERATOR_SRCS)


MICRO_SPEECH_HDRS := \
tensorflow/lite/micro/examples/micro_speech/audio_provider.h \
tensorflow/lite/micro/examples/micro_speech/feature_provider.h \
tensorflow/lite/micro/examples/micro_speech/micro_features/no_micro_features_data.h \
tensorflow/lite/micro/examples/micro_speech/micro_features/yes_micro_features_data.h \
tensorflow/lite/micro/examples/micro_speech/micro_features/tiny_conv_micro_features_model_data.h \
tensorflow/lite/micro/examples/micro_speech/recognize_commands.h \
tensorflow/lite/micro/examples/micro_speech/command_responder.h \
tensorflow/lite/micro/examples/micro_speech/main_functions.h \
$(MICRO_FEATURES_GENERATOR_HDRS)



#Find any platform - specific rules for this example.
include $(wildcard tensorflow/lite/micro/examples/micro_speech/*/Makefile.inc)

