#ifndef _KikurageBLECompletion_H_
#define _KikurageBLECompletion_H_

#include <M5Stack.h>

enum class KikurageBLECompletion {
    WiFiSettingSuccess,
    WiFiSettingFail,
};

class KikurageBLECompletionHandler {
    public:
    String getMessage(KikurageBLECompletion completion);
};

#endif // _KikurageBLECompletion_H_