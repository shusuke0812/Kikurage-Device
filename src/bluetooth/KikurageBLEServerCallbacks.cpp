#include "KikurageBLEServerCallbacks.h"

bool isConnected = false;

void KikurageBLEServerCallbacks::onConnect(BLEServer *peripheralServer) {
  M5.Lcd.drawCentreString("BLE connected", 160, 120, 4);
  isConnected = true;
}

void KikurageBLEServerCallbacks::onDisconnect(BLEServer *peripheralServer) {
  M5.Lcd.drawCentreString("BLE disconnected", 160, 120, 4);
  isConnected = false;
}
