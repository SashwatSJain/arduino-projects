
int echo = 9;
int trig = 10;
int buzz = 13;

int m = 2;
int n = 3;
int o = 4;
int p = 5;
int q = 6;

long d;
long t;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(m, OUTPUT);
  pinMode(n, OUTPUT);
  pinMode(o, OUTPUT);
  pinMode(p, OUTPUT);
  pinMode(q, OUTPUT);
  digitalWrite(m, LOW);
  digitalWrite(n, LOW);
  digitalWrite(o, LOW);
  digitalWrite(p, LOW);
  digitalWrite(q, LOW);
  digitalWrite(buzz, HIGH);
  delay(100);
  digitalWrite(buzz, LOW);
  delay(100);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH);
  d = t * 0.017;

  Serial.println(d);
  if (d < 20)
  {
    digitalWrite(m, HIGH);
    digitalWrite(n, LOW);
    digitalWrite(o, LOW);
    digitalWrite(p, LOW);
    digitalWrite(q, LOW);
    digitalWrite(buzz, HIGH);

  }
  else if (19 < d && d < 40)
  {
    digitalWrite(m, HIGH);
    digitalWrite(n, HIGH);
    digitalWrite(o, LOW);
    digitalWrite(p, LOW);
    digitalWrite(q, LOW);
    digitalWrite(buzz, LOW);
  }

  else if (d > 39 && d < 60)
  {
    digitalWrite(m, HIGH);
    digitalWrite(n, HIGH);
    digitalWrite(o, HIGH);
    digitalWrite(p, LOW);
    digitalWrite(q, LOW);
    digitalWrite(buzz, LOW);
  }

  else if (59 < d && d < 80)
  {
    digitalWrite(m, HIGH);
    digitalWrite(n, HIGH);
    digitalWrite(o, HIGH);
    digitalWrite(p, HIGH);
    digitalWrite(q, LOW);
    digitalWrite(buzz, LOW);
  }

  else if (79 < d)
  {
    digitalWrite(m, HIGH);
    digitalWrite(n, HIGH);
    digitalWrite(o, HIGH);
    digitalWrite(p, HIGH);
    digitalWrite(q, HIGH);
    digitalWrite(buzz, LOW);
  }
  delay(100);
}
