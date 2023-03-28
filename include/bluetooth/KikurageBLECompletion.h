#ifndef _KikurageBLECompletion_H_
#define _KikurageBLECompletion_H_

#include <M5Stack.h>
#include <ArduinoJson.h>

enum class KikurageBLECompletion {
    WiFiSettingSuccess,
    WiFiSettingFail,
};

struct BLECompletionMessage {
    String type; // success or error
    String message;
};

class KikurageBLECompletionHandler {
    public:
    BLECompletionMessage getMessage(KikurageBLECompletion completion);
};

String getBLECompletionMessageJSONString(BLECompletionMessage message);

#endif // _KikurageBLECompletion_H_