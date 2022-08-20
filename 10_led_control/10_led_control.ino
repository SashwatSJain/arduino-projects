int a = 22; int b = 23; int c = 24; int d = 25; int e = 26; int f = 27; int g = 28; int h = 29; int i = 30; int j = 31;
int x, y;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(i, OUTPUT);
  pinMode(j, OUTPUT);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);it
  digitalWrite(i, LOW);
  digitalWrite(j, LOW);

  for (x = 22; x <= 31; x++) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(h, HIGH);
    digitalWrite(i, HIGH);
    digitalWrite(j, HIGH);
    delay(1000);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(h, LOW);
    digitalWrite(i, LOW);
    digitalWrite(j, LOW);
    delay(1000);
  }
}

void loop() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
  digitalWrite(i, LOW);
  digitalWrite(j, LOW);

}
