#include "Color.h"

int Color::convertRGB(String s) {
    int val = 0;
    
    for (int i = 0; i < 2; i++) {
        val <<= 4;
        char c = s.charAt(i);
        
        if ((c >= '0') && (c <= '9')) {
            val += c - '0';
        } else if ((c >= 'a' && c <= 'f')) {
            val += (c - 'a') + 10;
        }
    }
    return val;
}
