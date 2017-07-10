//EV Stepper Motor Script 1
//This is me making an almost-exact copy of what I see in the youtube video
//Here's the link to it:
//there needs to be a "full rotation" variable, i can't find it <- NOTICE

/*Hardware Layout:
 * Stepper is wired into B.E.D. from left to right: Red, Yellow, Green, Grey. (May vary by MDFG)
 * B.E.D. is powered by 24V power supply
 * B.E.D. ground connected to Arduino Ground
 * B.E.D. STEP pin connected to Arduino Digital Pin 9
 * B.E.D. DIR pin connected to Arduino Digital Pin 8
 * Push Button connected to Arduino Digital Pin 2
 * Potentiometer Connected to Arduino Analog Pin 3
 */

float distance = 0; //how far we've traveled
int motorSpeed = 50000; //control how fast to "step" the motor

int numberOfSteps = 200; //how many steps does the stepper take to make a roation (the actual motor, not factoring in "micro" steps)
int microSteps = 16; //how many microsteps is the Bid Easy Driver set to (or whatever stepper driver is being used)
int fullRotation = numberOfSteps * microSteps;

void setup(){
  pinMode(8,OUTPUT); //DIRECTION pin (forward reverse)
  pinMode(9,OUTPUT); //STEP pin (this increments the motor - e.g. makes it turn!)
  digitalWrite(8,HIGH); 

  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(4,LOW);
  
  }

void loop() {

  digitalWrite(9,HIGH);
  delayMicroseconds(motorSpeed);
  digitalWrite(9,LOW);
  delayMicroseconds(motorSpeed);

  /*
  distance = distance + 1; //record this step
  if(distance == fullRotation){ //as soon as distance = "fullRotation," that means we have a full revolution!

     if(digitalRead(8) == LOW){
       digitalWrite(8,HIGH); //this is a "toggle" to reverse whichever way it is to the other direction!
     }
     else{
      digitalWrite(8,LOW);
     }

     distance = 0; //reset our distance counter!
     delay(10); //a pause at the end of each rotation; not necessary to have FYI
     
  }
  */
    
}
