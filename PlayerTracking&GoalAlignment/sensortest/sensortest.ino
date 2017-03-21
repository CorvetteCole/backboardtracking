//connect white wire to Arduino GND and the gray wire to digital in

void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

void loop() {
Serial.println("13");
Serial.println(digitalRead(13));
Serial.println("12");
Serial.println(digitalRead(12));

delay(500);
}
