#include <RFID.h>
#include <SPI.h>
#include <Servo.h>

int SDA_DIO = 53;
int RESET_DIO = 48;
int buzz = 2;
int a, b, c, d;

long e;

const long key = 736786391;

RFID RC522(SDA_DIO, RESET_DIO);
Servo srv;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  RC522.init();
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz, LOW);
  srv.attach(3);
  srv.write(0);
  delay(1000);
  srv.write(180);
  delay(1000);
  srv.write(0);
}

void open() {
  digitalWrite(buzz, HIGH);
  delay(100);
  digitalWrite(buzz, LOW);
  srv.write(0);
}

void wrongKey() {
  srv.write(90);
  digitalWrite(buzz, HIGH);
  delay(60);
  digitalWrite(buzz, LOW);
  delay(60);
  digitalWrite(buzz, HIGH);
  delay(60);
  digitalWrite(buzz, LOW);
}

void loop() {
  if (RC522.isCard()) {
    RC522.readCardSerial();
    a = RC522.serNum[1];
    b = RC522.serNum[2];
    c = RC522.serNum[3];
    d = RC522.serNum[4];
    e = d + (100 * c) + (100000 * b) + (100000000 * a);
    RC522.readCardSerial();
    Serial.println(e);
    Serial.println("\n\n");

    if (e == key) {
      open();
      delay(10000);
      wrongKey();      
    }

    else {
      wrongKey();
      //hahaaa
    }

  } else {
    //abc
  }
}
