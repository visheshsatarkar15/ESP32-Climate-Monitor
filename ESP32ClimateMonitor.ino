#include "arduino_secrets.h"
#include "thingProperties.h"
#include <DHT.h>
#include <math.h>

// DHT22 configuration
#define DHTPIN 4
#define DHTTYPE DHT22

// Capacitive soil moisture sensor
#define SOIL_PIN 13

DHT dht(DHTPIN, DHTTYPE);

// Sensor reading interval
unsigned long lastReadTime = 0;
const unsigned long READ_INTERVAL = 2500;

void setup() {
  Serial.begin(115200);
  delay(1500);

  // Initialize sensors
  dht.begin();
  analogReadResolution(12);

  // Initialize Arduino IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  Serial.println("ESP32 Environmental Monitor started");
  Serial.println("DHT22: GPIO 4");
  Serial.println("Soil sensor: GPIO 13");
}

void loop() {
  // Maintain cloud connection
  ArduinoCloud.update();

  unsigned long currentTime = millis();

  if (currentTime - lastReadTime >= READ_INTERVAL) {
    lastReadTime = currentTime;

    // Read temperature and humidity
    float temperatureReading = dht.readTemperature();
    float humidityReading = dht.readHumidity();

    // Read raw soil moisture sensor value
    int soilRaw = analogRead(SOIL_PIN);

    // Print soil sensor reading
    Serial.print("Soil raw reading: ");
    Serial.println(soilRaw);

    // Check DHT22 readings
    if (isnan(temperatureReading) ||
        isnan(humidityReading)) {
      Serial.println(
        "DHT22 reading failed. Check sensor wiring."
      );
    } else {
      // Update existing cloud variables
      Temperature = temperatureReading;
      Humidity = humidityReading;

      // Print temperature
      Serial.print("Temperature: ");
      Serial.print(temperatureReading, 1);
      Serial.print(" °C | Humidity: ");
      Serial.print(humidityReading, 1);
      Serial.println(" %");
    }

    Serial.println("---------------------------");
  }
}
