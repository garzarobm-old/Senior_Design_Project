//*****************************************************************************
//
//! @file radio_task.c
//!
//! @brief Task to handle radio operation.
//!
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

#include <stdbool.h>
/* end of seniorFit includes */
//*****************************************************************************
//
// Global includes for this project.
//
//*****************************************************************************
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/ble_freertos_fit_lp.h"
//#include "ble_freertos_fit_lp.h"
#include "tensorflow/lite/micro/examples/micro_speech/main_functions.h"

//*****************************************************************************
//
// WSF standard includes.
//
//*****************************************************************************
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/wsf_types.h"
//#include "wsf_types.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/wsf_trace.h"
//#include "wsf_trace.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/wsf_buf.h"
//#include "wsf_buf.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/wsf_timer.h"
//#include "wsf_timer.h"

//*****************************************************************************
//
// Includes for operating the ExactLE stack.
//
//*****************************************************************************
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_handler.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/dm_handler.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/l2c_handler.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/att_handler.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/smp_handler.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/l2c_api.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/att_api.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/smp_api.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/app_api.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_core.h"
//#include "hci_core.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_drv.h"
//#include "hci_drv.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_drv_apollo.h"
//#include "hci_drv_apollo.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_drv_apollo3.h"
//#include "hci_drv_apollo3.h"

#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_apollo_config.h"
//#include "hci_apollo_config.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/wsf_msg.h"
//#include "wsf_msg.h"

//*****************************************************************************
//
// Includes for the ExactLE "fit" profile.
//
//*****************************************************************************
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/fit_api.h"
//#include "fit_api.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/app_ui.h"
//#include "app_ui.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/cmsis/include/apollo3.h"

//*****************************************************************************
//
// Radio task handle.
//
//*****************************************************************************
TaskHandle_t radio_task_handle;
//miguel defines to allow static
//*****************************************************************************
//
// Handle for Radio-related events.
//
//*****************************************************************************
EventGroupHandle_t xRadioEventHandle;

//*****************************************************************************
//
// Function prototypes
//
//*****************************************************************************
void exactle_stack_init(void);
void scheduler_timer_init(void);
void update_scheduler_timers(void);
void set_next_wakeup(void);

//*****************************************************************************
//
// Timer configuration macros.
//
//*****************************************************************************
// Configure how to driver WSF Scheduler
#if 1
// Preferred mode to use when using FreeRTOS
#define USE_FREERTOS_TIMER_FOR_WSF
#else
#ifdef AM_FREERTOS_USE_STIMER_FOR_TICK
#define USE_STIMER_FOR_WSF // Reuse FreeRTOS used STimer for WSF
#else
#define USE_CTIMER_FOR_WSF
#endif
#endif

// Use FreeRTOS timer for WSF Ticks
#ifdef USE_FREERTOS_TIMER_FOR_WSF
#define CLK_TICKS_PER_WSF_TICKS     (WSF_MS_PER_TICK*configTICK_RATE_HZ/1000)
#endif

#ifdef USE_CTIMER_FOR_WSF
#define WSF_CTIMER_NUM              1
#define CLK_TICKS_PER_WSF_TICKS     (WSF_MS_PER_TICK*512/1000)   // Number of CTIMER counts per WSF tick.

#if WSF_CTIMER_NUM == 0
#define WSF_CTIMER_INT  AM_HAL_CTIMER_INT_TIMERA0
#elif WSF_CTIMER_NUM == 1
#define WSF_CTIMER_INT  AM_HAL_CTIMER_INT_TIMERA1
#elif WSF_CTIMER_NUM == 2
#define WSF_CTIMER_INT  AM_HAL_CTIMER_INT_TIMERA2
#elif WSF_CTIMER_NUM == 3
#define WSF_CTIMER_INT  AM_HAL_CTIMER_INT_TIMERA3
#endif
#endif

#ifdef USE_STIMER_FOR_WSF
#define CLK_TICKS_PER_WSF_TICKS     (WSF_MS_PER_TICK*configSTIMER_CLOCK_HZ/1000)   // Number of STIMER counts per WSF tick.
#endif

