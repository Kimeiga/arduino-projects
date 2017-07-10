// Josef Spjut
// August 2015

// set pin numbers for joystick axes
const int xAxisRight = A0;   // right stick X axis  
const int yAxisRight = A1;   // right stick Y axis
const int xAxisLeft = A2;    // left stick x
const int yAxisLeft = A3;    // left stick y
const int invertY = 0;       // set invertY to 1 to invert

// parameters
int range = 10;               // max output of X or Y movement (12 default)
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range/10;      // resting threshold
int center = range/2;         // resting position value

int oriX;
int oriY;

int val;

void setup() {
  Mouse.begin();    // be a mouse
  Keyboard.begin(); // be a keyboard!
  
  pinMode(4, INPUT_PULLUP);
}

void loop() {  
  // read joystick state
  int xReading = readAxis(xAxisRight , 1);
  int yReading = readAxis(yAxisRight , invertY);

  //xReading -= oriX;
  //yReading -= oriY;

  val = digitalRead(4);
  if(val == 1){
    oriX = readAxis(xAxisRight, 1);
    oriY = readAxis(yAxisRight, invertY);
    }

  // Move the mouse
  Mouse.move(xReading -1, yReading, 0);

  // wait to allow computer to respond
  delay(responseDelay);
}

/*
  reads an axis (0 or 1 for x or y) and scales the 
 analog input range to a range from 0 to <range>
 */

int readAxis(int thisAxis, int isY) { 
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  if (isY) reading = range-reading; // invert y axis


  // if the output reading is outside from the
  // rest position threshold,  use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  } 

  // return the distance for this axis:
  return distance;
}

