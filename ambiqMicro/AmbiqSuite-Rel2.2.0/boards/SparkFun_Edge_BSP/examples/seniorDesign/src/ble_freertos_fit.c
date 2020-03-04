//*****************************************************************************
//
//! @file ble_freertos_fit.c
//!
//! @brief ARM Cordio BLE - Fit Application Example.
//!
//! Purpose: This example implements a BLE heart rate sensor within the FreeRTOS
//! framework. To minimize power usage, this application is compiled without
//! debug printing by default (the "lp" version of this example excludes
//! them by default).  
//!
//! Additional Information:
//! To enable debug printing, add the following project-level macro definitions.
//!
//! AM_DEBUG_PRINTF
//! WSF_TRACE_ENABLED=1
//!
//! When defined, debug messages will be sent over ITM/SWO at 1M Baud.
//!
//! Note that when these macros are defined, the device will never achieve deep
//! sleep, only normal sleep, due to the ITM (and thus the HFRC) being enabled.
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

//*****************************************************************************
//
// This application has a large number of common include files. For
// convenience, we'll collect them all together in a single header and include
// that everywhere.
//
//*****************************************************************************
#include "ble_freertos_fit.h"
#include "rtos.h"

//*****************************************************************************
//
// Enable printing to the console.
//
//*****************************************************************************
void
enable_print_interface(void)
{

	// this is for uart miguel
	am_bsp_uart_printf_enable();


    //
    // Initialize a debug printing interface.
    //
    am_bsp_itm_printf_enable();
	

	//print the banner  miguel
}

//*****************************************************************************
//
// UART configuration settings.
//
//*****************************************************************************
void
setup_serial(int32_t i32Module)
{
    //
    // Enable a UART to use for the menu.
    //
    const am_hal_uart_config_t sUartConfig =
    {
        //
        // Standard UART settings: 115200-8-N-1
        //
        .ui32BaudRate = 115200,
        .ui32DataBits = AM_HAL_UART_DATA_BITS_8,
        .ui32Parity = AM_HAL_UART_PARITY_NONE,
        .ui32StopBits = AM_HAL_UART_ONE_STOP_BIT,
        .ui32FlowControl = AM_HAL_UART_FLOW_CTRL_NONE,

        //
        // Set TX and RX FIFOs to interrupt at half-full.
        //
        .ui32FifoLevels = (AM_HAL_UART_TX_FIFO_1_2 |
                           AM_HAL_UART_RX_FIFO_1_2),

        //
        // Buffers
        //
        .pui8TxBuffer = 0,
        .ui32TxBufferSize = 0,
        .pui8RxBuffer = 0,
        .ui32RxBufferSize = 0,
    };

    am_hal_uart_initialize(0, &UART);
    am_hal_uart_power_control(UART, AM_HAL_SYSCTRL_WAKE, false);
    am_hal_uart_configure(UART, &sUartConfig);

    //
    // Make sure the UART interrupt priority is set low enough to allow
    // FreeRTOS API calls.
    //
    NVIC_SetPriority(UART0_IRQn, NVIC_configMAX_SYSCALL_INTERRUPT_PRIORITY);


    am_hal_gpio_pinconfig(AM_BSP_GPIO_COM_UART_TX, g_AM_BSP_GPIO_COM_UART_TX);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_COM_UART_RX, g_AM_BSP_GPIO_COM_UART_RX);

    //
    // Enable UART RX interrupts manually.
    //
    am_hal_uart_interrupt_clear(UART, AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT);
    am_hal_uart_interrupt_enable(UART, AM_HAL_UART_INT_RX | AM_HAL_UART_INT_RX_TMOUT);
    NVIC_EnableIRQ(UART0_IRQn);
=======
>>>>>>> 1a534b8a25b94207a3a3c5fadf9f679e9ac9783a
=======
>>>>>>> 1a534b8a25b94207a3a3c5fadf9f679e9ac9783a
}

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int
main(void)
{
    //
    // Set the clock frequency
    //
    am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_SYSCLK_MAX, 0);

    //
    // Set the default cache configuration
    //
    am_hal_cachectrl_config(&am_hal_cachectrl_defaults);
    am_hal_cachectrl_enable();

#ifndef NOFPU
    //
    // Enable the floating point module, and configure the core for lazy
    // stacking.
    //
    am_hal_sysctrl_fpu_enable();
    am_hal_sysctrl_fpu_stacking_enable(true);
#else
    am_hal_sysctrl_fpu_disable();
#endif

    //
    // Configure the board for low power.
    //
    //am_bsp_low_power_init();

    // Turn off unused Flash & SRAM
#if 1
    am_hal_pwrctrl_memory_enable(AM_HAL_PWRCTRL_MEM_SRAM_96K);
    am_hal_pwrctrl_memory_enable(AM_HAL_PWRCTRL_MEM_FLASH_512K);
#endif
#ifdef AM_PART_APOLLO
    //
    // SRAM bank power setting.
    // Need to match up with actual SRAM usage for the program
    // Current usage is between 32K and 40K - so disabling upper 3 banks
    //
    am_hal_mcuctrl_sram_power_set(AM_HAL_MCUCTRL_SRAM_POWER_DOWN_5 |
                                  AM_HAL_MCUCTRL_SRAM_POWER_DOWN_6 |
                                  AM_HAL_MCUCTRL_SRAM_POWER_DOWN_7,
                                  AM_HAL_MCUCTRL_SRAM_POWER_DOWN_5 |
                                  AM_HAL_MCUCTRL_SRAM_POWER_DOWN_6 |
                                  AM_HAL_MCUCTRL_SRAM_POWER_DOWN_7);

#if 0 // Not turning off the Flash as it may be needed to download the image
    //
    // Flash bank power set.
    //
    am_hal_mcuctrl_flash_power_set(AM_HAL_MCUCTRL_FLASH_POWER_DOWN_1);
#endif
#endif // AM_PART_APOLLO

#ifdef AM_PART_APOLLO2
#if 0 // Not turning off the Flash as it may be needed to download the image
    am_hal_pwrctrl_memory_enable(AM_HAL_PWRCTRL_MEMEN_FLASH512K);
#endif
    am_hal_pwrctrl_memory_enable(AM_HAL_PWRCTRL_MEMEN_SRAM64K);
#endif // AM_PART_APOLLO2

    //
    // Enable printing to the console.
    //
<<<<<<< HEAD
<<<<<<< HEAD
//#ifdef AM_DEBUG_PRINTF
    enable_print_interface();
	setup_serial(0);
//#endif
=======
#ifdef AM_DEBUG_PRINTF
    enable_print_interface();
#endif
>>>>>>> 1a534b8a25b94207a3a3c5fadf9f679e9ac9783a
=======
#ifdef AM_DEBUG_PRINTF
    enable_print_interface();
#endif
>>>>>>> 1a534b8a25b94207a3a3c5fadf9f679e9ac9783a

    //
    // Initialize plotting interface.
    //
    am_util_debug_printf("FreeRTOS Fit Example\n");

    //
    // Run the application.
    //
    run_tasks();

    //
    // We shouldn't ever get here.
    //
    while (1)
    {
    }

}

