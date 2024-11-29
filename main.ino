#include "Io_light.h"
#include "Wifi_server.h"

io_light* io_light_class;
Wifi_server* wifi_server_class;

#include <WiFi.h>
#ifndef STASSID
#define STASSID "Joyce_Chan-2.4G"
#define STAPSK "98048299"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

int port = 80;

WiFiServer server(port);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //io_light_class = new io_light(LED_BUILTIN);
  //io_light_class->flash_light(1);

  wifi_server_class = new Wifi_server();
  wifi_server_class->wifi_connect();

  io_light_class = new io_light(LED_BUILTIN);
  io_light_class->flash_light(1);

}

void loop() {}

