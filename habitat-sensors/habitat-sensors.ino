#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

#define sms1 A0
#define sms2 A1

DHT dht(DHTPIN, DHTTYPE);
int AirValue = 835;
int WaterValue = 395;
int soilMoistureValue = 0;int soilMoistureValue2 = 0;
int soilmoisturepercent = 0;
void setup() {
  pinMode(sms1, INPUT);
  pinMode(sms2, INPUT);
  Serial.begin(9600);
  dht.begin();

}
void loop() {

  soilMoistureValue = analogRead(sms1);
  soilMoistureValue2 = analogRead(sms2);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  soilmoisturepercent = map((soilMoistureValue + soilMoistureValue2)/2, AirValue, WaterValue, 0, 100);
  if (soilmoisturepercent >= 100)
  {
    Serial.print("soilmoisturepercent : 100 % ");
  }
  else if (soilmoisturepercent <= 0)
  {
    Serial.print("soilmoisturepercent : 0 % ");
  }
  else if (soilmoisturepercent > 0 && soilmoisturepercent < 100)
  {
    Serial.print("soilmoisturepercent : ");
    Serial.print(soilmoisturepercent);
    Serial.print(" % ");
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F(" %  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  delay(3000);
}
