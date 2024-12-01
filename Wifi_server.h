#include <WiFi.h>
#ifndef WIFI_SERVER_H
#define WIFI_SERVER_H

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <LEAmDNS.h>

class Wifi_server {
public:
    Wifi_server(const char* ssid, const char* password);
    void begin();
    void handleClient();

private:
    const char* ssid;
    const char* password;
    WebServer server;
    const int led = LED_BUILTIN;

    void handleRoot();
    void handleNotFound();
    void set_api_to_server();
};

#endif // WIFI_SERVER_H