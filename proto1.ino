//Read Acelerometer Orientation for FMP Project

//read pins
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//The minimum and maximum values that came from
//the accelerometer while standing still
int minVal = 265;
int maxVal = 402;

//To send to processing to provide feedback
String begin1 = "begin";

//to hold the caculated values
double x;
double y;
double z;

float values[2];

void setup(){
  Serial.begin(9600); 
}


void loop(){

  //read the analog values from the accelerometer
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);

  //convert read values to degrees -90 to 90 - Needed for atan2
  int xAng = map(xRead, minVal, maxVal, -90, 90);
  int yAng = map(yRead, minVal, maxVal, -90, 90);
  int zAng = map(zRead, minVal, maxVal, -90, 90);

  //Caculate 360deg values like so: atan2(-yAng, -zAng)
  //atan2 convert radians to degree (pi values to degrees)
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  //Output the caculations
//  Serial.print(“x: “);
  values[0] = x;
  values[1] = y;
  values[2] = z;
  
  //Testing Serial to give start and end signal to processing 
  //for all the three axises
  Serial.println("begin");
  Serial.println(begin1);
  delay(10);
  Serial.println(values[0]);
  delay(10);
  Serial.println(values[1]);
  delay(10);
  Serial.println(values[2]);
  delay(10);
Serial.println("done");
  
  
  //small delay, else, too much and too fast data.
  delay(100);
}
