
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <temperatur.h>

#define BLYNK_TEMPLATE_ID "TMPL6AyN0dnMq"
#define BLYNK_TEMPLATE_NAME "EdTech team"

char ssid[] = "Galaxy A10";
char pass[] = "20072009";

void setup()
{
  Serial.begin(9600);
  BeginDHT();
  Blynk.begin("qLA8EZOuoocJM6O_lo9QheakvLbRcsxZ", ssid, pass);

}

void loop()
{
  Blynk.virtualWrite(0,getTemp());
  Blynk.virtualWrite(2,getHum());
  Blynk.run();
}

