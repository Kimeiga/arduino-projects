#include <VarSpeedServo.h> // include VarSpeedServo library

VarSpeedServo myservo1; // create servo object to control a servo
void setup() { 
  
  myservo1.attach(1); // attaches the servo on pin 1 to the myservo1 object }
}
void loop() { // loop the following code

      myservo1.write(0, 30, true);  // go to 0 degrees with a speed of 30, wait for movement to finish

      // I start with this because I want the servo to start at 0 degrees. However, when I stop the servo
      // at 0 degrees, and turn the program back on, it actually moves half a round, and then go back to the 0
      // degrees point. I have NO IDEA why this happens!

      myservo1.write(1, 0, true);   // go to 1 degrees with full speed, wait for movement to finish

      // The second line of code is needed because the servo somehow slows down extremely when it is nearing
      // the 0 degree point. To speed things up, and make sure it actually ends at ~ (1) degrees, I make it
      // go full speed. I know this isn't how it's supposed to be, but it works for now.

      delay(5000);                  // wait 5 seconds 

      // The delay command is NOT executed after the code before that. It looks like the 'true' only waits
      // with the next code if it is also a function of the VarSpeedServo library.

      myservo1.write(75, 30, true); // go to 75 degrees with a speed of 30, wait for movement to finish

      // The 75 degrees makes the current attached circle rotate 360 degrees. This has something to do 
      // the servo, on the page I linked to it sais this motor can actually turn 1260 degrees! 
  }
