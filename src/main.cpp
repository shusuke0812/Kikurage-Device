#include <Arduino.h>
#include <M5Stack.h>

void setup() {
  // put your setup code here, to run once:

  M5.begin();

  M5.Lcd.setCursor(20,60);
  M5.Lcd.setTextSize(4);
  M5.Lcd.print("Hello world");
}

void loop() {
  // put your main code here, to run repeatedly:
}