ESP32 Climate Monitor

A temperature and humidity monitoring project built using an ESP32 DevKit V1, DHT22 sensor, and Arduino IoT Cloud.

Features

* Real-time temperature monitoring in °C
* Relative humidity monitoring in %
* Cloud-based data visualization
* Serial Monitor output for debugging
* Periodic sensor readings

Hardware

* ESP32 DevKit V1
* DHT22 temperature and humidity sensor
* Jumper wires
* USB data cable
* Wi-Fi connection

Wiring

DHT22 breakout	ESP32
VCC (+)	3V3
DATA (OUT)	GPIO 4
GND (-)	GND

Software

* Arduino IDE / Arduino Cloud Editor
* Arduino IoT Cloud
* Adafruit DHT sensor library
* Adafruit Unified Sensor library

Setup

1. Connect the DHT22 to the ESP32 using the wiring table above.
2. Install the required sensor libraries.
3. Create a Thing in Arduino IoT Cloud.
4. Create two cloud variables: Temperature and Humidity.
5. Configure the device and Wi-Fi credentials locally.
6. Upload the sketch to the ESP32.
7. Create dashboard widgets linked to both variables.

Security

Do not commit Wi-Fi passwords, Arduino Cloud device secret keys, authentication tokens, or other private credentials. Use local configuration files for secrets and publish only sanitized examples.

Future improvements

* Historical temperature and humidity charts
* Temperature threshold alerts
* Improved dashboard design
* Sensor data logging and analysis
