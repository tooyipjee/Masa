#ifndef CLOCK_H
#define CLOCK_H

#include "Arduino.h"
#include <ezTime.h>

class Clock
{
  public:
    Clock();
    void init(const char* _timezone, int _updatePeriod_s);
    void update();
    String getTime();
    int getHour();
    int getMin();
    int getLedTime();
    int getDigit(int idx);
    
  private:
    Timezone timeObj;
    String currentTime;
    double lastUpdateTick = 0;
    int updatePeriod_s = 0;    
    int D, M, Y, h, m, s;

    int ledTime[2];
};


#endif
