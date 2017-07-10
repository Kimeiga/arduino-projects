//Electric Vehicle Script 1

float distance = 0; //how far we've traveled
int motorSpeed = 25; //control how fast to "step" the motor (25 is ostensibly about the lowest you can go(meaning the highest speed))
 
int numberOfSteps = 200; //how many steps does the stepper take to make a roation (the actual motor, not factoring in "micro" steps)
int microSteps = 16; //how many microsteps is the Bid Easy Driver set to (or whatever stepper driver is being used)

int fullRotation = numberOfSteps * microSteps;

float targetDistance = 9; //the distance needed to be traveled (9m is the lower bound)
float targetSteps; //the steps needed to be traveled

int directionPin = 8;
int stepPin = 9;
int potentiometerPin = 3;

float circumferenceOfWheel = 0.37699f //this is the circumference of a CD in meters (as a test)
float scaleFactor = 1 / circumferenceOfWheel; //this would be 2.65259025438f in this example

void setup() {

  distance = 0;

  pinMode(directionPin,OUTPUT); //DIRECTION pin (forward, reverse)
  pinMode(stepPin,OUTPUT); //STEP pin (increments the motor)
  digitalWrite(directionPin,LOW); //the motor is always going to be moving forward
  digitalWrite(stepPin,LOW); //just an initial value;
  Serial.begin(9600); //just in case

  
  
  }

void loop(){

  targetDistance = analogRead(potentiometerPin);
  targetDistance = map(targetDistance, 0, 1023, 12, 9); //map the value from the potentiometer to 12m - 10m (you can reverse this if it is more intuitive)
  targetSteps = targetDistance * scaleFactor * fullRotation;


  if(distance < targetSteps){ 

  //move forward at "motorSpeed"
    
  digitalWrite(9,HIGH);
  delayMicroseconds(motorSpeed);
  digitalWrite(9,LOW);
  delayMicroseconds(motorSpeed);
  distance = distance + 1; //record this step
    
    }
  
  }
