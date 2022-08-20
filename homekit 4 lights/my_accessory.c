#include <homekit/homekit.h>
#include <homekit/characteristics.h>

void my_accessory_identify(homekit_value_t _value)
{
    printf("accessory identify\n");
}

homekit_characteristic_t cha_switch_on_1 = HOMEKIT_CHARACTERISTIC_(ON, false);
homekit_characteristic_t cha_switch_on_2 = HOMEKIT_CHARACTERISTIC_(ON, false);
homekit_characteristic_t cha_switch_on_3 = HOMEKIT_CHARACTERISTIC_(ON, false);
homekit_characteristic_t cha_switch_on_4 = HOMEKIT_CHARACTERISTIC_(ON, false);

homekit_characteristic_t cha_name_1 = HOMEKIT_CHARACTERISTIC_(NAME, "Switch 1");
homekit_characteristic_t cha_name_2 = HOMEKIT_CHARACTERISTIC_(NAME, "Switch 2");
homekit_characteristic_t cha_name_3 = HOMEKIT_CHARACTERISTIC_(NAME, "Switch 3");
homekit_characteristic_t cha_name_4 = HOMEKIT_CHARACTERISTIC_(NAME, "Switch 4");

homekit_accessory_t *accessories[] = {
    HOMEKIT_ACCESSORY(.id = 1, .category = homekit_accessory_category_switch, .services = (homekit_service_t *[]){HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics = (homekit_characteristic_t *[]){HOMEKIT_CHARACTERISTIC(NAME, "Switch 1"), HOMEKIT_CHARACTERISTIC(MANUFACTURER, "SASHWAT"), HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0000000"), HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266"), HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0"), HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify), NULL}), HOMEKIT_SERVICE(SWITCH, .primary = true, .characteristics = (homekit_characteristic_t *[]){&cha_switch_on_1, &cha_name_1, NULL}), NULL}),
    HOMEKIT_ACCESSORY(.id = 2, .category = homekit_accessory_category_switch, .services = (homekit_service_t *[]){HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics = (homekit_characteristic_t *[]){HOMEKIT_CHARACTERISTIC(NAME, "Switch 2"), HOMEKIT_CHARACTERISTIC(MANUFACTURER, "SASHWAT"), HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0000000"), HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266"), HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0"), HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify), NULL}), HOMEKIT_SERVICE(SWITCH, .primary = true, .characteristics = (homekit_characteristic_t *[]){&cha_switch_on_2, &cha_name_2, NULL}), NULL}),
    HOMEKIT_ACCESSORY(.id = 3, .category = homekit_accessory_category_switch, .services = (homekit_service_t *[]){HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics = (homekit_characteristic_t *[]){HOMEKIT_CHARACTERISTIC(NAME, "Switch 3"), HOMEKIT_CHARACTERISTIC(MANUFACTURER, "SASHWAT"), HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0000000"), HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266"), HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0"), HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify), NULL}), HOMEKIT_SERVICE(SWITCH, .primary = true, .characteristics = (homekit_characteristic_t *[]){&cha_switch_on_3, &cha_name_3, NULL}), NULL}),
    HOMEKIT_ACCESSORY(.id = 4, .category = homekit_accessory_category_switch, .services = (homekit_service_t *[]){HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics = (homekit_characteristic_t *[]){HOMEKIT_CHARACTERISTIC(NAME, "Switch 4"), HOMEKIT_CHARACTERISTIC(MANUFACTURER, "SASHWAT"), HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0000000"), HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266"), HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0"), HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify), NULL}), HOMEKIT_SERVICE(SWITCH, .primary = true, .characteristics = (homekit_characteristic_t *[]){&cha_switch_on_4, &cha_name_4, NULL}), NULL}),
    NULL};

homekit_server_config_t config = {
    .accessories = accessories,
    .password = "157-51-575"};