//*****************************************************************************
//
// WSF buffer pools.
//
//*****************************************************************************
#define WSF_BUF_POOLS               4

// Important note: the size of g_pui32BufMem should includes both overhead of internal
// buffer management structure, wsfBufPool_t (up to 16 bytes for each pool), and pool
// description (e.g. g_psPoolDescriptors below).

// Memory for the buffer pool
// extra AMOTA_PACKET_SIZE bytes for OTA handling
static uint32_t g_pui32BufMem[
        (WSF_BUF_POOLS*16
         + 16*8 + 32*4 + 64*6 + 280*6) / sizeof(uint32_t)];

// Default pool descriptor.
static wsfBufPoolDesc_t g_psPoolDescriptors[WSF_BUF_POOLS] =
{
    {  16,  8 },
    {  32,  4 },
    {  64,  6 },
    { 280,  6 }
};

#define WSF_TRACE_ENABLED  1 //miguel define

//*****************************************************************************
//
// Tracking variable for the scheduler timer.
//
//*****************************************************************************
uint32_t g_ui32LastTime = 0;

void radio_timer_handler(void);

#ifdef USE_CTIMER_FOR_WSF
//*****************************************************************************
//
// Set up a pair of timers to handle the WSF scheduler.
//
//*****************************************************************************
void
scheduler_timer_init(void)
{
   	am_util_stdio_printf("scheduler_timer()\r\n");//miguel call 2
    // Enable the LFRC
    am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_LFRC_START, 0);

    //
    // One of the timers will run in one-shot mode and provide interrupts for
    // scheduled events.
    //
    am_hal_ctimer_clear(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERA);
    am_hal_ctimer_config_single(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERA,
                                (AM_HAL_CTIMER_INT_ENABLE |
                                 AM_HAL_CTIMER_LFRC_512HZ |
                                 AM_HAL_CTIMER_FN_ONCE));

    //
    // The other timer will run continuously and provide a constant time-base.
    //
    am_hal_ctimer_clear(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERB);
    am_hal_ctimer_config_single(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERB,
                                (AM_HAL_CTIMER_LFRC_512HZ |
                                 AM_HAL_CTIMER_FN_CONTINUOUS));

    //
    // Start the continuous timer.
    //
    am_hal_ctimer_start(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERB);

    //
    // Enable the timer interrupt.
    //
	//MIGUEL LOOKS LIKE THE CTIMER (WHICH COULD BE KERNEL) IS SET TO PRIORITY 7 
    am_hal_ctimer_int_register(WSF_CTIMER_INT, radio_timer_handler);
    NVIC_SetPriority(CTIMER_IRQn, NVIC_configKERNEL_INTERRUPT_PRIORITY);
    am_hal_ctimer_int_enable(WSF_CTIMER_INT);
    NVIC_EnableIRQ(CTIMER_IRQn);
}

//*****************************************************************************
//
// Calculate the elapsed time, and update the WSF software timers.
//
//*****************************************************************************
void
update_scheduler_timers(void)
{
   	am_util_stdio_printf("currenttime \r\n");//miguel call 2
    uint32_t ui32CurrentTime, ui32ElapsedTime;

    //
    // Read the continuous timer.
    //
    ui32CurrentTime = am_hal_ctimer_read(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERB);

    //
    // Figure out how long it has been since the last time we've read the
    // continuous timer. We should be reading often enough that we'll never
    // have more than one overflow.
    //
    ui32ElapsedTime = ui32CurrentTime - g_ui32LastTime;

    //
    // Check to see if any WSF ticks need to happen.
    //
    if ( (ui32ElapsedTime / CLK_TICKS_PER_WSF_TICKS) > 0 )
    {
        //
        // Update the WSF timers and save the current time as our "last
        // update".
        //
        WsfTimerUpdate(ui32ElapsedTime / CLK_TICKS_PER_WSF_TICKS);

        g_ui32LastTime = ui32CurrentTime;
    }
   	am_util_stdio_printf("inside next_wakeup()\r\n");//miguel call 2
}

