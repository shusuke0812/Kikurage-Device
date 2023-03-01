#include "bluetooth/KikurageBLECharacteristicCallbacks.h"

Color color;

void KikurageBLECharacteristicCallbacks::onWrite(NimBLECharacteristic *pCharacteristic) {
    Serial.println("debug: called write of characteristic");
    M5.Lcd.println("white");
    std::string value = pCharacteristic->getValue();
    String colorval = String(value.c_str());

    int r, g, b;
    colorval.toLowerCase();
    if (colorval.charAt(0) != '#') {
        r = g = b = 0;
        M5.Lcd.fillScreen(0);
    } else {
        colorval.toLowerCase();
        r = color.convertRGB(colorval.substring(1, 3));
        g = color.convertRGB(colorval.substring(3, 5));
        b = color.convertRGB(colorval.substring(5, 7));

        int rgb565 = ((r>>3)<<11) | ((g>>2)<<5) | (b>>3);
        M5.Lcd.fillScreen(rgb565);
    }
}

void KikurageBLECharacteristicCallbacks::onRead(NimBLECharacteristic *pCharacteristic) { 
    Serial.println("debug: called read of characteristic");
    M5.Lcd.println("read");
}