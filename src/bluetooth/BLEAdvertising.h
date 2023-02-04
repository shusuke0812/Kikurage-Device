#ifndef _BLEAdvertising_H_
#define _BLEAdvertising_H_

#include <ArduinoBLE.h>

class BLEAdvertising {
  private:
    BLEService kikurageService;
    BLEIntCharacteristic kikurageCharacteristic;
    void initializeBLE();

  public:
    void kikurageAdverise();
    void kikuragePoll();
};

#endif // _BLEAdvertising_H_