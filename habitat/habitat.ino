#include <DHT.h>
#include <DHT_U.h>


// soil moisture, relays - 8, DHT-11
int r1 = 25;int r2 = 26;int r3 = 27;int r4 = 28;int r5 = 29;int r6 = 30;int r7 = 31;int r8 = 32;
int DHTPIN = 2;
int sm = A0;
int pass = 0;

#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// -------------------------------
int airval = 620;int wtval = 310;
// -------------------------------
int smval = 0;int smper = 0;

void setup() {
  pinMode(sm, INPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);2w
  DHT.begin();
}

void loop() {
  int
  //  --------------------------------------
  smper = map(smval, airval, wtval, 0, 100);
  if(smper>=100){
    smper = 100;
  }
  else if(smper<=0){
    smper = 0;
  }
  else
  {
    pass = 1;
  }
  // ---------------------------------------

}
