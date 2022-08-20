const int buzzer = 2;
const int ldr = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);

}

void ring() {
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(ldr) == HIGH) {
    ring();
  }
  else {
    digitalWrite(buzzer, LOW);
  }

}
