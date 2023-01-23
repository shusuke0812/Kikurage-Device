#include <Arduino.h>
#include <M5Stack.h>
#include "utility/MPU9250.h"

MPU9250 IMU;

void setupShowText();
void setupDrawRect();
void setupMPU9250(); // 9 axis sensor

void loopShowImage();
void loopVolume();

float bfreq = 0;

// put your setup code here, to run once
void setup() {
  Serial.begin(115200);

  // initialize UART, Display, Power, microSD card
  M5.begin();

  setupMPU9250();
}

// put your main code here, to run repeatedly
void loop() {
  loopShowImage();
  loopVolume();
}

/******
 * sample code
 */

void setupShowText() {
  M5.Lcd.setCursor(20,60);
  M5.Lcd.setTextSize(4);
  M5.Lcd.setTextWrap(true);
  M5.Lcd.print("Hello world");
}

void setupDrawRect() {
  M5.Lcd.fillRect(100, 100, 50, 60, TFT_GREEN);
}

void loopShowImage() {
  if (M5.BtnA.wasPressed()) {
    M5.Lcd.drawJpgFile(SD, "/Smile.jpg", 0, 0);
  } else if (M5.BtnB.wasPressed()) {
    M5.Lcd.drawJpgFile(SD, "/Sad.jpg", 0, 0);
  } else if (M5.BtnC.wasReleasefor(300)) {
    M5.Lcd.clear();
  }

  M5.update(); // have to run for M5Stack button tapped
}

void loopVolume() {
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

void setupMPU9250() {
  // initialize I2C
  Wire.begin();
  // initialize MPU9250
  IMU.initMPU9250();
}