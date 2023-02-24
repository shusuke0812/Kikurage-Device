#ifndef _KikurageBLEUUID_H_
#define _KikurageBLEUUID_H_

#include <NimBLEDevice.h>

class KikurageBLEUUID {
  private:
    const char *SERVICE_UUID;
    const char *CHARACTERISTICS[4];

  public:
    const NimBLEUUID serviceId;
    const NimBLEUUID characteristicId;
};

#endif // _KikurageBLEUUID_H_