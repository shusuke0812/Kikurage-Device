#include "bluetooth/KikurageBLECharacteristicCallbacks.h"

void KikurageBLECharacteristicCallbacks::onWrite(NimBLECharacteristic *pCharacteristic) {
    std::string value = pCharacteristic->getValue();
    String stopWiFiScanCommand = String(value.c_str());

    DynamicJsonDocument doc(128);
    deserializeJson(doc, stopWiFiScanCommand);

    bool temp = doc["is_stop"];
    isStopWiFiScan = temp;

    Serial.print("debug: called stop wifi scan = ");
    Serial.println(temp); // `true = 1`
}

void KikurageBLECharacteristicCallbacks::onRead(NimBLECharacteristic *pCharacteristic) { 
    Serial.println("debug: called read of characteristic");
    M5.Lcd.println("read");
}

void KikurageBLEWiFiSettingCharacteristicCallbacks::onWrite(NimBLECharacteristic *pCharacteristic) {
    // change flag
    isWiFiSetting = true;
    
    // decode
    std::string value = pCharacteristic->getValue();
    String wifiSettingCommand = String(value.c_str());

    DynamicJsonDocument doc(128);
    deserializeJson(doc, wifiSettingCommand);

    const char *ssid = doc["ssid"];
    const char *password = doc["password"];

    KikurageWiFiSetting wifiSetting;
    wifiSetting.setupWiFi(ssid, password);

    Serial.println("debug: called wifi setting");
}

void KikurageBLEWiFiSettingCharacteristicCallbacks::onRead(NimBLECharacteristic *pCharacteristic) { 
    Serial.println("debug: called read of characteristic");
    M5.Lcd.println("read");
}