#include "network.h"

NetworkManager::NetworkManager(const char* ssid, const char* password)
    : wifi(ssid, password) {}

void NetworkManager::connect() {
    wifi.connect();

    #ifdef ENABLE_MQTT
    mqtt.connect();
    #endif

    #ifdef ENABLE_SERVER
    server.begin();
    #endif
}

void NetworkManager::loop() {
    wifi.loop();

    #ifdef ENABLE_MQTT
    mqtt.loop();
    #endif

    #ifdef ENABLE_SERVER
    server.handleClient();
    #endif
}