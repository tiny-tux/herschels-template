#pragma once

#include <WiFiServer.h>

class ServerManager {
public:
    ServerManager();
    void begin();
    void handleClient();

private:
    WiFiServer _server;
};