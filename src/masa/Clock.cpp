#include "Clock.h"

Clock::Clock()
{

};

void Clock::init(const char* _timezone, int _updatePeriod_s)
{
  timeObj.setLocation(_timezone);
  updatePeriod_s = _updatePeriod_s*1000;

};

void Clock::update()
{
  if(millis() > lastUpdateTick + updatePeriod_s)
  {
    lastUpdateTick = millis();
    currentTime = timeObj.dateTime();

    D = timeObj.day();
    M = timeObj.month();
    Y = timeObj.year();
    h = timeObj.hour();
    m = timeObj.minute();
    s = timeObj.second();

    ledTime[0] = h;
    ledTime[1] = m;
  }
  
};

String Clock::getTime()
{
  return currentTime;
}

int Clock::getHour()
{
  return h;
}

int Clock::getMin()
{
  return m;
}

int Clock::getLedTime()
{
  return h*100+m;
}

int Clock::getDigit(int idx)
{
//  Get index - 0 to 3 (from right to left) - e.g. 0 is the minute, 3 is the hour 
  int t = h*100+m;
  for (int i = 0; i < idx; i++)
  {
    
    t = t/10;
//    Serial.println(t);
  }
  t = t%10;
  return t;
}
