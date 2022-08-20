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
#define APP_KEY           "40e73d7d-8939-45d1-b9c2-eb666dce36cb"      // Should look like "de0bxxxx-1x3x-4x3x-ax2x-5dabxxxxxxxx"
#define APP_SECRET        "907de164-501b-4a6a-a01a-ea77b992578e-f3e48be4-6dcd-4d2d-a20a-c31529cdcca6"   // Should look like "5f36xxxx-x3x7-4x3x-xexe-e86724a9xxxx-4c4axxxx-3x3x-x5xe-x9x3-333d65xxxxxx"
#define SWITCH_ID          "60b0c1308cf8a303b939697a"    // Should look like "5dc1564130xxxxxxxxxxxxxx"

#define BAUD_RATE         9600                // Change baudrate to your need

#define RELAY_PIN         D5                  // Pin where the relay is connected (D5 = GPIO 14 on ESP8266)

bool onPowerState(const String &deviceId, bool &state) {
  digitalWrite(RELAY_PIN, state);             // set pin state
  return true;                                // request handled properly
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);                 // set relay-pin to output mode
  WiFi.begin(WIFI_SSID, WIFI_PASS);           // start wifi

  SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];   // create new switch device
  mySwitch.onPowerState(onPowerState);                // apply onPowerState callback
  SinricPro.begin(APP_KEY, APP_SECRET);               // start SinricPro
}

void loop() {
  SinricPro.handle();                         // handle SinricPro commands
}
