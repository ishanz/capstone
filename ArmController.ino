 /*
  * (1) Read in the flex sensor voltage values through the ADC pins
  * (2) Use the obtained ADC voltage values to control PWM outputs
  * (3) Send PWM signals to the robotic arm
  *
  */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 14;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
  Serial.println(sensorValue);
}
