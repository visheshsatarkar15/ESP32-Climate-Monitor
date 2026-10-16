#include "arduino_secrets.h"



#include "thingProperties.h"
#include <DHT.h>
#include <math.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

unsigned long lastReadTime = 0;
const unsigned long READ_INTERVAL = 2500;

void setup() {
  Serial.begin(115200);
  delay(1500);

  dht.begin();

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  Serial.println("ESP32 Climate Monitor started");
}

void loop() {
  ArduinoCloud.update();

  unsigned long currentTime = millis();

  if (currentTime - lastReadTime >= READ_INTERVAL) {
    lastReadTime = currentTime;

    float temperatureReading = dht.readTemperature();
    float humidityReading = dht.readHumidity();

    if (isnan(temperatureReading) || isnan(humidityReading)) {
      Serial.println("DHT22 reading failed. Check sensor wiring.");
      return;
    }

    Temperature = temperatureReading;
    Humidity = humidityReading;

    Serial.print("Temperature: ");
    Serial.print(temperatureReading, 1);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidityReading, 1);
    Serial.println(" %");
  }
}