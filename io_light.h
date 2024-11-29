#ifndef IO_LIGHT_H
#define IO_LIGHT_H

#include <Arduino.h>

// LED_BUILTIN

class io_light{
  public:
    io_light(int light_pin);
    void flash_light(int loop_times);
  
  private:
    int light_pin;

};

#endif