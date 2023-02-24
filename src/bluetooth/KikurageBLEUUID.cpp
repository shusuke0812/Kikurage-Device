#include "KikurageBLEUUID.h"

const char *SERVICE_UUID = "65609901-b6ed-45cc-b8af-b4055a9b7666";
const char *CHARACTERISTICS[] = {
  "65609902-b6ed-45cc-b8af-b4055a9b7666",
  "65609903-b6ed-45cc-b8af-b4055a9b7666",
  "65609904-b6ed-45cc-b8af-b4055a9b7666",
  "65609905-b6ed-45cc-b8af-b4055a9b7666",
};

const char *DEVICE = "kikurage-device-m5-stack"

NimBLEUUID serviceId(SERVICE_UUID);
NimBLEUUID characteristicId(CHARACTERISTICS[0]);