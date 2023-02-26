#ifndef _KikurageBLEServerCallbacks_H_
#define _KikurageBLEServerCallbacks_H_

#include <NimBLEDevice.h>
#include <M5Stack.h>

class KikurageBLEServerCallbacks: public NimBLEServerCallbacks {
    public:
    bool isConnected;
};

#endif // _KikurageBLEServerCallbacks_H