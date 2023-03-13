#ifndef _KikurageWiFi_H_
#define _KikurageWiFi_H_

#include <M5Stack.h>
#include <ArduinoJson.h>

struct KikurageWiFi {
    String ssid;
    int32_t channel;
    int32_t rssi;
    bool isAuthOpen;
};

String getKikurageWiFiJSONString(KikurageWiFi kikruageWiFi);

#endif // _KkikurageWiFi_H_