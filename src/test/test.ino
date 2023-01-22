#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  22
#define LEDS_PIN_1  8 
#define LEDS_PIN_2  7 
#define LEDS_PIN_3  5 
#define LEDS_PIN_4  4 
#define CHANNEL   0

Freenove_ESP32_WS2812 strip_1 = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN_1, CHANNEL, TYPE_GRB);
Freenove_ESP32_WS2812 strip_2 = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN_2, CHANNEL, TYPE_GRB);
Freenove_ESP32_WS2812 strip_3 = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN_3, CHANNEL, TYPE_GRB);
Freenove_ESP32_WS2812 strip_4 = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN_4, CHANNEL, TYPE_GRB);

u8 m_color[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0} };
int delayval = 100;
u8 digit_row_interlace[11][4] = {
  {0,8,13,21},
  {7,8,13,14},
  {1,7,14,20},
  {1,9,12,20},
  {6,9,12,15},
  {2,6,15,19},
  {2,10,11,19},
  {5,10,12,16},
  {3,5,16,18},
  {3,4,17,18}
};

u8 digit_row[11][2] = {
  {0,21},
  {8,13},
  {7,14},
  {1,20},
  {9,12},
  {6,15},
  {2,19},
  {10,11},
  {5,16},
  {3,18},  
  {3,18},
};

void setup() {
  strip_1.begin();
  strip_1.setBrightness(10);  

  strip_2.begin();
  strip_2.setBrightness(10);  

  strip_3.begin();
  strip_3.setBrightness(10);  

  strip_4.begin();
  strip_4.setBrightness(10);  

  Serial.begin(115200);
}
void loop() {
//  for (int j = 0; j < 5; j++) {
//    for (int i = 0; i < LEDS_COUNT; i++) {
////      strip_1.setLedColorData(i, m_color[j][0], m_color[j][1], m_color[j][2]);
////      strip_1.show();
////
////      strip_2.setLedColorData(i, m_color[j][0], m_color[j][1], m_color[j][2]);
////      strip_2.show();
////
////      strip_3.setLedColorData(i, m_color[j][0], m_color[j][1], m_color[j][2]);
////      strip_3.show();
//
//      strip_4.setLedColorData(i, m_color[j][0], m_color[j][1], m_color[j][2]);
//      strip_4.show();
//      
//      
//      
//      delay(delayval);
//    }
//    delay(500);
//  }
  for (int i = 0; i < 11; i++) {
   for (int j = 0; j < 5; j++) {
      
      strip_1.setLedColorData(digit_row[i][0], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip_1.setLedColorData(digit_row[i][1], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip_1.show();
      
      strip_2.setLedColorData(digit_row_interlace[i][0], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip_2.setLedColorData(digit_row_interlace[i][1], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip_2.setLedColorData(digit_row_interlace[i][2], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip_2.setLedColorData(digit_row_interlace[i][3], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip_2.show();

      for (int k = 0; k < LEDS_COUNT; k++)
      {
        strip_3.setLedColorData(k, m_color[j][0], m_color[j][1], m_color[j][2]);
        
      }
      strip_3.show();
      
      delay(delayval);
    }
    delay(500);
  }
  
}
