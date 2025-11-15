#pragma once

#include <Arduino.h>

// Turn on/off with comments
#define ENABLE_DEBUG
#define ENABLE_MQTT
//#define ENABLE_HTTP
//#define ENABLE_SERVER // Not finished

// Debug macros
#ifdef ENABLE_DEBUG
  #define DEBUG_SERIAL_PRINT(x) Serial.print(x)
  #define DEBUG_SERIAL_PRINTLN(x) Serial.println(x)
  #define DEBUG_SERIAL_PRINTF(...)  Serial.printf(__VA_ARGS__)

  #ifdef ENABLE_MQTT
    #define DEBUG_PRINT(x)    DEBUG_SERIAL_PRINT(x)         // Update these two so that they use an MQTT debug print as well as serial
    #define DEBUG_PRINTLN(x)  DEBUG_SERIAL_PRINTLN(x)       // Update these two so that they use an MQTT debug print as well as serial
  #else
    #define DEBUG_PRINT(x)    DEBUG_SERIAL_PRINT(x)
    #define DEBUG_PRINTLN(x)  DEBUG_SERIAL_PRINTLN(x)
  #endif
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
  #define DEBUG_SERIAL_PRINTF(...)
#endif

#define WIFI_RECONNECT_INTERVAL_MS 5000
#define MQTT_SERVER "192.168.4.38"
#define MQTT_PORT 1883
#define MQTT_DEBUG_TOPIC "device/logs" // Update device name
#define MQTT_WILL_TOPIC "device/status" // Update device name