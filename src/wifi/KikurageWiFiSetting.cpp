#include "wifi/KikurageWiFiSetting.h"

// To start timer, it must be declared timer.run() in main loop.
// https://github.com/m5stack/M5Stack/blob/master/src/utility/M5Timer.h#L48

void callback() {
    Serial.println("debug: wifi begin timeout");
    
    timer.disable(wifiSettingTimerId);

    kBLEServer.sendWiFiSettingCompletionToCentral(KikurageBLECompletion::WiFiSettingFail);
}

void KikurageWiFiSetting::setupWiFi(const char *ssid, const char *password) {
    wifiSettingTimerId = timer.setTimeout(5 * 1000, callback);

    Serial.println("debug: wifi begin ...");

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        if (!timer.isEnabled(wifiSettingTimerId)) {
            Serial.println("debug: stop checking wifi status");
            break;
        }
        delay(1); // If this code is not here, it is occured error for `tasks did not reset the watchdog in time`. After that M5Stack is shutdown.
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("debug: wifi begin success");

        isWiFiSetting = false;
        timer.disable(wifiSettingTimerId);

        kBLEServer.sendWiFiSettingCompletionToCentral(KikurageBLECompletion::WiFiSettingSuccess);
    }
}
