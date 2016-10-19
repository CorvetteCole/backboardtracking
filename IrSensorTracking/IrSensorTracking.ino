/*code should provide numbers from 4 sensors simultaneously.
 * 
 */
int sensor1voltage,sensor2voltage,sensor3voltage,sensor4voltage,sensor1dist,sensor2dist,sensor3dist,sensor4dist, sensor1value, sensor2value, sensor3value, sensor4value = 0;

void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}

void loop() {
  sensor1value = analogRead(A0);  // Read the sensors
  sensor2value = analogRead(A1);
  sensor3value = analogRead(A2);
  sensor4value = analogRead(A3);
  float sensor1voltage = sensor1value * (5.0 / 1023.0);
  float sensor2voltage = sensor2value * (5.0 / 1023.0);
  float sensor3voltage = sensor3value * (5.0 / 1023.0);
  float sensor4voltage = sensor4value * (5.0 / 1023.0);                    
  
  if ( 2.1 <= sensor1voltage && sensor1voltage <= 2.5)
		sensor1dist = 1;                          // There will definitely be more blocks in the final version. The following code is a placeholder/outline
  if (1.95 <= sensor1voltage && sensor1voltage < 2.1)
        	sensor1dist = 2;
  if (1.86 <= sensor1voltage && sensor1voltage < 1.95)
		sensor1dist = 3;
  if (1.83 < sensor1voltage && sensor1voltage <= 1.86)        // Values in final version will be very different to reduce false readings
		sensor1dist = 4;
  if (1.8 < sensor1voltage && sensor1voltage < 1.83)
    sensor1dist = 5;
/*if (340 < sensor2voltage && sensor2voltage < 361.96)           //sensor 2 referencing begins
		sensor2dist = 1;
  if (361.96 < sensor2voltage && sensor2voltage < 510)
		sensor2dist = 2;
  if (383.92 < sensor2voltage && sensor2voltage < 765)
		sensor2dist = 3;
  if (405.88 < sensor2voltage && sensor2voltage < 1020)
		sensor2dist = 4;
  if (427.84 < sensor2voltage && sensor2voltage < 449.8)
    sensor2dist = 5;
  if (340 < sensor3voltage && sensor3voltage < 255)           //sensor 3 referencing begins
    sensor3dist = 1;
  if (361.96 < sensor3voltage && sensor3voltage < 510)
    sensor3dist = 2;
  if (383.92 < sensor3voltage && sensor3voltage < 765)
    sensor3dist = 3;
  if (405.88 < sensor3voltage && sensor3voltage < 1020)
    sensor3dist = 4;
  if (427.84 < sensor3voltage && sensor3voltage < 449.8)
    sensor3dist = 5;
  if (340 < sensor4voltage && sensor4voltage < 255)           //sensor 4 referencing begins
    sensor4dist = 1;
  if (361.96 < sensor4voltage && sensor4voltage < 510)
    sensor4dist = 2;
  if (383.92 < sensor4voltage && sensor4voltage < 765)
    sensor4dist = 3;
  if (405.88 < sensor4voltage && sensor4voltage < 1020)
    sensor4dist = 4;
  if (427.84 < sensor4voltage && sensor4voltage < 449.8)
    sensor4dist = 5;*/


    Serial.println("Sensor 1 block");
    Serial.println(sensor1dist, DEC);
  delay(500);
}

