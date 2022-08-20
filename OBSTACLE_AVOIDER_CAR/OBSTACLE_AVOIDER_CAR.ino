int m1a = 22;
int m1b = 23;
int m2a = 24;
int m2b = 25;

int echo = 10;
int trig = 9;
long dist, dur;

void setup() {
  // put your setup code here, to run once:
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  digitalWrite(trig, LOW);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dist = dur * 0.034 / 2;
  Serial.println(dist);
  //     B  F  L  R
  // M1A 0  1  0  1
  // M1B 1  0  1  0
  // M2A 0  1  1  0
  // M2B 1  0  0  1
  // M1- LEFT
  // M2- RIGHT
  //  digitalWrite(m1a, LOW);
  //  digitalWrite(m1b, LOW);
  //  digitalWrite(m2a, LOW);
  //  digitalWrite(m2b, LOW);

  if (dist < 10)
  {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
  }
  else
  {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
  }

}
