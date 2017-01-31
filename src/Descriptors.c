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
 *  USB Device Descriptors, for library use when in USB device mode. Descriptors are special
 *  computer-readable structures which the host requests upon device enumeration, to determine
 *  the device's capabilities and functions.
 */

#include "Descriptors.h"
#include "hid_sensor_spec_macros.h"

/** HID class report descriptor. This is a special descriptor constructed with values from the
 *  USBIF HID class specification to describe the reports and capabilities of the HID device. This
 *  descriptor is parsed by the host and its contents used to determine what data (and in what encoding)
 *  the device will send, and what it may be sent back from the host. Refer to the HID specification for
 *  more details on HID report descriptors.
 */
const USB_Descriptor_HIDReport_Datatype_t PROGMEM GenericReport[] =
{
   // 3D Accelerometer
   HID_USAGE_PAGE_SENSOR,
   HID_USAGE_SENSOR_TYPE_MOTION_ACCELEROMETER_3D,
   HID_COLLECTION(Physical),
   
   //feature reports (xmit/receive)
   HID_USAGE_PAGE_SENSOR,
   
   HID_USAGE_SENSOR_PROPERTY_SENSOR_CONNECTION_TYPE,  // NAry
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_8(2),
   HID_REPORT_SIZE(8),
   HID_REPORT_COUNT(1),
   HID_COLLECTION(Logical),
   HID_USAGE_SENSOR_PROPERTY_CONNECTION_TYPE_PC_INTEGRATED_SEL,
   HID_USAGE_SENSOR_PROPERTY_CONNECTION_TYPE_PC_ATTACHED_SEL,
   HID_USAGE_SENSOR_PROPERTY_CONNECTION_TYPE_PC_EXTERNAL_SEL,
   HID_FEATURE(Data_Arr_Abs),
   HID_END_COLLECTION,

   HID_USAGE_SENSOR_PROPERTY_REPORTING_STATE,
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_8(5),
   HID_REPORT_SIZE(8),
   HID_REPORT_COUNT(1),
   HID_COLLECTION(Logical),
   HID_USAGE_SENSOR_PROPERTY_REPORTING_STATE_NO_EVENTS_SEL,
   HID_USAGE_SENSOR_PROPERTY_REPORTING_STATE_ALL_EVENTS_SEL,
   HID_USAGE_SENSOR_PROPERTY_REPORTING_STATE_THRESHOLD_EVENTS_SEL,
   HID_USAGE_SENSOR_PROPERTY_REPORTING_STATE_NO_EVENTS_WAKE_SEL,
   HID_USAGE_SENSOR_PROPERTY_REPORTING_STATE_ALL_EVENTS_WAKE_SEL,
   HID_USAGE_SENSOR_PROPERTY_REPORTING_STATE_THRESHOLD_EVENTS_WAKE_SEL,
   HID_FEATURE(Data_Arr_Abs),
   HID_END_COLLECTION,

   HID_USAGE_SENSOR_PROPERTY_POWER_STATE,
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_8(5),
   HID_REPORT_SIZE(8),
   HID_REPORT_COUNT(1),
   HID_COLLECTION(Logical),
   HID_USAGE_SENSOR_PROPERTY_POWER_STATE_UNDEFINED_SEL,
   HID_USAGE_SENSOR_PROPERTY_POWER_STATE_D0_FULL_POWER_SEL,
   HID_USAGE_SENSOR_PROPERTY_POWER_STATE_D1_LOW_POWER_SEL,
   HID_USAGE_SENSOR_PROPERTY_POWER_STATE_D2_STANDBY_WITH_WAKE_SEL,
   HID_USAGE_SENSOR_PROPERTY_POWER_STATE_D3_SLEEP_WITH_WAKE_SEL,
   HID_USAGE_SENSOR_PROPERTY_POWER_STATE_D4_POWER_OFF_SEL,
   HID_FEATURE(Data_Arr_Abs),
   HID_END_COLLECTION,

   HID_USAGE_SENSOR_STATE,
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_8(6),
   HID_REPORT_SIZE(8),
   HID_REPORT_COUNT(1),
   HID_COLLECTION(Logical),
   HID_USAGE_SENSOR_STATE_UNKNOWN_SEL,
   HID_USAGE_SENSOR_STATE_READY_SEL,
   HID_USAGE_SENSOR_STATE_NOT_AVAILABLE_SEL,
   HID_USAGE_SENSOR_STATE_NO_DATA_SEL,
   HID_USAGE_SENSOR_STATE_INITIALIZING_SEL,
   HID_USAGE_SENSOR_STATE_ACCESS_DENIED_SEL,
   HID_USAGE_SENSOR_STATE_ERROR_SEL,
   HID_FEATURE(Data_Arr_Abs),
   HID_END_COLLECTION,

   HID_USAGE_SENSOR_PROPERTY_REPORT_INTERVAL,
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_32(0xFF,0xFF,0xFF,0xFF),
   HID_REPORT_SIZE(32),
   HID_REPORT_COUNT(1),
   HID_UNIT_EXPONENT(0),
   HID_FEATURE(Data_Var_Abs),

   HID_USAGE_SENSOR_DATA(HID_USAGE_SENSOR_DATA_MOTION_ACCELERATION,HID_USAGE_SENSOR_DATA_MOD_CHANGE_SENSITIVITY_ABS),
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_16(0xFF,0xFF),
   HID_REPORT_SIZE(16),
   HID_REPORT_COUNT(1),
   HID_UNIT_EXPONENT(0x0E),  // scale default unit Gs to “centi-Gs” to provide 2 digits past Gs decimal point
   HID_FEATURE(Data_Var_Abs),

   HID_USAGE_SENSOR_DATA(HID_USAGE_SENSOR_DATA_MOTION_ACCELERATION,HID_USAGE_SENSOR_DATA_MOD_MAX),
   HID_LOGICAL_MIN_16(0x01,0x80), //    LOGICAL_MINIMUM (-32767)
   HID_LOGICAL_MAX_16(0xFF,0x7F), //    LOGICAL_MAXIMUM (32767)
   HID_REPORT_SIZE(16),
   HID_REPORT_COUNT(1),
   HID_UNIT_EXPONENT(0x0E),  // scale default unit Gs to “centi-Gs” to provide 2 digits past Gs decimal point
   HID_FEATURE(Data_Var_Abs),

   HID_USAGE_SENSOR_DATA(HID_USAGE_SENSOR_DATA_MOTION_ACCELERATION,HID_USAGE_SENSOR_DATA_MOD_MIN),
   HID_LOGICAL_MIN_16(0x01,0x80), //    LOGICAL_MINIMUM (-32767)
   HID_LOGICAL_MAX_16(0xFF,0x7F), //    LOGICAL_MAXIMUM (32767)
   HID_REPORT_SIZE(16),
   HID_REPORT_COUNT(1),
   HID_UNIT_EXPONENT(0x0E),  // scale default unit Gs to “centi-Gs” to provide 2 digits past Gs decimal point
   HID_FEATURE(Data_Var_Abs),
   
   //input reports (transmit)
   HID_USAGE_PAGE_SENSOR,
   HID_USAGE_SENSOR_STATE,
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_8(6),
   HID_REPORT_SIZE(8),
   HID_REPORT_COUNT(1),
   HID_COLLECTION(Logical),
   HID_USAGE_SENSOR_STATE_UNKNOWN_SEL,
   HID_USAGE_SENSOR_STATE_READY_SEL,
   HID_USAGE_SENSOR_STATE_NOT_AVAILABLE_SEL,
   HID_USAGE_SENSOR_STATE_NO_DATA_SEL,
   HID_USAGE_SENSOR_STATE_INITIALIZING_SEL,
   HID_USAGE_SENSOR_STATE_ACCESS_DENIED_SEL,
   HID_USAGE_SENSOR_STATE_ERROR_SEL,
   HID_INPUT(Data_Arr_Abs),
   HID_END_COLLECTION,

   HID_USAGE_SENSOR_EVENT,
   HID_LOGICAL_MIN_8(0),
   HID_LOGICAL_MAX_8(5),
   HID_REPORT_SIZE(8),
   HID_REPORT_COUNT(1),
   HID_COLLECTION(Logical),
   HID_USAGE_SENSOR_EVENT_UNKNOWN_SEL,
   HID_USAGE_SENSOR_EVENT_STATE_CHANGED_SEL,
   HID_USAGE_SENSOR_EVENT_PROPERTY_CHANGED_SEL,
   HID_USAGE_SENSOR_EVENT_DATA_UPDATED_SEL,
   HID_USAGE_SENSOR_EVENT_POLL_RESPONSE_SEL,
   HID_USAGE_SENSOR_EVENT_CHANGE_SENSITIVITY_SEL,
   HID_INPUT(Data_Arr_Abs),
   HID_END_COLLECTION,

   HID_USAGE_SENSOR_DATA_MOTION_ACCELERATION_X_AXIS,
   HID_LOGICAL_MIN_16(0x01,0x80), //    LOGICAL_MINIMUM (-32767)
   HID_LOGICAL_MAX_16(0xFF,0x7F), //    LOGICAL_MAXIMUM (32767)
   HID_REPORT_SIZE(16),
   HID_REPORT_COUNT(1),
   HID_UNIT_EXPONENT(0x0E),  // scale default unit Gs to “centi-Gs” to provide 2 digits past Gs decimal point
   HID_INPUT(Data_Var_Abs),
   HID_USAGE_SENSOR_DATA_MOTION_ACCELERATION_Y_AXIS,
   HID_LOGICAL_MIN_16(0x01,0x80), //    LOGICAL_MINIMUM (-32767)
   HID_LOGICAL_MAX_16(0xFF,0x7F), //    LOGICAL_MAXIMUM (32767)
   HID_REPORT_SIZE(16),
   HID_REPORT_COUNT(1),
   HID_UNIT_EXPONENT(0x0E),  // scale default unit Gs to “centi-Gs” to provide 2 digits past Gs decimal point
   HID_INPUT(Data_Var_Abs),
   HID_USAGE_SENSOR_DATA_MOTION_ACCELERATION_Z_AXIS,
   HID_LOGICAL_MIN_16(0x01,0x80), //    LOGICAL_MINIMUM (-32767)
   HID_LOGICAL_MAX_16(0xFF,0x7F), //    LOGICAL_MAXIMUM (32767)
   HID_REPORT_SIZE(16),
   HID_REPORT_COUNT(1),
   HID_UNIT_EXPONENT(0x0E),  // scale default unit Gs to “centi-Gs” to provide 2 digits past Gs decimal point
   HID_INPUT(Data_Var_Abs),

   //include the following datafield if required to support the “shake” event
   //HID_USAGE_SENSOR_DATA_MOTION_STATE,
   //HID_LOGICAL_MIN_8(0), // False = Still
   //HID_LOGICAL_MAX_8(1), // True = In Motion
   //HID_REPORT_SIZE(8),
   //HID_REPORT_COUNT(1),
   //HID_INPUT(Data_Var_Abs),

   HID_END_COLLECTION
};

