#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Data Logger Started");
  Serial.println("Time(s)\tTemperature(C)\tHumidity(%)");
}

void loop() {
  // read temperature and humidity
  float temp = dht.readTemperature(); // Celsius
  float hum = dht.readHumidity();
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    unsigned long timeSec = millis() / 1000; // seconds since start
    Serial.print(timeSec);
    Serial.print("\t");
    Serial.print(temp, 1);
    Serial.print("\t");
    Serial.println(hum, 1);
  }
  delay(2000);
}
