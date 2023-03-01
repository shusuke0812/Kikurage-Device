#include "bluetooth/KikurageBLEServerCallbacks.h"

bool isConnected = false;

void KikurageBLEServerCallbacks::onConnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE connected");
    M5.Lcd.drawCentreString("BLE connected", 160, 120, 4);
    isConnected = true;
}

void KikurageBLEServerCallbacks::onDisconnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE disconnected");
    M5.Lcd.drawCentreString("BLE disconnected", 160, 120, 4);
    isConnected = false;
}
