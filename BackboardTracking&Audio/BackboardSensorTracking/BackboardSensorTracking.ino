#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <SD.h>

TMRpcm tmrpcm;

float med [3] = { };
int sensordist;
void playAudio(void);

void setup() {
  Serial.begin(9600);
  tmrpcm.speakerPin = 9;                                                                    //connect speaker positive to pin 9
  if (!SD.begin(4)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  Serial.println("ready");
}

void loop() {                                                                               //connect top sensor to A0, bottom to A4
 sensorcalc(1);
 sensorcalc(2);
 sensorcalc(3);
 sensorcalc(4);
 sensorcalc(5);
} 

void sensorcalc(int sensorID){ 
 float sensorvoltage = volt((sensorID - 1));
     if (1.66 <= sensorvoltage && sensorvoltage <= 2.5) { 
      med[0] = sensorvoltage;                    
      delay(55);                                    
      sensorvoltage = volt((sensorID - 1));                                      
      med[1] = sensorvoltage;                    
      delay(38);                                    
      sensorvoltage = volt((sensorID - 1));                                      
      med[2] = sensorvoltage;                    
      sort(med,3);                                 
      sensorvoltage = med[1];                    
                      
       if (2.12 < sensorvoltage && sensorvoltage < 2.5) {   
       sensordist = 1;                                      
       }
       else if (1.93 < sensorvoltage && sensorvoltage < 2.12) {   
        sensordist = 2;                                             
       }
       else if (1.82 < sensorvoltage && sensorvoltage < 1.93) {   
        sensordist = 3;                                             
       }
       else if (1.73 < sensorvoltage && sensorvoltage < 1.82) {    
        sensordist = 4;                                            
       }
       else if (1.66 < sensorvoltage && sensorvoltage < 1.73) {   
        sensordist = 5;                                             
       }
    }      
  playAudio(sensorID);
}

void sort(float a[], float size) { 
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

void playAudio(int sensor) {
 Serial.println("playaudio");
 Serial.println(sensor);
 tmrpcm.play("ball_hit.wav");
 while (tmrpcm.isPlaying() == 1) {
  delay(20);
 }
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
 while (tmrpcm.isPlaying() == 1) {
  delay(20);
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

