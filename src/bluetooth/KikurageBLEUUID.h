#ifndef _KikurageBLEUUID_H_
#define _KikurageBLEUUID_H_

struct KikurageBLEUUID {
    public:
    const char *SERVICE_UUID;
    const char *CHARACTERISTICS[4];
    const char *DEVICE;
};

#endif // _KikurageBLEUUID_H_