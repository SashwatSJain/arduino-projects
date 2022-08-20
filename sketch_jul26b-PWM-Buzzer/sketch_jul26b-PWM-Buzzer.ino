int buzzer = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(buzzer, 255);
  delay(500);
  analogWrite(buzzer, 205);
  delay(500);
  analogWrite(buzzer, 155);
  delay(500);
  analogWrite(buzzer, 105);
  delay(500);
  analogWrite(buzzer, 55);
  delay(500);
  analogWrite(buzzer, 0);
  delay(500);
  
}
