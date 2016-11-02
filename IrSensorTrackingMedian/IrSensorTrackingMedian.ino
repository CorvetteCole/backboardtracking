/*code should provide numbers from 4 sensors simultaneously.
 * 
 */
int sensor1voltage,sensor2voltage,sensor3voltage,sensor4voltage,sensor1dist,sensor2dist,sensor3dist,sensor4dist, sensor1value, sensor2value, sensor3value, sensor4value = 0;
int med1 [5] = { };
int med2 [5] = { };
int med3 [5] = { };
int med4 [5] = { };
void sort(int a[], int size) {
    for(int i=0; i<(size-1); i++) {
        for(int o=0; o<(size-(i+1)); o++) {
                if(a[o] > a[o+1]) {
                    int t = a[o];
                    a[o] = a[o+1];
                    a[o+1] = t;
                }
        }
    }
}
void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}
 
void loop() {
  int i = 5;
  while (i > 0){
    i--;
    sensor1value = analogRead(A0);
    sensor2value = analogRead(A1);
    sensor3value = analogRead(A2);
    sensor4value = analogRead(A3);
    delay(55);
  }
  
    med1 [0] = sensor1value;
    med2 [0] = sensor2value;    //as you can see by this example, the code is easily scaled.
    delay(55);
    med1 [1] = sensor1value;
    delay(55);
    med1 [2] = sensor1value;
    delay(55);
    med1 [3] = sensor1value;
    delay(55);
    med1 [4] = sensor1value;
    delay(55);   

    sort(med1,5);
    sensor1value = med1 [2];

  
  float sensor1voltage = sensor1value * (5.0 / 1023.0);
  float sensor2voltage = sensor2value * (5.0 / 1023.0);
  float sensor3voltage = sensor3value * (5.0 / 1023.0);
  float sensor4voltage = sensor4value * (5.0 / 1023.0);
                 
  
  if ( 2.12 < sensor1voltage && sensor1voltage < 2.5)
		sensor1dist = 1;                          // There will definitely be more blocks in the final version. The following code is a placeholder/outline
  if (1.93 < sensor1voltage && sensor1voltage < 2.12)
    sensor1dist = 2;
  if (1.82 < sensor1voltage && sensor1voltage < 1.93)
		sensor1dist = 3;
  if (1.73 < sensor1voltage && sensor1voltage < 1.82)        // Values in final version will be very different to reduce false readings
		sensor1dist = 4;
  if (1.66 < sensor1voltage && sensor1voltage < 1.73)
    sensor1dist = 5;
  if (sensor1voltage < 1.66)
    return;
/*if (340 < sensor2voltage && sensor2voltage < 361.96)           //sensor 2 referencing begins
		sensor2dist = 6;
  if (361.96 < sensor2voltage && sensor2voltage < 510)
		sensor2dist = 7;
  if (383.92 < sensor2voltage && sensor2voltage < 765)
		sensor2dist = 8;
  if (405.88 < sensor2voltage && sensor2voltage < 1020)
		sensor2dist = 9;
  if (427.84 < sensor2voltage && sensor2voltage < 449.8)
    sensor2dist = 10;
  if (340 < sensor3voltage && sensor3voltage < 255)           //sensor 3 referencing begins
    sensor3dist = 11;
  if (361.96 < sensor3voltage && sensor3voltage < 510)
    sensor3dist = 12;
  if (383.92 < sensor3voltage && sensor3voltage < 765)
    sensor3dist = 13;
  if (405.88 < sensor3voltage && sensor3voltage < 1020)
    sensor3dist = 14;
  if (427.84 < sensor3voltage && sensor3voltage < 449.8)
    sensor3dist = 15;
  if (340 < sensor4voltage && sensor4voltage < 255)           //sensor 4 referencing begins
    sensor4dist = 16;
  if (361.96 < sensor4voltage && sensor4voltage < 510)
    sensor4dist = 17;
  if (383.92 < sensor4voltage && sensor4voltage < 765)
    sensor4dist = 18;
  if (405.88 < sensor4voltage && sensor4voltage < 1020)
    sensor4dist = 19;
  if (427.84 < sensor4voltage && sensor4voltage < 449.8)
    sensor4dist = 20;*/
   

    Serial.println("Sensor 1 block");
    Serial.println(sensor1dist, DEC);
  delay(275);
}

