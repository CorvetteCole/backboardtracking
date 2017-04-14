int x, IN1, IN2, t;
void fwd(void), rev(void), none(void);

void setup() {
  Serial.begin(9600);
  IN1 = 8;   //change pin numbers to respective pins
  IN2 = 9;
  //waiting for input
  Serial.println("Input ready");
  Serial.println("1 fwd, 2 rev, 3 none");
}

void loop() {
  
  while (Serial.available() == 0) {}
  x = Serial.parseFloat();
  if (x == 1) {
    fwd();
  }
  if (x == 2) {
    rev();
  }
  if (x == 3) {
    none();
  }

}

void fwd() {
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
}

void rev() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
}

void none() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
}

