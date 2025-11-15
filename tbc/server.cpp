#include "server.h"
#include <WiFi.h>
#include <Arduino.h>
#include "config.h"


ServerManager::ServerManager()
: _server(80) // Listen on port 80
{}

void ServerManager::begin() {
    if(WiFi.status() == WL_CONNECTED) {
        _server.begin();
    }
    else {
        // Fallback
    }
   

}

void ServerManager::handleClient() {
    WiFiClient client = _server.accept();
    if(!client) return;

    DEBUG_PRINTLN("New client");
    digitalWrite(LED_BUILTIN, HIGH);

    unsigned long startTime = millis();
    char reqLine[100] = {0};
    int i = 0;

    // Wait for data with timeout
    while(client.connected() && millis() - startTime < 1000) {
        if(client.available()) {
        char c = client.read();
        if (c == '\r' || c == '\n') break;
        if (i < sizeof(reqLine) - 1) reqLine[i++] = c;
        }
    }

    DEBUG_PRINT("Request: ");
    DEBUG_PRINTLN(reqLine);
    // Default fallback response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<h1>Welcome to the Pico Server</h1>");

    client.flush();
    client.stop();
    digitalWrite(LED_BUILTIN, LOW);
    DEBUG_PRINTLN("Client disconnected");
}