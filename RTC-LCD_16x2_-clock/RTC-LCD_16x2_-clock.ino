#include <LiquidCrystal.h>
#include <DS3232RTC.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  setSyncProvider(RTC.get);
}

void loop() {
  int d = day();
  int m = month();
  int y = year();
  int h = hour();
  int mi = minute();
  int s = second();
  lcd.home();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(h);

  lcd.setCursor(2, 0);
  lcd.print(":");


  lcd.setCursor(3, 0);
  lcd.print(mi);


  lcd.setCursor(5, 0);
  lcd.print(":");


  lcd.setCursor(6, 0);
  lcd.print(s);


  lcd.setCursor(0, 1);
  lcd.print(d);


  lcd.setCursor(2, 1);
  lcd.print("/");


  lcd.setCursor(3, 1);
  lcd.print(m);


  lcd.setCursor(5, 1);
  lcd.print("/");


  lcd.setCursor(6, 1);
  lcd.print(y);
  delay(1000);
  lcd.clear();

  //  lcd.print("Arduino"); // Prints "Arduino" on the LCD
  //  delay(3000); // 3 seconds delay
  //  lcd.setCursor(2, 1); // Sets the location at which subsequent text written to the LCD will be displayed
  //  lcd.print("LCD Tutorial");
  //  delay(3000);
  //  lcd.clear(); // Clears the display
  //  lcd.blink(); //Displays the blinking LCD cursor
  //  delay(4000);
  //  lcd.setCursor(7, 1);
  //  delay(3000);
  //  lcd.noBlink(); // Turns off the blinking LCD cursor
  //  lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written
  //  delay(4000);
  //  lcd.noCursor(); // Hides the LCD cursor
  //  lcd.clear(); // Clears the LCD screen
}
