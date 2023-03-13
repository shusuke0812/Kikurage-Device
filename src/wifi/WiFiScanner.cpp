#include "wifi/WiFiScanner.h"

void WiFiScanner::initialize() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void WiFiScanner::loopScanDebug() {
    int foundWiFiNum = WiFi.scanNetworks();

    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0);

    if (foundWiFiNum == 0) {
        M5.Lcd.println("not found networks");
    } else {
        M5.Lcd.print(foundWiFiNum);
        M5.Lcd.println(" found networks");
        for (int i = 0; i < foundWiFiNum; ++i) {
            M5.Lcd.print(i + 1);
            M5.Lcd.print(": ");
            M5.Lcd.print(WiFi.SSID(i));

            M5.Lcd.print(" ");

            M5.Lcd.print(WiFi.channel(i));
            M5.Lcd.print("CH");

            M5.Lcd.print("(");
            M5.Lcd.print(WiFi.RSSI(i));
            M5.Lcd.print(")");

            M5.Lcd.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");

            delay(10);
        }
    }
}

std::vector<KikurageWiFi> WiFiScanner::getWiFiList() {
    int foundWiFiNum = WiFi.scanNetworks();
    std::vector<KikurageWiFi> wifiList;

    if (foundWiFiNum == 0) {
        Serial.println("debug: not found WiFi");
    } else {
        for (int i = 0; i < foundWiFiNum; i++) {
            KikurageWiFi wifi = { WiFi.SSID(i), WiFi.channel(i), WiFi.RSSI(i), WiFi.encryptionType(i) == WIFI_AUTH_OPEN };
            wifiList.push_back(wifi);
        }
    }
    return wifiList;
}