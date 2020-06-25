Name:
=====
 ble_freertos_fit_lp


Description:
============
 ARM Cordio BLE - Fit Application Example at lowest possible power.


Purpose:
========
This example implements a BLE heart rate sensor within the FreeRTOS
framework. To minimize power usage, this application is compiled without
debug printing by default (the non-"lp" version of this example enables
them by default).  

Additional Information:
=======================
To enable debug printing, add the following project-level macro definitions.

AM_DEBUG_PRINTF
WSF_TRACE_ENABLED=1

When defined, debug messages will be sent over ITM/SWO at 1M Baud.

Note that when these macros are defined, the device will never achieve deep
sleep, only normal sleep, due to the ITM (and thus the HFRC) being enabled.


******************************************************************************

FOR SENIOR DESIGN:


The bluetooth uses GATT messaging protocol to send to device 

This is define in the 

src/third_party/exactle/sw/services/svc_ch.h
src/third_party/exactle/sw/stack/include/att_uuid.h

somewhere in the project, it calls 
	"attHrmChUuid[8Or16bit];attHrsSvcUUid[8Or16Bit]; " // to start the service, I do not believe we can manually change the name, but we could change it within our android app.


We have currently updating the heart measurement to be a value that we want according to what we would supposedly get from the model. We also have light blue reading it as a heart rate value
