
// LED

const int p = 3;
const int q = 5;
const int r = 6;
const int s = 9;
const int t = 10;

// flex sensors

const int a = A4;
const int b = A3;
const int c = A2;
const int d = A1;
const int e = A0;

int va; int vb; int vc; int vd; int ve;

void setup() {
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
  pinMode(d, INPUT);
  pinMode(e, INPUT);

  pinMode(p, OUTPUT);
  pinMode(q, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(t, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  va = analogRead(a);
  vb = analogRead(b);
  vc = analogRead(c);
  vd = analogRead(d);
  ve = analogRead(e);
  
  Serial.print(va);
  Serial.print(", ");
  Serial.print(vb);
  Serial.print(", ");
  Serial.print(vc);
  Serial.print(", ");
  Serial.print(vd);
  Serial.print(", ");
  Serial.println(ve);
  
  va = map(va, 17, 100, 0, 255);
  vb = map(vb, 70, 240, 0, 255);
  vc = map(vc, 150, 290, 0, 255);
  vd = map(vd, 125, 290, 0, 255);
  ve = map(ve, 150, 290, 0, 255);


  analogWrite(p, va);
  analogWrite(q, vb);
  analogWrite(r, vc);
  analogWrite(s, vd);
  analogWrite(t, ve);
  delay(500);
}
