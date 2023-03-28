#ifndef _KikurageBLEUUID_H_
#define _KikurageBLEUUID_H_

// How to create UUID : https://www.uuidgenerator.net/

const char *SERVICE_UUID = "65609901-b6ed-45cc-b8af-b4055a9b7666";
const char *CHARACTERISTICS[4] = {
    "65609902-b6ed-45cc-b8af-b4055a9b7666", // stop wifi scan
    "65609904-b6ed-45cc-b8af-b4055a9b7666", // wifi setting
    "65609903-b6ed-45cc-b8af-b4055a9b7666", // wifi read
    "65609905-b6ed-45cc-b8af-b4055a9b7666", // setting completion
};

const char *DEVICE_NAME = "kikurage-device-m5-stack";

#endif // _KikurageBLEUUID_H_