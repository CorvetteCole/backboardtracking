//code should be able to tell where a ball hits on the backboard. The backboard is seperated in to 20 blocks and the code can tell which block it hits in. This code is easily scalable.

//IMPORTANT: Connect the top sensor to A0, top middle to A1, lower middle to A2, Lower to A3
float sensorvoltage [4] = { };
int sensordist [4] = { };
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
    sensorvoltage [0] = analogRead(A0) * (5.0 / 1023.0); //deb:Serial.println("sensor1 read");    
   case 2:                                //deb:Serial.println("sensor2 read");
    sensorvoltage [1] = analogRead(A1) * (5.0 / 1023.0);     
   case 3:                                //deb:Serial.println("sensor3 read");
    sensorvoltage [2] = analogRead(A2) * (5.0 / 1023.0);     
   case 4:                                //deb:Serial.println("sensor4 read");
    sensorvoltage [3] = analogRead(A3) * (5.0 / 1023.0); 
  }
}
void loop() {
  volt(1);                                          //deb:Serial.println("Volt1 ran");
  volt(2);
  volt(3);
  volt(4);
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
        sensordist [1] = 1;                                      //deb:Serial.println(sensor1dist, DEC);}                      
       }
       else if (1.93 < sensorvoltage [1] && sensorvoltage [1] < 2.12) {    //deb:Serial.println("block2 triggered");
        sensordist [1] = 2;                                             //deb:Serial.println(sensor1dist, DEC);     
       }
       else if (1.82 < sensorvoltage [1] && sensorvoltage [1] < 1.93) {    //deb:Serial.println("block3 triggered");
        sensordist [1] = 3;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.73 < sensorvoltage [1] && sensorvoltage [1] < 1.82) {    //deb:Serial.println("block4 triggered");
        sensordist [1] = 4;                                             //deb:Serial.println(sensor1dist, DEC);   
       }
       else if (1.66 < sensorvoltage [1] && sensorvoltage [1] < 1.73) {    //deb:Serial.println("block5 triggered");
        sensordist [1] = 5;                                             //deb:Serial.println(sensor1dist, DEC);  
       }
       Serial.println("Sensor2 block");
       Serial.println(sensordist [1], DEC);
    }    
  }


