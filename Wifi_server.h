#include <WiFi.h>

#ifndef STASSID
#define STASSID "Joyce_Chan-2.4G" //ssid
#define STAPSK "98048299" //password
#endif


#ifndef WIFI_SERVER_H
#define WIFI_SERVER_H



class Wifi_server{
  public:
    Wifi_server();
    void wifi_connect();
  
  private:
    const char* ssid = STASSID;
    const char* password = STAPSK;
    int port;
};

#endif