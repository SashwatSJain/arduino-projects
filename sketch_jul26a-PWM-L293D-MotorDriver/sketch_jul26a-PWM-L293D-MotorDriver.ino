int en = 2;
int c = 4;
int cc = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(en, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(cc, OUTPUT);
  Serial.begin(9600);
  digitalWrite(c, LOW);
  digitalWrite(cc, LOW);
  analogWrite(en, 0);
}

void loop() {
  digitalWrite(c, HIGH);
  digitalWrite(cc, LOW);
  analogWrite(en, 255);
  delay(2000);
  digitalWrite(c, HIGH);
  digitalWrite(cc, LOW);
  analogWrite(en, 155);
  delay(2000);
  digitalWrite(c, HIGH);
  digitalWrite(cc, LOW);
  analogWrite(en, 80);
  delay(2000);
  digitalWrite(cc, HIGH);
  digitalWrite(c, LOW);
  analogWrite(en, 255);
  delay(2000);
  digitalWrite(cc, HIGH);
  digitalWrite(c, LOW);
  analogWrite(en, 155);
  delay(2000);
  digitalWrite(cc, HIGH);
  digitalWrite(c, LOW);
  analogWrite(en, 80);
  delay(2000);
}
