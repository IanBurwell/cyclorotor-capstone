#include <Servo.h>

//pin for servo 1
#define MOTOR1 3 
          
Servo servo1; //variable of Servo type named servo1

//Functions
float degree2ms(float degrees)  //Convert Degrees to microseconds, which is read by servos
{
  return 500 + degrees * 200.0/18;
}

float gear_ratio(float circle)  //converts input angle (which can be 0 to 360) to the angle of motion of the servo (currently 180 deg.)
{
return  circle/2;
}


void setup(){
  Serial.begin(9600);

  servo1.attach(MOTOR1);
}

void loop(){
//Serial.print("Please input an angle in degrees, only put in the number")

  if(Serial.available()){
    String input_angle = Serial.readStringUntil('\n');   
    float angle = input_angle.toFloat();
    angle = gear_ratio(angle);
    angle = degree2ms(angle);

    servo1.writeMicroseconds(angle);
      
    Serial.print("The servo is mvoving towards ");
    Serial.print(input_angle);
    Serial.print(". \n");

  }
}