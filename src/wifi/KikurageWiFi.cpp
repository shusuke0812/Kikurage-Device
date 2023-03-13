#include "wifi/KikurageWiFi.h"

String getKikurageWiFiJSONString(KikurageWiFi kikurageWiFi) {

    DynamicJsonDocument doc(128);

    doc["ssid"] = kikurageWiFi.ssid;
    doc["channel"] = kikurageWiFi.channel;
    doc["rssi"] = kikurageWiFi.rssi;
    doc["is_auth_open"] = kikurageWiFi.isAuthOpen;

    String output;
    serializeJson(doc, output);

    return output;
}