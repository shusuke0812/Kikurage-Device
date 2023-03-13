#include "bluetooth/KikurageBLEServerCallbacks.h"
#include "bluetooth/KikurageBLEMessage.h"
#include "bluetooth/KikurageBLEState.h"

void KikurageBLEServerCallbacks::onConnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE connected");
    kDrawString("BLE Connect");
    isBLEConnected = true;
}

void KikurageBLEServerCallbacks::onDisconnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE disconnected");
    kDrawString("BLE Disconnect");
    isBLEConnected = false;
}
