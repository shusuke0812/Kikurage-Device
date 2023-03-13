#include "bluetooth/KikurageBLEMessage.h"

void kDrawString(String message) {
    M5.Lcd.clear(TFT_BLACK);
    M5.Lcd.drawCentreString(message, 160, 120, 4);
    //M5.Lcd.setTextSize(3);
    //M5.Lcd.drawString(message, 90, 115);
}