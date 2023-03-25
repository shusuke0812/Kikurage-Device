#include "bluetooth/KikurageBLECharacteristicCallbacks.h"

Color color;

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