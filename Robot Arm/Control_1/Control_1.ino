#include <Servo.h>

//Basic Robot Arm Script
//This maps the values of 4 robot arms and 1 switch to 5 servos
//or at least attempts to

//Checklist:
//Figure out how to interpret a switch; may need to find the switch first to try this

//also idk which arduino we are using so i'm just going to pick random numbers for the pin slots

int potpin1 = 1; //input pin for first potentiometer
int potpin2 = 2; //input pin for second potentiometer
int potpin3 = 3; //input pin for thrid potentiometer
int potpin4 = 4; //input pin for fourth potentiometer
int potpin5 = 5; //input pin for fifth potentiometer
int potpin6 = 6; //input pin for the button for the gripper


int buttonReading; //the current reading from the button
int previousButtonReading; //the previous reading from the button

bool extendingGripper = false; //the state of the gripper ahora

float gripSpeed = 5; //how fast the gripper transitions
long gripDelay = 30; //how many milliseconds to delay the grip transition
long lastGripTime = 0; //the last time the grip transition was called


// the follow variables are long's because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastTime = 0;     // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers




int value1 = 0; //variable to store the value of the first potentiometer
int value2 = 0; //variable to store the value of the second potentiometer
int value3 = 0; //variable to store the value of the third potentiometer
int value4 = 0; //variable to store the value of the fourth potentiometer
int value5 = 0; //variable to store the value of the fifth potentiometer
int value6 = 0; //the variable to move the gripper

Servo servo1; //I will rename these to "wrist," "shoulder," etc. after I figure out which is which lol
int servo1Pin = 7;
Servo servo2;
int servo2Pin = 8;
Servo servo3;
int servo3Pin = 9;
Servo servo4;
int servo4Pin = 10;
Servo servo5; //I didn't know if the gripper used a servo, but I think it does, so I'm putting this here
int servo5Pin = 11;
Servo servo6;
int servo6pin = 12;

//A little warning: I don't think that the 5V power source from the Arduino will be enough for 5 servos; we may need an external power source somehow.


int delayTime = 15; //time to wait in between loop() calls
int lastServoTime = 0; //used to cause delay

void setup(){

  servo1.attach(servo1Pin); //attaches the servo on pin "servo1Pin" to the servo object :)
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  servo5.attach(servo5Pin);

  //setting up the button pin
  pinMode(potpin5, INPUT);
  
  }


void loop() {


  if(millis() - lastServoTime > delayTime){

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
  
     lastServoTime = millis();
    
    }
  

  //The gripper will be different because I assume that we are using a button...
  //so I will turn the button into a switch with the following code, and then use that to control a function that will gradually increase or decrease the value of the gripper servo

  buttonReading = digitalRead(potpin5);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (buttonReading == HIGH && previousButtonReading == LOW && millis() - lastTime > debounce) {
    if (extendingGripper == false)
      extendingGripper = true;
    else
      extendingGripper = false;

    lastTime = millis();    
  }

  previousButtonReading = buttonReading;


  //ok so here's where i attempt to extend and contract the gripper

  if(millis() - lastGripTime > gripDelay){
    
     //extending (0 -> 180)
  if(extendingGripper == true && value5 < 180){

    value5 += gripperSpeed;

  }

  //contracting (180 -> 0)
  if(extendingGripper == false && value5 > 0){

    value5 -= gripperSpeed;  
    
  }

  lastGripTime = millis();
    
    }
 

  
//Clamps the value5 between 0 and 180
  if(value5 > 180){

      value5 = 180;
    
    }
  if(value5 < 0){

      value5 = 0;
    
    }
    

//sends the value5 to the gripper servo
servo5.write(value5);


//this code is a bit unoptimized, but it should work kinda
//the pin positions need to be changed, but i don't think much else has to be
//(unless i'm optimizing)

  
  }






