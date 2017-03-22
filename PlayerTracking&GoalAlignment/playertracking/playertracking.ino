int pin13, pin12, pin11, pin10, pin9, pin8, pin7, pin6, pin5, pin4;  //pins 13-9 are x axis, pins 8-4 are y axis 
int x, y;

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
}

void triangulate() {
 if (pin13 == 1) { 
  x = 1; }
 else if (pin12 == 1) {
  x = 2; }
 else if (pin11 == 1) {
  x = 3; }
 else if (pin10 == 1) {
  x = 4; }
 else if (pin9 == 1) {
  x = 5; } 
 if (pin8 == 1) {
  y = 1; }
 else if (pin7 == 1) {
  y = 2; }
 else if (pin6 == 1) {
  y = 3; }
 else if (pin5 == 1) {
  y = 4; }
 else if (pin4 == 1) {
  y = 5; }   
alignmotor();
}


void alignmotor() {
  Serial.println("it works");
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

