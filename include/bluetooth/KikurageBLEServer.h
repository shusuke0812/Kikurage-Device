#ifndef _KikurageBLEServer_H_
#define _KikurageBLEServer_H_

#include <NimBLEDevice.h>
#include "KikurageBLEServerCallbacks.h"
#include "KikurageBLECharacteristicCallbacks.h"

void initializeBLEServer();
void loop9axisSensor();

#endif // _KikurageBLEServer_H_