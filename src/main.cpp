#include <Arduino.h>
#include <M5Stack.h>
#include "sample/Sample.h"
#include "bluetooth/KikurageBLEServer.h"

Sample sample;
KikurageBLEServer kikurageBLEServer;

// put your setup code here, to run once
void setup() {
    Serial.begin(115200);
    
    // initialize UART, Display, Power, microSD card
    M5.begin();
    
    sample.setupMPU9250();
    
    kikurageBLEServer.initialize();
}

// put your main code here, to run repeatedly
void loop() {
    //sample.loopShowImage();
    //sample.loopVolume();
    //sample.loopMPU9250();
}