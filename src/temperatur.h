#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>

#define DHTPIN A2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void BeginDHT()
{
    dht.begin();
}

float getTemp()
{
    return dht.readTemperature();
}

float getHum()
{
    return dht.readHumidity();
}