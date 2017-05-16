//code should be able to tell where a ball hits on the backboard. The backboard is seperated in to 25 blocks and the code can tell which block it hits in. This code is easily scalable.

//IMPORTANT: Connect the top sensor to A0, the one under it to A1, etc.
float sensorvoltage [5] = { }, med1 [3] = { }, med2 [3] = { }, med3 [3] = { }, med4 [3] = { }, med5 [3] = { };
int sensordist [5] = { }; 
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
    sensorvoltage [0] = analogRead(A0) * (5.0 / 1023.0); //deb:Serial.println("sensor1 read");    
   case 2:                                //deb:Serial.println("sensor2 read");
    sensorvoltage [1] = analogRead(A1) * (5.0 / 1023.0);     
   case 3:                                //deb:Serial.println("sensor3 read");
    sensorvoltage [2] = analogRead(A2) * (5.0 / 1023.0);     
   case 4:                                //deb:Serial.println("sensor4 read");
    sensorvoltage [3] = analogRead(A3) * (5.0 / 1023.0); 
   case 5:
    sensorvoltage [4] = analogRead(A4) * (5.0 / 1023.0);
  }
}
void loop() {
  volt(1);                                          //deb:Serial.println("Volt1 ran");
  volt(2);
  volt(3);
  volt(4);
  volt(5);
    if (1.66 <= sensorvoltage [0] && sensorvoltage [0] <= 2.5) { //deb:Serial.println("sensor1 if statement activated");  //deb:Serial.println(sensor1voltage, DEC);      
      med1 [0] = sensorvoltage [0];                    //deb:Serial.println("first array value assigned to sensor1voltage");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(1);                                      //deb:Serial.println("volt1 for array value 2 ran"); //deb:Serial.println(sensor1voltage, DEC);
      med1 [1] = sensorvoltage [0];                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(1);                                      //deb:Serial.println("volt1 for array value 3 ran"); //deb:Serial.println(sensor1voltage, DEC);
      med1 [2] = sensorvoltage [0];                    //deb:Serial.println("Value 3 of array assigned");
      sort(med1,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med1 [1], DEC);
      sensorvoltage [0] = med1 [1];                    //deb:Serial.println("sensor1voltage assigned from value 2 in array"); //deb:Serial.println(sensor1voltage, DEC);
                      
       if (2.12 < sensorvoltage [0] && sensorvoltage [0] < 2.5) {   //deb:Serial.println("block1 triggered");
      	sensordist [0] = 1;                                      //deb:Serial.println(sensor1dist, DEC);}                      
       }
       else if (1.93 < sensorvoltage [0] && sensorvoltage [0] < 2.12) {    //deb:Serial.println("block2 triggered");
        sensordist [0] = 2;                                             //deb:Serial.println(sensor1dist, DEC);     
       }
       else if (1.82 < sensorvoltage [0] && sensorvoltage [0] < 1.93) {    //deb:Serial.println("block3 triggered");
      	sensordist [0] = 3;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.73 < sensorvoltage [0] && sensorvoltage [0] < 1.82) {    //deb:Serial.println("block4 triggered");
      	sensordist [0] = 4;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.66 < sensorvoltage [0] && sensorvoltage [0] < 1.73) {    //deb:Serial.println("block5 triggered");
        sensordist [0] = 5;                                             //deb:Serial.println(sensor1dist, DEC);  
       }
       Serial.println("Sensor1 block");
       Serial.println(sensordist [0], DEC);
    }    
    if (1.66 <= sensorvoltage [1] && sensorvoltage [1] <= 2.5) {  //deb:Serial.println("sensor2 if statement activated");  //deb:Serial.println(sensorvoltage [1], DEC);      
      med2 [0] = sensorvoltage [1];                    //deb:Serial.println("first array value assigned to sensorvoltage [1]");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(2);                                      //deb:Serial.println("volt2 for array value 2 ran"); //deb:Serial.println(sensorvoltage [1], DEC);
      med2 [1] = sensorvoltage [1];                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(2);                                      //deb:Serial.println("volt2 for array value 3 ran"); //deb:Serial.println(sensorvoltage [1], DEC);
      med2 [2] = sensorvoltage [1];                    //deb:Serial.println("Value 3 of array assigned");
      sort(med2,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med2 [1], DEC);
      sensorvoltage [1] = med2 [1];                    //deb:Serial.println("sensorvoltage [1] assigned from value 2 in array"); //deb:Serial.println(sensorvoltage [1], DEC);
                      
       if (2.12 < sensorvoltage [1] && sensorvoltage [1] < 2.5) {   //deb:Serial.println("block1 triggered");
        sensordist [1] = 6;                                      //deb:Serial.println(sensor1dist, DEC);}                      
       }
       else if (1.93 < sensorvoltage [1] && sensorvoltage [1] < 2.12) {    //deb:Serial.println("block2 triggered");
        sensordist [1] = 7;                                             //deb:Serial.println(sensor1dist, DEC);     
       }
       else if (1.82 < sensorvoltage [1] && sensorvoltage [1] < 1.93) {    //deb:Serial.println("block3 triggered");
        sensordist [1] = 8;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.73 < sensorvoltage [1] && sensorvoltage [1] < 1.82) {    //deb:Serial.println("block4 triggered");
        sensordist [1] = 9;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.66 < sensorvoltage [1] && sensorvoltage [1] < 1.73) {    //deb:Serial.println("block5 triggered");
        sensordist [1] = 10;                                             //deb:Serial.println(sensor1dist, DEC);  
       }
       Serial.println("Sensor2 block");
       Serial.println(sensordist [1], DEC);
    }
    if (1.66 <= sensorvoltage [2] && sensorvoltage [2] <= 2.5) { //deb:Serial.println("sensor3 if statement activated");  //deb:Serial.println(sensor3voltage, DEC);      
      med3 [0] = sensorvoltage [2];                    //deb:Serial.println("first array value assigned to sensor3voltage");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(3);                                      //deb:Serial.println("volt3 for array value 2 ran"); //deb:Serial.println(sensor3voltage, DEC);
      med3 [1] = sensorvoltage [2];                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(3);                                      //deb:Serial.println("volt3 for array value 3 ran"); //deb:Serial.println(sensor3voltage, DEC);
      med3 [2] = sensorvoltage [2];                    //deb:Serial.println("Value 3 of array assigned");
      sort(med3,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med3 [1], DEC);
      sensorvoltage [2] = med3 [1];                    //deb:Serial.println("sensor3voltage assigned from value 2 in array"); //deb:Serial.println(sensor3voltage, DEC);
                      
       if (2.12 < sensorvoltage [2] && sensorvoltage [2] < 2.5) {   //deb:Serial.println("block1 triggered");
        sensordist [2] = 11;                                      //deb:Serial.println(sensor3dist, DEC);}                      
       }
       else if (1.93 < sensorvoltage [2] && sensorvoltage [2] < 2.12) {    //deb:Serial.println("block2 triggered");
        sensordist [2] = 12;                                             //deb:Serial.println(sensor3dist, DEC);     
       }
       else if (1.82 < sensorvoltage [2] && sensorvoltage [2] < 1.93) {    //deb:Serial.println("block3 triggered");
        sensordist [2] = 13;                                             //deb:Serial.println(sensor3dist, DEC);   
       }
       else if (1.73 < sensorvoltage [2] && sensorvoltage [2] < 1.82) {    //deb:Serial.println("block4 triggered");
        sensordist [2] = 14;                                             //deb:Serial.println(sensor3dist, DEC);   
       }
       else if (1.66 < sensorvoltage [2] && sensorvoltage [2] < 1.73) {    //deb:Serial.println("block5 triggered");
        sensordist [2] = 15;                                             //deb:Serial.println(sensor3dist, DEC);  
       }
       Serial.println("sensor3 block");
       Serial.println(sensordist [2], DEC);
    }
    if (1.66 <= sensorvoltage [3] && sensorvoltage [3] <= 2.5) { //deb:Serial.println("sensor4 if statement activated");  //deb:Serial.println(sensor4voltage, DEC);      
      med4 [0] = sensorvoltage [3];                    //deb:Serial.println("first array value assigned to sensor4voltage");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(4);                                      //deb:Serial.println("volt4 for array value 2 ran"); //deb:Serial.println(sensor4voltage, DEC);
      med4 [1] = sensorvoltage [3];                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(4);                                      //deb:Serial.println("volt4 for array value 3 ran"); //deb:Serial.println(sensor4voltage, DEC);
      med4 [2] = sensorvoltage [3];                    //deb:Serial.println("Value 3 of array assigned");
      sort(med4,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med4 [1], DEC);
      sensorvoltage [3] = med4 [1];                    //deb:Serial.println("sensor4voltage assigned from value 2 in array"); //deb:Serial.println(sensor4voltage, DEC);
                      
       if (2.12 < sensorvoltage [3] && sensorvoltage [3] < 2.5) {   //deb:Serial.println("block1 triggered");
        sensordist [3] = 16;                                      //deb:Serial.println(sensor4dist, DEC);}                      
       }
       else if (1.93 < sensorvoltage [3] && sensorvoltage [3] < 2.12) {    //deb:Serial.println("block2 triggered");
        sensordist [3] =17;                                             //deb:Serial.println(sensor4dist, DEC);     
       }
       else if (1.82 < sensorvoltage [3] && sensorvoltage [3] < 1.93) {    //deb:Serial.println("block3 triggered");
        sensordist [3] = 18;                                             //deb:Serial.println(sensor4dist, DEC);   
       }
       else if (1.73 < sensorvoltage [3] && sensorvoltage [3] < 1.82) {    //deb:Serial.println("block4 triggered");
        sensordist [3] = 19;                                             //deb:Serial.println(sensor4dist, DEC);   
       }
       else if (1.66 < sensorvoltage [3] && sensorvoltage [3] < 1.73) {    //deb:Serial.println("block5 triggered");
        sensordist [3] = 20;                                             //deb:Serial.println(sensor4dist, DEC);  
       }
       Serial.println("sensor4 block");
       Serial.println(sensordist [3], DEC);        
  }
  if (1.66 <= sensorvoltage [4] && sensorvoltage [4] <= 2.5) { //deb:Serial.println("sensor5 if statement activated");  //deb:Serial.println(sensor5voltage, DEC);      
      med5 [0] = sensorvoltage [4];                    //deb:Serial.println("first array value assigned to sensor5voltage");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(5);                                      //deb:Serial.println("volt5 for array value 2 ran"); //deb:Serial.println(sensor5voltage, DEC);
      med5 [1] = sensorvoltage [4];                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(5);                                      //deb:Serial.println("volt5 for array value 3 ran"); //deb:Serial.println(sensor5voltage, DEC);
      med5 [2] = sensorvoltage [4];                    //deb:Serial.println("Value 3 of array assigned");
      sort(med5,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med5 [1], DEC);
      sensorvoltage [4] = med5 [1];                    //deb:Serial.println("sensor5voltage assigned from value 2 in array"); //deb:Serial.println(sensor5voltage, DEC);
                      
       if (2.12 < sensorvoltage [4] && sensorvoltage [4] < 2.5) {   //deb:Serial.println("block1 triggered");
        sensordist [4] = 21;                                      //deb:Serial.println(sensor5dist, DEC);}                      
       }
       else if (1.93 < sensorvoltage [4] && sensorvoltage [4] < 2.12) {    //deb:Serial.println("block2 triggered");
        sensordist [4] = 22;                                             //deb:Serial.println(sensor5dist, DEC);     
       }
       else if (1.82 < sensorvoltage [4] && sensorvoltage [4] < 1.93) {    //deb:Serial.println("block3 triggered");
        sensordist [4] = 23;                                             //deb:Serial.println(sensor5dist, DEC);   
       }
       else if (1.73 < sensorvoltage [4] && sensorvoltage [4] < 1.82) {    //deb:Serial.println("block4 triggered");
        sensordist [4] = 24;                                             //deb:Serial.println(sensor5dist, DEC);   
       }
       else if (1.66 < sensorvoltage [4] && sensorvoltage [4] < 1.73) {    //deb:Serial.println("block5 triggered");
        sensordist [4] = 25;                                             //deb:Serial.println(sensor5dist, DEC);  
       }
       Serial.println("sensor5 block");
       Serial.println(sensordist [4], DEC);
  }
}


