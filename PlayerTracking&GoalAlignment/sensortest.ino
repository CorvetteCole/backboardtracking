void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue;
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  if (analogRead(A0) > 0) {
    sensorValue = 1;
  }
  if (analogRead(A0) <= 0) {
    sensorValue = 0;
  }
  Serial.println(sensorValue);
  delay(500);
}

