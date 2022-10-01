#include <Servo.h>

#define MOTOR1 C06


#define SERIAL_TX2 A02
#define SERIAL_RX2 A03

Servo esc, servo1, servo2;

void setup(){
  Serial.begin(9600);

  servo1.attach(MOTOR1);

}

void loop(){

  if(Serial.available()){
    char c = Serial.read();    
    if(c == '2'){
      esc.writeMicroseconds(1500);
      servo1.writeMicroseconds(1500);
      servo2.writeMicroseconds(1500);
    }

    serial.println("The input was " + c + ".")
  }
}