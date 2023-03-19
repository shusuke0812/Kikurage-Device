#ifndef _KikurageBLECharacteristicCallbacks_H_
#define _KikurageBLECharacteristicCallbacks_H_

#include <NimBLEDevice.h>
#include <M5Stack.h>
#include <ArduinoJson.h>
#include "sample/Color.h"
#include "wifi/KikurageWiFiState.h"

class KikurageBLECharacteristicCallbacks: public NimBLECharacteristicCallbacks {
    public:
    void onWrite(NimBLECharacteristic *pCharacteristic);
    void onRead(NimBLECharacteristic *pCharacteristic);
};

#endif // _KikurageBLECharacteristicCallbacks_H_