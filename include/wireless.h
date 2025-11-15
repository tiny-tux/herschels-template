#pragma once

class WiFiManager {
public:
    WiFiManager(const char* ssid, const char* password);
    void connect();
    bool isConnected();
    void loop();

private:
    const char* _ssid;
    const char* _password;
    unsigned long _lastReconnectAttempt;
};