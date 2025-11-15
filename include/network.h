#pragma once

#include "config.h"
#include "wireless.h"

#ifdef ENABLE_MQTT
#include "mqtt.h"
#endif

#ifdef ENABLE_HTTP
#include "http.h"
#endif

#ifdef ENABLE_SERVER
#include "server.h"
#endif

class NetworkManager {
    public:
        NetworkManager(const char* ssid, const char* password);
        void connect();
        void loop();
    
        WiFiManager wifi;

        #ifdef ENABLE_MQTT
        MQTTManager mqtt;
        #endif

        #ifdef ENABLE_HTTP
        HTTPManager http;
        #endif

        #ifdef ENABLE_SERVER
        ServerManager server;
        #endif
    };