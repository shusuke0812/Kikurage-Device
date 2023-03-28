#ifndef _KikurageWiFiSetting_H_
#define _KikurageWiFiSetting_H_

#include <M5Stack.h>
#include <WiFi.h>
#include <utility/M5Timer.h>
#include "wifi/KikurageWiFiState.h"
#include "bluetooth/KikurageBLEServer.h"
#include "bluetooth/KikurageBLEState.h"

class KikurageWiFiSetting {
    public:
    void setupWiFi(const char *ssid, const char *password);
};

#endif // _KikurageWiFiSetting_H_