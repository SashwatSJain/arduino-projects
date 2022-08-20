int led = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(led, 255);
  delay(1000);
  analogWrite(led, 205);
  delay(1000);
  analogWrite(led, 155);
  delay(1000);
  analogWrite(led, 105);
  delay(1000);
  analogWrite(led, 55);
  delay(1000);
}