/** Device descriptor structure. This descriptor, located in FLASH memory, describes the overall
 *  device characteristics, including the supported USB version, control endpoint size and the
 *  number of device configurations. The descriptor is read out by the USB host when the enumeration
 *  process begins.
 */
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

	.USBSpecification       = VERSION_BCD(1,1,0),
	.Class                  = USB_CSCP_NoDeviceClass,
	.SubClass               = USB_CSCP_NoDeviceSubclass,
	.Protocol               = USB_CSCP_NoDeviceProtocol,

	.Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

	.VendorID               = 0x03EB,
	.ProductID              = 0x204F,
	.ReleaseNumber          = VERSION_BCD(0,0,1),

	.ManufacturerStrIndex   = STRING_ID_Manufacturer,
	.ProductStrIndex        = STRING_ID_Product,
	.SerialNumStrIndex      = NO_DESCRIPTOR,

	.NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

/** Configuration descriptor structure. This descriptor, located in FLASH memory, describes the usage
 *  of the device in one of its supported configurations, including information about any device interfaces
 *  and endpoints. The descriptor is read out by the USB host during the enumeration process when selecting
 *  a configuration so that the host may correctly communicate with the USB device.
 */
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
	.Config =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},

			.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
			.TotalInterfaces        = 1,

			.ConfigurationNumber    = 1,
			.ConfigurationStrIndex  = NO_DESCRIPTOR,

			.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_SELFPOWERED),

			.MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
		},

	.HID_Interface =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

			.InterfaceNumber        = INTERFACE_ID_GenericHID,
			.AlternateSetting       = 0x00,

			.TotalEndpoints         = 1,

			.Class                  = HID_CSCP_HIDClass,
			.SubClass               = HID_CSCP_NonBootSubclass,
			.Protocol               = HID_CSCP_NonBootProtocol,

			.InterfaceStrIndex      = NO_DESCRIPTOR
		},

	.HID_GenericHID =
		{
			.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

			.HIDSpec                = VERSION_BCD(1,1,1),
			.CountryCode            = 0x00,
			.TotalReportDescriptors = 1,
			.HIDReportType          = HID_DTYPE_Report,
			.HIDReportLength        = sizeof(GenericReport)
		},

	.HID_ReportINEndpoint =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

			.EndpointAddress        = GENERIC_IN_EPADDR,
			.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
			.EndpointSize           = GENERIC_EPSIZE,
			.PollingIntervalMS      = 0x05
		},
};

