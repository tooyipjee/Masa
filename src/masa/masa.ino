#include "credentials.h"
#include "Clock.h"
#include "Led.h"
#include "Masa_SHT20.h"
#include "OTA.h"
#include <Preferences.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <WiFi.h>
#include <nvs_flash.h>

#define     LEDS_COUNT  22
#define     LEDS_PIN_1  8
#define     LEDS_PIN_2  7
#define     LEDS_PIN_3  5
#define     LEDS_PIN_4  4

#define SDA       10
#define SCL       11
#define LIGHT_SIG 12

#define WIFI_PIN  0

Clock clk;
Led led_1;
Led led_2;
Led led_3;
Led led_4;
Masa_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
WiFiManager wm;
WiFiManagerParameter custom_param_timezone("tz", "Timezone", "", 40);
WiFiManagerParameter custom_param_weather("wt", "Location", "", 40);

String timezone;
String weather;
Preferences preferences;

void setup()
{
  Serial.begin(115200);
  preferences.begin("credentials", false); 
  wm.addParameter(&custom_param_timezone);
  wm.addParameter(&custom_param_weather);
  wm.setSaveParamsCallback(saveParamsCallback);
  delay(1000);
  // Configure and start the WiFi station
  WiFi.mode(WIFI_STA);
//  Reset the WM settings to relaunch web portal.
  if (digitalRead(WIFI_PIN) == LOW)
  {
//    nvs_flash_erase(); // erase the NVS partition and...
//    nvs_flash_init(); // initialize the NVS partition.
    wm.resetSettings();
  }
  bool res;
  res = wm.autoConnect("Masa_AP", "elektroThing"); // password protected app
  if (!res) {
    Serial.println("Failed to connect");
    wm.setConfigPortalTimeout(60);
    ESP.restart();
  }
  setupOTAWiFiMuted("Masa");

  waitForSync();
  Serial.println("Synced!");

  timezone = preferences.getString("timezone", "");
  weather = preferences.getString("weather", "");

  Serial.println(timezone);
  Serial.println(weather);

  clk.init(timezone.c_str(), 10);
  
  led_1.init(LEDS_PIN_1 , LEDS_COUNT);
  led_2.init(LEDS_PIN_2 , LEDS_COUNT);
  led_3.init(LEDS_PIN_3 , LEDS_COUNT);
  led_4.init(LEDS_PIN_4 , LEDS_COUNT);

  led_1.test();
  led_2.test();
  led_3.test();
  led_4.test();

  sht20.initSHT20();
  sht20.checkSHT20();

}
void loop()
{

  ArduinoOTA.handle();
  //  SHT20
  float humd = sht20.readHumidity(); //Read the measured data of air humidity
  float temp = sht20.readTemperature(); //Read the measured temp data

  Serial.println(temp);

  clk.update();

  int brightness = map(analogRead(LIGHT_SIG), 0, 8000, 2, 100);

  led_1.setBrightness(brightness);
  led_2.setBrightness(brightness);
  led_3.setBrightness(brightness);
  led_4.setBrightness(brightness);

  led_1.setLed(clk.getDigit(3), true);
  led_2.setLed(clk.getDigit(2), true);
  led_3.setLed(clk.getDigit(1), true);
  led_4.setLed(clk.getDigit(0), true);

  led_1.update();
  led_2.update();
  led_3.update();
  led_4.update();

  TelnetStream.println("Time: " + clk.getTime());
  TelnetStream.println(timezone);

  delay(500);
}

void saveParamsCallback () {
  String tz = custom_param_timezone.getValue();
  String wt = custom_param_weather.getValue();


  Serial.print("Timezone: "); Serial.println(tz);
  Serial.print("Weather: "); Serial.println(wt);

  preferences.putString("timezone", tz); 
  preferences.putString("weather", tz); 

}
