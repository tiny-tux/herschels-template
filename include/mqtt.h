#pragma once

#include <PubSubClient.h>
#include <WiFiClient.h>

class MQTTManager {
public:
    MQTTManager();
    bool connect();
    bool isConnected();
    bool publish(const char* topic, const char* payload);
    void subscribe(const char* topic);
    void setCallback(MQTT_CALLBACK_SIGNATURE);
    void loop();

private:
    WiFiClient _wifiClient;
    PubSubClient _client;
};