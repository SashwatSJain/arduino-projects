#include <Servo.h>
int echo = 2;
int trig = 3;
int x; //open pos
int y; //close pos
long duration;
int distance;
Servo myservo;
int pos;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  myservo.attach(4);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.00017;

  if (distance < 15) {
    myservo.write(x);
    //servo open
    delay(10000);
    //wait 10 seconds
    myservo.write(y);
    //servo close
  }
}
