int led = 13;
int flag;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
//  digitalWrite(led, LOW);
  Serial.begin(9600);
  flag = 0;
}

void loop() {

  switch (flag) {
    case 0:
      digitalWrite(led, HIGH);
      delay(500);
      flag = 1;
      break;

    case 1:
      digitalWrite(led, LOW);
      delay(500);
      flag = 0;
      break;

  }
//delay(1000);
}
