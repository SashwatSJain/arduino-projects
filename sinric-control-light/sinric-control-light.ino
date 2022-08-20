/*
   If you encounter any issues:
   - check the readme.md at https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md
   - ensure all dependent libraries are installed
     - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#arduinoide
     - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#dependencies
   - open serial monitor and check whats happening
   - check full user documentation at https://sinricpro.github.io/esp8266-esp32-sdk
   - visit https://github.com/sinricpro/esp8266-esp32-sdk/issues and check for existing issues or open a new one
*/

// Uncomment the following line to enable serial debug output
//#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif

#include <Arduino.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#endif
#ifdef ESP32
#include <WiFi.h>
#endif

#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID         "SHANTINIVAS"
#define WIFI_PASS         "jain9999"
#define APP_KEY           "40e73d7d-8939-45d1-b9c2-eb666dce36cb"
#define APP_SECRET        "907de164-501b-4a6a-a01a-ea77b992578e-f3e48be4-6dcd-4d2d-a20a-c31529cdcca6"
#define SWITCH_ID         "60b0c1308cf8a303b939697a"
#define BAUD_RATE         9600

#define RELAY_PIN         D5

bool onPowerState(const String &deviceId, bool &state) {
  digitalWrite(RELAY_PIN, state);
  return true;
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];
  mySwitch.onPowerState(onPowerState);
  SinricPro.begin(APP_KEY, APP_SECRET);
}

void loop() {
  SinricPro.handle();
}
