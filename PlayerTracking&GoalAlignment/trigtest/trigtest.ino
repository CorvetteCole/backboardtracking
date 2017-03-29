
const float Pi = 3.14159;
float radian, x, y;
int angle;

void setup(){
Serial.begin(9600);

}

void loop(){

//waiting for input
Serial.println("x=");
while (Serial.available() == 0) {}
x = Serial.parseFloat();
Serial.flush();

Serial.println("y=");
while (Serial.available() == 0) {}
y = Serial.parseFloat(); //read int or parseFloat for ..float...


if (x != 0) {
  radian = atan(y/x);
  angle = (radian * 180)/Pi;
}
else if (x == 0) {
  angle = 0;
}
else if ((y == 0) && (x < 0)) {
  angle = 270;
}
else if ((y == 0) && (x > 0)) {
  angle = 90;
}

if (angle < 0) {
  angle = 360 + angle;
}
Serial.println(angle);



}
