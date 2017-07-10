#include <Servo.h>

int potpin1 = 1; //input pin for first potentiometer
int potpin2 = 2; //input pin for second potentiometer
int potpin3 = 3; //input pin for thrid potentiometer
int potpin4 = 4; //input pin for fourth potentiometer
int potpin5 = 5; //input pin for fifth potentiometer
int potpin6 = 6; //input pin for sixth potentiometer

int value1 = 0; //variable to store the value of the first potentiometer
int value2 = 0; //variable to store the value of the second potentiometer
int value3 = 0; //variable to store the value of the third potentiometer
int value4 = 0; //variable to store the value of the fourth potentiometer
int value5 = 0; //variable to store the value of the fifth potentiometer
int value6 = 0; //variable to store the value of the sixth potentiometer

Servo servo1; 
int servo1Pin = 7;
Servo servo2;
int servo2Pin = 8;
Servo servo3;
int servo3Pin = 9;
Servo servo4;
int servo4Pin = 10;
Servo servo5; 
int servo5Pin = 11;
Servo servo6;
int servo6pin = 12;

int delayTime = 15;

void setup(){
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  servo5.attach(servo5Pin);
  servo6.attach(servo6pin);
}

void loop() {

     value1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
     value1 = map(value1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     servo1.write(value1);                  // sets the servo position according to the scaled value
  
     value2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
     value2 = map(value2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     servo2.write(value2);                  // sets the servo position according to the scaled value
  
     value3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023)
     value3 = map(value3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     servo3.write(value3);                  // sets the servo position according to the scaled value
  
     value4 = analogRead(potpin4);            // reads the value of the potentiometer (value between 0 and 1023)
     value4 = map(value4, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     servo4.write(value4);                  // sets the servo position according to the scaled value

     value5 = analogRead(potpin5);            // reads the value of the potentiometer (value between 0 and 1023)
     value5 = map(value5, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     servo5.write(value5);                  // sets the servo position according to the scaled value

     value6 = analogRead(potpin6);            // reads the value of the potentiometer (value between 0 and 1023)
     value6 = map(value6, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     servo6.write(value6);                  // sets the servo position according to the scaled value
  
  
   delay(delayTime);
  
  }






