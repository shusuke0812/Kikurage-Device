#ifndef _KikurageBLEServerCallbacks_H_
#define _KikurageBLEServerCallbacks_H_

#include <BLEServer.h>
#include <BLEDevice.h>
#include <M5Stack.h>

class KikurageBLEServerCallbacks: public BLEServerCallbacks {
  private:
    bool isConnected;
  public:
    virtual void onConnect(BLEServer *peripheralServer);
    virtual void onDisconnect(BLEServer *peripheralServer);
};

#endif // _KikurageBLEServerCallbacks_H