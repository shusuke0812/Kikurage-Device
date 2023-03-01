#include <Arduino.h>
#include <M5Stack.h>
#include "sample/Sample.h"
#include "bluetooth/KikurageBLEServer.h"

Sample sample;

// put your setup code here, to run once
void setup() {
    Serial.begin(115200);
    
    // initialize UART, Display, Power, microSD card
    M5.begin();
    M5.Lcd.clear(TFT_BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.drawString("Disconnected", 90, 115);
    
    sample.setupMPU9250();
    initializeBLEServer();
}

// put your main code here, to run repeatedly
void loop() {
    delay(1000);
    M5.update();
    //sample.loopShowImage();
    //sample.loopVolume();
    //sample.loopMPU9250();
}