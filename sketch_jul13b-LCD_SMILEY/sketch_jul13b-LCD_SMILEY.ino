#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

byte smiley[8] = {
  B00011,
  B00010,
  B01010,
  B11110,
  B10010,
  B10010,
  B10010,
};

void setup() {
  lcd.createChar(0, smiley);
  lcd.begin(16, 2);  
  lcd.write(byte(0));lcd.write(byte(0));lcd.write(byte(0));
}

void loop(){
  //haha
}
