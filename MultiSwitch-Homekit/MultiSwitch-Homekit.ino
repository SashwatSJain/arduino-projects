#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "wifi_info.h"

#define LOG_D(fmt, ...)   printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);

void setup() {
  Serial.begin(115200);
  wifi_connect();
  //homekit_storage_reset();
  my_homekit_setup();
}

void loop() {
  my_homekit_loop();
  delay(10);
}

extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_switch_on;

static uint32_t next_heap_millis = 0;

#define PIN_SWITCH 2

void cha_switch_on_setter(const homekit_value_t value) {
  bool on = value.bool_value;
  cha_switch_on.value.bool_value = on;
  LOG_D("Switch: %s", on ? "ON" : "OFF");
  digitalWrite(PIN_SWITCH, on ? LOW : HIGH);
}

void my_homekit_setup() {
  pinMode(PIN_SWITCH, OUTPUT);
  digitalWrite(PIN_SWITCH, HIGH);

  cha_switch_on.setter = cha_switch_on_setter;
  arduino_homekit_setup(&config);

//  bool switch_is_on = true/false;
//  cha_switch_on.value.bool_value = switch_is_on;
//  homekit_characteristic_notify(&cha_switch_on, cha_switch_on.value);
}

void my_homekit_loop() {
  arduino_homekit_loop();
  const uint32_t t = millis();
  if (t > next_heap_millis) {
    // show heap info every 5 seconds
    next_heap_millis = t + 5 * 1000;
    LOG_D("Free heap: %d, HomeKit clients: %d",
        ESP.getFreeHeap(), arduino_homekit_connected_clients_count());

  }
}
