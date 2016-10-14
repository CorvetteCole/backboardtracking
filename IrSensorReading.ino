/*code should provide numbers from 4 sensors simultaneously.
 * 
 */
int sensor1,sensor2,sensor3,sensor4 = 0;

void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}

void loop() {
  sensor1 = analogRead(A0);  // Read the sensor
  sensor2 = analogRead(A1);
  sensor3 = analogRead(A2);
  sensor4 = analogRead(A3);
  Serial.println("Sensor1");   
  Serial.println(sensor1, DEC);   // Display value in Serial Monitor window
  Serial.println("Sensor2");
  Serial.println(sensor2, DEC);
  Serial.println("Sensor3");
  Serial.println(sensor3, DEC);
  Serial.println("Sensor4");
  Serial.println(sensor4, DEC);
  delay(250);                      // Wait 1/4 second for the next read
}
