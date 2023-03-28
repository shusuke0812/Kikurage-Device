#include "bluetooth/KikurageBLEMessage.h"

void kDrawString(String message) {
    M5.Lcd.clear(TFT_BLACK);
    M5.Lcd.drawCentreString(message, 160, 120, 4);
}