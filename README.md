# hid-imu
9DOF I2C inertial measurement unit (IMU) with USB HID on Atmega32u4 for Windows

This application reads 3D accelerometer, 3D gyrometer and 3D magnetometer using a Sparkfun SEN-10724 board through I2C, calculates orientation and inclinometer from the nine measurements and sends the values to Windows 10 built-in sensor HID class driver through USB.

## Project state

The current version only includes a 3D accelerometer that transmits the constant values X = 0.5, Y = 1.0, Z = -0.5. A future version will also include the 3D gyrometer and 3D magnometer and will read the measurements from the Sparkfun SEN-10724 board through I2C.

## Building

1. Compile using [Atmel Studio 7](http://www.atmel.com/Microsite/atmel-studio/)
2. Transfer .hex file to [Teensy 2.0](https://www.pjrc.com/store/teensy.html) using [Teensy Loader](https://www.pjrc.com/teensy/loader.html)

## Testing

1. Connect a USB cable between the computer and the Teensy 2.0. The sensor devices should automatically load the built-in Windows 10 drivers and appear in the device manager.
2. Open a Windows Store application such as [SensorInfo](https://www.microsoft.com/en-us/store/p/sensorinfo/9wzdncrfjqwf) or [Sensor List](https://www.microsoft.com/en-us/store/p/sensor-list/9wzdncrdktf9) to display a list of sensors and their readings.

## USB Vendor ID and Product ID

Planning to use a Vendor ID and Product ID provided by pid.codes. 

The code currently uses VID and PID from a LUFA demo. This VID/PID combination is not universally unique and MUST NOT be used on any device that will be redistributed, sold, or manufactured.

## Dependencies

The project uses the [LUFA library](https://github.com/abcminiuser/lufa) for usb communication.

## References

**Microsoft**

hid-imu uses the HID descriptors from WDK 8.0 Sensors HID sample driver hid_sensor_spec_macros.h and hid_sensor_spec_report_descriptors.h files.

* [Built-in drivers for other devices - Sensors: Sensor HID class driver](https://msdn.microsoft.com/en-us/library/windows/hardware/dn449736.aspx)
* [Integrating Motion and Orientation Sensors](https://msdn.microsoft.com/en-us/library/windows/hardware/dn642102%28v=vs.85%29.aspx)
* [HID Sensors Usages](https://msdn.microsoft.com/en-us/library/windows/hardware/dn613934%28v=vs.85%29.aspx)
* [Windows Driver Kit (WDK) 8.0 Samples - Sensors HID sample driver](https://code.msdn.microsoft.com/windowsapps/Windows-Driver-Kit-WDK-80-e3161626)

**USB Implementers Forum**

* [HID Information](http://www.usb.org/developers/hidpage/)
* [Device Class Definition for HID 1.11](http://www.usb.org/developers/hidpage/HID1_11.pdf)
* [HID Usage Tables 1.12](http://www.usb.org/developers/hidpage/Hut1_12v2.pdf)
* [HID Usage Table Sensor Page](http://www.usb.org/developers/hidpage/HUTRR39b.pdf)
* [Sensor Page Usages for Wearables](http://www.usb.org/developers/hidpage/HUTRR59_-_Usages_for_Wearables.pdf)

**PJRC - Teensy**

* [Pin Assignments](https://www.pjrc.comd/teensy/pinout.html)
* [Schematic](https://www.pjrc.com/teensy/schematic.html)
* [Dimensions](https://www.pjrc.com/teensy/dimensions.html)
* [Datasheets](https://www.pjrc.com/teensy/datasheets.html)
