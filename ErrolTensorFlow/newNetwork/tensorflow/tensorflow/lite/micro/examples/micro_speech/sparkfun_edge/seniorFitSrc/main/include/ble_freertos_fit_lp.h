/* inserting c code */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/mcu/am_mcu_apollo.h" //don't know if this one works
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/bsp/am_bsp.h" //don't know if this one works
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/utils/include/am_util.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/FreeRTOS.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/task.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/portmacro.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/portable.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/semphr.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/event_groups.h"


#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/radio_task.h"
/* if you want to insert class definitions */
#ifdef __cplusplus

#endif

/* END OF CLASS DEFINITIONS */




/*C++ declaration in a header file for C files*/

#ifdef __cplusplus

extern "C" int ble_main(int argc, char** argv);

#endif