//*****************************************************************************
//
// Set a timer interrupt for the next upcoming scheduler event.
//
//*****************************************************************************
void
set_next_wakeup(void)
{
   	am_util_stdio_printf("inside next_wakeup()\r\n");//miguel call 2
    bool_t bTimerRunning;
    wsfTimerTicks_t xNextExpiration;

    //
    // Stop and clear the scheduling timer.
    //
    am_hal_ctimer_stop(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERA);
    am_hal_ctimer_clear(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERA);

    //
    // Check to see when the next timer expiration should happen.
    //
    xNextExpiration = WsfTimerNextExpiration(&bTimerRunning);

    //
    // If there's a pending WSF timer event, set an interrupt to wake us up in
    // time to service it. Otherwise, set an interrupt to wake us up in time to
    // prevent a double-overflow of our continuous timer.
    //
    if ( xNextExpiration )
    {
        am_hal_ctimer_period_set(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERA,
                                 xNextExpiration * CLK_TICKS_PER_WSF_TICKS, 0);
    }
    else
    {
        am_hal_ctimer_period_set(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERA, 0x8000, 0);
    }

    //
    // Start the scheduling timer.
    //
    am_hal_ctimer_start(WSF_CTIMER_NUM, AM_HAL_CTIMER_TIMERA);
}

