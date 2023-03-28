#include "bluetooth/KikurageBLECompletion.h"

BLECompletionMessage  KikurageBLECompletionHandler::getMessage(KikurageBLECompletion completion) {
    switch (completion) {
    case KikurageBLECompletion::WiFiSettingSuccess:
        return { "success", "wifi setting success" };
    case KikurageBLECompletion::WiFiSettingFail:
        return { "error", "wifi setting fail" };
    default:
        return { "error", "message not found" };
    }
}

String getBLECompletionMessageJSONString(BLECompletionMessage message) {
    DynamicJsonDocument doc(128);

    doc["type"] = message.type;
    doc["description"] = message.description;

    String output;
    serializeJson(doc, output);

    return output;
}