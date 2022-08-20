
int led = 8;
int a, b;
void setup() {
  // put your setup code here, to run once:

  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  a = analogRead(A0);
  b = map(a, 0, 1024, 0, 255);
  Serial.println(b);
  analogWrite(led, b);
  delay(30);
  // put your main code here, to run repeatedly:

}
