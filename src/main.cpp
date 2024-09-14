
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <temperatur.h>
#include "gyro.h"

#define BLYNK_TEMPLATE_ID "TMPL6AyN0dnMq"
#define BLYNK_TEMPLATE_NAME "EdTech team"

char ssid[] = "Ruslan";
char pass[] = "ruslan1424%";

void setup()
{
  Serial.begin(9600);
  BeginDHT();
  BeginGyro();
  Blynk.begin("qLA8EZOuoocJM6O_lo9QheakvLbRcsxZ", ssid, pass);
}

void loop()
{
  Blynk.run();
  Serial.println(getTemp());
  float* acc=getAcceleration();
  Serial.println(acc[0]);

  String acceleration="X:"+String(acc[0])+" Y:"+String(acc[1])+" Z:"+String(acc[2]);
  Blynk.virtualWrite(2,acceleration);
  Blynk.virtualWrite(0,"24");
  Blynk.virtualWrite(1,"62%");
/*   Blynk.virtualWrite(0,String(getTemp()));
  Blynk.virtualWrite(1,String(getHum()));
  Blynk.run(); */
  delay(200);
}
