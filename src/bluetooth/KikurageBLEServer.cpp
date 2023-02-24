#include "KikurageBLEServer.h"

KikurageBLEUUID id;

/* BLE sample initialize */
void KikurageBLEServer::initialize() {
  NimBLEDevice::init("kikurage-device-m5-stack");

  // Callbacks for connected and disconnected
  NimBLEServer *peripheralServer = NimBLEDevice::createServer();
  peripheralServer->setCallbacks(new KikurageBLEServerCallbacks());

  // Create service
  NimBLEService *peripheralService = peripheralServer->createService(id.SERVICE_UUID);

  // Create characteristics
  peripheralCharacteristic[0] = peripheralService->createCharacteristic(
    id.CHARACTERISTICS[0],
    NIMBLE_PROPERTY::WRITE
  );
  peripheralCharacteristic[0]->setCallbacks(new KikurageBLECharacteristicCallbacks());

  // Advertising
  peripheralService->start();
  NimBLEAdvertising *peripheralAdvertising = peripheralServer->getAdvertising();
  peripheralAdvertising->start();
}