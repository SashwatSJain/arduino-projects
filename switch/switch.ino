#include <arduino_homekit_server.h>
#include "wifi_info.h"
#define LOG_D(fmt, ...)printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);
int PIN_SWITCH = 2;

void setup() {
  Serial.begin(115200);
  wifi_connect(); // in wifi_info.h
  //  homekit_storage_reset();
  my_homekit_setup();
}

void loop() {
  arduino_homekit_loop();
  //  my_homekit_loop();
  delay(10);
}

extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_switch_on;

static uint32_t next_heap_millis = 0;

//------------------------------------------------------------------------------------------

//called when the switch value is changed by ios home app
void cha_switch_on_setter(const homekit_value_t value) {
  bool on = value.bool_value;
  cha_switch_on.value.bool_value = on;	//sync the value
  LOG_D("Switch: %s", on ? "ON" : "OFF");
  digitalWrite(PIN_SWITCH, on ? LOW : HIGH);
}

//------------------------------------------------------------------------------------------

void my_homekit_setup() {
  pinMode(PIN_SWITCH, OUTPUT);
  digitalWrite(PIN_SWITCH, HIGH);

  //Add the .setter function to get the switch-event sent from iOS Home APP.
  //The .setter should be added before arduino_homekit_setup.
  //HomeKit sever uses the .setter_ex internally, see homekit_accessories_init function.
  //Maybe this is a legacy design issue in the original esp-homekit library,
  //and I have no reason to modify this "feature".
  cha_switch_on.setter = cha_switch_on_setter;
  arduino_homekit_setup(&config);

  //report the switch value to HomeKit if it is changed (e.g. by a physical button)
  bool switch_is_on = true / false;
  cha_switch_on.value.bool_value = switch_is_on;
  homekit_characteristic_notify(&cha_switch_on, cha_switch_on.value);
}
