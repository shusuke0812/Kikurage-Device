#ifndef _Sample_H_
#define _Sample_H_

#include <M5Stack.h>
#include "utility/MPU9250.h"

class Sample {
    private:
    float bfreq;
    MPU9250 IMU;

    public:
    void setupShowText();
    void setupDrawRect();
    void setupMPU9250();

    void loopShowImage();
    void loopVolume();
    void loopMPU9250();
};

#endif // _Sample_H_