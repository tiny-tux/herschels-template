#include "config.h"
#include "credentials.h"
#include "mqtt.h"
#include "wireless.h"

MQTTManager::MQTTManager() : _client(_wifiClient) {
    _client.setServer(MQTT_SERVER, MQTT_PORT);
}

bool MQTTManager::connect() {
    DEBUG_PRINTLN("Connecting to MQTT...");
    while (!_client.connected()) {
        if (_client.connect(
            "PicoWClient",   // Give device proper name
            MQTT_USER, 
            MQTT_PASSWORD, 
            MQTT_WILL_TOPIC, // Will topic
            1,               // QoS
            true,            // Retain flag
            "dead",          // LWT payload
            true             // Clean session flag
        )) {
        DEBUG_PRINTLN("MQTT Connected!");
        return true;
        } else {
            DEBUG_PRINT("MQTT failed, rc=");
            DEBUG_PRINTLN(_client.state());
            delay(2000); // Wait before retry
        }
    }
    return false;
}

bool MQTTManager::isConnected() {
    return _client.connected();
}

bool MQTTManager::publish(const char* topic, const char* payload) {
    return _client.publish(topic, payload);
}

void MQTTManager::loop() {
    if (!_client.connected()) {
        connect();
    }
    _client.loop();
}

void MQTTManager::subscribe(const char* topic) {
    _client.subscribe(topic);
}

void MQTTManager::setCallback(MQTT_CALLBACK_SIGNATURE) {
    _client.setCallback(callback);
}