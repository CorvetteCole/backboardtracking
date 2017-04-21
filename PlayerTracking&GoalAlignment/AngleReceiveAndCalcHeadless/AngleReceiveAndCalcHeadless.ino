#include <Wire.h>
#include <digitalWriteFast.h>   
#include <RFM69.h>
#include <RFM69registers.h>
#include <RFM69_ATC.h> 

//Radio setup
#define NETWORKID     0   // Must be the same for all nodes
#define MYNODEID      1   // My node ID
#define TONODEID      2   // Destination node ID
#define FREQUENCY     RF69_915MHZ
#define ENCRYPT       false
#define USEACK        false
RFM69 radio;

//Other declarations
int angle, ux = 0, uy = 0, u = 0;
const float Pi = 3.14159;




void setup() {
  Serial.begin(9600);  //Initialize serial terminal
  Wire.begin();
  //Radio setup
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW
  Serial.println("Ready");
}

void loop() {
 if (radio.receiveDone()) // Got one!
  {
    // The actual message is contained in the DATA array,
    // and is DATALEN bytes in size:
    // NOTE: each element is an int (2 bytes), so need to recast the data as such...
    int *pData = (int*)radio.DATA;

    for (byte i = 0; i < radio.DATALEN; i+=2)
      u = (*pData++);
    if (u > 10) {     //x slave will add 30 to its value before transmission, y slave will not
      ux = u-30;
      u = 0;
    }
    else if (u < 10) {
      uy = u;
      u = 0; 
    }
 
   if (uy >= 0) {
    angle = angleCalc(ux, uy); 
    }
    Wire.beginTransmission(8);
    Wire.write("angle is ");
    Wire.write(angle); 
    Wire.endTransmission();
  }
}


int angleCalc(int ux, int uy) {
 int a;
 float radian, x, y; 
 switch(ux) {
  case -3:     //change 0s to equal actual distance values for x axis
   x = -25;
   break;
  case -2:
   x = -16.66;
   break;
  case -1:
   x = -8.33;
   break;
  case 0:
   x = 0;
   break;
  case 1:
   x = 8.33;
   break;
  case 2:
   x = 16.66;
   break;
  case 3:
   x = 25;
   break;
 }
 switch(uy) { 
  case 0:
   y = 0;
   break;
  case 1:
   y = 7.33;
   break;
  case 2:
   y = 15.66;   //replace 0s with actual values of the y sensors
   break;  
  case 3:
   y = 23.5;
   break;
  case 4:
   y = 31.33;
   break;
  case 5:
   y = 39.15;
   break;
  case 6:
   y = 47;
   break;
 }
if (y == 0 && x < 0) {
  a = -90;
 }
else if (y == 0 && x > 0) {
  a = 90;
 }
else if (x == 0) {
  a = 0;
 }
else {
  radian = atan(y/x);
  a = (radian * 180)/Pi;
 }
 return a;
}

