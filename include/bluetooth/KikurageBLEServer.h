#ifndef _KikurageBLEServer_H_
#define _KikurageBLEServer_H_

#include <M5Stack.h>
#include <NimBLEDevice.h>
#include "KikurageBLEServerCallbacks.h"
#include "KikurageBLECharacteristicCallbacks.h"


class KikurageBLEServer {
    public:
    void initialize();
    void loop9axisSensor();
    void sendWiFiToCentral(String jsonString);
};

#endif // _KikurageBLEServer_H_