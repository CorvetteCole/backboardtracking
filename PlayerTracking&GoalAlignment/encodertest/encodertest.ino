int encoderValue;
void count(void);

void setup()  {
  Serial.begin(9600);
  pinMode(2, INPUT);    //connect encoder channel A to pin 2 and channel B to pin 3
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), count, FALLING);
} 

void loop()  {
    
    
    Serial.println(encoderValue);   
   
    
  }

void count(){
  if(digitalRead(3)) {
        encoderValue++;               
      }   
      else {
        encoderValue--;               
      } 
}  


