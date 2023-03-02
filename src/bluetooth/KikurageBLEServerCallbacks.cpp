#include "bluetooth/KikurageBLEServerCallbacks.h"
#include "bluetooth/KikurageBLEMessage.h"

bool isConnected = false;

void KikurageBLEServerCallbacks::onConnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE connected");
    kDrawString("Connect");
    isConnected = true;
}

void KikurageBLEServerCallbacks::onDisconnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE disconnected");
    kDrawString("Disconnect");
    isConnected = false;
}
