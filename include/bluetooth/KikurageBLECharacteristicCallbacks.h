#ifndef _KikurageBLECharacteristicCallbacks_H_
#define _KikurageBLECharacteristicCallbacks_H_

#include <NimBLEDevice.h>
#include <M5Stack.h>
#include <ArduinoJson.h>
#include "wifi/KikurageWiFiState.h"
#include "wifi/KikurageWiFiSetting.h"

class KikurageBLECharacteristicCallbacks: public NimBLECharacteristicCallbacks {
    public:
    void onWrite(NimBLECharacteristic *pCharacteristic);
    void onRead(NimBLECharacteristic *pCharacteristic);
};

class KikurageBLEWiFiSettingCharacteristicCallbacks: public NimBLECharacteristicCallbacks {
    public:
    void onWrite(NimBLECharacteristic *pCharacteristic);
    void onRead(NimBLECharacteristic *pCharacteristic);
};

#endif // _KikurageBLECharacteristicCallbacks_H_