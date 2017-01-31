/*
             LUFA Library
     Copyright (C) Dean Camera, 2015.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2015  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for GenericHID.c.
 */

#ifndef _GENERICHID_H_
#define _GENERICHID_H_

	/* Includes: */
		#include <avr/io.h>
		#include <avr/wdt.h>
		#include <avr/power.h>
		#include <avr/interrupt.h>
		#include <string.h>

		#include "Descriptors.h"
		#include "Config/AppConfig.h"

		#include "LUFA/Drivers/Board/LEDs.h"
		#include "LUFA/Drivers/USB/USB.h"
		#include "LUFA/Platform/Platform.h"

   /* Type Defines: */
		/** Type define for the HID report structure, for creating and sending HID reports to the host PC.
		 *  This mirrors the layout described to the host in the HID report descriptor, in Descriptors.c.
		 */
		typedef struct
		{
         uint8_t sensor_property_sensor_connection_type;
         uint8_t sensor_property_reporting_state;
         uint8_t sensor_property_power_state;
         uint8_t sensor_state;
         uint32_t sensor_property_report_interval;
         uint16_t sensor_date_motion_acceleration_mod_change_sensitivity_abs;
         int16_t sensor_date_motion_acceleration_mod_max;
         int16_t sensor_date_motion_acceleration_mod_min;
		} USB_FeatureReport_Data_t;

      typedef struct
      {
         uint8_t sensor_state;
         uint8_t sensor_event;
         int16_t sensor_data_motion_acceleration_x_axis;
         int16_t sensor_data_motion_acceleration_y_axis;
         int16_t sensor_data_motion_acceleration_z_axis;
         //uint8_t sensor_data_motion_state;
      } USB_InputReport_Data_t;

	/* Macros: */
		/** LED mask for the library LED driver, to indicate that the USB interface is not ready. */
		#define LEDMASK_USB_NOTREADY      LEDS_LED1

		/** LED mask for the library LED driver, to indicate that the USB interface is enumerating. */
		#define LEDMASK_USB_ENUMERATING  (LEDS_LED2 | LEDS_LED3)

		/** LED mask for the library LED driver, to indicate that the USB interface is ready. */
		#define LEDMASK_USB_READY        (LEDS_LED2 | LEDS_LED4)

		/** LED mask for the library LED driver, to indicate that an error has occurred in the USB interface. */
		#define LEDMASK_USB_ERROR        (LEDS_LED1 | LEDS_LED3)

   /* Enums: */
      enum Sensor_Property_Sensor_Connection_Type
      {
         SENSOR_PROPERTY_CONNECTION_TYPE_PC_INTEGRATED_SEL  = 1,
         SENSOR_PROPERTY_CONNECTION_TYPE_PC_ATTACHED_SEL = 2,
         SENSOR_PROPERTY_CONNECTION_TYPE_PC_EXTERNAL_SEL = 3,
      };

      enum Sensor_Property_Reporting_State
      {
         SENSOR_PROPERTY_REPORTING_STATE_NO_EVENTS_SEL = 1,
         SENSOR_PROPERTY_REPORTING_STATE_ALL_EVENTS_SEL = 2,
         SENSOR_PROPERTY_REPORTING_STATE_THRESHOLD_EVENTS_SEL = 3,
         SENSOR_PROPERTY_REPORTING_STATE_NO_EVENTS_WAKE_SEL = 4,
         SENSOR_PROPERTY_REPORTING_STATE_ALL_EVENTS_WAKE_SEL = 5,
         SENSOR_PROPERTY_REPORTING_STATE_THRESHOLD_EVENTS_WAKE_SEL = 6,
      };

      enum Sensor_Property_Power_State
      {
         SENSOR_PROPERTY_POWER_STATE_UNDEFINED_SEL = 1,
         SENSOR_PROPERTY_POWER_STATE_D0_FULL_POWER_SEL = 2,
         SENSOR_PROPERTY_POWER_STATE_D1_LOW_POWER_SEL = 3,
         SENSOR_PROPERTY_POWER_STATE_D2_STANDBY_WITH_WAKE_SEL = 4,
         SENSOR_PROPERTY_POWER_STATE_D3_SLEEP_WITH_WAKE_SEL = 5,
         SENSOR_PROPERTY_POWER_STATE_D4_POWER_OFF_SEL = 6,
      };

      enum Sensor_State
      {
         SENSOR_STATE_UNKNOWN_SEL = 1,
         SENSOR_STATE_READY_SEL = 2,
         SENSOR_STATE_NOT_AVAILABLE_SEL = 3,
         SENSOR_STATE_NO_DATA_SEL = 4,
         SENSOR_STATE_INITIALIZING_SEL = 5,
         SENSOR_STATE_ACCESS_DENIED_SEL = 6,
         SENSOR_STATE_ERROR_SEL = 7,
      };

      enum Sensor_Event
      {
         SENSOR_EVENT_UNKNOWN_SEL = 1,
         SENSOR_EVENT_STATE_CHANGED_SEL = 2,
         SENSOR_EVENT_PROPERTY_CHANGED_SEL = 3,
         SENSOR_EVENT_DATA_UPDATED_SEL = 4,
         SENSOR_EVENT_POLL_RESPONSE_SEL = 5,
         SENSOR_EVENT_CHANGE_SENSITIVITY_SEL = 6,
      };

 
	/* Function Prototypes: */
		void SetupHardware(void);

		void EVENT_USB_Device_Connect(void);
		void EVENT_USB_Device_Disconnect(void);
		void EVENT_USB_Device_ConfigurationChanged(void);
		void EVENT_USB_Device_ControlRequest(void);
		void EVENT_USB_Device_StartOfFrame(void);

		bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
		                                         uint8_t* const ReportID,
		                                         const uint8_t ReportType,
		                                         void* ReportData,
		                                         uint16_t* const ReportSize);
		void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
		                                          const uint8_t ReportID,
		                                          const uint8_t ReportType,
		                                          const void* ReportData,
		                                          const uint16_t ReportSize);

#endif

