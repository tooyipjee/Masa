#include "Led.h"
Led::Led()
{

};

void Led::init(int pin, int _count)
{
  strip = new Freenove_ESP32_WS2812(_count, pin, CHANNEL, TYPE_GRB);
  count = _count;
  strip->begin();
  strip->setBrightness(brightness);
};

void Led::update()
{
  //  Update the strip object with the latest settings
  strip->setBrightness(brightness);
  reset();
  //  For each Led in list
  for (int i = 0; i < 4; i++)
  {
    strip->setLedColorData(selectedLed[i], color[0], color[1], color[2]);
  }

  //  Show the strip
  strip->show();
}
void Led::setLed(int digit, bool useInterlace)
{ 

  if (useInterlace)
  {
    selectedLed[0] = digit_row_interlace[digit][0];
    selectedLed[1] = digit_row_interlace[digit][1];
    selectedLed[2] = digit_row_interlace[digit][2];
    selectedLed[3] = digit_row_interlace[digit][3];
  }
  else
  {
    selectedLed[0] = digit_row[digit][0];
    selectedLed[1] = digit_row[digit][1];
    selectedLed[2] = digit_row[digit][0];
    selectedLed[3] = digit_row[digit][1];
  }
}

void Led::reset()
{
  for (int idx = 0; idx < count; idx++) 
  {
    strip->setLedColorData(idx, m_color[4][0], m_color[4][0], m_color[4][0]);
  }
}

void Led::setBrightness(int _brightness)
{
  brightness = _brightness;
  
}
void Led::test()
{
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < count; i++) {
      strip->setLedColorData(i, m_color[j][0], m_color[j][1], m_color[j][2]);
      strip->show();
      delay(10);
    }
    delay(10);
  }
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 5; j++) {

      strip->setLedColorData(digit_row[i][0], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip->setLedColorData(digit_row[i][1], m_color[j][0], m_color[j][1], m_color[j][2]);
      strip->show();

      delay(10);
    }
    delay(10);
  }
};
