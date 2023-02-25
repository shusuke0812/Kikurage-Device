#ifndef _KikurageBLEServerCallbacks_H_
#define _KikurageBLEServerCallbacks_H_

#include <NimBLEServer.h>
#include <NimBLEDevice.h>
#include <M5Stack.h>

class KikurageBLEServerCallbacks: public NimBLEServerCallbacks {
    public:
    bool isConnected;
    virtual void onConnect(NimBLEServer *peripheralServer);
    virtual void onDisconnect(NimBLEServer *peripheralServer);
};

#endif // _KikurageBLEServerCallbacks_H