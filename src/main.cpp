#include <Arduino.h>
#include <M5Stack.h>

#include "bluetooth/KikurageBLEServer.h"
#include "bluetooth/KikurageBLEMessage.h"
#include "bluetooth/KikurageBLEState.h"

#include "wifi/WiFiScanner.h"
#include "wifi/KikurageWiFi.h"

KikurageBLEServer kBLEServer;
WiFiScanner wifiScanner;

// put your setup code here, to run once
void setup() {
    Serial.begin(115200);
    
    // initialize UART, Display, Power, microSD card
    M5.begin();
    kDrawString("BLE Disconnect");
    
    kBLEServer.initialize();
}

// put your main code here, to run repeatedly
void loop() {
    if (isBLEConnected && isStartWiFiScan) {
        std::vector<KikurageWiFi> wifiList = wifiScanner.getWiFiList();
        int wifiListCount = wifiList.size();

        for (int i = 0; i < wifiListCount; i++) {
            String jsonString = getKikurageWiFiJSONString(wifiList[i]);
            kBLEServer.setupWiFiToPeripheral(jsonString);
        }
    }
    delay(1000);
    M5.update();
}