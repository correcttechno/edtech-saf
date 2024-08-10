#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>


#define DHTPIN 33  
#define DHTTYPE    DHT11   
DHT_Unified dht(DHTPIN, DHTTYPE);

void BeginDHT(){
    dht.begin();
    
}

int getTemp(){
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    return event.temperature;
}

int getHum(){
    sensors_event_t event;
    dht.humidity().getEvent(&event);
    return event.relative_humidity;
}