#include <Arduino.h>
#include <pico/stdlib.h>
#include "config.h"
#include "secrets.h"
#include "network.h"
#include "sensor.h"

NetworkManager networkManager(WIFI_SSID, WIFI_PASSWORD);

void setup() {
#ifdef ENABLE_DEBUG
    Serial.begin(9600);
#endif
    networkManager.connect();

    sensor_setup();
}

void loop() {
    networkManager.loop();
}

void loop1() {
    sensor_loop();
}
