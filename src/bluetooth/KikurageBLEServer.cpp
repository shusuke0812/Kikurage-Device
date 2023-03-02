#include "bluetooth/KikurageBLEServer.h"
#include "bluetooth/KikurageBLEUUID.h"

NimBLECharacteristic *pCharacteristic[4] = {};
NimBLEServer *pServer = NULL;

/* BLE sample initialize */
void initializeBLEServer() {
    NimBLEDevice::init(DEVICE_NAME);
    NimBLEDevice::setPower(ESP_PWR_LVL_P9);
    NimBLEDevice::setSecurityAuth(false, false, false);
    
    // Service
    pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(new KikurageBLEServerCallbacks());
    
    NimBLEService *pService = pServer->createService(SERVICE_UUID);
    
    // Characteristic( for display color )
    pCharacteristic[0] = pService->createCharacteristic(
        CHARACTERISTICS[0],
        NIMBLE_PROPERTY::WRITE
    );
    pCharacteristic[0]->setCallbacks(new KikurageBLECharacteristicCallbacks());
    
    // Advertising
    pService->start();
    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->addTxPower();
    pAdvertising->start();
}