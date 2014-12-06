 /*
  * (1) Read in the flex sensor voltage values through the ADC pins
  * (2) Use the obtained ADC voltage values to control PWM outputs
  * (3) Send PWM signals to the robotic arm
  *
  */

#include "Energia.h"


void setup();
void loop();

int sensorPin1 = 3;    // select the input pin for the potentiometer
int sensorPin2 = 4;    // select the input pin for the potentiometer
int sensorPin3 = 5;    // select the input pin for the potentiometer
int ledPin = 14;      // select the pin for the LED
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
int sensorValue3 = 0;  // variable to store the value coming from the sensor
int previousValue = 0;
int diffVal = 0; //difference between previous and sensor values
int baseValue = 0;
int flag = 0; //flag for initial start up
int forward = 0; //flag for going forward

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
//  baseValue = analogRead(sensorPin);
  pinMode(ledPin, OUTPUT);  
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
//  if (flag == 0){
//	  flag = 1;
//  } else {
//	  diffVal = sensorValue - previousValue;
//  }


//  if ( diffVal < -20) {
//	  digitalWrite(6, LOW);
//	  digitalWrite(7, HIGH);
//  } else if ( diffVal > 20) { //move down
//	  digitalWrite(7, LOW);
//	  digitalWrite(6, HIGH);
//  } else { //move up
//	  digitalWrite(7, LOW);
//	  digitalWrite(6, LOW);
//  }


//  if ( (baseValue-sensorValue) < 15 ){
//	  digitalWrite(7, LOW);
//	  digitalWrite(6, LOW);
//  }
//  else if( forward == 0 && (baseValue - sensorValue) > 50){ //move down
//	  	  forward = 1;
//	  	digitalWrite(7, LOW);
//		  digitalWrite(6, HIGH);
//  } else if (forward == 1 && (baseValue - sensorValue) < 50){ //move up
//	  forward = 0;
//	  digitalWrite(6, LOW);
//	  digitalWrite(7, HIGH);
//  }

  // stop the program for <sensorValue> milliseconds:
//  delay(sensorValue);
  // turn the ledPin off:        
//  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
//  delay(diffVal * 10);
//  previousValue = sensorValue;
//  Serial.println(sensorValue);
}


