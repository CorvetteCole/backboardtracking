/*
 Sharp GP2Y0A710K0F infrared proximity sensor (#28999)
 Displays raw digital value of approximate distance every 
 quarter second (250 milliseconds).
 
 Distance measurement range is 100cm to 550cm (39.3" to 216.5")
 
 Returns basic 10-bit analog-to-digital value where 0=0 volts, and 1023=5 volts,
 and displays it in the Arduino Serial Monitor window. After uploading the
 sketch, open the Serial Monitor and be sure to set communication speed
 to 9600 baud.
 
 Typical values are from 340 to 380 (maximum distance) to 545-610, indicating 
 minimum distance. Values outside these ranges may occur when the object 
 is too close to the sensor (under 100cm)
 
 Keep in mind output is not linear to distance. See the Sharp GP2Y0A710K0F 
 datasheet for more information.
 
 This example code is for the Arduino Uno and direct compatible boards, using the
 Arduino 1.0 or later IDE software. It has not been tested, nor designed for, other 
 Arduino boards, including the Arduino Due.
 
Connections:
Sensor       Arduino
GND          GND
Vcc          5V
VO(utput)    Analog pin 0 (A0)

Note: The following standard color-coded is use with the adapter cable included
from Parallax with this sensor:

Color       Connection on sensor
Black       GND
Red         Vcc
White       VO

*/

const int irSense = A0;            // Connect sensor to analog pin A0
int sensor,voltage,distance = 0;

void setup() {
  Serial.begin(9600);              // Use Serial Monitor window
}

void loop() {
  sensor = analogRead(irSense);  // Read the sensor
  float voltage = analogRead(A0)  * (5.0 / 1023.0);      
 
  Serial.println(voltage, DEC);   // Display value in Serial Monitor window
  delay(1000);                      // Wait 1/4 second for the next read
}
