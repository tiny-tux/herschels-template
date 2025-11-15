#include "wireless.h"
#include "config.h"
#include "secrets.h"
#include <Arduino.h>
#include <WiFi.h>

WiFiManager::WiFiManager(const char* ssid, const char* password)
    : _ssid(ssid), _password(password), _lastReconnectAttempt(0) {}

void WiFiManager::connect() {
    DEBUG_PRINT("Connecting to ");
    DEBUG_PRINTLN(_ssid);
    WiFi.begin(_ssid, _password);
}

bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

void WiFiManager::loop() {
    if (!isConnected() && millis() - _lastReconnectAttempt > WIFI_RECONNECT_INTERVAL_MS) {
        _lastReconnectAttempt = millis();
        connect();
    }
}