#ifndef _WiFiScanner_H_
#define _WiFiScanner_H_

#include <M5Stack.h>
#include <WiFi.h>

class WiFiScanner {
    public:
    void initialize();
    void loopScanDebug();
};

#endif // _WiFiScanner_H_