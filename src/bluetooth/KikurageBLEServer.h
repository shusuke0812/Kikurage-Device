#ifndef _KikurageBLEServer_H_
#define _KikurageBLEServer_H_

#include <NimBLEDevice.h>
#include "KikurageBLEServerCallbacks.h"
#include "KikurageBLECharacteristicCallbacks.h"
#include "KikurageBLEUUID.h"

class KikurageBLEServer {
    private:
    NimBLECharacteristic *peripheralCharacteristic[4];
    NimBLEService *peripheralService;
    public:
    NimBLEServer *peripheralServer;
    void initialize();
};

#endif // _KikurageBLEServer_H_