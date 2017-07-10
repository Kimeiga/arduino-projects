#include <Servo.h>

///This script transfers the input from a single potentiometer to a single servo

//THIS WORKS (1/25/16 Arduino Micro)
//orient the potentiometer such that the white knob is at the bottom
//left goes to 5v, middle goes to A2, right goes to ground


int potPin = A3;    // select the input pin for the potentiometer
int value = 0;       // variable to store the value coming from the sensor

Servo servo1;
int servo1Pin = 6;

void setup() {

  // initialize serial
  Serial.begin(9600);

  servo1.attach(servo1Pin);
  
}

void loop() {


  value = GetValue(potPin);

  //value = map(value, 0, 1023, 0, 180);
  //servo1.write(value);  


  Serial.print(value);
  Serial.println();
  
}


// Does the process
int GetValue(int apin)
{
    int val;
    int temp[2];
    
    // Ready the analog converter (and wait for initialization)
    analogRead(apin);
    delayMicroseconds(100);

    // Get readings
    temp[0] = analogRead(apin);
    temp[1] = analogRead(apin);

    // Calculate average
    val = (temp[0] + temp[1]) / 2;

    return val;
}
