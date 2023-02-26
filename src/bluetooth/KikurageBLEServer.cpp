#include "KikurageBLEServer.h"

// private
KikurageBLEUUID id;

/* BLE sample initialize */
void KikurageBLEServer::initialize() {
    NimBLEDevice::init(id.DEVICE);
    
    // Service
    pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(new KikurageBLEServerCallbacks());
    
    pService = pServer->createService(id.serviceId);
    
    // Characteristic
    pCharacteristic[0] = pService->createCharacteristic(
        id.characteristicId,
        NIMBLE_PROPERTY::WRITE
    );
    pCharacteristic[0]->setCallbacks(new KikurageBLECharacteristicCallbacks());
    
    // Advertising    
    pService->start();
    NimBLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
}