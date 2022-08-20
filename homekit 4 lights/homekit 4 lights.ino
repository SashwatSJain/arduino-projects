#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "wifi_info.h"
#define LOG_D(fmt, ...) printf_P(PSTR(fmt "\n"), ##__VA_ARGS__);
extern "C" homekit_server_config_t config;
#define LOG_D(fmt, ...) printf_P(PSTR(fmt "\n"), ##__VA_ARGS__);

#define PIN_SWITCH_1 14
#define PIN_SWITCH_2 16
#define PIN_SWITCH_3 5
#define PIN_SWITCH_4 4

extern "C" homekit_characteristic_t cha_switch_on_1;
extern "C" homekit_characteristic_t cha_switch_on_2;
extern "C" homekit_characteristic_t cha_switch_on_3;
extern "C" homekit_characteristic_t cha_switch_on_4;

void cha_switch_on_setter_1(const homekit_value_t value){
  bool on1 = value.bool_value;
  cha_switch_on_1.value.bool_value = on1;
  LOG_D("Switch(1): %s", on1 ? "ON" : "OFF");
  digitalWrite(PIN_SWITCH_1, on1 ? LOW : HIGH);
  homekit_characteristic_notify(&cha_switch_on_1, cha_switch_on_1.value);
  }

void cha_switch_on_setter_2(const homekit_value_t value){
  bool on2 = value.bool_value;
  cha_switch_on_2.value.bool_value = on2;
  LOG_D("Switch(2): %s", on2 ? "ON" : "OFF");
  digitalWrite(PIN_SWITCH_2, on2 ? LOW : HIGH);
  homekit_characteristic_notify(&cha_switch_on_2, cha_switch_on_2.value);
  }

void cha_switch_on_setter_3(const homekit_value_t value){
  bool on3 = value.bool_value;
  cha_switch_on_3.value.bool_value = on3;
  LOG_D("Switch(3): %s", on3 ? "ON" : "OFF");
  digitalWrite(PIN_SWITCH_3, on3 ? LOW : HIGH);
  homekit_characteristic_notify(&cha_switch_on_3, cha_switch_on_3.value);
  }

void cha_switch_on_setter_4(const homekit_value_t value){
  bool on4 = value.bool_value;
  cha_switch_on_4.value.bool_value = on4;
  LOG_D("Switch(4): %s", on4 ? "ON" : "OFF");
  digitalWrite(PIN_SWITCH_4, on4 ? LOW : HIGH);
  homekit_characteristic_notify(&cha_switch_on_4, cha_switch_on_4.value);
  }



void my_homekit_setup()
{
  pinMode(PIN_SWITCH_1, OUTPUT);
  pinMode(PIN_SWITCH_2, OUTPUT);
  pinMode(PIN_SWITCH_3, OUTPUT);
  pinMode(PIN_SWITCH_4, OUTPUT);

  digitalWrite(PIN_SWITCH_1, HIGH);
  digitalWrite(PIN_SWITCH_2, HIGH);
  digitalWrite(PIN_SWITCH_3, HIGH);
  digitalWrite(PIN_SWITCH_4, HIGH);
  
  cha_switch_on_1.setter = cha_switch_on_setter_1;
  cha_switch_on_2.setter = cha_switch_on_setter_2;
  cha_switch_on_3.setter = cha_switch_on_setter_3;
  cha_switch_on_4.setter = cha_switch_on_setter_4;

  arduino_homekit_setup(&config);

  bool switch_is_on_1 = false;
  bool switch_is_on_2 = false;
  bool switch_is_on_3 = false;
  bool switch_is_on_4 = false;

  cha_switch_on_1.value.bool_value = switch_is_on_1;
  cha_switch_on_2.value.bool_value = switch_is_on_2;
  cha_switch_on_3.value.bool_value = switch_is_on_3;
  cha_switch_on_4.value.bool_value = switch_is_on_4;
  
  homekit_characteristic_notify(&cha_switch_on_1, cha_switch_on_1.value);
  homekit_characteristic_notify(&cha_switch_on_2, cha_switch_on_2.value);
  homekit_characteristic_notify(&cha_switch_on_3, cha_switch_on_3.value);
  homekit_characteristic_notify(&cha_switch_on_4, cha_switch_on_4.value);
}

void setup()
{
  
  Serial.begin(115200);
  wifi_connect();
  homekit_storage_reset();
  my_homekit_setup();
}

void loop()
{
  arduino_homekit_loop();
}
