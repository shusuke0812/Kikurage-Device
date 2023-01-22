#include <Arduino.h>
#include <M5Stack.h>

void setupShowImage();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // initialize UART, Display, Power, microSD card
  M5.begin();

  setupShowImage();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// **** sample code ****

void setupShowText() {
  M5.Lcd.setCursor(20,60);
  M5.Lcd.setTextSize(4);
  M5.Lcd.setTextWrap(true);
  M5.Lcd.print("Hello world");
}

void setupDrawRect() {
  M5.Lcd.fillRect(100, 100, 50, 60, TFT_GREEN);
}

void setupShowImage() {
  M5.Lcd.drawJpgFile(SD, "/Smile.jpg", 0, 0);
}