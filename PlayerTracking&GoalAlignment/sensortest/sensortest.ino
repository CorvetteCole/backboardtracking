//connect white wire to Arduino GND and the gray wire to digital in

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
Serial.print("sensor 1");
Serial.print("   ");
Serial.println(digitalRead(3));
Serial.print("sensor 2");
Serial.print("   ");
Serial.println(digitalRead(4));
Serial.print("sensor 3");
Serial.print("   ");
Serial.println(digitalRead(5));
Serial.print("sensor 4");
Serial.print("   ");
Serial.println(digitalRead(6));
Serial.print("sensor 5");
Serial.print("   ");
Serial.println(digitalRead(7));
delay(1000);
}
