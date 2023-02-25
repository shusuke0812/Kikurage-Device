#include "KikurageBLEServerCallbacks.h"

bool isConnected = false;

void KikurageBLEServerCallbacks::onConnect(NimBLEServer *peripheralServer) {
  Serial.println("device connected");
  
  M5.Lcd.drawCentreString("BLE connected", 160, 120, 4);
  isConnected = true;
}

void KikurageBLEServerCallbacks::onDisconnect(NimBLEServer *peripheralServer) {
  Serial.println("device disconnected");
  
  M5.Lcd.drawCentreString("BLE disconnected", 160, 120, 4);
  isConnected = false;
}
