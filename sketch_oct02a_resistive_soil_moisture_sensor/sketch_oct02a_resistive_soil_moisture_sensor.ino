int a = A1;
int r = 2;
int t = 800;
int b, c;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(a, INPUT);
pinMode(r, OUTPUT);
}

void loop() {
  b = analogRead(a);
  b = 1024 - b;
  if(b<=t){
    digitalWrite(r, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(r, LOW);
  }
  Serial.println(b);
}
