int relay = 2;
int ir = 3;
int ird;
void setup() {
  pinMode(relay, OUTPUT);
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  ird = digitalRead(ir);
  if (ird == LOW){
    digitalWrite(relay, LOW);
  }
  else{
    digitalWrite(relay, HIGH);
    delay(300);
    digitalWrite(relay, LOW);
  }
}
