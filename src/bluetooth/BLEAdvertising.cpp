#include "BLEAdvertising.h"

// Advertising parameters should have a global scope. Do NOT define them in 'setup' or in 'loop'
const uint8_t manufactData[4] = {0x01, 0x02, 0x03, 0x04};
const uint8_t serviceData[3] = {0x00, 0x01, 0x02};

kikurageService = BLEService("fff0");
kikurageCharacteristic = BLECharacteristic("fff1", BLERead | BLENotify);

void initializeBLE() {
  if (!BLE.begin()) {
    Serial.println("error: failed to initialize BLE");
    while(1);
  }
}

void kikurageAdvertise() {
  initializeBLE();

  kikurageService.addCharacteristic(kikurageCharacteristic);
  BLE.addService(kikurageService);

  // Scan
  BLEAdvertisingData scanData;
  scanData.setLocalName("test enhanced advertising");
  BLE.setScanResponseData(scanData);

  // Advertise
  BLEAdvertisingData advData;
  advData.setManufacturerData(0x004C, manucatData, sizeof(manufactData));
  advData.setAdvertisedService(kikurageService);
  advData.setAdvertisedServiceData(0xfff0, serviceData, sizeof(serviceData));
  BLE.setAdvertisingData(advData);

  BLE.advertise();
  Serial.println("advertising...");
}

void kikuragePoll() {
  BLE.poll();
}