/** Language descriptor structure. This descriptor, located in FLASH memory, is returned when the host requests
 *  the string descriptor with index 0 (the first index). It is actually an array of 16-bit integers, which indicate
 *  via the language ID table available at USB.org what languages the device supports for its string descriptors.
 */
const USB_Descriptor_String_t PROGMEM LanguageString = USB_STRING_DESCRIPTOR_ARRAY(LANGUAGE_ID_ENG);

/** Manufacturer descriptor string. This is a Unicode string containing the manufacturer's details in human readable
 *  form, and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ManufacturerString = USB_STRING_DESCRIPTOR(L"Dean Camera");

/** Product descriptor string. This is a Unicode string containing the product's details in human readable form,
 *  and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ProductString = USB_STRING_DESCRIPTOR(L"LUFA Generic HID Demo");

/** This function is called by the library when in device mode, and must be overridden (see library "USB Descriptors"
 *  documentation) by the application code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on the control endpoint, this function
 *  is called so that the descriptor details can be passed back and the appropriate descriptor sent back to the
 *  USB host.
 */
uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
{
	const uint8_t  DescriptorType   = (wValue >> 8);
	const uint8_t  DescriptorNumber = (wValue & 0xFF);

	const void* Address = NULL;
	uint16_t    Size    = NO_DESCRIPTOR;

	switch (DescriptorType)
	{
		case DTYPE_Device:
			Address = &DeviceDescriptor;
			Size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			Address = &ConfigurationDescriptor;
			Size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (DescriptorNumber)
			{
				case STRING_ID_Language:
					Address = &LanguageString;
					Size    = pgm_read_byte(&LanguageString.Header.Size);
					break;
				case STRING_ID_Manufacturer:
					Address = &ManufacturerString;
					Size    = pgm_read_byte(&ManufacturerString.Header.Size);
					break;
				case STRING_ID_Product:
					Address = &ProductString;
					Size    = pgm_read_byte(&ProductString.Header.Size);
					break;
			}

			break;
		case HID_DTYPE_HID:
			Address = &ConfigurationDescriptor.HID_GenericHID;
			Size    = sizeof(USB_HID_Descriptor_HID_t);
			break;
		case HID_DTYPE_Report:
			Address = &GenericReport;
			Size    = sizeof(GenericReport);
			break;
	}

	*DescriptorAddress = Address;
	return Size;
}

