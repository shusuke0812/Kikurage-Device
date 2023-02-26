#include "KikurageBLEServer.h"

KikurageBLEUUID id;

/* BLE sample initialize */
void KikurageBLEServer::initialize() {
    NimBLEDevice::init(id.DEVICE);
    NimBLEDevice::setPower(ESP_PWR_LVL_P9);
    NimBLEDevice::setSecurityAuth(false, false, false);
    
    // Service
    pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(new KikurageBLEServerCallbacks());
    
    pService = pServer->createService(id.SERVICE_UUID);
    
    // Characteristic
    pCharacteristic[0] = pService->createCharacteristic(
        id.CHARACTERISTICS[0],
        NIMBLE_PROPERTY::WRITE
    );
    pCharacteristic[0]->setCallbacks(new KikurageBLECharacteristicCallbacks());
    
    // Advertising
    pService->start();
    NimBLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->addServiceUUID(id.SERVICE_UUID);
    pAdvertising->addTxPower();
    pAdvertising->start();
}