//*****************************************************************************
//
// Interrupt handler for the CTIMERs
//
//*****************************************************************************
void
radio_timer_handler(void)
{
    // Signal radio task to run

   	am_util_stdio_printf("radiotimer handler\r\n");//miguel call 2
    WsfTaskSetReady(0, 0);
}
#endif
#ifdef USE_STIMER_FOR_WSF
//*****************************************************************************
//
// Reuse STIMER to handle the WSF scheduler.
//
//*****************************************************************************
void
scheduler_timer_init(void)
{
    //
    // USe CMPR1 of STIMER for one-shot mode interrupts for
    // scheduled events.
    //
    uint32_t cfgVal;
    /* Stop the Stimer momentarily.  */
    cfgVal = am_hal_stimer_config(AM_HAL_STIMER_CFG_FREEZE);


    //
    // Configure the STIMER->COMPARE_1
    //
    am_hal_stimer_compare_delta_set(1, CLK_TICKS_PER_WSF_TICKS);
    am_hal_stimer_int_enable(AM_HAL_STIMER_INT_COMPAREB);
    am_hal_stimer_config(cfgVal | AM_HAL_STIMER_CFG_COMPARE_B_ENABLE);

    //
    // Enable the timer interrupt in the NVIC, making sure to use the
    // appropriate priority level.
    //
    NVIC_SetPriority(STIMER_CMPR1_IRQn, NVIC_configKERNEL_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ(STIMER_CMPR1_IRQn);

    //
    // Reuse STIMER to provide a constant time-base.
    //

}


//*****************************************************************************
//
// Interrupt handler for the CTIMERs
//
//*****************************************************************************
void
radio_timer_handler(void)
{
    // Signal radio task to run

   	am_util_stdio_printf("radio_timer handler() called\r\n");//miguel call 2
    WsfTaskSetReady(0, 0);
}

//*****************************************************************************
//
// Interrupt handler for the STIMER module Compare 1.
//
//*****************************************************************************
void
am_stimer_cmpr1_isr(void)
{
    am_hal_stimer_int_clear(AM_HAL_STIMER_INT_COMPAREB);

    //
    // Run handlers for the various possible timer events.
    //
    radio_timer_handler();

}
#endif
#ifdef USE_FREERTOS_TIMER_FOR_WSF
TimerHandle_t xWsfTimer;
//*****************************************************************************
//
// Callback handler for the FreeRTOS Timer
//
//*****************************************************************************
void
wsf_timer_handler(TimerHandle_t xTimer)
{
    // Signal radio task to run
   	am_util_stdio_printf("wsf_timer_handler() called\r\n");//miguel call 2

    WsfTaskSetReady(0, 0);
}

//*****************************************************************************
//
// Reuse FreeRTOS TIMER to handle the WSF scheduler.
//
//*****************************************************************************
void
scheduler_timer_init(void)
{
    // Create a FreeRTOS Timer
    /*xWsfTimer = xTimerCreate("WSF Timer", pdMS_TO_TICKS(WSF_MS_PER_TICK),
            pdFALSE, NULL, wsf_timer_handler,
			&( radioBuffer[0] )
			);
	*/
    xWsfTimer = xTimerCreate("WSF Timer", pdMS_TO_TICKS(WSF_MS_PER_TICK),
            pdFALSE, NULL, wsf_timer_handler			);
/* comment out because you can't have the ==
	if ( radioBuffer[0] == NULL ) {



   		am_util_stdio_printf("the timer was not created\r\n");//miguel call 2

	}
*/


    configASSERT(xWsfTimer);
}

//*****************************************************************************
//
// Calculate the elapsed time, and update the WSF software timers.
//
//*****************************************************************************
void
update_scheduler_timers(void)
{
    uint32_t ui32CurrentTime, ui32ElapsedTime;

    //
    // Read the continuous timer.
    //
    ui32CurrentTime = xTaskGetTickCount();
   	am_util_stdio_printf("continuousTimer = %d\r\n", ui32CurrentTime);//miguel call 2

    //
    // Figure out how long it has been since the last time we've read the
    // continuous timer. We should be reading often enough that we'll never
    // have more than one overflow.
    //
    ui32ElapsedTime = ui32CurrentTime - g_ui32LastTime;

    //
    // Check to see if any WSF ticks need to happen.
    //
    if ( (ui32ElapsedTime / CLK_TICKS_PER_WSF_TICKS) > 0 )
    {
        //
        // Update the WSF timers and save the current time as our "last
        // update".
        //
        WsfTimerUpdate(ui32ElapsedTime / CLK_TICKS_PER_WSF_TICKS);

        g_ui32LastTime = ui32CurrentTime;
    }
}

//*****************************************************************************
//
// Set a timer interrupt for the next upcoming scheduler event.
//
//*****************************************************************************
void
set_next_wakeup(void)
{
    bool_t bTimerRunning;
    wsfTimerTicks_t xNextExpiration;

    //
    // Check to see when the next timer expiration should happen.
    //
    xNextExpiration = WsfTimerNextExpiration(&bTimerRunning);

    //
    // If there's a pending WSF timer event, set an interrupt to wake us up in
    // time to service it.
    //
    if ( xNextExpiration )
    {
        configASSERT(pdPASS == xTimerChangePeriod( xWsfTimer,
                pdMS_TO_TICKS(xNextExpiration*CLK_TICKS_PER_WSF_TICKS), 100)) ;
    }
}
#endif

//*****************************************************************************
//
// Initialization for the ExactLE stack.
//
//*****************************************************************************
void
exactle_stack_init(void)
{
    wsfHandlerId_t handlerId;
    uint16_t       wsfBufMemLen;
    //
    // Set up timers for the WSF scheduler.
    //
    scheduler_timer_init();
    WsfTimerInit();

    //
    // Initialize a buffer pool for WSF dynamic memory needs.
    //
    wsfBufMemLen = WsfBufInit(sizeof(g_pui32BufMem), (uint8_t *)g_pui32BufMem, WSF_BUF_POOLS,
               g_psPoolDescriptors);

    if (wsfBufMemLen > sizeof(g_pui32BufMem))
    {
        am_util_debug_printf("Memory pool is too small by %d\r\n",
                             wsfBufMemLen - sizeof(g_pui32BufMem));
    }

    //
    // Initialize the WSF security service.
    //
    SecInit();
    SecAesInit();
    SecCmacInit();
    SecEccInit();

    //
    // Set up callback functions for the various layers of the ExactLE stack.
    //
    handlerId = WsfOsSetNextHandler(HciHandler);
    HciHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(DmHandler);
    DmDevVsInit(0);
    DmAdvInit();
    DmConnInit();
    DmConnSlaveInit();
    DmSecInit();
    DmSecLescInit();
    DmPrivInit();
    DmHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(L2cSlaveHandler);
    L2cSlaveHandlerInit(handlerId);
    L2cInit();
    L2cSlaveInit();

    handlerId = WsfOsSetNextHandler(AttHandler);
    AttHandlerInit(handlerId);
    AttsInit();
    AttsIndInit();
    AttcInit();

    handlerId = WsfOsSetNextHandler(SmpHandler);
    SmpHandlerInit(handlerId);
    SmprInit();
    SmprScInit();
    HciSetMaxRxAclLen(251);

    handlerId = WsfOsSetNextHandler(AppHandler);
    AppHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(FitHandler);
    FitHandlerInit(handlerId);

    handlerId = WsfOsSetNextHandler(HciDrvHandler);
    HciDrvHandlerInit(handlerId);
}

//*****************************************************************************
//
// UART interrupt handler.
//
//*****************************************************************************
void
am_uart_isr(void)
{
    uint32_t ui32Status;

    //
    // Read and save the interrupt status, but clear out the status register.
    //
    ui32Status = UARTn(0)->MIS;
    UARTn(0)->IEC = ui32Status;

    //
    // Allow the HCI driver to respond to the interrupt.
    //
    //HciDrvUartISR(ui32Status);

    // Signal radio task to run

    WsfTaskSetReady(0, 0);
}

//*****************************************************************************
//
// Interrupt handler for BLE
//
//*****************************************************************************
void
am_ble_isr(void)
{

   	am_util_stdio_printf("am_ble_isr() called\r\n");//miguel call 2
    HciDrvIntService();

    // Signal radio task to run

    WsfTaskSetReady(0, 0);
}

//*****************************************************************************
//
// Perform initial setup for the radio task.
//
//*****************************************************************************
void
RadioTaskSetup(void)
{

    //
    // Create an event handle for our wake-up events.
    //
    xRadioEventHandle = xEventGroupCreate();

    //
    // Make sure we actually allocated space for the events we need.
    //
    while ( xRadioEventHandle == NULL );

    // Pass event object to WSF scheduler
    wsfOsSetEventObject((void*)xRadioEventHandle);
	
   	am_util_stdio_printf("BLE_IRQn = %d\r\n", BLE_IRQn);//miguel call 2
    NVIC_SetPriority(12, NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);

    //
    // Boot the radio.
    //
   	am_util_stdio_printf(" HciDrvRadioBoot(1) \r\n");//miguel call 2
    HciDrvRadioBoot(1);


	

}



//*****************************************************************************
//
// Short Description.
//
//*****************************************************************************
void
RadioTask(void *pvParameters)
{
#if WSF_TRACE_ENABLED == TRUE
    //
    // Enable ITM
    //
#endif

   	am_util_stdio_printf("before stack\r\n");//miguel call 2
    //
    // Initialize the main ExactLE stack.
    //
    exactle_stack_init();

   	am_util_stdio_printf("FitStart()\r\n");//miguel call 2
    //
    // Start the "Fit" profile.
    //
    FitStart();

    while (1)
    {
        //
        // Calculate the elapsed time from our free-running timer, and update
        // the software timers in the WSF scheduler.
        //

		//skips scheduler
   		am_util_stdio_printf("update_scheduler_timers\r\n");//miguel call 2
        update_scheduler_timers();


   		am_util_stdio_printf("os_dispatcher\r\n");//miguel call 2
        wsfOsDispatcher();
        //
        // Enable an interrupt to wake us up next time we have a scheduled
        // event.
        //
        set_next_wakeup();

        
        // Check to see if the WSF routines are ready to go to sleep.
        //
		bool mybool = wsfOsReadyToSleep();

   		am_util_stdio_printf("checking my bool= %d\r\n", mybool);//miguel call 2
		
        if ( mybool )
        {
            //
            // Attempt to shut down the UART. If we can shut it down
            // successfully, we can go to deep sleep. Otherwise, we'll need to
            // stay awake to finish processing the current packet.
            //

   			am_util_stdio_printf("trying to shut down the uart= %d\r\n", mybool);//miguel call 2
            //
            // Wait for an event to be posted to the Radio Event Handle.
            //
            xEventGroupWaitBits(xRadioEventHandle, 1, pdTRUE, pdFALSE, portMAX_DELAY);	
        }
    }
}
