#include "clSonar.h"
#include "clPotentiometer.h"

// DEFINE PINS

#define TRIGPIN_1 2
#define ECHOPIN_1 3

#define TRIGPIN_2 4
#define ECHOPIN_2 5

#define TRIGPIN_3 6
#define ECHOPIN_3 7

#define TRIGPIN_4 8
#define ECHOPIN_4 9

#define TRIGPIN_5 10
#define ECHOPIN_5 11

#define TRIGPIN_6 12
#define ECHOPIN_6 13

#define POTPIN_1 14

// INIT CLASS INSTANCE

clSonar sonar1(TRIGPIN_1, ECHOPIN_1, 0);
clSonar sonar2(TRIGPIN_2, ECHOPIN_2, 1);
clSonar sonar3(TRIGPIN_3, ECHOPIN_3, 2);
clSonar sonar4(TRIGPIN_4, ECHOPIN_4, 3);
clSonar sonar5(TRIGPIN_5, ECHOPIN_5, 4);
clSonar sonar6(TRIGPIN_6, ECHOPIN_6, 5);

clPotentiometer pot1(POTPIN_1, 0);

// GENERAL SETUP

void setup() {
  Serial.begin(115200); 
}

// LOOP

void loop() {
  sonar1.updateMidi();
  sonar2.updateMidi();
  sonar3.updateMidi();
  sonar4.updateMidi();
  sonar5.updateMidi();
  sonar6.updateMidi();

  sonar6.updateMidi();
  delay(100); 
}
