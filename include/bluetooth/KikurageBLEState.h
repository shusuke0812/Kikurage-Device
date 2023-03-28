#ifndef _KikurageBLEState_H_
#define _KikurageBLEState_H_

#include <utility/M5Timer.h>
#include "bluetooth/KikurageBLEServer.h"

extern bool isBLEConnected;

extern M5Timer timer;
extern int wifiSettingTimerId;

#endif // _KikurageBLEState_H_