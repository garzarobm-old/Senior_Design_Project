//*****************************************************************************
//
//! @file rtos.c
//!
//! @brief Essential functions to make the RTOS run correctly.
//!
//! These functions are required by the RTOS for ticking, sleeping, and basic
//! error checking.
//
//*****************************************************************************

//*****************************************************************************
//
// Copyright (c) 2019, Ambiq Micro
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
// 
// Third party software included in this distribution is subject to the
// additional license terms as defined in the /docs/licenses directory.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision v2.2.0-7-g63f7c2ba1 of the AmbiqSuite Development Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>

/* seniorFit includes */
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/mcu/am_mcu_apollo.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/bsp/am_bsp.h"

#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/FreeRTOS.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/task.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/queue.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/portmacro.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/portable.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/ble_freertos_fit_lp.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/rtos.h"

//extra ones added by miguel
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/RTOSEdits/include/mpu_wrappers.h"

/* end of seniorFit includes */
//#include "am_mcu_apollo.h" //done
//#include "am_bsp.h"

//#include "FreeRTOS.h"		//done
//#include "task.h"			//done
//#include "queue.h"		//done
//#include "portmacro.h"
//#include "portable.h"		//done
//#include "ble_freertos_fit_lp.h" //done

//*****************************************************************************
//
// Task handle for the initial setup task.
//
//*****************************************************************************
TaskHandle_t xSetupTask; // has the tcb
StackType_t setupStack[512*10]; // miguel defined a stack for the setupStack

StackType_t radioStack[512*10]; // miguel defined a stack for the setupStack


//*****************************************************************************
//
// Interrupt handler for the CTIMER module.
//
//*****************************************************************************
void
am_ctimer_isr(void)
{
    uint32_t ui32Status;

    //
    // Check the timer interrupt status.
    //
    ui32Status = am_hal_ctimer_int_status_get(false);
    am_hal_ctimer_int_clear(ui32Status);

    //
    // Run handlers for the various possible timer events.
    //
    am_hal_ctimer_int_service(ui32Status);
}

//*****************************************************************************
//
// Sleep function called from FreeRTOS IDLE task.
// Do necessary application specific Power down operations here
// Return 0 if this function also incorporates the WFI, else return value same
// as idleTime
//
//*****************************************************************************
uint32_t am_freertos_sleep(uint32_t idleTime)
{
    am_hal_sysctrl_sleep(AM_HAL_SYSCTRL_SLEEP_DEEP);
    return 0;
}

//*****************************************************************************
//
// Recovery function called from FreeRTOS IDLE task, after waking up from Sleep
// Do necessary 'wakeup' operations here, e.g. to power up/enable peripherals etc.
//
//*****************************************************************************
void am_freertos_wakeup(uint32_t idleTime)
{
    return;
}


//*****************************************************************************
//
// FreeRTOS debugging functions.
//
//*****************************************************************************
void
vApplicationMallocFailedHook(void)
{
    //
    // Called if a call to pvPortMalloc() fails because there is insufficient
    // free memory available in the FreeRTOS heap.  pvPortMalloc() is called
    // internally by FreeRTOS API functions that create tasks, queues, software
    // timers, and semaphores.  The size of the FreeRTOS heap is set by the
    // configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h.
    //
    while (1);
}

void
vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void) pcTaskName;
    (void) pxTask;

   	am_util_stdio_printf("stack overflow\r\n");//miguel call 2
    //
    // Run time stack overflow checking is performed if
    // configconfigCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    // function is called if a stack overflow is detected.
    //
    while (1)
    {
        __asm("BKPT #0\n") ; // Break into the debugger
    }
}

void TenseTask(void *pvParameters){


//while(1){
//loop();
//}

}

TaskHandle_t tense_task_handle;
//*****************************************************************************
//
// High priority task to run immediately after the scheduler starts.
//
// This task is used for any global initialization that must occur after the
// scheduler starts, but before any functional tasks are running. This can be
// useful for enabling events, semaphores, and other global, RTOS-specific
// features.
//
//*****************************************************************************
void
setup_task(void *pvParameters)
{
    //
    // Print a debug message.
    //
    //am_util_debug_printf("Running setup tasks...\r\n");

   	am_util_stdio_printf("before RadioTaskSetup\r\n");//miguel call 2
    //
    // Run setup functions.
    //
    RadioTaskSetup();

   	am_util_stdio_printf("after RadioTaskSetup()\r\n");//miguel call 2

	
    //
    // Create the functional tasks
    //
    xTaskCreate(RadioTask, "RadioTask", 512, 0, 3, &radio_task_handle);

	/* miguel wants to make a task!!!! */
	//setup();	 // for tensorflow
	//tensorflow_cc_entry();

    //xTaskCreate(TenseTask, "TenseTask", 512, 0, 3, &tense_task_handle);
	//creating task tensorflow
    //
    // The setup operations are complete, so suspend the setup task now.
    //
    vTaskSuspend(NULL);

    while (1);
}

//*****************************************************************************
//
// Initializes all tasks
//
//*****************************************************************************
void
run_tasks(void)
{
    //
    // Set some interrupt priorities before we create tasks or start the scheduler.
    //
    // Note: Timer priority is handled by the FreeRTOS kernel, so we won't
    // touch it here.
    //

	//setup_task = function

	//this is add thread

    xTaskCreate(setup_task, "Setup", 512, 0, 3,  &xSetupTask);


    //
    // Start the scheduler.
    //
    vTaskStartScheduler();
}

