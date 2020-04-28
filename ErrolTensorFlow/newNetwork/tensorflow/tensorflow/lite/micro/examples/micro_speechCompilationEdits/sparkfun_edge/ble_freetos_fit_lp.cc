

#include "tensorflow/lite/micro/micro_error_reporter.h"
//end of tensorflow includes


#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/ble_freetos_fit_lp.h"
// These are headers from Ambiq's Apollo3 SDK.
#include "am_bsp.h"         // NOLINT
#include "am_mcu_apollo.h"  // NOLINT
#include "am_util.h"        // NOLINT

//miguel definitions



void call(tflite::ErrorReporter* error_reporter ){


	
    TF_LITE_REPORT_ERROR(error_reporter, "my code works!");

}
