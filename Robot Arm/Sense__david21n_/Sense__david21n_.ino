// Sense Sketch
// by david21n

// Simple sketch to read potentiometer values
// Run sketch and open serial monitor and record
// the values of the potentiometer at 0 and 180 degrees

// analog pins to read the potentiometers values
int input1 = 4;
int input2 = 2;
int input3 = 1;
int input4 = 0;

int val1;
int val2;
int val3;
int val4;

void setup() 
{ 
  // initialize serial
  Serial.begin(9600);
}

void loop()
{
  // raed values
  val1 = analogRead(input1);
  val2 = analogRead(input2);
  val3 = analogRead(input3);
  val4 = analogRead(input4);
  
  // Print each input 
  Serial.print(input1);
  Serial.print(": ");
  Serial.print(val1);
  
  Serial.print("  ");
  Serial.print(input2);
  Serial.print(": ");
  Serial.print(val2);
  
  Serial.print("  ");
  Serial.print(input3);
  Serial.print(": ");
  Serial.print(val3);
  
  Serial.print("  ");
  Serial.print(input4);
  Serial.print(": ");
  Serial.print(val4);
  
  Serial.println();
}


