#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <SPI.h>

#include <SD.h>

TMRpcm tmrpcm;

float sensorvoltage, med [3] = { };
int sensordist, sensor;
void playAudio(void);

void setup() {
  Serial.begin(9600);
  tmrpcm.speakerPin = 9;
  if (!SD.begin(4)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
}

void loop() {
 sensorcalc(1);
 sensorcalc(2);
 sensorcalc(3);
 sensorcalc(4);
 sensorcalc(5);
} 

void sensorcalc(int sensorID){ 
 sensorvoltage = volt((sensorID - 1));
     if (1.66 <= sensorvoltage && sensorvoltage <= 2.5) { //deb:Serial.println("sensor1 if statement activated");  //deb:Serial.println(sensorvoltage, DEC);      
      med[0] = sensorvoltage;                    //deb:Serial.println("first array value assigned to sensorvoltage");  
      delay(55);                                    //deb:Serial.println("1st 38 ms delay finished");
      volt(1);                                      //deb:Serial.println("volt1 for array value 2 ran"); //deb:Serial.println(sensorvoltage, DEC);
      med[1] = sensorvoltage;                    //deb:Serial.println("Value 2 of array assigned");
      delay(38);                                    //deb:Serial.println("2nd 38 ms delay finished");
      volt(1);                                      //deb:Serial.println("volt1 for array value 3 ran"); //deb:Serial.println(sensorvoltage, DEC);
      med[2] = sensorvoltage;                    //deb:Serial.println("Value 3 of array assigned");
      sort(med,3);                                 //deb:Serial.println("Array sort ran"); //deb:Serial.println(med[1], DEC);
      sensorvoltage = med[1];                    //deb:Serial.println("sensorvoltage assigned from value 2 in array"); //deb:Serial.println(sensorvoltage, DEC);
                      
       if (2.12 < sensorvoltage && sensorvoltage < 2.5) {   //deb:Serial.println("block1 triggered");
       sensordist = 1;                                      //deb:Serial.println(sensordist, DEC);}                      
       }
       else if (1.93 < sensorvoltage && sensorvoltage < 2.12) {    //deb:Serial.println("block2 triggered");
        sensordist = 2;                                             //deb:Serial.println(sensordist, DEC);     
       }
       else if (1.82 < sensorvoltage && sensorvoltage < 1.93) {    //deb:Serial.println("block3 triggered");
        sensordist = 3;                                             //deb:Serial.println(sensordist, DEC);   
       }
       else if (1.73 < sensorvoltage && sensorvoltage < 1.82) {    //deb:Serial.println("block4 triggered");
        sensordist = 4;                                             //deb:Serial.println(sensordist, DEC);   
       }
       else if (1.66 < sensorvoltage && sensorvoltage < 1.73) {    //deb:Serial.println("block5 triggered");
        sensordist = 5;                                             //deb:Serial.println(sensordist, DEC);  
       }
    }    
  sensor = sensorID; 
  playAudio();
}

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

int volt(int pin) {
  float voltage;
  voltage = analogRead(pin) * (5.0 / 1023.0);
  return voltage;
}

void playAudio() {
 Serial.println("playaudio");
 Serial.println(sensor);
 switch(sensor) {
  case 1:
   tmrpcm.play("top.wav");
  case 2:
   tmrpcm.play("upper.wav");
  case 3:
   tmrpcm.play("middle.wav");
  case 4:
   tmrpcm.play("lower.wav");
  case 5:
   tmrpcm.play("bottom.wav");
 }

 switch(sensordist) {
  case 1:
   tmrpcm.play("far_left.wav");
  case 2:
   tmrpcm.play("left.wav");
  case 3:
   tmrpcm.play("center.wav");
  case 4:
   tmrpcm.play("right.wav");
  case 5:
   tmrpcm.play("far_right.wav");
 }
}

