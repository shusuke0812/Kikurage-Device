#include "wifi/KikurageWiFiSetting.h"

void KikurageWiFiSetting::setupWiFi(const char *ssid, const char *password) {
    WiFi.begin(ssid, password);
    while (WiFi.status() == WL_CONNECTED) {
        isWiFiSetting = false;
    }
}