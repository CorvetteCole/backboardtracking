#include <digitalWriteFast.h>


int angle, input, PWM;
void align(void);

// It turns out that the regular digitalRead() calls are too slow and bring the arduino down when
// I use them in the interrupt routines while the motor runs at full speed.

// Quadrature encoder
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
int encoderValue = 0;

void setup()  {
  Serial.begin(9600);
// Quadrature encoder
  pinMode(cEncoderPinA, INPUT);      // sets pin A as input
  digitalWrite(cEncoderPinA, LOW);  // turn on pullup resistors
  pinMode(cEncoderPinB, INPUT);      // sets pin B as input
  digitalWrite(cEncoderPinB, LOW);  // turn on pullup resistors
  attachInterrupt(cEncoderInterruptA, HandleMotorInterruptA, CHANGE);
  attachInterrupt(cEncoderInterruptB, HandleMotorInterruptB, CHANGE);
  Serial.println("desired angle in degrees");
} 

void loop()  {
    encoderValue = encoderCalc();
    if (encoderValue != angle) {
      void align();
    }
    while (Serial.available() == 0) {
      encoderValue = encoderCalc();
    if (encoderValue != angle) {
      void align();
      }
    }
    input = Serial.parseFloat();
    if (input != 0) {
      angle = input;
      align();
      encoderValue = encoderCalc();
      Serial.println(encoderValue);
    }
}

void align(){    
   while (encoderValue != angle) { 
    if ((encoderValue > (angle+40)) || (encoderValue < (angle-40))) {
      PWM = 120;
    }
    else PWM = 80;
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
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
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

int encoderCalc() {
  int i = 0;                              //gearing ratio should be 35/7.5
  i = EncoderTicks * (360/1856.0);
  i = i / (35/7.5);   //adjust for ratio between drive wheel and lazy susan
  return i;
}


