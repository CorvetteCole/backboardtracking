#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*code should provide numbers from 4 sensors simultaneously.
 * 
 */
int sensor1voltage,sensor2voltage,sensor3voltage,sensor4voltage,sensor1dist,sensor2dist,sensor3dist,sensor4dist, sensor1value, sensor2value, sensor3value, sensor4value = 0;

void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}

int irRead1() {
  int Median [4];             //  Holds value to average readings

  // Get a sampling of 5 readings from sensor
  for (int i=0; i<5; i++) {
    Median[0] = irRead1();
    delay(55);
    Median[1] = irRead1();
    delay(55);
    Median[2] = irRead1();
    delay(55);
    Median[3] = irRead1();
    delay(55);
    Median[4] = irRead1();    
     }  
    vector<int> mArray(Median,Median+5); // Remember to set this number to match the number of items in your int array
    vector<int>::iterator it;

    sort(mArray.begin(),mArray.end());

// Find the median.
    int median,middle,middleh;
    int middlel;
    vector<int>::iterator z;
    switch(mArray.size()%2) {
        case(0): // even
            z = mArray.begin();
            middlel = mArray.size()/2;
            z += middlel;
            middleh = (*z+*(--z))/2;
            sensor1value = middleh;
        break;
        case(1): // odd
            z = mArray.begin();
            middle = mArray.size()/2;
            sensor1value = middle;
        break;
    }
  return(sensor1value);              // Return value   
  }
void loop() {

  float sensor1voltage = irRead1() * (5.0 / 1023.0);
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
  delay(250);
}

