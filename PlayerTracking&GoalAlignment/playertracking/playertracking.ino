int angle, pin13, pin12, pin11, pin10, pin9, pin8, pin7, pin6, pin5, pin4, encoderValue = 0;  //pins 13-9 are x axis, pins 8-4 are y axis 
float radian, x, y;
const float Pi = 3.14159;
void alignment(void), triangulate(void), count(void), forward(void), reverse(void);

void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

  pinMode(2, INPUT);   //replace 2 with whatever pin encoder is attached to
  attachInterrupt(digitalPinToInterrupt(2), count, FALLING);
  encoderValue = 0;
}

void loop() {
 pin13 = digitalRead(13);
 pin12 = digitalRead(12);
 pin11 = digitalRead(11);
 pin10 = digitalRead(10);
 pin9 = digitalRead(9);
 pin8 = digitalRead(8);
 pin7 = digitalRead(7);
 pin6 = digitalRead(6);
 pin5 = digitalRead(5);
 pin4 = digitalRead(4);
 if ((pin13 == 1 || pin12 == 1 || pin11 == 1 || pin10 == 1 || pin9 == 1) && (pin8 == 1 || pin7 == 1 || pin6 == 1 || pin5 == 1 || pin4 == 1)) {
 
  triangulate();
  Serial.println(x);
  Serial.println(y);
  delay(500);
   }
}

void triangulate() {
 if (pin13 == 1) { 
  x = -50; }
 else if (pin12 == 1) {
  x = -25; }
 else if (pin11 == 1) {
  x = 0; }
 else if (pin10 == 1) {
  x = 25; }
 else if (pin9 == 1) {
  x = 50; } 
 if (pin8 == 1) {
  y = 0; }
 else if (pin7 == 1) {
  y = 10.5; }
 else if (pin6 == 1) {
  y = 21; }
 else if (pin5 == 1) {
  y = 31.5; }
 else if (pin4 == 1) {
  y = 42; }   
alignmotor();
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


