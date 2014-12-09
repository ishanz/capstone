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
const int clawIn1 = 10;
const int clawIn2 = 11;
const int armIn1 = 8;
const int armIn2 = 9;
const int wristIn1 = 12;
const int wristIn2 = 13;
const int maxClaw = 475;
const int maxWrist = 529;
const int maxArm = 526;
const int minClaw = 388;
const int minWrist = 450;
const int minArm = 427;
const int maxThumb = 699;
const int maxIndex = 678;
const int maxMid = 572;
const int minThumb = 648;
const int minIndex = 627;
const int minMid = 663;
int mappedValue = 0;

void setup() {
  Serial.begin(9600);
  digitalWrite(armIn1, LOW);
  digitalWrite(armIn2, LOW);
  digitalWrite(clawIn1, LOW);
  digitalWrite(clawIn2, LOW);
  digitalWrite(wristIn1, LOW);
  digitalWrite(wristIn2, LOW);
  pinMode(armIn1, OUTPUT);
  pinMode(armIn2, OUTPUT);
  pinMode(clawIn1, OUTPUT);
  pinMode(clawIn2, OUTPUT);
  pinMode(wristIn1, OUTPUT);
  pinMode(wristIn2, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  thumbVal = analogRead(thumbPin);
  indexVal = analogRead(indexPin);
  midVal = analogRead(midPin);
  clawVal = analogRead(clawPin);
  wristVal = analogRead(wristPin);
  armVal = analogRead(armPin);

//  mappedValue = map(indexVal, minIndex, maxIndex, minArm, maxArm);

//  if (armVal > minArm && armVal < maxArm) {
//	  if (mappedValue+20 > armVal && armVal > minArm) { //move up
//		  digitalWrite(9, LOW);
//		  digitalWrite(8, HIGH);
//	  } else if (mappedValue+20 < armVal && armVal < maxArm) { //move down
//		  digitalWrite(8, LOW);
//		  digitalWrite(9, HIGH);
//	  } else {
//		  digitalWrite(9, LOW);
//		  digitalWrite(8, LOW);
//	  }
//  } else {
//	  digitalWrite(9, LOW);
//	  digitalWrite(8, LOW);
//  }


  // Index to Arm
  if ((indexVal+5 > maxIndex) && (armVal > minArm)){
	  digitalWrite(armIn2, LOW);
	  digitalWrite(armIn1, HIGH);
  } else if ((indexVal-5 < minIndex) && (armVal < maxArm)){
	  digitalWrite(armIn1, LOW);
	  digitalWrite(armIn2, HIGH);
  } else {
	  digitalWrite(armIn1, LOW);
	  digitalWrite(armIn2, LOW);
  }

  // Thumb to Claw
  if ((thumbVal > maxThumb) && (clawVal > minClaw)){
   // to open
   digitalWrite(clawIn2, LOW);
   digitalWrite(clawIn1, HIGH);
  } else if ((thumbVal < minThumb) && (clawVal < maxClaw)){
	  // to close
   digitalWrite(clawIn1, LOW);
   digitalWrite(clawIn2, HIGH);
  } else {
   digitalWrite(clawIn1, LOW);
   digitalWrite(clawIn2, LOW);
  }

	// Middle finger to wrist
	if ((midVal-10 > maxMid) && (wristVal > minWrist)){
	  // to go up
	 digitalWrite(wristIn2, LOW);
	 digitalWrite(wristIn1, HIGH);
	} else if ((midVal+10 < minMid) && (wristVal < maxWrist)){
	  // to go down
	 digitalWrite(wristIn1, LOW);
	 digitalWrite(wristIn2, HIGH);
	} else {
	 digitalWrite(wristIn1, LOW);
	 digitalWrite(wristIn2, LOW);
	}

}


