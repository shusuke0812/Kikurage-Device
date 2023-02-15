#include "KikurageBLECharacteristicCallbacks.h"

void KikurageBLECharacteristicCallbacks::onWrite(NimBLECharacteristic *peripheralCharacteristic) {
  M5Stack.Lcd.println("white");
  std::string value = peripheralCharacteristic->getValue();
  String colorval = String(value.c_str());

  int r, g, b;
  colorval.toLowerCase();
  if (colorval.charAt(0) != '#') {
    r = g = b = 0;
    M5.Lcd.fillScreen(0);
  } else {
    colorval.toLowerCase();
    r = convertRGB(colorval.substring(1, 3));
    g = convertRGB(colorval.substring(3, 5));
    b = convertRGB(colorval.substring(5, 7));

    int rgb565 = ((r>>3)<<11) | ((g>>2)<<5) | (b>>3);
    M5.Lcd.fillScreen(rgb565);
  }
}

void KikurageBLECharacteristicCallbacks::onRead(NimBLECharacteristic *peripheralCharacteristic) {
  M5.Lcd.println("read");
}