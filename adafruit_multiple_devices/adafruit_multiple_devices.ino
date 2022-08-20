#include "config.h"
#define LED_PIN 2
int a = 2;
int b = 3;
int c = 4;
int d = 5;
// set up the 'digital' feed
AdafruitIO_Feed *digital1 = io.feed("front");
AdafruitIO_Feed *digital2 = io.feed("back");
AdafruitIO_Feed *digital3 = io.feed("left");
AdafruitIO_Feed *digital4 = io.feed("right");

void setup() {
  
  pinMode(LED_PIN, OUTPUT);
  
  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'digital' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  digital1->onMessage(handleMessage1);
  digital2->onMessage(handleMessage2);
  digital3->onMessage(handleMessage3);
  digital4->onMessage(handleMessage4);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  digital1->get();
  digital2->get();
  digital3->get();
  digital4->get();

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

}

// this function is called whenever an 'digital' feed message
// is received from Adafruit IO. it was attached to
// the 'digital' feed in the setup() function above.
void handleMessage1(AdafruitIO_Data *data) {

  Serial.print("received <- ");

  if(data->toPinLevel() == 1)
    Serial.println("1");
  else
    Serial.println("LOW");


  digitalWrite(LED_PIN, data->toPinLevel());
}

void handleMessage2(AdafruitIO_Data *data) {

  Serial.print("received <- ");

  if(data->toPinLevel() == 1)
    Serial.println("2");
  else
    Serial.println("LOW");


  digitalWrite(LED_PIN, data->toPinLevel());
}

void handleMessage3(AdafruitIO_Data *data) {

  Serial.print("received <- ");

  if(data->toPinLevel() == 1)
    Serial.println("3");
  else
    Serial.println("LOW");


  digitalWrite(LED_PIN, data->toPinLevel());
}

void handleMessage4(AdafruitIO_Data *data) {

  Serial.print("received <- ");

  if(data->toPinLevel() == 1)
    Serial.println("4");
  else
    Serial.println("LOW");


  digitalWrite(LED_PIN, data->toPinLevel());
}
