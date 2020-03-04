//*****************************************************************************
//
//! @file main.c
//!
//! @brief Edge Test is an example to demonstrate the built-in hardware on the Edge board
//!
//! SWO is configured in 2M baud, 8-n-1 mode.
//
//*****************************************************************************
//#include "hci_drv_apollo3.h"
#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
//#include "hci_drv.h"
static int  boardSetup(void);
static void boardTeardown(void);
static int  testADC(void);
//axis3bit16_t data_raw_acceleration;
//axis1bit16_t data_raw_temperature;
//float acceleration_mg[3];
//float temperature_degC;

//typedef void (*function)(uint8_t *pui8Data, uint32_t ui32Length, void *pvContext);
static void *BLE;
//miguel includes
void runtask(void);
void initializeNVIC(void);

//our queues
/* buffer for holding outgoing hci packets 
we redefiined the function from the hci file
*/
typedef struct {
	uint32_t ui32Length;
	uint32_t pui32Data[256/ 4]; // max packet
}
write_t;
write_t writeBuffers[8];

//this is our queue for 

am_hal_queue_t writeQueue;

//our counter for counting the read data
volatile uint32_t interruptCounter = 0;


/* adc interrupting */




//*****************************************************************************
//
// Main function.
//
//*****************************************************************************
int main(void)
{
    boardSetup();
    am_util_stdio_terminal_clear();

    am_util_stdio_printf("SparkFun Edge Board Test\n");
    am_util_stdio_printf("Compiled on %s, %s\n\n", __DATE__, __TIME__);
    am_util_stdio_printf("SparkFun Tensorflow Debug Output (UART)\r\n");
    am_bsp_uart_string_print("Hello, UART!\r\n");

	uint32_t debug = -1;
	uint32_t powerDebug = -1;
	uint32_t configDebug = -1;
	uint32_t bootDebug = -1;
	uint32_t powerSetDebug = -1;
  	 //initialize
	debug = am_hal_ble_initialize(0, &BLE);


	//step 2:power cycle 
	powerDebug = am_hal_ble_power_control(BLE, AM_HAL_BLE_POWER_ACTIVE);
	
	//step 3: ble config gets called
        am_hal_ble_config_t sBleConfig =
        {
            // Configure the HCI interface clock for 6 MHz
            .ui32SpiClkCfg = AM_HAL_BLE_HCI_CLK_DIV8,

            // Set HCI read and write thresholds to 32 bytes each.
            .ui32ReadThreshold = 32,
            .ui32WriteThreshold = 32,

            // The MCU will supply the clock to the BLE core.
            .ui32BleClockConfig = AM_HAL_BLE_CORE_MCU_CLK,

            // Default settings for expected BLE clock drift (measured in PPM).
            .ui32ClockDrift = 0,
            .ui32SleepClockDrift = 50,

            // Default setting - AGC Enabled
            .bAgcEnabled = true,

            // Default setting - Sleep Algo enabled
            .bSleepEnabled = true,

            // Apply the default patches when am_hal_ble_boot() is called.
            .bUseDefaultPatches = true,
        };
	configDebug = am_hal_ble_config(BLE, &sBleConfig);
        
	//step 4: ble boot gets called
	bootDebug = am_hal_ble_boot(BLE);	

	//step 5: ble power gets set
	powerSetDebug = am_hal_ble_tx_power_set(BLE,0x8);

	//step 6: initialize interrupts for bluetooth module
	//initializeNVIC();	

	//step 7: set up some debugging variables

	
  	//am_hal_queue_from_array(&writeQueue, writeBuffers);

	//step 6: initialize interrupts for bluetooth module
	initializeNVIC();	

	//step 7: set up some debugging variables
	
  	am_hal_queue_from_array(&writeQueue, writeBuffers);
	interruptCounter = 0;	
    /*
		look at debugging values continuously till pin14 is pressed
    */
    while(1)
    {
	uint32_t data = 0x0001;
	
	uint32_t debugWrite = -1;	
	debugWrite = am_hal_ble_blocking_hci_write(BLE, 0x01, &data, 1);
        // Use Button 14 to break the loop and shut down
        uint32_t pin14Val = 1; 
        am_hal_gpio_state_read( AM_BSP_GPIO_14, AM_HAL_GPIO_INPUT_READ, &pin14Val);
        if( pin14Val == 0 ){ break; }
    	am_util_stdio_printf("debug = %d powerdebug = %d configDebug = %d bootDebug = %d powerset = %d \r\n", debug, powerDebug, configDebug, bootDebug, powerSetDebug);

    	am_util_stdio_printf("debugWrite = %d\r\n", debugWrite);
    	am_util_stdio_printf("interruptCounter = %d\r\n", interruptCounter);
    }

    // Turn off leds
    boardTeardown();

    // Disable debug
    am_bsp_debug_printf_disable();
    
    // Go to Deep Sleep.
    am_hal_sysctrl_sleep(AM_HAL_SYSCTRL_SLEEP_DEEP);
}

static int boardSetup(void)
{
    // Set the clock frequency.
    am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_SYSCLK_MAX, 0);

    // Set the default cache configuration
    am_hal_cachectrl_config(&am_hal_cachectrl_defaults);
    am_hal_cachectrl_enable();

    // Configure the board for low power operation.
    am_bsp_low_power_init();

    // Initialize the printf interface for ITM/SWO output.
    am_bsp_uart_printf_enable(); // Enable UART - will set debug output to UART
    //am_bsp_itm_printf_enable(); // Redirect debug output to SWO

    // Setup LED's as outputs
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_RED, g_AM_HAL_GPIO_OUTPUT_12);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_BLUE, g_AM_HAL_GPIO_OUTPUT_12);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_GREEN, g_AM_HAL_GPIO_OUTPUT_12);
    am_hal_gpio_pinconfig(AM_BSP_GPIO_LED_YELLOW, g_AM_HAL_GPIO_OUTPUT_12);

    // Set up button 14 as input (has pullup resistor on hardware)
    am_hal_gpio_pinconfig(AM_BSP_GPIO_14, g_AM_HAL_GPIO_INPUT);

    // Turn on the LEDs
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_RED);
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_BLUE);
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_GREEN);
    am_hal_gpio_output_set(AM_BSP_GPIO_LED_YELLOW);

    return 0;
}

static void boardTeardown(void)
{
    // Lights out
    am_hal_gpio_output_clear(AM_BSP_GPIO_LED_RED);
    am_hal_gpio_output_clear(AM_BSP_GPIO_LED_BLUE);
    am_hal_gpio_output_clear(AM_BSP_GPIO_LED_GREEN);
    am_hal_gpio_output_clear(AM_BSP_GPIO_LED_YELLOW);
}

static int testADC(void)
{
    initADC();
    enableAdcInterrupts();
    //triggerAdc();

    return 0;
}
/*miguel functions*/
void initializeNVIC(void){
    am_hal_ble_int_clear(BLE, (AM_HAL_BLE_INT_CMDCMP |
                               AM_HAL_BLE_INT_DCMP |
                               AM_HAL_BLE_INT_BLECIRQ |
                               AM_HAL_BLE_INT_BLECSSTAT));

    am_hal_ble_int_enable(BLE, (AM_HAL_BLE_INT_CMDCMP |
                                AM_HAL_BLE_INT_DCMP |
                                AM_HAL_BLE_INT_BLECIRQ |
                                AM_HAL_BLE_INT_BLECSSTAT));
	NVIC_EnableIRQ(BLE_IRQn);	
	am_hal_interrupt_master_enable();
}
void initialize(void){
   

}
