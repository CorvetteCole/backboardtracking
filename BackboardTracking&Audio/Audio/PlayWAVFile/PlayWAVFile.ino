#include <SPI.h>

#include <SD.h>

#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

TMRpcm tmrpcm;   // create an object for use in this sketch
char mychar;

void setup(){

  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(4)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
}
  
void loop(){  

  if(Serial.available()){   
    mychar = Serial.read();

    if(mychar == 't'){ //send the letter t over the serial monitor to start playback
      Serial.println("playing");
      tmrpcm.play("ball_hit.wav");
      while (tmrpcm.isPlaying() == 1) {
      delay(20);
     }
     tmrpcm.play("top.wav");
      while (tmrpcm.isPlaying() == 1) {
      delay(20);
      }
     tmrpcm.play("left.wav"); 
    }
  }
}
