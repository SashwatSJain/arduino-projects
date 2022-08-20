int a;
int op = 0;
int cl = 0;
int opp = 0, cll = 0;
int i;
int opd, cld;
int l = 13;
void setup() {
  pinMode(l, OUTPUT);
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
//  ################################
  Serial.println("open");
  delay(3000);
  for (i = 1; i < 21; i++) {
    opp = opp + analogRead(A0);
    delay(100);
    Serial.println(opp / i);
  }
  op = opp / 20;
  Serial.println(op);
//  #####################################
  Serial.println("close");
  delay(3000);
  for (i = 1; i < 21; i++) {
    cll = cll + analogRead(A0);
    delay(100);
    Serial.println(cll / i);
  }
  cl = cll / 20;
  Serial.println(cl);
//  ######################
}
void loop() {
  a = analogRead(A0);
  opd = (a - op);
  cld = (cl - a);
//  Serial.print("val");Serial.println(a);Serial.print("cld : ");Serial.println(cld);Serial.print("opd : ");Serial.println(opd);
  if (opd < cld) {
    Serial.println("open");
    digitalWrite(l, HIGH);
  }
  else {
    Serial.println("close");
    digitalWrite(l, LOW);
  }
  //  Serial.print()
  delay(5);
}
