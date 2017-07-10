//Electric Vehicle Script 3

float distance = 0; //how far we've traveled
int motorSpeed = 25; //control how fast to "step" the motor (25 is ostensibly about the lowest you can go(meaning the highest speed))
 
int numberOfSteps = 200; //how many steps does the stepper take to make a roation (the actual motor, not factoring in "micro" steps)
int microSteps = 16; //how many microsteps is the Bid Easy Driver set to (or whatever stepper driver is being used)

int fullRotation = numberOfSteps * microSteps;


int directionPin = 8;
int stepPin = 9;
int limitSwitchPin = 10;
int switchPin = 11;

float circumferenceOfWheel = 0.37699f //this is the circumference of a CD in meters (as a test)

void setup() {


  Serial.begin(9600); //just in case
  distance = 0;

  pinMode(directionPin,OUTPUT); //DIRECTION pin (forward, reverse)
  pinMode(stepPin,OUTPUT); //STEP pin (increments the motor)
  digitalWrite(directionPin,LOW); //the motor is always going to be moving forward
  digitalWrite(stepPin,LOW); //just an initial value;

  pinMode(limitSwitchPin, INPUT); //set the limit switch pin as input so it can be read by the arduino
  
  pinMode(limitPin, INPUT_PULLUP);
  
  
  
  }

void loop(){


  int limitSwitchValue = digitalRead(limitSwitchPin); //define the limit switch

  int switchValue = digitalRead(switchPin);


  if(limitSwitchValue == HIGH && switchValue == LOW){ //if the limit switch is not closed, but the starter switch is closed...

  //move forward at "motorSpeed"
    
  digitalWrite(9,HIGH);
  delayMicroseconds(motorSpeed);
  digitalWrite(9,LOW);
  delayMicroseconds(motorSpeed);
  distance = distance + 1; //record this step
    
    }

  

  Serial.print(distance * circumferenceOfWheel/ fullRotation); //for testing: just show the distance as recorded
  Serial.println;
  
  }
