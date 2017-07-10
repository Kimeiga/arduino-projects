// Remote Sketch
// by david21n

// Simple sketch for one to one robot arm project

#include <Servo.h> 
 
Servo servo1;    // create servo object to control a servo 
Servo servo2;    // a maximum of eight servo objects can be created 
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;

// States of the claw
const int OPEN = 0;
const int CLOSED = 1;
const int OPENING = 2;
const int CLOSING = 3;

// claw close and open positions
const int closeClaw1 = 160;
const int openClaw1 = 105;
const int closeClaw2 = 15;
const int openClaw2 = 70;

// intial values of servos
int val1 = 90;        // Joint 1 (Base)
int val2 = 90;        // Joint 2 (Close to base)
int val3 = 90;        // Joint 3 (Middle)
int val4 = 90;        // Joint 4 (End)
int val5 = 90;        // Joint 5 (Rotate the claw)
int valClaw1 = 160;   // claw 1 
int valClaw2 = 15;    // claw 2

// Movement of the Servos
// - each servo moves depending how it is mounted
// Joint 1 (Base)           --- right = 0, left = 180
// Joint 2 (Close to base)  --- back or up = 0, forward or down = 180
// Joint 3 (Middle)         --- back or up = 0, forward or down = 180
// Joint 3 (End)            --- back or up = 180, forward or down = 0

// analog pins
const int input1 = 3;    // Base
const int input2 = 2;    // Joint 1 (Close to base)
const int input3 = 1;    // Joint 2 (Middle)
const int input4 = 0;    // Joint 3 (End)

// The potentiometers would be read and adjusted to
// a value between 0 and 180 that the servo function 
// can use. But, the potentiometers go father than 
// 180 degrees, so the program need parameters.
// To get these parameters run the "Sense" sketch
// and write down the values of the joint when the
// potentiometer is at 0 and 180 degrees.

// IMPORTANT: make sure the 0 degree position of the
// potentiometer is the same as the 0 degree position
// of the servo. If the 0 degree positon of potentiometer
// is the 180 degree position of the servo, the servo 
// would go the reverse direction of the potentiomter

// Joint read values at 0 and 180 degrees
const int deg1[] = {205,935};
const int deg2[] = {95,830};
const int deg3[] = {210,915};
const int deg4[] = {130,830};

// scales used to scale input value to 0 to 180
// scale = (deg180 - deg0) / 180;
const float scale1 = 3.91;
const float scale2 = 3.91;
const float scale3 = 4.08;
const float scale4 = 3.89;

// Joint offset
// The offset is when the servo is not mounted 
// correctly by a few degrees, so an offset is applied
// to correct it.
const int offset1 = 0;
const int offset2 = 5;
const int offset3 = -5;
const int offset4 = 5;

// Claw increment
const int incClaw1 = -5;
const int incClaw2 = 5;

// Led pin to show arduino is on
int ledPin = 13;

// Claw variables
int buttonPin = 12;
int buttonState = 0;
int clawState = CLOSED;

void setup() 
{ 
  // attach servos
  servo1.attach(0);  // BASE
  servo2.attach(1);  // Joint 1 
  servo3.attach(2);  // Joint 2
  servo4.attach(3);  // Joint 3
  servo5.attach(5);  // Joint 4 rotate
  servo6.attach(6);  // claw 1
  servo7.attach(7);  // claw 2
  
  // led pin
  pinMode(ledPin, OUTPUT);
} 
 
 
void loop() 
{ 
  // Turn on led
  digitalWrite(ledPin, HIGH);
  
  // Read the potentiometers
  val1  = analogRead(input1);
  val2  = analogRead(input2);
  val3  = analogRead(input3);
  val4  = analogRead(input4);
  
  // Adjust the read values
  val1 = adj(val1, deg1, scale1, offset1);
  val2 = adj(val2, deg2, scale2, offset2);
  val3 = adj(val3, deg3, scale3, offset3);
  val4 = adj(val4, deg4, scale4, offset4);
  
  // Send out signal to servos
  servo1.write(val1);              
  servo2.write(val2);              
  servo3.write(val3);            
  servo4.write(val4);             
  servo5.write(val5);
  servo6.write(valClaw1);
  servo7.write(valClaw2);
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // Check if the pushbutton is pressed.
  
  // if it is, the buttonState is LOW,
  // changes the claw state
  if ((buttonState == LOW)) 
  {        
    if (clawState == CLOSED)
      clawState = OPENING;
    else if (clawState == OPEN)
      clawState = CLOSING;
  }
  
  // if claw is opening or closing, increases 
  // or decreases the servo value
  if (clawState == OPENING)
  {
    if(valClaw1 > openClaw1 && clawState == OPENING)
    {
      valClaw1 += incClaw1;
      valClaw2 += incClaw2;
      servo6.write(valClaw1);
      servo7.write(valClaw2);
    }
    else
      clawState = OPEN;      // claw is open
  }
  else if (clawState == CLOSING)
  {
    if(valClaw1 < closeClaw1 && clawState == CLOSING)
    {
      valClaw1 -= incClaw1;
      valClaw2 -= incClaw2;
      servo6.write(valClaw1);
      servo7.write(valClaw2);
    }
    else
      clawState = CLOSED;    // claw is closed
  }
  
  // delay for the servo to 
  // move to the new position
  delay(15);
}

// The function adjusts the analog read value to degrees
int adj(int input, const int deg[], const float scale, const int offset)
{
  float val = 0;
  
  // scales the value to 0 to 180
  if ( input < deg[0])
    val = 0;
  else if ( (input >= deg[0]) && (input <= deg[1]) )
    val = (input - deg[0])/scale;
  else if (input > deg[1])
    val = 180;
  
  // add offset
  val = val + offset;
  // fix max and min
  if (val > 180)
    val = 180;
  else if (val < 0)
    val = 0;
  
  return val;
}
