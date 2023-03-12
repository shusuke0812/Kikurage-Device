#include <Arduino.h>
#include <M5Stack.h>
#include "bluetooth/KikurageBLEServer.h"
#include "bluetooth/KikurageBLEMessage.h"
#include "bluetooth/KikurageBLEState.h"

KikurageBLEServer kBLEServer;

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
    delay(1000);
    M5.update();
    //sample.loopVolume();
    //sample.loopMPU9250();
}