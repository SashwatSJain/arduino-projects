int x = A2;
int drx;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  drx = analogRead(x);
  Serial.println(drx);
  delay(100);

}
