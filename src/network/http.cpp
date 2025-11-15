#include "http.h"
#include "config.h"

HTTPManager::HTTPManager() {}

String HTTPManager::get(const char* url) {
    if (busy) return "";  // Prevent overlapping requests
    busy = true;

    httpClient.begin(url);
    int httpCode = httpClient.GET();
    String payload;

    if (httpCode > 0) {
        payload = httpClient.getString();
    } else {
        payload = "";
    }

    httpClient.end();  // Clean up
    busy = false;
    return payload;
}

bool HTTPManager::post(const char* url, const String& payload) {
    if (busy) return false;  // Prevent overlapping requests
    busy = true;

    httpClient.begin(url);
    httpClient.addHeader("Content-Type", "application/json");
    int httpCode = httpClient.POST(payload);

    httpClient.end();  // Clean up
    busy = false;
    return httpCode > 0 && httpCode < 400;
}
