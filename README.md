**Masa: A Smart, Energy-Efficient Retro Clock**
=====================================================
**Introduction**
---------------
Masa, the Malaysian word for time, is a project that brings together modern electronic components to achieve a beautiful vintage look. Masa combines the aesthetic of traditional Nixie tubes with modern LED technology and advanced features.

**Project Overview**
--------------------
Masa is a type of electronic clock that replicates the vintage aesthetic of traditional Nixie clocks while using modern LED technology. It displays the time and can also display additional panels such as weather, tickers, and other illustrations. Masa has internet connectivity, allowing it to retrieve data from the internet and features several onboard environmental sensors.

**Key Features**
----------------
* LEDs with full brightness and color control
* Environmental sensor to measure room temperature and humidity
* Phototransistor for ambient light measurement
* ESP32-S2 to drive and interface with sensors and get the latest time from the NTP server over WiFi
* Compatible with rapidly prototype-able Cricut-based perspex "displays"
* Powered by USB-C

**Specification**
---------------
* Microcontroller: ESP32-S2
* WiFi: 802.11b/g/n
* FLASH: 4MB
* Programming: USB over UART
* Humidity and Temperature Sensor: SHT20
    + Capacitive type humidity sensor
    + Band gap temperature sensor
    + Digital processing unit - I2C
* Light Sensor: TEMT6000X01
    + High photo sensitivity
    + Adapted to human eye responsivity
    + Angle of half sensitivity ± 60°
* Power: USB-C + 3.3V LDO

**Acknowledgement**
----------------
Special thanks to JLCPCB for sponsoring this project. Their rapid prototyping and high-quality assembly services enabled us to bring this project to life.
