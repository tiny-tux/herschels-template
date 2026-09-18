#pragma once

#include "config.h"

#ifdef ENABLE_WIFI
#include "wireless.h"
#endif

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
    
        #ifdef ENABLE_WIFI
        WiFiManager wifi;
        #endif

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