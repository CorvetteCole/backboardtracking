/*code should provide numbers from 4 sensors simultaneously.
 * 
 */
int sensor1,sensor2,sensor3,sensor4,sensor1dist,sensor2dist,sensor3dist,sensor4dist = 0;

void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}

void loop() {
  sensor1 = analogRead(A0);  // Read the sensors
  sensor2 = analogRead(A1);
  sensor3 = analogRead(A2);
  sensor4 = analogRead(A3);                    
  
	if (340 < sensor1 && sensor1 < 361.96)
		sensor1dist = 1;                          // There will definitely be more blocks in the final version. The following code is a placeholder/outline
	if (361.96 < sensor1 && sensor1 < 383.92)
		sensor1dist = 2;
	if (383.92 < sensor1 && sensor1 < 405.88)
		sensor1dist = 3;
	if (405.88 < sensor1 && sensor1 < 427.84)        // Values in final version will be very different to reduce false readings
		sensor1dist = 4;
  if (427.84 < sensor1 && sensor1 < 449.8)
    sesnor1dist = 5;
	/*if (0 < sensor2 && sensor2 < 255)           //sensor 2 referencing begins
		sensor2dist = 1;
	if (255 < sensor2 && sensor2 < 510)
		sensor2dist = 2;
	if (510 < sensor2 && sensor2 < 765)
		sensor2dist = 3;
	if (765 < sensor2 && sensor2 < 1020)
		sensor2dist = 4;
  if (0 < sensor3 && sensor3 < 255)           //sensor 3 referencing begins
    sensor3dist = 1;
  if (255 < sensor3 && sensor3 < 510)
    sensor3dist = 2;
  if (510 < sensor3 && sensor3 < 765)
    sensor3dist = 3;
  if (765 < sensor3 && sensor3 < 1020)
    sensor3dist = 4;
  if (0 < sensor4 && sensor4 < 255)           //sensor 4 referencing begins
    sensor4dist = 1;
  if (255 < sensor4 && sensor4 < 510)
    sensor4dist = 2;
  if (510 < sensor4 && sensor4 < 765)
    sensor4dist = 3;
  if (765 < sensor4 && sensor4 < 1020)
    sensor4dist = 4;*/


    Serial.println("Sensor 1 block");
    Serial.println(sensor1dist, DEC);
}

