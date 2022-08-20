
#include <DS3232RTC.h>

void setup()
{
//  lcd.begin(16,2);
  Serial.begin(9600);
  setSyncProvider(RTC.get);
}

void loop()
{
  Serial.print(hour());
  Serial.print(':');
  Serial.print(minute());
  Serial.print(':');
  Serial.print(second());
  Serial.print('|');
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print('/');
  Serial.println(year());
  delay(500);
//  lcd.setCursor(0, 1);
  
}
