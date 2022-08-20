int echo = 9;
int trig = 10;
long duration, distance, wall, interrupt;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  wall = duration * 0.017;
  Serial.print("wall : ");
  Serial.println(wall);
  delay(5000);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  interrupt = duration * 0.017;
  Serial.print("interrupt : ");
  Serial.println(interrupt);
  Serial.println(wall-interrupt);

}

void loop()
{

}
