//code should be able to tell where a ball hits on the backboard. The backboard is seperated in to 20 blocks and the code can tell which block it hits in. This code is easily scalable.

//IMPORTANT: Connect the top sensor to A0, top middle to A1, lower middle to A2, Lower to A3
int sensor1voltage,sensor2voltage,sensor3voltage,sensor4voltage,sensor1dist,sensor2dist,sensor3dist,sensor4dist = 0;
int med1 [3] = { };
int med2 [3] = { };
int med3 [3] = { };
int med4 [3] = { };
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
  sensor1voltage = analogRead(A0) * (5.0 / 1023.0);
  /*sensor2voltage = analogRead(A0) * (5.0 / 1023.0); 
  sensor3voltage = analogRead(A0) * (5.0 / 1023.0);
  sensor4voltage = analogRead(A0) * (5.0 / 1023.0);*/
    if (1.66 < sensor1voltage && sensor1voltage < 2.5) {
    Serial.println("broken");
    med1 [0] = sensor1voltage;
   /* med2 [0] = sensor2voltage;    //as you can see by this example, the code is easily scaled.
    med3 [0] = sensor3voltage;
    med4 [0] = sensor4voltage;*/
    delay(38);
    med1 [1] = sensor1voltage;
   /* med2 [1] = sensor2voltage;
    med3 [1] = sensor3voltage;
    med4 [1] = sensor4voltage);*/
    delay(38);
    med1 [2] = sensor1voltage;
   /* med2 [2] = sensor2oltage;
    med3 [2] = sensor3voltage;
    med4 [2] = sensor4voltage;*/
    delay(38);   

    sort(med1,3);
    /*sort(med2,3);
    sort(med3,3);
    sort(med4,3);*/
    sensor1voltage = med1 [1];
    /*sensor2voltage = med2 [1];
    sensor3voltage = med3 [1];
    sensor4voltage = med4 [1];*/                 
  
  if (2.12 < sensor1voltage && sensor1voltage < 2.5)
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
    }
    
  }


