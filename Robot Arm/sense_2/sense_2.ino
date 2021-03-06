//THIS WORKS (1/25/16 Arduino Micro)
//orient the potentiometer such that the white knob is at the bottom
//left goes to 5v, middle goes to A2, right goes to ground



/* Analog Read to LED
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead(). In the easiest case we connect
 * a potentiometer to analog pin 2.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

int potPin = 2;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT

  // initialize serial
  Serial.begin(9600);
  
}

void loop() {

  /*
  val = analogRead(potPin) * 4;    // read the value from the sensor
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
  */

  val = analogRead(potPin);

  //cut off val at 700 (lower bound)
  

  Serial.print(val);

  Serial.println();
  
}
