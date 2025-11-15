#pragma once

#include <HTTPClient.h>

class HTTPManager {
public:
    HTTPManager();
    String get(const char* url);
    bool post(const char* url, const String& payload);

private:
    HTTPClient httpClient;
    bool busy = false;
};