#ifndef _KikurageBLEServerCallbacks_H_
#define _KikurageBLEServerCallbacks_H_

#include <NimBLEDevice.h>
#include <M5Stack.h>

class KikurageBLEServerCallbacks: public NimBLEServerCallbacks {
    public:
    void onConnect(NimBLEServer *pServer);
    void onDisconnect(NimBLEServer *pServer);
};

#endif // _KikurageBLEServerCallbacks_H