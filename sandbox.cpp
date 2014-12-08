 /*
  * (1) Read in the flex sensor voltage values through the ADC pins
  * (2) Use the obtained ADC voltage values to control PWM outputs
  * (3) Send PWM signals to the robotic arm
  *
  */

#include "Energia.h"


void setup();
void loop();

int thumbPin = 3;    // select the input pin for the potentiometer
int indexPin = 4;    // select the input pin for the potentiometer
int midPin = 5;    // select the input pin for the potentiometer
int clawPin = 6;
int wristPin = 7;
int armPin = 14;
int thumbVal = 0;  // variable to store the value coming from the sensor
int indexVal = 0;  // variable to store the value coming from the sensor
int midVal = 0;  // variable to store the value coming from the sensor
int clawVal = 0;
int wristVal = 0;
int armVal = 0;
const int maxClaw = 497;
const int maxWrist = 529;
const int maxArm = 526;
const int minClaw = 388;
const int minWrist = 366;
const int minArm = 427;
const int maxThumb = 699;
const int maxIndex = 678;
const int maxMid = 572;
const int minThumb = 648;
const int minIndex = 627;
const int minMid = 663;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
//  baseValue = analogRead(sensorPin);
//  pinMode(ledPin, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  thumbVal = analogRead(thumbPin);
  indexVal = analogRead(indexPin);
  midVal = analogRead(midPin);
  clawVal = analogRead(clawPin);
  wristVal = analogRead(wristPin);
  armVal = analogRead(armPin);
//  digit(sensorValue);

  if( (indexVal+10) > (maxIndex) && armVal > minArm){
	  digitalWrite(9,LOW);
	  digitalWrite(8,HIGH);
  } else if ( (indexVal-10) < (minIndex) && armVal < maxArm ){
	  digitalWrite(8, LOW);
	  digitalWrite(9,HIGH);
  } else {
	  digitalWrite(8, LOW);
	  digitalWrite(9, LOW);
  }

}


