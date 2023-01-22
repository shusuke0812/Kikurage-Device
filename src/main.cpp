#include <Arduino.h>
#include <M5Stack.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // initialize UART, Display, Power, microSD card
  M5.begin();

  M5.Lcd.setCursor(20,60);
  M5.Lcd.setTextSize(4);
  M5.Lcd.print("Hello world");

  M5.Lcd.fillRect(100, 100, 50, 60, TFT_GREEN);
}

void loop() {
  // put your main code here, to run repeatedly:
}