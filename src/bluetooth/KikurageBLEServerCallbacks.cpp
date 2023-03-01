#include "bluetooth/KikurageBLEServerCallbacks.h"

bool isConnected = false;

void onConnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE connected");
    M5.Lcd.drawCentreString("BLE connected", 160, 120, 4);
    isConnected = true;
}

void onDisconnect(NimBLEServer *pServer) {
    Serial.println("debug: BLE disconnected");
    M5.Lcd.drawCentreString("BLE disconnected", 160, 120, 4);
    isConnected = false;
}
