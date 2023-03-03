#include <Arduino.h>
#include <M5Stack.h>
#include "sample/Sample.h"
#include "bluetooth/KikurageBLEServer.h"
#include "bluetooth/KikurageBLEMessage.h"
#include "bluetooth/KikurageBLEState.h"

Sample sample;
KikurageBLEServer kBLEServer;

// put your setup code here, to run once
void setup() {
    Serial.begin(115200);
    
    // initialize UART, Display, Power, microSD card
    M5.begin();
    kDrawString("Disconnect");
    
    sample.setupMPU9250();
    kBLEServer.initialize();
}

// put your main code here, to run repeatedly
void loop() {
    kBLEServer.loop9axisSensor();
    delay(1000);
    M5.update();
    //sample.loopShowImage();
    //sample.loopVolume();
    //sample.loopMPU9250();
}