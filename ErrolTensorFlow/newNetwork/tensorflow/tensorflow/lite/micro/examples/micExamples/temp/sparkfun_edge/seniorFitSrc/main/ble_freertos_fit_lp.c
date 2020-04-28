
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

//*****************************************************************************
//
// This application has a large number of common include files. For
// convenience, we'll collect them all together in a single header and include
// that everywhere.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
/* tensorflow includes */
#include "tensorflow/lite/micro/examples/micro_speech/main_functions.h"
/* end of tensor flow includes */


/* seniorFit includes */
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/ble_freertos_fit_lp.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/main/include/rtos.h"

#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/mcu/am_mcu_apollo.h" 
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/utils/include/am_util.h"
/* end of seniorFit includes */



/* miguel definitions */
//static int  boardSetup(void);
 #define AM_DEBUG_PRINTF  1
 #define WSF_TRACE_ENABLED   1

static uint32_t g_ui32Count = 0;
//*****************************************************************************
//
// Timer Interrupt Service Routine (ISR)
//
//*****************************************************************************
void
am_stimer_cmpr0_isr(void)
{
    //
    // Check the timer interrupt status.
    //
    am_hal_stimer_int_clear(AM_HAL_STIMER_INT_COMPAREA);
    am_hal_stimer_compare_delta_set(0, WAKE_INTERVAL_IN_MS);

	loop();
    g_ui32Count++;
    //
    // Do a linefeed after 32 prints.
    //
    if ( (g_ui32Count & 0x1F) == 0 )
    {
        am_util_stdio_printf("\n");
    }
}
//*****************************************************************************
//
// Enable printing to the console.
//
//*****************************************************************************
void
enable_print_interface(void)
{
    //
    // Initialize a debug printing interface.
    //
    am_bsp_itm_printf_enable();
}

/* C code: */
int ble_main(int argc, char** argv)	{


	/*clk, memory, lazy loading cache configurtation */	
	//NOTE: may not need since clock already seems enabled here 
	am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_SYSCLK_MAX, 0); //uncomment if needed
	


	/* cache and fpu configuration */
    //
    // Set the default cache configuration
    //
    am_hal_cachectrl_config(&am_hal_cachectrl_defaults);
    am_hal_cachectrl_enable();

    //
    // Enable the floating point module, and configure the core for lazy
    // stacking.
    //
    am_hal_sysctrl_fpu_enable();
    am_hal_sysctrl_fpu_stacking_enable(true);

	/* end of cache and fpu configuration */



	/*MIGUEL START OF SRAM SETTINGS */

    //
    // Enable printing to the console.
    //
    enable_print_interface();

	
	boardSetup();  //miguel call 1



   	am_util_stdio_printf("debugging setup!\r\n");//miguel call 2


/*
	
	const char* typeOfNoise;
	int noise = grab();
	if (noise == 0 ) typeOfNoise = "unknown";//unknown
	else if (noise == 1 ) typeOfNoise = "speech";//unknown
	else if (noise == 2 ) typeOfNoise = "music";//unknown
	else if (noise == 3 ) typeOfNoise = "silence";//unknown
	else{
   	am_util_stdio_printf("ERROR , %d\r\n", noise);

	} 

   	am_util_stdio_printf("READ NOISE %s \r\n", typeOfNoise);//miguel call 2
	reset();
*/
    //
    // Run the application.
    //	
	/* write os here or call run_tasks() */
	// os_setup(); //miguel defined
    //run_tasks();
	//call to test c++ entry

	run_tasks();
   	//am_util_stdio_printf("got past run_tasks!\r\n");//miguel call 2





    while (1)
    {
    //
    // We shouldn't ever get here.
    //
     //   am_hal_sysctrl_sleep(AM_HAL_SYSCTRL_SLEEP_DEEP);

    }
	




	return 1;
}

int boardSetup(void)
{

    // Initialize the printf interface for ITM/SWO output.
    am_bsp_uart_printf_enable(); // Enable UART - will set debug output to UART
    //am_bsp_itm_printf_enable(); // Redirect debug output to SWO

    // Setup LED's as outputs
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_RED, g_AM_HAL_GPIO_OUTPUT_12);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_BLUE, g_AM_HAL_GPIO_OUTPUT_12);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_GREEN, g_AM_HAL_GPIO_OUTPUT_12);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_YELLOW, g_AM_HAL_GPIO_OUTPUT_12);

    // Set up button 14 as input (has pullup resistor on hardware)
    am_hal_gpio_pinconfig( 14, g_AM_HAL_GPIO_INPUT);

    // Turn on the LEDs
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_RED);
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_BLUE);
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_GREEN);
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_YELLOW);

    return 0;
}
