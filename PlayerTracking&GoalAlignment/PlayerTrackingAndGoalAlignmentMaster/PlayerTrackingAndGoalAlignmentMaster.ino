int angle, encoderValue, u = 0;
float radian, x, y;
const float Pi = 3.14159;
void alignment(void), count(void), forward(void), reverse(void);

#include <RFM69.h>
#include <RFM69registers.h>
#include <RFM69_ATC.h> 

#define NETWORKID     0   // Must be the same for all nodes
#define MYNODEID      1   // My node ID
#define TONODEID      2   // Destination node ID

#define FREQUENCY     RF69_915MHZ
#define ENCRYPT       false
#define USEACK        false
RFM69 radio;

void setup() {
  Serial.begin(9600);
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW
  
  pinMode(2, INPUT);   //replace 2 with whatever pin encoder is attached to
  attachInterrupt(digitalPinToInterrupt(2), count, FALLING);
  encoderValue = 0;
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
      Serial.print(u);
      Serial.print("\n" );
    if (u > 10) {     //x slave will add 30 to its value before transmission, y slave will not
      y = u-30;
      u = 0;
    }
    if (u < 10) {
      x = u;
      u = 0; 
    }
 
   if ((x >= 1) && (y >= 1)) {
 
    Serial.println(x);
    Serial.println(y);
    delay(500);
    alignmotor();
    }
  }
}

void alignmotor() {
  Serial.println("it works");
if (x != 0) {
  radian = atan(y/x);
  angle = (radian * 180)/Pi;
}
else if (x == 0) {
  angle = 0;
}
else if ((y == 0) && (x < 0)) {
  angle = 270;
}
else if ((y == 0) && (x > 0)) {
  angle = 90;
}

if (angle < 0) {
  angle = 360 + angle;
}

if (angle < encoderValue) {
  forward();
 }
if (angle > encoderValue) {
  reverse();
 }
}

void forward() {
  while (encoderValue != angle) {
    digitalWrite(1,1); //forward motor pin
  }   
}

void reverse() {
  while (encoderValue != angle) {
    digitalWrite(2,1); //reverse motor pin
  }
}

void count() {
  encoderValue++;
  Serial.print("Encoder value="); 
  Serial.println(encoderValue);
}


