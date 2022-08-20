// {soil moisture, humidity, temperature}
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int cx = 0;

#define DHTPIN2 3
#define DHTTYPE2 DHT11
DHT dht2(DHTPIN2, DHTTYPE2);
int lightrelay = 8;


int soilMoistureValue1;
int soilMoistureValue2;

void setup() {
  Serial.begin(9600);
  pinMode(lightrelay, OUTPUT)
  dht.begin();
  dht2.begin();
  
}

void loop() {
  cx=1;
  
  soilMoistureValue1 = analogRead(A0);
  float h1 = dht.readHumidity();
  float t1 = dht.readTemperature();

  soilMoistureValue2 = analogRead(A1);
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();


  //  Serial.print("{" + soilMoistureValue1 +","+ h1 + ","+ t1, ","+ soilMoistureValue2+","+h2+ ","+ t2+ "}");
  Serial.print("{");
  Serial.print(soilMoistureValue1);
  Serial.print(",");
  Serial.print(h1);
  Serial.print(",");
  Serial.print(t1);
  Serial.print(",");
  Serial.print(soilMoistureValue2);
  Serial.print(",");
  Serial.print(h2);
  Serial.print(",");
  Serial.print(t2);
  Serial.println("}");
  delay(1800000);
}
