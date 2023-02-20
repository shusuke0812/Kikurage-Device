#ifndef _KikurageBLEServer_H_
#define _KikurageBLEServer_H_

#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include "KikurageBLEServerCallbacks.h"
#include "KikurageBLECharacteristicCallbacks.h"
#include "KikurageBLEUUID.h"

class KikurageBLEServer {
  private:
    NimBLEServer *peripheralServer;
    NimBLECharacteristic *peripheralCharacteristic[4];
  public:
    void initialize();
};

#endif // _KikurageBLEServer_H_