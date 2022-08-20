#include <Servo.h>

Servo x;
int echoPin = 2;
int trigPin = 3;
long duration;
long distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  x.attach(5);
  x.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  distance = pulseIn(echoPin, HIGH) * 0.034 / 2;
  Serial.println(distance);
  delay(1000);
  if (distance < 10) {
    x.write(120);
    delay(5000);
    x.write(0);
  }
  else {
    Serial.print("");
    x.write(0);
  }

}
