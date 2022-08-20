#include <LiquidCrystal.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 6
#define DHTTYPE DHT11
int f = 8;
int h = 9;

DHT_Unified dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  pinMode(f, OUTPUT);
  pinMode(h, OUTPUT);
  digitalWrite(f, LOW);
  digitalWrite(h, LOW);
  dht.begin();
  
  lcd.print("DHT initalized");
  sensor_t sensor;
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(1000);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  int aaa = event.temperature;
  lcd.setCursor(0,0);
  lcd.print(aaa);
  if (aaa < 33) {
    digitalWrite(f, LOW);
    digitalWrite(h, HIGH);
  }
  else {
    digitalWrite(h, LOW);
    digitalWrite(f, HIGH);
  }
}
