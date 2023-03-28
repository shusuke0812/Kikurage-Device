#ifndef _WiFiScanner_H_
#define _WiFiScanner_H_

#include <M5Stack.h>
#include <WiFi.h>
#include <vector>
#include "wifi/KikurageWiFi.h"

class WiFiScanner {
    public:
    void initialize();
    void loopScanDebug();
    std::vector<KikurageWiFi> getWiFiList();
};

#endif // _WiFiScanner_H_