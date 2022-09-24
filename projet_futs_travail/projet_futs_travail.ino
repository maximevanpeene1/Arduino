#include "SR04.h"
#define OUTPUT_PIN 13
#define TRIG_PIN 12
#define ECHO_PIN 11
#define DISTANCE_LIMITE 30 //en cm
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int triggerOutputLed(int distance){
  int outputState;
  if (distance>DISTANCE_LIMITE){
    outputState=HIGH;
  }
  else outputState=LOW;
  digitalWrite(OUTPUT_PIN,outputState);
}

void setup() {
   pinMode(OUTPUT_PIN,OUTPUT);
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   distance=sr04.Distance();
   Serial.println(distance);
   triggerOutputLed(distance);
   delay(1000);
}
