int l2 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(l2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(l2, HIGH);
  delay(1000);
  digitalWrite(l2, LOW);
  delay(1000);
}
