int led = 13;
int x = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop() {
  switch (x) {
    case 5:
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);;
      break;

    default:
      digitalWrite(led, LOW);
      break;
  }
  // put your main code here, to run repeatedly:

}
