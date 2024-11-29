#include "Wifi_server.h"

//Constructor
Wifi_server::Wifi_server()
  :port(4242){
    Serial.printf("Wifi_init");
  }

//functions
void Wifi_server::wifi_connect(){
  WiFiServer server(port);
  WiFi.mode(WIFI_STA);
  WiFi.setHostname("PicoW2");
  Serial.printf("Connecting to '%s' with '%s'\n", ssid, password);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.printf("\nConnected to WiFi\n\nConnect to server at %s:%d\n", WiFi.localIP().toString().c_str(), port);

  server.begin();
}