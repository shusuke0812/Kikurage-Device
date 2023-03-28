#include "bluetooth/KikurageBLECompletion.h"

String KikurageBLECompletionHandler::getMessage(KikurageBLECompletion completion) {
    switch (completion) {
    case KikurageBLECompletion::WiFiSettingSuccess:
        return "wifi setting success";
    case KikurageBLECompletion::WiFiSettingFail:
        return "wifi setting fail";
    default:
        return "message not found";
    }
}