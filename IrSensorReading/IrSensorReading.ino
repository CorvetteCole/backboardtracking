<<<<<<< HEAD:IrSensorReading/IrSensorReading.ino
/*code should provide numbers from 4 sensors simultaneously.
 * 
 */
int sensor1,sensor2,sensor3,sensor4,sensor1dist,sensor2dist,sensor3dist,sensor4dist = 0;

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
  
	if (0 < sensor1) && (510 < sensor1)
		sensor1dist = 1;            // This likely isn't the fastest or most efficient way of doing it (I don't even know if it works).
	if (255 < sensor1) && (sensor1 < 510)
		sensor1dist = 2;
	if (510 < sensor1) && (sensor1 < 765)
		sensor1dist = 3;
	if (765 < sensor1) && (sensor1 < 1020)      // Values in final version will be very different to reduce false readings
		sensor1dist = 4;
	if (0 < sensor2) && (sensor2 < 255)           //sensor 2 referencing begins
		sensor2dist = 1;
	if (255 < sensor2) && (sensor2 < 510)
		sensor2dist = 2;
	if (510 < sensor2) && (sensor2 < 765)
		sensor2dist = 3;
	if (765 < sensor2) && (sensor2 < 1020)
		sensor2dist = 4;
}
=======
/*code should provide numbers from 4 sensors simultaneously.
 * 
 */
int sensor1,sensor2,sensor3,sensor4,sensor1dist,sensor2dist,sensor3dist,sensor4dist = 0;

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
void loop() {
	if (0 < sensor1 < 255)
		sensor1dist = 1;            // This likely isn't the fastest or most efficient way of doing it (I don't even know if it works).
	if (255 < sensor1 < 510)
		sensor1dist = 2;
	if (510 < sensor1 < 765)
		sensor1dist = 3;
	if (765 < sensor1 < 1020)      // Values in final version will be very different to reduce false readings
		sensor1dist = 4;
	if (0 < sensor2 < 255)           //sensor 2 referencing begins
		sensor2dist = 1;
	if (255 < sensor2 < 510)
		sensor2dist = 2;
	if (510 < sensor2 < 765)
		sensor2dist = 3;
	if (765 < sensor2 < 1020)
		sensor2dist = 4;
}
>>>>>>> d90353cb46858bf23745205e414aaf1b283b79dc:IrSensorReading.ino
