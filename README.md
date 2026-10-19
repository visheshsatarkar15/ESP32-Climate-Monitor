# ESP32 Environmental Monitoring System 

An IoT-based environmental monitoring project built using an ESP32 DevKit V1, DHT22 temperature and humidity sensor, capacitive soil moisture sensor, and Arduino IoT Cloud.

The system measures ambient temperature, relative humidity, and raw soil moisture sensor readings. Temperature and humidity are published to Arduino IoT Cloud, while soil sensor readings are currently available through the Serial Monitor.

## Features

-  Real-time temperature monitoring in °C
-  Relative humidity monitoring in %
-  Capacitive soil moisture sensor integration
-  Arduino IoT Cloud connectivity
-  Cloud-based temperature and humidity visualization
-  Analog sensor readings using the ESP32 ADC
-  Serial Monitor output for debugging
-  Periodic sensor readings every 2.5 seconds

## Hardware Requirements

- ESP32 DevKit V1
- DHT22 temperature and humidity sensor breakout
- Capacitive soil moisture sensor with analog output
- Jumper wires
- USB data cable
- Wi-Fi connection

## Wiring

DHT22 SENSOR VCC - ESP32 3V3
DHT22 SENSOR GND - ESP32 GND
DHT22 SENSOR DATA - ESP32 GPIO 4

MOISTURE SENSOR VCC - ESP32 3V3
MOISTURE SENSOR GND - ESP32 GND
MOISTURE SENSOR AOUT - ESP32 GPIO 13

Note - Both sensors share the ESP32's 3.3 V and GND connections. Ensure the connections are secure and the combined current is within the board's power capacity. Never allow the soil sensor's analog output to exceed the ESP32's permitted input voltage.

## Software and Libraries

- Arduino IDE or Arduino Cloud Editor
- Arduino IoT Cloud
- Adafruit DHT sensor library
- Adafruit Unified Sensor library
- ESP32 Arduino core

## How It Works

1. The DHT22 measures ambient temperature and relative humidity.
2. The capacitive soil moisture sensor produces an analog voltage corresponding to the surrounding soil conditions.
3. The ESP32 reads the analog signal through GPIO 13 using its ADC.
4. The firmware periodically collects sensor readings.
5. Temperature and humidity values are sent to Arduino IoT Cloud.
6. Soil sensor raw readings are printed to the Serial Monitor for testing and calibration.

## Arduino IoT Cloud Setup

1. Create an ESP32 device in Arduino IoT Cloud.
2. Create a Thing and associate it with the device.
3. Add the following cloud variables:

   - `Temperature` — floating-point value
   - `Humidity` — floating-point value

4. Configure the device's Wi-Fi connection and credentials locally.
5. Upload the firmware to the ESP32.
6. Create dashboard widgets and link them to the cloud variables.
7. Open the Serial Monitor at 115200 baud to inspect sensor readings.

## Soil Moisture Calibration

The capacitive soil moisture sensor initially provides a raw ADC reading rather than a calibrated moisture percentage.

To estimate soil moisture:

1. Record the sensor reading in air or dry conditions.
2. Record readings in dry soil.
3. Record readings in moist soil.
4. Use the observed values to establish suitable calibration endpoints.

Sensor readings vary by model, soil composition, temperature, and water content. Calibration is required before converting raw readings into a meaningful percentage.

## Current Project Status

- [x] ESP32 and DHT22 integration
- [x] Temperature and humidity readings
- [x] Arduino IoT Cloud integration for temperature and humidity
- [x] Capacitive soil moisture sensor connection
- [x] Raw soil sensor readings through Serial Monitor
- [ ] Soil moisture calibration
- [ ] Soil moisture percentage calculation
- [ ] Soil moisture cloud variable and dashboard widget

## Security

Never publish:

- Wi-Fi passwords
- Arduino IoT Cloud device secrets
- Authentication tokens
- Private credentials or personal connection details

Keep actual credentials in local configuration files. Publish only sanitized code and configuration examples.

If credentials are accidentally exposed in a public repository, rotate them immediately. Deleting a file alone may not remove its contents from Git history.

## Future Improvements

- Display soil moisture readings on Arduino IoT Cloud
- Calibrate raw readings into an estimated moisture percentage
- Add historical charts for all three measurements
- Implement configurable temperature and soil moisture alerts
- Add data logging and trend analysis
- Explore automated plant watering using a suitable pump and driver circuit

## Technologies Used

ESP32 C++ DHT22 Capacitive Soil Moisture Sensor Arduino IoT Cloud Embedded Systems IoT

## Author

Developed as a hands-on embedded systems and Internet of Things project.
