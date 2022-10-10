#include <Servo.h>

//pins for servo, lin actuator, ESC
#define MOTOR1 3 
#define MOTOR2 4
#define MOTOR3 9
          
Servo servo1; //variable of Servo type named servo1
Servo lin_act;
Servo ESC;

//Functions
float degree2ms(float degrees){  //Convert Degrees to microseconds, which is read by servos
  return 500 + (degrees * 200.0/18);
}

float gear_ratio(float circle){  //converts input angle (which can be 0 to 360) to the angle of motion of the servo (currently 180 deg.)
  return  circle/2;
}

float eccen2ms(float eccen){  //Convert eccen to microseconds, which is read by the linear actuator
  return 1000 + (eccen * 1000.0/30);
}

float esc2ms(float esc){ //Convert esc to microseconds, which is read by the ESC
  return 1000 + (esc *10);
}

void setup(){
  Serial.begin(9600);

  servo1.attach(MOTOR1);
  lin_act.attach(MOTOR2);
  ESC.attach(MOTOR3);

  // Wait for serial port to connect
  while(!Serial);
  Serial.println("Ready. \nSet Serial Monitor to 'No Line Ending.' \nInput angle,eccentricity,motorpower (degrees,mm,%)");

}

void loop(){

  if(Serial.available()){
    float input_angle = Serial.parseFloat();
    float angle = gear_ratio(input_angle);
    angle = degree2ms(angle);

    float input_eccen = Serial.parseFloat();
    float eccen = eccen2ms(input_eccen);

    float input_esc = Serial.parseFloat();
    float esc = esc2ms(input_esc);

    servo1.writeMicroseconds(angle);
    lin_act.writeMicroseconds(eccen);
    ESC.writeMicroseconds(esc);
      
    Serial.print("The servo is moving towards ");
    Serial.print(angle);
    Serial.print(" degrees. \nThe lin. actuator is moving toward ");
    Serial.print(eccen);
    Serial.print(" mm. \nThe motor is at ");
    Serial.print(esc);
    Serial.print(" %. \n");
    
  }
}