#include "Sample.h"

MPU9250 IMU;

float breq = 0;

void Sample::setupShowText() {
    M5.Lcd.setCursor(20,60);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextWrap(true);
    M5.Lcd.print("Hello world");
}

void Sample::setupDrawRect() {
    M5.Lcd.fillRect(100, 100, 50, 60, TFT_GREEN);
}

void Sample::setupMPU9250() {
    // initialize I2C
    Wire.begin();
    // initialize MPU9250
    IMU.initMPU9250();
}

void Sample::loopShowImage() {
    if (M5.BtnA.wasPressed()) {
        Serial.println("debug: tapped A");
        M5.Lcd.drawJpgFile(SD, "/Smile.jpg", 0, 0);
    } else if (M5.BtnB.wasPressed()) {
        Serial.println("debug: tapped B");
        M5.Lcd.drawJpgFile(SD, "/Sad.jpg", 0, 0);
    } else if (M5.BtnC.wasReleasefor(300)) {
        Serial.println("debug: tapped C");
        M5.Lcd.clear();
    }
    
    M5.update(); // have to run for M5Stack button tapped
}

void Sample::loopVolume() {
    bool pressed = false;
    float freq[] = {261.6, 329.6, 392.6};
    float nowfreq;
    
    if (M5.BtnA.read()) {
        nowfreq = freq[0];
        pressed = true;
    } else if (M5.BtnB.read()) {
        nowfreq = freq[1];
        pressed = true;
    }
    
    if (pressed) {
        if (bfreq != nowfreq) {
            M5.Speaker.tone(nowfreq);
            bfreq = nowfreq;
        }
    }
    if (!pressed) {
        M5.Speaker.mute();
        bfreq = 0;
    }
    
    M5.update();
}

void Sample::loopMPU9250() {
    float x, y, z;
    String msg;
    
    if(IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {
        msg = "-";

        IMU.readAccelData(IMU.accelCount);
        IMU.getAres();
        x = IMU.accelCount[0] * IMU.aRes;
        y = IMU.accelCount[1] * IMU.aRes;
        z = IMU.accelCount[2] * IMU.aRes;

        if (abs(x) > 0.5) {
            msg = (x < 0) ? "RIGHT" : "LEFT";
        }
        if (abs(y) > 0.5) {
            msg = (y < 0) ? "BACK" : "FRONT";
        }
        if (abs(z) > 0.5) {
            msg = (z < 0) ? "DOWN" : "UP";
        }
        M5.Lcd.clear();
        M5.Lcd.drawCentreString(msg, 160, 120, 4);
        delay(500);
    }
}