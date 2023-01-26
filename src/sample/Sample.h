#ifndef _Sample_H_
#define _Sample_H_

class Sample {
  private:
    float bfreq;

  public:
    void setupShowText();
    void setupDrawRect();
    void setupMPU9250();

    void loopShowImage();
    void loopVolume();
    void loopMPU9250();
};

#endif // _Sample_H_