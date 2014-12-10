 /*
  * (1) Read in the flex sensor voltage values through the ADC pins
  * (2) Use the obtained ADC voltage values to control PWM outputs
  * (3) Send PWM signals to the robotic arm
  *
  */

#include "Energia.h"


void setup();
void loop();
int debounced(int buttonPin);

int buttonPin = 5;
int thumbPin = 3;    // select the input pin for the potentiometer
int indexPin = 4;    // select the input pin for the potentiometer
int midPin = 15;    // select the input pin for the potentiometer
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
const int maxClaw = 460;
const int maxWrist = 529;
const int maxArm = 526;
const int minClaw = 388;
const int minWrist = 400;
const int minArm = 427;
int maxThumb = 680;
int maxIndex = 660;
int maxMid = 560;
int minThumb = 625;
int minIndex = 625;
int minMid = 440;

int reading;
int buttonState = HIGH;
int lastButtonState = LOW;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 100;    // the debounce time; increase if the output flickers
long currentTime = 0;


void debounced(){
  reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  currentTime = millis();
  if ((currentTime - lastDebounceTime) > debounceDelay) {
    buttonState = reading;
  }
  lastButtonState = reading;

}

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(armIn1, OUTPUT);
  pinMode(armIn2, OUTPUT);
  pinMode(clawIn1, OUTPUT);
  pinMode(clawIn2, OUTPUT);
  pinMode(wristIn1, OUTPUT);
  pinMode(wristIn2, OUTPUT);
  digitalWrite(armIn1, LOW);
  digitalWrite(armIn2, LOW);
  digitalWrite(clawIn1, LOW);
  digitalWrite(clawIn2, LOW);
  digitalWrite(wristIn1, LOW);
  digitalWrite(wristIn2, LOW);

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
	if ((midVal > maxMid) && (wristVal > minWrist)){
	  // to go up
	 digitalWrite(wristIn2, LOW);
	 digitalWrite(wristIn1, HIGH);
	} else if ((midVal < minMid) && (wristVal < maxWrist)){
	  // to go down
	 digitalWrite(wristIn1, LOW);
	 digitalWrite(wristIn2, HIGH);
	} else {
	 digitalWrite(wristIn1, LOW);
	 digitalWrite(wristIn2, LOW);
	}

}


