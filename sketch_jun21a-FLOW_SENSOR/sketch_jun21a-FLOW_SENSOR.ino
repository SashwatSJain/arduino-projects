float vol = 0.0, l_minute;
const int flowsensor = 2;
long currentTime;
long cloopTime;
int flow_frequency;


void flow () 
{
  flow_frequency++;
}


void setup()
{
  Serial.begin(9600);
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH);
  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING);
  currentTime = millis();
  cloopTime = currentTime;
}


void loop ()
{
  currentTime = millis();
  if (currentTime >= (cloopTime + 1000))
  {
    cloopTime = currentTime;
    if (flow_frequency != 0)
    {
      l_minute = (flow_frequency / 7.5);
      l_minute = l_minute / 60;
      vol = vol + l_minute;
      Serial.println(vol);
      flow_frequency = 0; 
    }
    else {
      Serial.println(vol);
    }
  }
}
