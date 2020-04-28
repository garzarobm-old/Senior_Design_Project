ifneq (3.82,$(firstword $(sort $(MAKE_VERSION) 3.82)))
  $(error "Requires make version 3.82 or later (current is $(MAKE_VERSION))")
endif

MAKEFILE_DIR := tensorflow/lite/micro/tools/make

# Pull in some convenience functions.
include $(MAKEFILE_DIR)/helper_functions.inc

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

# Default compiler and tool names:
CXX_TOOL := g++
CC_TOOL := gcc
AR_TOOL := ar

DEFINES = -DPART_APOLLO3
DEFINES += -DAM_PACKAGE_BGA
DEFINES += -DAM_PART_APOLLO3
DEFINES += -DAM_FREERTOS
# Specify TAGS on the command line to add a particular set of specialized
# implementations, for example TAGS="CMSIS disco_f746ng" to target a Discovery
# STM32F746NG board, using the CMSIS library's implementations where possible.
ALL_TAGS := $(TAGS) $(TARGET)

# This is obviously horrible.  We need to generate these 3 versions of the
# include directories from one source.
INCLUDES := \
-I. \
-I$(MAKEFILE_DIR)/downloads/ \
-I$(MAKEFILE_DIR)/downloads/gemmlowp \
-I$(MAKEFILE_DIR)/downloads/flatbuffers/include

# Same list of paths, but now relative to the generated project files.
GENERATED_PROJECT_INCLUDES := \
-I. \
-I./third_party/gemmlowp \
-I./third_party/flatbuffers/include

# Same list of paths, but now in the format the generate_keil_project.py
# script expects them.
PROJECT_INCLUDES := \
. \
third_party/gemmlowp \
third_party/flatbuffers/include

TEST_SCRIPT := tensorflow/lite/micro/testing/test_linux_binary.sh
# MIGUEL ADDED A LIB
LIBS = ${BLE_BLE_SOURCES}/lib/libstacklib.a
# END OF MIGUEL ADDED A LIB
MICROLITE_LIBS := -lm 

# TODO(b/150240249): Add in -fno-rtti once that works for the Xtensa toolchain.
CXXFLAGS := -std=c++11 -DTF_LITE_STATIC_MEMORY
CCFLAGS  := -std=c11   -DTF_LITE_STATIC_MEMORY $(DEFINES)
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

# This library is the main target for this makefile. It will contain a minimal
# runtime that can be linked in to other programs.
MICROLITE_LIB_NAME := libtensorflow-microlite.a

