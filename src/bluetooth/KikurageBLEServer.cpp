#include "KikurageBLEServer.h"

// private
KikurageBLEUUID id;

/* BLE sample initialize */
void KikurageBLEServer::initialize() {
  NimBLEDevice::init(id.DEVICE);

  // Service
  peripheralServer = NimBLEDevice::createServer();
  peripheralServer->setCallbacks(new KikurageBLEServerCallbacks());

  peripheralService = peripheralServer->createService(id.serviceId);

  // Characteristic
  peripheralCharacteristic[0] = peripheralService->createCharacteristic(
    id.characteristicId,
    NIMBLE_PROPERTY::WRITE
  );
  peripheralCharacteristic[0]->setCallbacks(new KikurageBLECharacteristicCallbacks());

  // Advertising
  peripheralService->start();
  NimBLEAdvertising *peripheralAdvertising = peripheralServer->getAdvertising();
  peripheralAdvertising->start();
}