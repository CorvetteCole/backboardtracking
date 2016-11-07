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
void volt(int sensor){
  if (sensor=1)
  sensor1voltage = analogRead(A0) * (5.0 / 1023.0);
  if (sensor=2)
  sensor2voltage = analogRead(A1) * (5.0 / 1023.0);
  if (sensor=3)
  sensor3voltage = analogRead(A2) * (5.0 / 1023.0);
  if (sensor=4)
  sensor4voltage = analogRead(A3) * (5.0 / 1023.0);
}
void loop() {
  volt(1);
  volt(2);
  volt(3);
  volt(4);
    if (1.66 < sensor1voltage && sensor1voltage < 2.5) {
    Serial.println("broken");
    med1 [0] = sensor1voltage;  
    delay(38);
    volt(1);
    med1 [1] = sensor1voltage;   
    delay(38);
    volt(1);
    med1 [2] = sensor1voltage;   
    sort(med1,3);
    /*sort(med2,3);*/
    sensor1voltage = med1 [1];                 
      if (2.12 < sensor1voltage && sensor1voltage < 2.5)
    		sensor1dist = 1;                         
      if (1.93 < sensor1voltage && sensor1voltage < 2.12)
        sensor1dist = 2;
      if (1.82 < sensor1voltage && sensor1voltage < 1.93)
    		sensor1dist = 3;
      if (1.73 < sensor1voltage && sensor1voltage < 1.82)       
    		sensor1dist = 4;
      if (1.66 < sensor1voltage && sensor1voltage < 1.73)
        sensor1dist = 5;
      Serial.println("Sensor 1 block");
      Serial.println(sensor1dist, DEC);
    }    
    if (1.66 < sensor2voltage && sensor2voltage < 2.5) {
     med2 [0] = sensor2voltage;
     delay(38); 
     volt(2);
     med2 [1] = sensor2voltage;
     delay(38);
     volt(2);
     med3 [2] = sensor2voltage; 
     sort(med2,3);
     sensor2voltage = med2 [1];
      if (2.12 < sensor2voltage && sensor2voltage < 2.5)
        sensor2dist = 6;                         
      if (1.93 < sensor2voltage && sensor2voltage < 2.12)
        sensor2dist = 7;
      if (1.82 < sensor2voltage && sensor2voltage < 1.93)
        sensor2dist = 8;
      if (1.73 < sensor2voltage && sensor2voltage < 1.82)       
        sensor2dist = 9;
      if (1.66 < sensor2voltage && sensor2voltage < 1.73)
        sensor2dist = 10;
      Serial.println("Sensor 2 block");
      Serial.println(sensor2dist, DEC);
    } 
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
   
  }


