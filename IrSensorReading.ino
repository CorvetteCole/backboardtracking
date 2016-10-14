/*code should provide numbers from two sensors simultaneously. Still need to distinguish which is which though.
 * 
 */
int sensor1,sensor2 = 0;

void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}

void loop() {
  sensor1 = analogRead(A0);  // Read the sensor
  sensor2 = analogRead(A1);
  Serial.println(sensor1, DEC);   // Display value in Serial Monitor window
  Serial.println(sensor2, DEC);
  delay(250);                      // Wait 1/4 second for the next read
}
