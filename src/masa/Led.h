#ifndef LED_H
#define LED_H

#include "Arduino.h"
#include "Freenove_WS2812_Lib_for_ESP32.h"


#define     CHANNEL     0

class Led
{
  public:
    Led();
    void init(int pin, int _count);
    void test();
    void update();
    void setBrightness(int _brightness);
    void setLed(int digit, bool useInterlace);
    void reset();

  private:
    Freenove_ESP32_WS2812* strip; // = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN_1, CHANNEL, TYPE_GRB);
    int brightness = 5;
    int count = 0;

    u8 color[3] = {255, 191, 0};
    u8 selectedLed[4] = {0, 8, 13, 21};

    u8 m_color[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0} };
    u8 digit_row_interlace[11][4] = {
      {0, 8, 13, 21},   //0
      {7, 8, 13, 14},   //1
      {1, 7, 14, 20},   //2
      {1, 9, 12, 20},   //3
      {6, 9, 12, 15},   //4
      {2, 6, 15, 19},   //5  
      {2, 10, 11, 19},  //6
      {5, 10, 11, 16},  //7
      {3, 5, 16, 18},   //8
      {3, 4, 17, 18}    //9
    };
    u8 digit_row[11][2] = {
      {0, 21},          //0
      {8, 13},          //1
      {7, 14},          //2
      {1, 20},          //3
      {9, 12},          //4
      {6, 15},          //5
      {2, 19},          //6
      {10, 11},         //7
      {5, 16},          //8
      {3, 18},          //9
      {3, 18},          //10
    };
};


#endif
