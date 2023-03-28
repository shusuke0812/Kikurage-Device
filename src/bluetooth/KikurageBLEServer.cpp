#include "bluetooth/KikurageBLEServer.h"
#include "bluetooth/KikurageBLEUUID.h"
#include "bluetooth/KikurageBLEState.h"

#include "utility/MPU9250.h"

NimBLECharacteristic *pCharacteristics[4] = {};
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
    
    // Characteristic( for stop wifi scan )
    pCharacteristics[0] = pService->createCharacteristic(
        CHARACTERISTICS[0],
        NIMBLE_PROPERTY::WRITE
    );
    pCharacteristics[0]->setCallbacks(new KikurageBLECharacteristicCallbacks());

    // Characteristic( for setting wifi )
    pCharacteristics[1] = pService->createCharacteristic(
        CHARACTERISTICS[1],
        NIMBLE_PROPERTY::WRITE
    );
    pCharacteristics[1]->setCallbacks(new KikurageBLEWiFiSettingCharacteristicCallbacks());

    // Characteristic( for result of scanning wifi and completion )
    for (int i = 0; i < 1; i++) {
        pCharacteristics[i + 2] = pService->createCharacteristic(
            CHARACTERISTICS[i + 2],
            NIMBLE_PROPERTY::READ |
            NIMBLE_PROPERTY::NOTIFY
        );
        pCharacteristics[i + 1]->setCallbacks(new KikurageBLECharacteristicCallbacks());
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
    if (isBLEConnected) {
        if (IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {
            IMU.readAccelData(IMU.accelCount);
            IMU.getAres();
            for (int i = 0; i < 3; i++) {
                float val = IMU.accelCount[i] * IMU.aRes;
                pCharacteristics[i + 1]->setValue(val);
                pCharacteristics[i + 1]->notify();
                Serial.print("debug: set value of characteristic number = ");
                Serial.println(i + 1);
            }
        }
    }
}

void KikurageBLEServer::sendWiFiToCentral(String jsonString) {
    pCharacteristics[1]->setValue(jsonString);
    pCharacteristics[1]->notify();
    delay(100);
    Serial.print("debug: setup characteristic -> ");
    Serial.println(jsonString);
}