//code should be able to tell where a ball hits on the backboard. The backboard is seperated in to 20 blocks and the code can tell which block it hits in. This code is easily scalable.

//IMPORTANT: Connect the top sensor to A0, top middle to A1, lower middle to A2, Lower to A3
float sensor1voltage,sensor2voltage,sensor3voltage,sensor4voltage = 0;
int sensor1dist,sensor2dist,sensor3dist,sensor4dist = 0;
float med1 [3] = { };
float med2 [3] = { };
float med3 [3] = { };
void sort(float a[], float size) { //deb:Serial.println("sorting...");  
    for(int i=0; i<(size-1); i++) {
        for(int j=0; j<(size-(i+1)); j++) {
                if(a[j] > a[j+1]) {
                    int t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
        }
    }
}
void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}
void volt(int sensor){
  switch(sensor){ 
   case 1:   
    sensor1voltage = analogRead(A0) * (5.0 / 1023.0); //deb:Serial.println("sensor1 read");    
   case 2:                                //deb:Serial.println("sensor2 read");
    sensor2voltage = analogRead(A1) * (5.0 / 1023.0);     
   case 3:                                //deb:Serial.println("sensor3 read");
    sensor3voltage = analogRead(A2) * (5.0 / 1023.0);     
   case 4:                                //deb:Serial.println("sensor4 read");
    sensor4voltage = analogRead(A3) * (5.0 / 1023.0); 
  }
}
void loop() {
  volt(1);                                          //deb:Serial.println("Volt1 ran");
  volt(2);
  volt(3);
  volt(4);
    if (1.66 <= sensor1voltage && sensor1voltage <= 2.5) {  //deb:Serial.println("sensor1 if statement activated");  //deb:Serial.println(sensor1voltage, DEC);      
      med1 [0] = sensor1voltage;                    //deb:Serial.println("first array value assigned to sensor1voltage");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(1);                                      //deb:Serial.println("volt1 for array value 2 ran"); //deb:Serial.println(sensor1voltage, DEC);
      med1 [1] = sensor1voltage;                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(1);                                      //deb:Serial.println("volt1 for array value 3 ran"); //deb:Serial.println(sensor1voltage, DEC);
      med1 [2] = sensor1voltage;                    //deb:Serial.println("Value 3 of array assigned");
      sort(med1,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med1 [1], DEC);
      sensor1voltage = med1 [1];                    //deb:Serial.println("sensor1voltage assigned from value 2 in array"); //deb:Serial.println(sensor1voltage, DEC);
                      
       if (2.12 < sensor1voltage && sensor1voltage < 2.5) {   //deb:Serial.println("block1 triggered");
      	sensor1dist = 1;                                      //deb:Serial.println(sensor1dist, DEC);}                      
       }
       else if (1.93 < sensor1voltage && sensor1voltage < 2.12) {    //deb:Serial.println("block2 triggered");
        sensor1dist = 2;                                             //deb:Serial.println(sensor1dist, DEC);     
       }
       else if (1.82 < sensor1voltage && sensor1voltage < 1.93) {    //deb:Serial.println("block3 triggered");
      	sensor1dist = 3;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.73 < sensor1voltage && sensor1voltage < 1.82) {    //deb:Serial.println("block4 triggered");
      	sensor1dist = 4;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.66 < sensor1voltage && sensor1voltage < 1.73) {    //deb:Serial.println("block5 triggered");
        sensor1dist = 5;                                             //deb:Serial.println(sensor1dist, DEC);  
       }
       Serial.println("Sensor1 block");
       Serial.println(sensor1dist, DEC);
    }    
    if (1.66 <= sensor2voltage && sensor2voltage <= 2.5) {  //deb:Serial.println("sensor2 if statement activated");  //deb:Serial.println(sensor2voltage, DEC);      
      med2 [0] = sensor2voltage;                    //deb:Serial.println("first array value assigned to sensor2voltage");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(2);                                      //deb:Serial.println("volt2 for array value 2 ran"); //deb:Serial.println(sensor2voltage, DEC);
      med2 [1] = sensor2voltage;                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(2);                                      //deb:Serial.println("volt2 for array value 3 ran"); //deb:Serial.println(sensor2voltage, DEC);
      med2 [2] = sensor2voltage;                    //deb:Serial.println("Value 3 of array assigned");
      sort(med2,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med2 [1], DEC);
      sensor2voltage = med2 [1];                    //deb:Serial.println("sensor2voltage assigned from value 2 in array"); //deb:Serial.println(sensor2voltage, DEC);
                      
       if (2.12 < sensor2voltage && sensor2voltage < 2.5) {   //deb:Serial.println("block1 triggered");
        sensor2dist = 1;                                      //deb:Serial.println(sensor1dist, DEC);}                      
       }
       else if (1.93 < sensor2voltage && sensor2voltage < 2.12) {    //deb:Serial.println("block2 triggered");
        sensor2dist = 2;                                             //deb:Serial.println(sensor1dist, DEC);     
       }
       else if (1.82 < sensor2voltage && sensor2voltage < 1.93) {    //deb:Serial.println("block3 triggered");
        sensor2dist = 3;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.73 < sensor2voltage && sensor2voltage < 1.82) {    //deb:Serial.println("block4 triggered");
        sensor2dist = 4;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.66 < sensor2voltage && sensor2voltage < 1.73) {    //deb:Serial.println("block5 triggered");
        sensor2dist = 5;                                             //deb:Serial.println(sensor1dist, DEC);  
       }
       Serial.println("Sensor2 block");
       Serial.println(sensor2dist, DEC);
    }    
  }


