//-- my script
#include "Io_light.h"
#include "Wifi_server.h"
#include "HUSKYLENS.h"

#include <stdio.h>
#include "pico/stdlib.h"
#include <Wire.h>



/*#ifndef STASSID
#define STASSID "Lourenco-pico"
#define STAPSK "1234"
#endif*/


#ifndef STASSID
#define STASSID "Lourenco-pico"
#define STAPSK "1234"
#endif


io_light* io_light_class;
Wifi_server Wifi_server(STASSID, STAPSK);

HUSKYLENS huskylens;
//HUSKYLENS green line >> SDA(4); blue line >> SCL(5)
#define SDA_PIN 26
#define SCL_PIN 27


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //huskylens
  Wire.setSDA(SDA_PIN);
  Wire.setSCL(SCL_PIN);
  Wire.begin();
  while (!huskylens.begin(Wire))
  {
      Serial.println(F("Begin failed!"));
      Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
      Serial.println(F("2.Please recheck the connection."));
      delay(100);
  }

  huskylens.writeAlgorithm(ALGORITHM_OBJECT_TRACKING); //Switch the algorithm to object tracking.

  //webserver
  Wifi_server.begin();

  //light
  io_light_class = new io_light(LED_BUILTIN);
  io_light_class->flash_light(10);

}

void loop() {
  Wifi_server.handleClient();
}

