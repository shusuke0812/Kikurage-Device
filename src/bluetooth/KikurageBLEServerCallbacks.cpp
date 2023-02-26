#include "KikurageBLEServerCallbacks.h"

bool isConnected = false;

void onConnect(NimBLEServer *pServer) {  
    M5.Lcd.drawCentreString("BLE connected", 160, 120, 4);
    isConnected = true;
}

void onDisconnect(NimBLEServer *pServer) {  
    M5.Lcd.drawCentreString("BLE disconnected", 160, 120, 4);
    isConnected = false;
}
