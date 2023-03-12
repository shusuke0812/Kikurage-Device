#ifndef _KikurageWiFi_H_
#define _KikurageWiFi_H_

#include <M5Stack.h>

struct KikurageWiFi {
    String ssid;
    int32_t channel;
    bool isAuthOpen;
}

struct KikurageWiFiList {
    KikurageWiFi list[];
}

#endif // _KkikurageWiFi_H_