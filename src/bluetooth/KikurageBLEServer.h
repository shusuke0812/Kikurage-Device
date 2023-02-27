#ifndef _KikurageBLEServer_H_
#define _KikurageBLEServer_H_

#include <NimBLEDevice.h>
#include "KikurageBLEServerCallbacks.h"
#include "KikurageBLECharacteristicCallbacks.h"
#include "KikurageBLEUUID.h"

void initializeBLEServer();

#endif // _KikurageBLEServer_H_