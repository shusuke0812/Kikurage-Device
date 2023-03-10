#include "bluetooth/KikurageBLEServer.h"
#include "bluetooth/KikurageBLEUUID.h"
#include "bluetooth/KikurageBLEState.h"

#include "utility/MPU9250.h"

NimBLECharacteristic *pCharacteristic[4] = {};
NimBLEServer *pServer = NULL;

MPU9250 IMU;

/* BLE sample initialize */
void KikurageBLEServer::initialize() {
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

    // Characteristic( for 9 axis sensor )
    for (int i = 0; i < 3; i++) {
        pCharacteristic[i + 1] = pService->createCharacteristic(
            CHARACTERISTICS[i + 1],
            NIMBLE_PROPERTY::READ |
            NIMBLE_PROPERTY::NOTIFY
        );
        pCharacteristic[i + 1]->setCallbacks(new KikurageBLECharacteristicCallbacks());
    }
    
    // Advertising
    pService->start();
    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->addTxPower();
    pAdvertising->start();
}

/* BLE sample setting value to characteristic */
void KikurageBLEServer::loop9axisSensor() {
    if (isConnected) {
        if (IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {
            IMU.readAccelData(IMU.accelCount);
            IMU.getAres();
            for (int i = 0; i < 3; i++) {
                float val = IMU.accelCount[i] * IMU.aRes;
                pCharacteristic[i + 1]->setValue(val);
                pCharacteristic[i + 1]->notify();
                Serial.print("debug: set value of characteristic number = ");
                Serial.println(i + 1);
            }
        }
    }
}