MICRO_LITE_EXAMPLE_TESTS := $(wildcard tensorflow/lite/micro/examples/*/Makefile.inc)



######miguel starting putting inputs after kernel_util.cc################

BLE_SOURCES = seniorFitSrc

MICROLITE_CC_BASE_SRCS := \
$(wildcard tensorflow/lite/micro/*.cc) \
$(wildcard tensorflow/lite/micro/kernels/*.cc) \
$(wildcard tensorflow/lite/micro/memory_planner/*.cc) \
tensorflow/lite/c/common.c \
tensorflow/lite/core/api/error_reporter.cc \
tensorflow/lite/core/api/flatbuffer_conversions.cc \
tensorflow/lite/core/api/op_resolver.cc \
tensorflow/lite/core/api/tensor_utils.cc \
tensorflow/lite/kernels/internal/quantization_util.cc \
tensorflow/lite/kernels/kernel_util.cc \
${BLE_BLE_SOURCES}/main/ble_freertos_fit_lp.c \
${BLE_BLE_SOURCES}/main/radio_task.c \
${BLE_BLE_SOURCES}/main/rtos.c \
${BLE_BLE_SOURCES}/exactle/bas_main.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_cmd.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_core.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_core_ps.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_evt.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_tr.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_vs.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_main.c \
${BLE_BLE_SOURCES}/exactle/hid_main.c \
${BLE_BLE_SOURCES}/exactle/wsf_buf.c \
${BLE_BLE_SOURCES}/exactle/wsf_efs.c \
${BLE_BLE_SOURCES}/exactle/wsf_msg.c \
${BLE_BLE_SOURCES}/exactle/wsf_queue.c \
${BLE_BLE_SOURCES}/exactle/wsf_timer.c \
${BLE_BLE_SOURCES}/exactle/cfg_stack.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_drv_apollo3.c \
${BLE_BLE_SOURCES}/exactle/rscps_main.c \
${BLE_BLE_SOURCES}/exactle/bda.c \
${BLE_BLE_SOURCES}/exactle/bstream.c \
${BLE_BLE_SOURCES}/exactle/crc32.c \
${BLE_BLE_SOURCES}/exactle/calc128.c \
${BLE_BLE_SOURCES}/exactle/print.c \
${BLE_BLE_SOURCES}/exactle/terminal.c \
${BLE_BLE_SOURCES}/exactle/wstr.c \
${BLE_BLE_SOURCES}/exactle/wsf_assert.c \
${BLE_BLE_SOURCES}/exactle/wsf_math.c \
${BLE_BLE_SOURCES}/exactle/wsf_trace.c \
${BLE_BLE_SOURCES}/exactle/wsf_os.c \
${BLE_BLE_SOURCES}/exactle/sec_ecc_hci.c \
${BLE_BLE_SOURCES}/exactle/sec_main.c \
${BLE_BLE_SOURCES}/exactle/sec_aes.c \
${BLE_BLE_SOURCES}/exactle/sec_cmac.c \
${BLE_BLE_SOURCES}/exactle/app_db.c \
${BLE_BLE_SOURCES}/exactle/hrps_main.c \
${BLE_BLE_SOURCES}/exactle/app_main.c \
${BLE_BLE_SOURCES}/exactle/fit_main.c \
${BLE_BLE_SOURCES}/exactle/app_slave.c \
${BLE_BLE_SOURCES}/exactle/app_ui.c \
${BLE_BLE_SOURCES}/exactle/svc_core.c \
${BLE_BLE_SOURCES}/exactle/svc_hrs.c \
${BLE_BLE_SOURCES}/exactle/svc_hid.c \
${BLE_BLE_SOURCES}/exactle/svc_batt.c \
${BLE_BLE_SOURCES}/exactle/svc_dis.c \
${BLE_BLE_SOURCES}/exactle/svc_rscs.c \
${BLE_BLE_SOURCES}/exactle/app_server.c \
${BLE_BLE_SOURCES}/exactle/bas_main.c \
${BLE_BLE_SOURCES}/exactle/app_hw.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_drv_apollo3.c \
${BLE_BLE_SOURCES}/exactle/rscps_main.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_cmd.c \
${BLE_BLE_SOURCES}/exactle/hci/hci_main.c \
${BLE_BLE_SOURCES}/RTOSEdits/tasks.c \
${BLE_BLE_SOURCES}/RTOSEdits/mpu_wrappers.c \
${BLE_BLE_SOURCES}/RTOSEdits/event_groups.c \
${BLE_BLE_SOURCES}/RTOSEdits/list.c \
${BLE_BLE_SOURCES}/RTOSEdits/queue.c \
${BLE_BLE_SOURCES}/RTOSEdits/timers.c \
${BLE_BLE_SOURCES}/utils/am_util_ble.c \
${BLE_BLE_SOURCES}/utils/am_util_debug.c \
${BLE_BLE_SOURCES}/utils/am_util_delay.c \
${BLE_BLE_SOURCES}/utils/am_util_faultisr.c \
${BLE_BLE_SOURCES}/utils/am_util_stdio.c \
${BLE_BLE_SOURCES}/exactle/app_slave_leg.c \
${BLE_BLE_SOURCES}/RTOSEdits/stream_buffer.c \
${BLE_BLE_SOURCES}/RTOSEdits/croutine.c \
${BLE_BLE_SOURCES}/RTOSEdits/port.c \
${BLE_BLE_SOURCES}/RTOSEdits/heap_2.c \
${BLE_BLE_SOURCES}/mcu/hal/am_hal_cachectrl.c \
${BLE_BLE_SOURCES}/mcu/hal/am_hal_sysctrl.c \
${BLE_BLE_SOURCES}/exactle/att_uuid.c \
${BLE_BLE_SOURCES}/exactle/uECC.c \
${BLE_BLE_SOURCES}/startup_gcc.c

#NOTE TO SELF: from the compiled part, part we got done when Filipe helped out, starting from sec_ecc_hci.c to all the way to the bottom of c file includes

#making own objects
MY_OBJECTS := \
${BLE_BLE_SOURCES}/objs/attc_disc.o \
${BLE_BLE_SOURCES}/objs/attc_main.o \
${BLE_BLE_SOURCES}/objs/attc_proc.o \
${BLE_BLE_SOURCES}/objs/attc_read.o \
${BLE_BLE_SOURCES}/objs/attc_sign.o \
${BLE_BLE_SOURCES}/objs/attc_write.o \
${BLE_BLE_SOURCES}/objs/attc_main.o \
${BLE_BLE_SOURCES}/objs/att_main.o \
${BLE_BLE_SOURCES}/objs/atts_ccc.o \
${BLE_BLE_SOURCES}/objs/atts_dyn.o \
${BLE_BLE_SOURCES}/objs/atts_ind.o \
${BLE_BLE_SOURCES}/objs/atts_main.o \
${BLE_BLE_SOURCES}/objs/atts_proc.o \
${BLE_BLE_SOURCES}/objs/atts_read.o \
${BLE_BLE_SOURCES}/objs/atts_sign.o \
${BLE_BLE_SOURCES}/objs/atts_write.o \
${BLE_BLE_SOURCES}/objs/dm_adv_leg.o \
${BLE_BLE_SOURCES}/objs/dm_adv.o \
${BLE_BLE_SOURCES}/objs/dm_adv_priv.o \
${BLE_BLE_SOURCES}/objs/dm_conn_master_leg.o \
${BLE_BLE_SOURCES}/objs/dm_conn_master.o \
${BLE_BLE_SOURCES}/objs/dm_conn.o \
${BLE_BLE_SOURCES}/objs/dm_conn_slave_leg.o \
${BLE_BLE_SOURCES}/objs/dm_conn_slave.o \
${BLE_BLE_SOURCES}/objs/dm_conn_sm.o \
${BLE_BLE_SOURCES}/objs/dm_dev.o \
${BLE_BLE_SOURCES}/objs/dm_main.o \
${BLE_BLE_SOURCES}/objs/dm_priv.o \
${BLE_BLE_SOURCES}/objs/dm_scan_leg.o \
${BLE_BLE_SOURCES}/objs/dm_scan.o \
${BLE_BLE_SOURCES}/objs/dm_sec_lesc.o \
${BLE_BLE_SOURCES}/objs/dm_sec_master.o \
${BLE_BLE_SOURCES}/objs/dm_sec.o \
${BLE_BLE_SOURCES}/objs/dm_sec_slave.o \
${BLE_BLE_SOURCES}/objs/l2c_coc.o \
${BLE_BLE_SOURCES}/objs/l2c_main.o \
${BLE_BLE_SOURCES}/objs/l2c_master.o \
${BLE_BLE_SOURCES}/objs/l2c_slave.o \
${BLE_BLE_SOURCES}/objs/smp_act.o \
${BLE_BLE_SOURCES}/objs/smp_main.o \
${BLE_BLE_SOURCES}/objs/smp_non.o \
${BLE_BLE_SOURCES}/objs/smp_sc_act.o \
${BLE_BLE_SOURCES}/objs/smp_sc_main.o \
${BLE_BLE_SOURCES}/objs/smpi_act.o \
${BLE_BLE_SOURCES}/objs/smpi_sc_act.o \
${BLE_BLE_SOURCES}/objs/smpi_sc_sm.o \
${BLE_BLE_SOURCES}/objs/smpi_sm.o \
${BLE_BLE_SOURCES}/objs/smpr_act.o \
${BLE_BLE_SOURCES}/objs/smpr_sc_act.o \
${BLE_BLE_SOURCES}/objs/smpr_sc_sm.o \
${BLE_BLE_SOURCES}/objs/smpr_sm.o
# edn of making own obj
MICROLITE_CC_SRCS := $(filter-out $(MICROLITE_TEST_SRCS), $(MICROLITE_CC_BASE_SRCS))

MICROLITE_CC_HDRS := \
$(wildcard tensorflow/lite/micro/*.h) \
$(wildcard tensorflow/lite/micro/kernels/*.h) \
$(wildcard tensorflow/lite/micro/memory_planner/*.h) \
LICENSE \
tensorflow/core/public/version.h \
tensorflow/lite/c/builtin_op_data.h \
tensorflow/lite/c/common.h \
tensorflow/lite/core/api/error_reporter.h \
tensorflow/lite/core/api/flatbuffer_conversions.h \
tensorflow/lite/core/api/op_resolver.h \
tensorflow/lite/core/api/tensor_utils.h \
tensorflow/lite/experimental/ruy/profiler/instrumentation.h \
tensorflow/lite/kernels/internal/common.h \
tensorflow/lite/kernels/internal/compatibility.h \
tensorflow/lite/kernels/internal/optimized/neon_check.h \
tensorflow/lite/kernels/internal/quantization_util.h \
tensorflow/lite/kernels/internal/reference/add.h \
tensorflow/lite/kernels/internal/reference/arg_min_max.h \
tensorflow/lite/kernels/internal/reference/binary_function.h \
tensorflow/lite/kernels/internal/reference/ceil.h \
tensorflow/lite/kernels/internal/reference/comparisons.h \
tensorflow/lite/kernels/internal/reference/concatenation.h \
tensorflow/lite/kernels/internal/reference/conv.h \
tensorflow/lite/kernels/internal/reference/depthwiseconv_float.h \
tensorflow/lite/kernels/internal/reference/depthwiseconv_uint8.h \
tensorflow/lite/kernels/internal/reference/dequantize.h \
tensorflow/lite/kernels/internal/reference/floor.h \
tensorflow/lite/kernels/internal/reference/fully_connected.h \
tensorflow/lite/kernels/internal/reference/integer_ops/add.h \
tensorflow/lite/kernels/internal/reference/integer_ops/conv.h \
tensorflow/lite/kernels/internal/reference/integer_ops/depthwise_conv.h \
tensorflow/lite/kernels/internal/reference/integer_ops/fully_connected.h \
tensorflow/lite/kernels/internal/reference/integer_ops/mul.h \
tensorflow/lite/kernels/internal/reference/integer_ops/softmax.h \
tensorflow/lite/kernels/internal/reference/maximum_minimum.h \
tensorflow/lite/kernels/internal/reference/mul.h \
tensorflow/lite/kernels/internal/reference/neg.h \
tensorflow/lite/kernels/internal/reference/pad.h \
tensorflow/lite/kernels/internal/reference/pooling.h \
tensorflow/lite/kernels/internal/reference/prelu.h \
tensorflow/lite/kernels/internal/reference/process_broadcast_shapes.h \
tensorflow/lite/kernels/internal/reference/quantize.h \
tensorflow/lite/kernels/internal/reference/reduce.h \
tensorflow/lite/kernels/internal/reference/requantize.h \
tensorflow/lite/kernels/internal/reference/round.h \
tensorflow/lite/kernels/internal/reference/softmax.h \
tensorflow/lite/kernels/internal/reference/logistic.h \
tensorflow/lite/kernels/internal/reference/strided_slice.h \
tensorflow/lite/kernels/internal/reference/integer_ops/pooling.h \
tensorflow/lite/kernels/internal/round.h \
tensorflow/lite/kernels/internal/strided_slice_logic.h \
tensorflow/lite/kernels/internal/tensor.h \
tensorflow/lite/kernels/internal/tensor_ctypes.h \
tensorflow/lite/kernels/internal/types.h \
tensorflow/lite/kernels/kernel_util.h \
tensorflow/lite/kernels/op_macros.h \
tensorflow/lite/kernels/padding.h \
tensorflow/lite/schema/schema_generated.h \
tensorflow/lite/string_type.h \
tensorflow/lite/string_util.h \
tensorflow/lite/type_to_tflitetype.h \
tensorflow/lite/version.h \
${BLE_BLE_SOURCES}/main/include/ble_freertos_fit_lp.h \
${BLE_BLE_SOURCES}/main/include/FreeRTOS.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/task.h \
${BLE_BLE_SOURCES}/main/include/radio_task.h \
${BLE_BLE_SOURCES}/main/include/rtos.h \
${BLE_BLE_SOURCES}/main/include/FreeRTOSConfig.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/radio_task.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/timers.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/queue.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/projdefs.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/portable.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/portmacro.h \
${BLE_BLE_SOURCES}/RTOSEdits/include/list.h \
${BLE_BLE_SOURCES}/mcu/am_mcu_apollo.h \
${BLE_BLE_SOURCES}/bsp/am_bsp.h \
${BLE_BLE_SOURCES}/utils/am_util.h \
${BLE_BLE_SOURCES}/exactle/include/sec_api.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_math.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_trace.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_os.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_timer.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_buf.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_msg.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_efs.h \
${BLE_BLE_SOURCES}/exactle/include/wsf_queue.h \
${BLE_BLE_SOURCES}/exactle/include/fit_main.h \
${BLE_BLE_SOURCES}/exactle/include/app_db.h \
${BLE_BLE_SOURCES}/exactle/include/cfg_stack.h \
${BLE_BLE_SOURCES}/exactle/include/app_hw.h \
${BLE_BLE_SOURCES}/exactle/include/hrps_api.h \
${BLE_BLE_SOURCES}/exactle/include/svc_hrs.h \
${BLE_BLE_SOURCES}/exactle/hci/include/hci_api.h \
${BLE_BLE_SOURCES}/exactle/include/terminal.h \
${BLE_BLE_SOURCES}/exactle/include/att_uuid.h \
${BLE_BLE_SOURCES}/exactle/include/dm_api.h \
${BLE_BLE_SOURCES}/exactle/include/att_api.h \
${BLE_BLE_SOURCES}/exactle/include/att_defs.h \
${BLE_BLE_SOURCES}/cmsis/include/apollo3.h \
tensorflow/lite/micro/examples/micro_speech/seniorFitSrc/include/usingC++ClassesExample.h



###############end of miguel imports #############################

THIRD_PARTY_CC_HDRS := \
third_party/gemmlowp/fixedpoint/fixedpoint.h \
third_party/gemmlowp/fixedpoint/fixedpoint_sse.h \
third_party/gemmlowp/internal/detect_platform.h \
third_party/gemmlowp/LICENSE \
third_party/flatbuffers/include/flatbuffers/base.h \
third_party/flatbuffers/include/flatbuffers/stl_emulation.h \
third_party/flatbuffers/include/flatbuffers/flatbuffers.h \
third_party/flatbuffers/LICENSE.txt

MAKE_PROJECT_FILES := \
  README_MAKE.md \
  Makefile \
  .vscode/tasks.json



ARDUINO_PROJECT_FILES := \
  library.properties

ESP_PROJECT_FILES := \
  README_ESP.md \
  CMakeLists.txt \
  main/CMakeLists.txt \
  components/tfmicro/CMakeLists.txt

ALL_PROJECT_TARGETS :=

ARDUINO_LIBRARY_TARGETS :=
ARDUINO_LIBRARY_ZIPS :=

include $(MAKEFILE_DIR)/third_party_downloads.inc
THIRD_PARTY_DOWNLOADS :=
$(eval $(call add_third_party_download,$(GEMMLOWP_URL),$(GEMMLOWP_MD5),gemmlowp,))
$(eval $(call add_third_party_download,$(FLATBUFFERS_URL),$(FLATBUFFERS_MD5),flatbuffers,))

# These target-specific makefiles should modify or replace options like
# CXXFLAGS or LIBS to work for a specific targeted architecture. All logic
# based on platforms or architectures should happen within these files, to
# keep this main makefile focused on the sources and dependencies.
include $(wildcard $(MAKEFILE_DIR)/targets/*_makefile.inc)

# Load dependencies for optimized kernel implementations.
include $(wildcard $(MAKEFILE_DIR)/ext_libs/*.inc)

# Call specialize here so that platform-specific tags can be taken into account.
MICROLITE_CC_SRCS := $(call specialize,$(MICROLITE_CC_SRCS))

ALL_TAGS += $(TARGET_ARCH)

ALL_SRCS := \
	$(MICROLITE_CC_SRCS) \
	$(MICROLITE_TEST_SRCS)

# Where compiled objects are stored.
GENDIR := $(MAKEFILE_DIR)/gen/$(TARGET)_$(TARGET_ARCH)/
OBJDIR := $(GENDIR)obj/
BINDIR := $(GENDIR)bin/
LIBDIR := $(GENDIR)lib/
PRJDIR := $(GENDIR)prj/

MICROLITE_LIB_PATH := $(LIBDIR)$(MICROLITE_LIB_NAME)

CXX := $(CC_PREFIX)${TARGET_TOOLCHAIN_PREFIX}${CXX_TOOL}
CC := $(CC_PREFIX)${TARGET_TOOLCHAIN_PREFIX}${CC_TOOL}
AR := $(CC_PREFIX)${TARGET_TOOLCHAIN_PREFIX}${AR_TOOL}

# Load the examples.
include $(MICRO_LITE_EXAMPLE_TESTS)

# Create rules for downloading third-party dependencies.
THIRD_PARTY_TARGETS :=
$(foreach DOWNLOAD,$(THIRD_PARTY_DOWNLOADS),$(eval $(call create_download_rule,$(DOWNLOAD))))
third_party_downloads: $(THIRD_PARTY_TARGETS)

MICROLITE_LIB_OBJS := $(addprefix $(OBJDIR), \
$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(MICROLITE_CC_SRCS))))

MICROLITE_LIB_OBJS += $(addprefix $(OBJDIR), \
$(patsubst %.S,%.o,$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(THIRD_PARTY_CC_SRCS)))))

# For normal manually-created TensorFlow C++ source files.
$(OBJDIR)%.o: %.cc $(THIRD_PARTY_TARGETS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# For normal manually-created TensorFlow C source files.
$(OBJDIR)%.o: %.c $(THIRD_PARTY_TARGETS)
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

# For normal manually-created TensorFlow ASM source files.
$(OBJDIR)%.o: %.S $(THIRD_PARTY_TARGETS)
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

# The target that's compiled if there's no command-line arguments.
all: $(MICROLITE_LIB_PATH)

microlite: $(MICROLITE_LIB_PATH)

# Hack for generating schema file bypassing flatbuffer parsing
tensorflow/lite/schema/schema_generated.h:
	@cp -u tensorflow/lite/schema/schema_generated.h.OPENSOURCE tensorflow/lite/schema/schema_generated.h

# Gathers together all the objects we've compiled into a single '.a' archive.
$(MICROLITE_LIB_PATH): tensorflow/lite/schema/schema_generated.h $(MICROLITE_LIB_OBJS) 
	@echo "allah!!!" && mkdir -p $(dir $@)
	$(AR) $(ARFLAGS) $(MICROLITE_LIB_PATH)  $(MICROLITE_LIB_OBJS) \
	$(MY_OBJECTS)
$(BINDIR)%_test : $(OBJDIR)%_test.o $(MICROLITE_LIB_PATH)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) \
	-o $@ $< \
	$(LIBFLAGS) $(MICROLITE_LIB_PATH) $(LDFLAGS) $(MICROLITE_LIBS)

$(BINDIR)%.test_target: $(BINDIR)%_test
	@test -f $(TEST_SCRIPT) || (echo 'Unable to find the test script. Is the software emulation available in $(TARGET)?'; exit 1)
	$(TEST_SCRIPT) $< '~~~ALL TESTS PASSED~~~'

# snease: Add %.bin rule here since BINDIR is now defined
# These are microcontroller-specific rules for converting the ELF output
# of the linker into a binary image that can be loaded directly.
OBJCOPY := $(TARGET_TOOLCHAIN_PREFIX)objcopy
$(BINDIR)%.bin: $(BINDIR)%
	@mkdir -p $(dir $@)
	$(OBJCOPY) $< $@ -O binary

# Generate standalone makefile projects for all of the test targets.
$(foreach TEST_TARGET,$(filter-out tensorflow/lite/micro/kernels/%,$(MICROLITE_TEST_SRCS)),\
$(eval $(call microlite_test,$(notdir $(basename $(TEST_TARGET))),$(TEST_TARGET))))
$(foreach TEST_TARGET,$(filter tensorflow/lite/micro/kernels/%,$(MICROLITE_TEST_SRCS)),\
$(eval $(call microlite_test,kernel_$(notdir $(basename $(TEST_TARGET))),$(TEST_TARGET))))

test: $(MICROLITE_TEST_TARGETS)

# Just build the test targets
build: $(MICROLITE_BUILD_TARGETS)

generate_projects: $(ALL_PROJECT_TARGETS)

generate_non_kernel_projects: $(filter-out generate_kernel%,$(ALL_PROJECT_TARGETS))

generate_non_test_projects: $(filter-out %_test%,$(ALL_PROJECT_TARGETS))

generate_arduino_zip: generate_non_kernel_projects $(ARDUINO_LIBRARY_ZIPS)
	python tensorflow/lite/micro/tools/make/merge_arduino_zips.py $(PRJDIR)/tensorflow_lite.zip $(ARDUINO_LIBRARY_ZIPS)

# Gets rid of all generated files.
clean:
	rm -rf $(MAKEFILE_DIR)/gen

# Removes third-party downloads.
clean_downloads:
	rm -rf $(MAKEFILE_DIR)/downloads

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d
.PRECIOUS: $(BINDIR)%_test

-include $(patsubst %,$(DEPDIR)/%.d,$(basename $(ALL_SRCS)))
