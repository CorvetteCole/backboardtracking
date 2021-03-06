//Libraries
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

//Quadrature Encoder
#define cEncoderInterruptA 0
#define cEncoderInterruptB 1
#define cEncoderPinA 2
#define cEncoderPinB 3
#define EncoderIsReversed
volatile bool EncoderASet;
volatile bool EncoderBSet;
volatile bool EncoderAPrev;
volatile bool EncoderBPrev;
volatile long EncoderTicks = 0;

//Other declarations
int angle, PWM, ux, uy, encoderValue = 0, u = 0;
void align(void);
const float Pi = 3.14159;



void setup() {
  Serial.begin(9600);  //Initialize serial terminal
  
  //Radio setup
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW
  
  // Quadrature encoder
  pinMode(cEncoderPinA, INPUT);      // sets pin A as input
  digitalWrite(cEncoderPinA, LOW);  // turn on pullup resistors
  pinMode(cEncoderPinB, INPUT);      // sets pin B as input
  digitalWrite(cEncoderPinB, LOW);  // turn on pullup resistors
  attachInterrupt(cEncoderInterruptA, HandleMotorInterruptA, CHANGE);
  attachInterrupt(cEncoderInterruptB, HandleMotorInterruptB, CHANGE);
}

void loop() {
 encoderValue = encoderCalc();
    if (encoderValue != angle) {
      void align();
    }
 if (radio.receiveDone()) // Got one!
  {
    // The actual message is contained in the DATA array,
    // and is DATALEN bytes in size:
    // NOTE: each element is an int (2 bytes), so need to recast the data as such...
    int *pData = (int*)radio.DATA;

    for (byte i = 0; i < radio.DATALEN; i+=2)
      u = (*pData++);
      Serial.print(u);
      Serial.print("\n" );
    if (u > 10) {     //x slave will add 30 to its value before transmission, y slave will not
      ux = u-30;
      u = 0;
    }
    else if (u < 10) {
      uy = u;
      u = 0; 
    }
 
   if (uy >= 1) {
 
    Serial.println(ux);
    Serial.print(", ");
    Serial.print(uy);
    delay(500);   //just allows me to interpret what is happening, will remove later
    align();  
    }
  }
}

void align() {
  encoderValue = encoderCalc();
  angle = angleCalc();   
   while (encoderValue != angle) { 
    if ((encoderValue > (angle+30)) || (encoderValue < (angle-30))) {
      PWM = 90;
    }
    else PWM = 45;
    if (encoderValue < angle) {
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      analogWrite(5, PWM);   //0-255 range for motor speed  
    }
    if (encoderValue > angle) {
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      analogWrite(5, PWM); 
    }
    encoderValue = encoderCalc();
    Serial.println(encoderValue);
 }
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
}  

int encoderCalc() {
  int i = 0;                       //gearing ratio should be (35/7.5)
  i = EncoderTicks * (360/1856.0);
  return i;
}

int angleCalc() {
 int a;
 float radian, x, y; 
 switch(ux) {
  case -3:     //change 0s to equal actual distance values for x axis
   x = -25;
  case -2:
   x = -16.66;
  case -1:
   x = -8.33;
  case 0:
   x = 0;
  case 1:
   x = 8.33;
  case 2:
   x = 16.66;
  case 3:
   x = 25;
 }
 switch(uy) { 
  case 0:
   y = 0;
  case 1:
   y = 7.33;
  case 2:
   y = 15.66;   //replace 0s with actual values of the y sensors
  case 3:
   y = 23.5;
  case 4:
   y = 31.33;
  case 5:
   y = 39.15;
  case 6:
   y = 47;
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

// Interrupt service routines for the  motor's quadrature encoder
void HandleMotorInterruptA(){
  EncoderBSet = digitalReadFast(cEncoderPinB);
  EncoderASet = digitalReadFast(cEncoderPinA);
  
  EncoderTicks+=ParseEncoder();
  
  EncoderAPrev = EncoderASet;
  EncoderBPrev = EncoderBSet;
}

// Interrupt service routines for the right motor's quadrature encoder
void HandleMotorInterruptB(){
  // Test transition;
  EncoderBSet = digitalReadFast(cEncoderPinB);
  EncoderASet = digitalReadFast(cEncoderPinA);
  
  EncoderTicks+=ParseEncoder();
  
  EncoderAPrev = EncoderASet;
  EncoderBPrev = EncoderBSet;
}

int ParseEncoder(){
  if(EncoderAPrev && EncoderBPrev){
    if(!EncoderASet && EncoderBSet) return 1;
    if(EncoderASet && !EncoderBSet) return -1;
  }else if(!EncoderAPrev && EncoderBPrev){
    if(!EncoderASet && !EncoderBSet) return 1;
    if(EncoderASet && EncoderBSet) return -1;
  }else if(!EncoderAPrev && !EncoderBPrev){
    if(EncoderASet && !EncoderBSet) return 1;
    if(!EncoderASet && EncoderBSet) return -1;
  }else if(EncoderAPrev && !EncoderBPrev){
    if(EncoderASet && EncoderBSet) return 1;
    if(!EncoderASet && !EncoderBSet) return -1;
  }
}
