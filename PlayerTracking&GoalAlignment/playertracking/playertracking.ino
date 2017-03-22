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

  
}

void loop() {
 int pin13, pin12, pin11, pin10, pin9, pin8, pin7, pin6, pin5, pin4;  //pins 13-9 are x axis, pins 8-4 are y axis
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
  Serial.println("it works");
 }

 
 
 
 

 



}

