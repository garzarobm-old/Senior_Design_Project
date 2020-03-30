├── ble_freertos_fit_lp.c
├── ble_freertos_fit_lp.h
├── CMSIS
│   ├── AmbiqMicro
│   │   ├── Include
│   │   │   ├── apollo1.h
│   │   │   ├── apollo2.h
│   │   │   ├── apollo3c.h
│   │   │   ├── apollo3.h
│   │   │   ├── system_apollo1.h
│   │   │   ├── system_apollo2.h
│   │   │   ├── system_apollo3c.h
│   │   │   └── system_apollo3.h
│   │   └── Source
│   │       ├── startup_apollo1.s
│   │       ├── startup_apollo2.s
│   │       ├── startup_apollo3.s
│   │       ├── system_apollo1.c
│   │       ├── system_apollo2.c
│   │       └── system_apollo3.c
│   ├── ARM
│   │   ├── Include
│   │   │   ├── arm_math.h
│   │   │   ├── cmsis_armcc.h
│   │   │   ├── cmsis_armclang.h
│   │   │   ├── cmsis_compiler.h
│   │   │   ├── cmsis_gcc.h
│   │   │   ├── cmsis_iccarm.h
│   │   │   ├── cmsis_version.h
│   │   │   ├── core_cm4.h
│   │   │   └── mpu_armv7.h
│   │   └── Lib
│   │       └── ARM
│   │           ├── arm_cortexM4lf_math.lib
│   │           ├── arm_cortexM4l_math.lib
│   │           ├── iar_cortexM4lf_math.a
│   │           ├── iar_cortexM4l_math.a
│   │           ├── libarm_cortexM4lf_math.a
│   │           └── libarm_cortexM4l_math.a
│   └── version_cmsis_info.txt
├── devices
│   ├── am_devices_button.c
│   ├── am_devices_button.h
│   ├── am_devices_da14581.c
│   ├── am_devices_da14581.h
│   ├── am_devices_em9304.c
│   ├── am_devices_em9304.h
│   ├── am_devices_fireball.c
│   ├── am_devices_fireball.h
│   ├── am_devices.h
│   ├── am_devices_led.c
│   ├── am_devices_led.h
│   ├── am_devices_mb85rc256v.c
│   ├── am_devices_mb85rc256v.h
│   ├── am_devices_mb85rs1mt.c
│   ├── am_devices_mb85rs1mt.h
│   ├── am_devices_mspi_flash.c
│   ├── am_devices_mspi_flash.h
│   ├── am_devices_mspi_psram.c
│   ├── am_devices_mspi_psram.h
│   ├── am_devices_spiflash.c
│   └── am_devices_spiflash.h
├── FreeRTOSConfig.h
├── hci_apollo_config.h
├── mcu
│   ├── apollo3
│   │   ├── am_mcu_apollo.h
│   │   ├── hal
│   │   │   ├── am_hal_adc.c
│   │   │   ├── am_hal_adc.h
│   │   │   ├── am_hal_ble.c
│   │   │   ├── am_hal_ble.h
│   │   │   ├── am_hal_ble_patch_b0.c
│   │   │   ├── am_hal_ble_patch_b0.h
│   │   │   ├── am_hal_ble_patch.c
│   │   │   ├── am_hal_ble_patch.h
│   │   │   ├── am_hal_burst.c
│   │   │   ├── am_hal_burst.h
│   │   │   ├── am_hal_cachectrl.c
│   │   │   ├── am_hal_cachectrl.h
│   │   │   ├── am_hal_clkgen.c
│   │   │   ├── am_hal_clkgen.h
│   │   │   ├── am_hal_cmdq.c
│   │   │   ├── am_hal_cmdq.h
│   │   │   ├── am_hal_ctimer.c
│   │   │   ├── am_hal_ctimer.h
│   │   │   ├── am_hal_debug.c
│   │   │   ├── am_hal_debug.h
│   │   │   ├── am_hal_flash.c
│   │   │   ├── am_hal_flash.h
│   │   │   ├── am_hal_global.c
│   │   │   ├── am_hal_global.h
│   │   │   ├── am_hal_gpio.c
│   │   │   ├── am_hal_gpio.h
│   │   │   ├── am_hal_interrupt.c
│   │   │   ├── am_hal_interrupt.h
│   │   │   ├── am_hal_iom.c
│   │   │   ├── am_hal_iom.h
│   │   │   ├── am_hal_ios.c
│   │   │   ├── am_hal_ios.h
│   │   │   ├── am_hal_itm.c
│   │   │   ├── am_hal_itm.h
│   │   │   ├── am_hal_mcuctrl.c
│   │   │   ├── am_hal_mcuctrl.h
│   │   │   ├── am_hal_mspi.c
│   │   │   ├── am_hal_mspi.h
│   │   │   ├── am_hal_pdm.c
│   │   │   ├── am_hal_pdm.h
│   │   │   ├── am_hal_pin.h
│   │   │   ├── am_hal_pwrctrl.c
│   │   │   ├── am_hal_pwrctrl.h
│   │   │   ├── am_hal_pwrctrl_internal.h
│   │   │   ├── am_hal_queue.c
│   │   │   ├── am_hal_queue.h
│   │   │   ├── am_hal_reset.c
│   │   │   ├── am_hal_reset.h
│   │   │   ├── am_hal_rtc.c
│   │   │   ├── am_hal_rtc.h
│   │   │   ├── am_hal_scard.c
│   │   │   ├── am_hal_scard.h
│   │   │   ├── am_hal_secure_ota.c
│   │   │   ├── am_hal_secure_ota.h
│   │   │   ├── am_hal_security.c
│   │   │   ├── am_hal_security.h
│   │   │   ├── am_hal_status.h
│   │   │   ├── am_hal_stimer.c
│   │   │   ├── am_hal_stimer.h
│   │   │   ├── am_hal_sysctrl.c
│   │   │   ├── am_hal_sysctrl.h
│   │   │   ├── am_hal_systick.c
│   │   │   ├── am_hal_systick.h
│   │   │   ├── am_hal_tpiu.c
│   │   │   ├── am_hal_tpiu.h
│   │   │   ├── am_hal_uart.c
│   │   │   ├── am_hal_uart.h
│   │   │   ├── am_hal_wdt.c
│   │   │   ├── am_hal_wdt.h
│   │   │   ├── gcc
│   │   │   │   ├── bin
│   │   │   │   │   └── libam_hal.a
│   │   │   │   └── Makefile
│   │   │   ├── iar
│   │   │   │   ├── bin
│   │   │   │   │   └── libam_hal.a
│   │   │   │   ├── libam_hal.ewd
│   │   │   │   ├── libam_hal.ewp
│   │   │   │   ├── libam_hal.eww
│   │   │   │   ├── Makefile
│   │   │   │   └── settings
│   │   │   ├── keil
│   │   │   │   ├── bin
│   │   │   │   │   └── libam_hal.lib
│   │   │   │   ├── libam_hal.uvoptx
│   │   │   │   ├── libam_hal.uvprojx
│   │   │   │   ├── Listings
│   │   │   │   └── Makefile
│   │   │   └── Makefile
│   │   ├── Makefile
│   │   └── regs
│   │       ├── am_reg_base_addresses.h
│   │       ├── am_reg.h
│   │       ├── am_reg_iomstr_cmd.h
│   │       ├── am_reg_jedec.h
│   │       ├── am_reg_m4.h
│   │       ├── am_reg_macros_asm.h
│   │       └── am_reg_macros.h
│   └── Makefile
├── radio_task.c
├── radio_task.h
├── rtos.c
├── rtos.h
├── tags
├── third_party
│   ├── exactle
│   │   ├── apollo-host
│   │   │   └── projects
│   │   │       └── common
│   │   │           ├── utils.c
│   │   │           └── utils.h
│   │   ├── projects
│   │   │   └── generic
│   │   │       └── stacklib
│   │   │           ├── gcc
│   │   │           │   └── bin-cortex-m4
│   │   │           │       └── libstacklib.a
│   │   │           ├── iar
│   │   │           │   └── bin
│   │   │           │       └── libstacklib.a
│   │   │           ├── iar75
│   │   │           │   └── bin
│   │   │           │       └── libstacklib.a
│   │   │           ├── keil
│   │   │           │   └── Cortex-M4
│   │   │           │       └── libstacklib.lib
│   │   │           └── keil6
│   │   │               └── Cortex-M4
│   │   │                   └── libstacklib.lib
│   │   ├── sw
│   │   │   ├── apps
│   │   │   │   ├── app
│   │   │   │   │   ├── app_disc.c
│   │   │   │   │   ├── app_main.c
│   │   │   │   │   ├── app_main.h
│   │   │   │   │   ├── app_master_ae.c
│   │   │   │   │   ├── app_master.c
│   │   │   │   │   ├── app_master_leg.c
│   │   │   │   │   ├── app_server.c
│   │   │   │   │   ├── app_slave_ae.c
│   │   │   │   │   ├── app_slave.c
│   │   │   │   │   ├── app_slave_leg.c
│   │   │   │   │   ├── app_terminal.c
│   │   │   │   │   ├── generic
│   │   │   │   │   │   ├── app_db.c
│   │   │   │   │   │   ├── app_hw.c
│   │   │   │   │   │   └── app_ui.c
│   │   │   │   │   ├── include
│   │   │   │   │   │   ├── app_api.h
│   │   │   │   │   │   ├── app_cfg.h
│   │   │   │   │   │   ├── app_db.h
│   │   │   │   │   │   ├── app_hw.h
│   │   │   │   │   │   ├── app_param.h
│   │   │   │   │   │   ├── app_terminal.h
│   │   │   │   │   │   └── app_ui.h
│   │   │   │   │   └── windows
│   │   │   │   │       ├── app_param.c
│   │   │   │   │       └── app_ui.c
│   │   │   │   ├── cycling
│   │   │   │   │   ├── cycling_api.h
│   │   │   │   │   └── cycling_main.c
│   │   │   │   ├── datc
│   │   │   │   │   ├── datc_api.h
│   │   │   │   │   └── datc_main.c
│   │   │   │   ├── dats
│   │   │   │   │   ├── dats_api.h
│   │   │   │   │   └── dats_main.c
│   │   │   │   ├── fit
│   │   │   │   │   ├── fit_api.h
│   │   │   │   │   ├── fit_main.c
│   │   │   │   │   └── tags
│   │   │   │   ├── fit_ota
│   │   │   │   │   ├── fit_api.h
│   │   │   │   │   └── fit_ota_main.c
│   │   │   │   ├── gluc
│   │   │   │   │   ├── gluc_api.h
│   │   │   │   │   └── gluc_main.c
│   │   │   │   ├── hidapp
│   │   │   │   │   ├── hidapp_api.h
│   │   │   │   │   └── hidapp_main.c
│   │   │   │   ├── medc
│   │   │   │   │   ├── medc_api.h
│   │   │   │   │   ├── medc_blp.c
│   │   │   │   │   ├── medc_glp.c
│   │   │   │   │   ├── medc_hrp.c
│   │   │   │   │   ├── medc_htp.c
│   │   │   │   │   ├── medc_main.c
│   │   │   │   │   ├── medc_main.h
│   │   │   │   │   ├── medc_plx.c
│   │   │   │   │   └── medc_wsp.c
│   │   │   │   ├── meds
│   │   │   │   │   ├── meds_api.h
│   │   │   │   │   ├── meds_blp.c
│   │   │   │   │   ├── meds_glp.c
│   │   │   │   │   ├── meds_htp.c
│   │   │   │   │   ├── meds_main.c
│   │   │   │   │   ├── meds_main.h
│   │   │   │   │   ├── meds_plx.c
│   │   │   │   │   └── meds_wsp.c
│   │   │   │   ├── sensor
│   │   │   │   │   ├── sensor_api.h
│   │   │   │   │   └── sensor_main.c
│   │   │   │   ├── tag
│   │   │   │   │   ├── tag_api.h
│   │   │   │   │   ├── tag_main.c
│   │   │   │   │   └── tag_main_wdxs.c
│   │   │   │   ├── uribeacon
│   │   │   │   │   ├── uribeacon_api.h
│   │   │   │   │   └── uribeacon_main.c
│   │   │   │   ├── watch
│   │   │   │   │   ├── watch_api.h
│   │   │   │   │   └── watch_main.c
│   │   │   │   └── wdxs
│   │   │   │       └── wdxs_oad.c
│   │   │   ├── hci
│   │   │   │   ├── ambiq
│   │   │   │   │   ├── apollo3
│   │   │   │   │   │   ├── hci_drv_apollo3.c
│   │   │   │   │   │   └── hci_drv_apollo3.h
│   │   │   │   │   ├── hci_cmd.c
│   │   │   │   │   ├── hci_core.c
│   │   │   │   │   ├── hci_core_ps.c
│   │   │   │   │   ├── hci_core_ps.h
│   │   │   │   │   ├── hci_drv_apollo.h
│   │   │   │   │   ├── hci_evt.c
│   │   │   │   │   ├── hci_tr_apollo.h
│   │   │   │   │   ├── hci_tr.c
│   │   │   │   │   └── hci_vs.c
│   │   │   │   └── include
│   │   │   │       ├── hci_cmd.h
│   │   │   │       ├── hci_core.h
│   │   │   │       ├── hci_drv.h
│   │   │   │       ├── hci_evt.h
│   │   │   │       └── hci_tr.h
│   │   │   ├── profiles
│   │   │   │   ├── anpc
│   │   │   │   │   ├── anpc_api.h
│   │   │   │   │   └── anpc_main.c
│   │   │   │   ├── bas
│   │   │   │   │   ├── bas_api.h
│   │   │   │   │   └── bas_main.c
│   │   │   │   ├── blpc
│   │   │   │   │   ├── blpc_api.h
│   │   │   │   │   └── blpc_main.c
│   │   │   │   ├── blps
│   │   │   │   │   ├── blps_api.h
│   │   │   │   │   └── blps_main.c
│   │   │   │   ├── cpp
│   │   │   │   │   ├── cpp_api.h
│   │   │   │   │   └── cpps_main.c
│   │   │   │   ├── cscp
│   │   │   │   │   ├── cscp_api.h
│   │   │   │   │   └── cscps_main.c
│   │   │   │   ├── dis
│   │   │   │   │   ├── dis_api.h
│   │   │   │   │   └── dis_main.c
│   │   │   │   ├── fmpl
│   │   │   │   │   ├── fmpl_api.h
│   │   │   │   │   └── fmpl_main.c
│   │   │   │   ├── gap
│   │   │   │   │   ├── gap_api.h
│   │   │   │   │   └── gap_main.c
│   │   │   │   ├── gatt
│   │   │   │   │   ├── gatt_api.h
│   │   │   │   │   └── gatt_main.c
│   │   │   │   ├── glpc
│   │   │   │   │   ├── glpc_api.h
│   │   │   │   │   └── glpc_main.c
│   │   │   │   ├── glps
│   │   │   │   │   ├── glps_api.h
│   │   │   │   │   ├── glps_db.c
│   │   │   │   │   ├── glps_main.c
│   │   │   │   │   └── glps_main.h
│   │   │   │   ├── hid
│   │   │   │   │   ├── hid_api.h
│   │   │   │   │   └── hid_main.c
│   │   │   │   ├── hrps
│   │   │   │   │   ├── hrps_api.h
│   │   │   │   │   └── hrps_main.c
│   │   │   │   ├── paspc
│   │   │   │   │   ├── paspc_api.h
│   │   │   │   │   └── paspc_main.c
│   │   │   │   ├── plxpc
│   │   │   │   │   ├── plxpc_api.h
│   │   │   │   │   └── plxpc_main.c
│   │   │   │   ├── plxps
│   │   │   │   │   ├── plxps_api.h
│   │   │   │   │   ├── plxps_db.c
│   │   │   │   │   ├── plxps_main.c
│   │   │   │   │   └── plxps_main.h
│   │   │   │   ├── rscp
│   │   │   │   │   ├── rscp_api.h
│   │   │   │   │   ├── rscps_main.c
│   │   │   │   │   └── tags
│   │   │   │   ├── scpps
│   │   │   │   │   ├── scpps_api.h
│   │   │   │   │   └── scpps_main.c
│   │   │   │   ├── tipc
│   │   │   │   │   ├── tipc_api.h
│   │   │   │   │   └── tipc_main.c
│   │   │   │   └── uribeacon
│   │   │   │       ├── uricfg_api.h
│   │   │   │       ├── uricfg_defs.h
│   │   │   │       └── uricfg_main.c
│   │   │   ├── sec
│   │   │   │   ├── common
│   │   │   │   │   ├── sec_aes.c
│   │   │   │   │   ├── sec_cmac.c
│   │   │   │   │   ├── sec_ecc_hci.c
│   │   │   │   │   ├── sec_main.c
│   │   │   │   │   └── sec_main.h
│   │   │   │   ├── include
│   │   │   │   │   └── sec_api.h
│   │   │   │   └── uecc
│   │   │   │       └── sec_ecc.c
│   │   │   ├── services
│   │   │   │   ├── svc_batt.c
│   │   │   │   ├── svc_batt.h
│   │   │   │   ├── svc_bps.c
│   │   │   │   ├── svc_bps.h
│   │   │   │   ├── svc_cfg.h
│   │   │   │   ├── svc_ch.h
│   │   │   │   ├── svc_core.c
│   │   │   │   ├── svc_core.h
│   │   │   │   ├── svc_cps.c
│   │   │   │   ├── svc_cps.h
│   │   │   │   ├── svc_cscs.c
│   │   │   │   ├── svc_cscs.h
│   │   │   │   ├── svc_dis.c
│   │   │   │   ├── svc_dis.h
│   │   │   │   ├── svc_gls.c
│   │   │   │   ├── svc_gls.h
│   │   │   │   ├── svc_gyro.c
│   │   │   │   ├── svc_gyro.h
│   │   │   │   ├── svc_hid.c
│   │   │   │   ├── svc_hid.h
│   │   │   │   ├── svc_hrs.c
│   │   │   │   ├── svc_hrs.h
│   │   │   │   ├── svc_hts.c
│   │   │   │   ├── svc_hts.h
│   │   │   │   ├── svc_ipss.c
│   │   │   │   ├── svc_ipss.h
│   │   │   │   ├── svc_plxs.c
│   │   │   │   ├── svc_plxs.h
│   │   │   │   ├── svc_px.c
│   │   │   │   ├── svc_px.h
│   │   │   │   ├── svc_rscs.c
│   │   │   │   ├── svc_rscs.h
│   │   │   │   ├── svc_scpss.c
│   │   │   │   ├── svc_scpss.h
│   │   │   │   ├── svc_temp.c
│   │   │   │   ├── svc_temp.h
│   │   │   │   ├── svc_uricfg.c
│   │   │   │   ├── svc_uricfg.h
│   │   │   │   ├── svc_wdxs.c
│   │   │   │   ├── svc_wdxs.h
│   │   │   │   ├── svc_wp.c
│   │   │   │   ├── svc_wp.h
│   │   │   │   ├── svc_wss.c
│   │   │   │   └── svc_wss.h
│   │   │   ├── stack
│   │   │   │   ├── cfg
│   │   │   │   │   ├── cfg_stack.c
│   │   │   │   │   └── cfg_stack.h
│   │   │   │   ├── hci
│   │   │   │   │   ├── hci_main.c
│   │   │   │   │   └── hci_main.h
│   │   │   │   └── include
│   │   │   │       ├── att_api.h
│   │   │   │       ├── att_defs.h
│   │   │   │       ├── att_handler.h
│   │   │   │       ├── att_uuid.h
│   │   │   │       ├── dm_api.h
│   │   │   │       ├── dm_handler.h
│   │   │   │       ├── hci_api.h
│   │   │   │       ├── hci_handler.h
│   │   │   │       ├── l2c_api.h
│   │   │   │       ├── l2c_defs.h
│   │   │   │       ├── l2c_handler.h
│   │   │   │       ├── smp_api.h
│   │   │   │       ├── smp_defs.h
│   │   │   │       ├── smp_handler.h
│   │   │   │       └── tags
│   │   │   └── udsc
│   │   │       ├── udsc_api.h
│   │   │       └── udsc_main.c
│   │   └── ws-core
│   │       ├── include
│   │       │   ├── hci_defs.h
│   │       │   └── ll_defs.h
│   │       ├── projects
│   │       │   └── common
│   │       │       ├── gcc
│   │       │       │   ├── build.mk
│   │       │       │   └── token.mk
│   │       │       └── token2header.py
│   │       └── sw
│   │           ├── util
│   │           │   ├── alternates
│   │           │   │   └── crc32_notable.c
│   │           │   ├── bda.c
│   │           │   ├── bda.h
│   │           │   ├── bstream.c
│   │           │   ├── bstream.h
│   │           │   ├── calc128.c
│   │           │   ├── calc128.h
│   │           │   ├── crc32.c
│   │           │   ├── crc32.h
│   │           │   ├── print.c
│   │           │   ├── print.h
│   │           │   ├── terminal.c
│   │           │   ├── terminal.h
│   │           │   ├── wstr.c
│   │           │   └── wstr.h
│   │           └── wsf
│   │               ├── ambiq
│   │               │   ├── wsf_assert.c
│   │               │   ├── wsf_assert.h
│   │               │   ├── wsf_cs.h
│   │               │   ├── wsf_intrinsic.h
│   │               │   ├── wsf_math.c
│   │               │   ├── wsf_os.c
│   │               │   ├── wsf_os_int.h
│   │               │   ├── wsf_trace.c
│   │               │   ├── wsf_trace.h
│   │               │   └── wsf_types.h
│   │               ├── common
│   │               │   ├── wsf_buf.c
│   │               │   ├── wsf_efs.c
│   │               │   ├── wsf_msg.c
│   │               │   ├── wsf_queue.c
│   │               │   └── wsf_timer.c
│   │               ├── generic
│   │               │   ├── wsf_assert.c
│   │               │   ├── wsf_assert.h
│   │               │   ├── wsf_cs.h
│   │               │   ├── wsf_intrinsic.h
│   │               │   ├── wsf_os.c
│   │               │   ├── wsf_os_int.h
│   │               │   ├── wsf_trace.c
│   │               │   ├── wsf_trace.h
│   │               │   └── wsf_types.h
│   │               └── include
│   │                   ├── wsf_buf.h
│   │                   ├── wsf_efs.h
│   │                   ├── wsf_math.h
│   │                   ├── wsf_msg.h
│   │                   ├── wsf_os.h
│   │                   ├── wsf_queue.h
│   │                   └── wsf_timer.h
│   ├── FreeRTOSv10.1.1
│   │   ├── License
│   │   │   └── license.txt
│   │   ├── readme.txt
│   │   └── Source
│   │       ├── croutine.c
│   │       ├── event_groups.c
│   │       ├── include
│   │       │   ├── croutine.h
│   │       │   ├── deprecated_definitions.h
│   │       │   ├── event_groups.h
│   │       │   ├── FreeRTOS.h
│   │       │   ├── list.h
│   │       │   ├── message_buffer.h
│   │       │   ├── mpu_prototypes.h
│   │       │   ├── mpu_wrappers.h
│   │       │   ├── portable.h
│   │       │   ├── projdefs.h
│   │       │   ├── queue.h
│   │       │   ├── semphr.h
│   │       │   ├── stack_macros.h
│   │       │   ├── StackMacros.h
│   │       │   ├── stdint.readme
│   │       │   ├── stream_buffer.h
│   │       │   ├── task.h
│   │       │   └── timers.h
│   │       ├── list.c
│   │       ├── portable
│   │       │   ├── Common
│   │       │   │   └── mpu_wrappers.c
│   │       │   ├── GCC
│   │       │   │   ├── AMapollo
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   ├── AMapollo2
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   └── ARM_CM4F
│   │       │   │       ├── port.c
│   │       │   │       └── portmacro.h
│   │       │   ├── IAR
│   │       │   │   ├── AMapollo
│   │       │   │   │   ├── portasm.s
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   ├── AMapollo2
│   │       │   │   │   ├── portasm.s
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   └── ARM_CM4F
│   │       │   │       ├── portasm.s
│   │       │   │       ├── port.c
│   │       │   │       └── portmacro.h
│   │       │   ├── Keil
│   │       │   │   ├── AMapollo
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   ├── AMapollo2
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   └── ARM_CM4F
│   │       │   │       ├── port.c
│   │       │   │       └── portmacro.h
│   │       │   ├── Keil6
│   │       │   │   ├── AMapollo
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   ├── AMapollo2
│   │       │   │   │   ├── port.c
│   │       │   │   │   └── portmacro.h
│   │       │   │   └── ARM_CM4F
│   │       │   │       ├── port.c
│   │       │   │       └── portmacro.h
│   │       │   ├── MemMang
│   │       │   │   ├── heap_1.c
│   │       │   │   ├── heap_2.c
│   │       │   │   ├── heap_3.c
│   │       │   │   ├── heap_4.c
│   │       │   │   ├── heap_5.c
│   │       │   │   └── ReadMe.url
│   │       │   └── readme.txt
│   │       ├── queue.c
│   │       ├── readme.txt
│   │       ├── stream_buffer.c
│   │       ├── tasks.c
│   │       └── timers.c
│   ├── Makefile
│   ├── micro-ecc
│   │   ├── asm_arm.inc
│   │   ├── asm_arm_mult_square.inc
│   │   ├── asm_arm_mult_square_umaal.inc
│   │   ├── asm_avr.inc
│   │   ├── asm_avr_mult_square.inc
│   │   ├── curve-specific.inc
│   │   ├── emk_project.py
│   │   ├── emk_rules.py
│   │   ├── examples
│   │   │   └── ecc_test
│   │   │       └── ecc_test.ino
│   │   ├── library.properties
│   │   ├── LICENSE.txt
│   │   ├── platform-specific.inc
│   │   ├── README.md
│   │   ├── scripts
│   │   │   ├── mult_arm.py
│   │   │   ├── mult_avr_extra.py
│   │   │   ├── mult_avr.py
│   │   │   ├── square_arm.py
│   │   │   └── square_avr.py
│   │   ├── test
│   │   │   ├── emk_rules.py
│   │   │   ├── test_compress.c
│   │   │   ├── test_compute.c
│   │   │   ├── test_ecdh.c
│   │   │   ├── test_ecdsa.c
│   │   │   └── test_ecdsa_deterministic.c.example
│   │   ├── types.h
│   │   ├── uECC.c
│   │   ├── uECC.h
│   │   └── uECC_vli.h
│   └── uecc
│       ├── gcc
│       │   ├── bin
│       │   │   └── lib_uecc.a
│       │   └── Makefile
│       ├── iar
│       │   ├── bin
│       │   │   └── lib_uecc.a
│       │   ├── lib_uecc.dep
│       │   ├── lib_uecc.ewd
│       │   ├── lib_uecc.ewp
│       │   ├── lib_uecc.eww
│       │   └── Makefile
│       ├── keil
│       │   ├── bin
│       │   │   └── lib_uecc.lib
│       │   └── Makefile
│       ├── license.txt
│       ├── Makefile
│       └── micro-ecc
│           ├── asm_arm.inc
│           ├── asm_arm_mult_square.inc
│           ├── asm_arm_mult_square_umaal.inc
│           ├── asm_avr.inc
│           ├── asm_avr_mult_square.inc
│           ├── curve-specific.inc
│           ├── emk_project.py
│           ├── emk_rules.py
│           ├── examples
│           │   └── ecc_test
│           │       └── ecc_test.ino
│           ├── library.properties
│           ├── LICENSE.txt
│           ├── platform-specific.inc
│           ├── README.md
│           ├── scripts
│           │   ├── mult_arm.py
│           │   ├── mult_avr_extra.py
│           │   ├── mult_avr.py
│           │   ├── square_arm.py
│           │   └── square_avr.py
│           ├── test
│           │   ├── emk_rules.py
│           │   ├── test_compress.c
│           │   ├── test_compute.c
│           │   ├── test_ecdh.c
│           │   ├── test_ecdsa.c
│           │   └── test_ecdsa_deterministic.c.example
│           ├── types.h
│           ├── uECC.c
│           ├── uECC.h
│           └── uECC_vli.h
├── tools
│   ├── amota
│   │   ├── Application-debug.apk
│   │   └── scripts
│   │       ├── bootloader_binary_combiner.py
│   │       ├── Makefile
│   │       └── ota_binary_converter.py
│   ├── apollo3_amota
│   │   ├── Application-debug.apk
│   │   └── scripts
│   │       ├── Makefile
│   │       └── ota_binary_converter.py
│   ├── apollo3_scripts
│   │   ├── am_defines.py
│   │   ├── create_cust_image_blob.py
│   │   ├── create_cust_wireupdate_blob.py
│   │   ├── create_info0.py
│   │   ├── create_info_keys.py
│   │   ├── jlink-prog-info0.txt
│   │   ├── jlink-prog-sbl.txt
│   │   ├── jlink-read-info0.txt
│   │   ├── keys_info0.py
│   │   ├── keys_info.py
│   │   ├── program_info0.bat
│   │   ├── __pycache__
│   │   │   ├── am_defines.cpython-36.pyc
│   │   │   └── keys_info.cpython-36.pyc
│   │   ├── sbl_updates
│   │   │   ├── history.txt
│   │   │   ├── sbl_v2_3_93e8.bin
│   │   │   └── sbl_v3_4_994c.bin
│   │   ├── uart_wired_update.py
│   │   └── verify_info0.bat
│   ├── bootloader_scripts
│   │   ├── generate_ota_descriptor.py
│   │   └── uart_boot_host.py
│   ├── bsp_generator
│   │   ├── pinconfig.py
│   │   ├── __pycache__
│   │   │   └── rsonlite.cpython-36.pyc
│   │   └── rsonlite.py
│   ├── emp2include
│   │   ├── 0000000_META_hci_patches_v8.emp
│   │   ├── data_length_extension.emp
│   │   ├── disable_pull-up_em_gpio10.emp
│   │   ├── disable_pull-up_em_gpio11.emp
│   │   ├── eight_connections.emp
│   │   ├── emp2include.py
│   │   ├── PATCHES.txt
│   │   ├── README.txt
│   │   ├── sleep_clk_src_apollo.emp
│   │   └── updateCRC.py
│   ├── keil_supplemental
│   │   ├── AmbiqMicro.Apollo_DFP.0.1.2.pack
│   │   └── Makefile
│   └── Makefile
└── utils
    ├── am_util_ble.c
    ├── am_util_ble.h
    ├── am_util_debug.c
    ├── am_util_debug.h
    ├── am_util_delay.c
    ├── am_util_delay.h
    ├── am_util_faultisr.c
    ├── am_util.h
    ├── am_util_id.c
    ├── am_util_id.h
    ├── am_util_regdump.c
    ├── am_util_regdump.h
    ├── am_util_stdio.c
    ├── am_util_stdio.h
    ├── am_util_string.c
    ├── am_util_string.h
    ├── am_util_time.c
    └── am_util_time.h

162 directories, 603 files
