#include <servo.h>

#define MOTOR1 C06
#define MOTOR2 C07
#define MOTOR3 B00
#define MOTOR4 B01

#define SERIAL_TX2 A02
#define SERIAL_RX2 A03
#define SERIAL_TX3 C10
#define SERIAL_RX3 C11
#define SERIAL_TX4 A00
#define SERIAL_RX4 A01

Servo esc, servo1, servo2;

void setup(){
  Serial.begin(9600);

  esc.attach(MOTOR1);
  servo1.attach(MOTOR2);
  servo2.attach(MOTOR3);

}

void loop(){

  if(Serial.available()){
    char c = Serial.read();    
    if(c == '1'){
      esc.writeMicroseconds(1000);
      servo1.writeMicroseconds(1000);
      servo2.writeMicroseconds(1000);
    }
    else if(c == '2'){
      esc.writeMicroseconds(1500);
      servo1.writeMicroseconds(1500);
      servo2.writeMicroseconds(1500);
    }
    else if(c == '3'){
      esc.writeMicroseconds(2000);
      servo1.writeMicroseconds(2000);
      servo2.writeMicroseconds(2000);
    }
  }
}