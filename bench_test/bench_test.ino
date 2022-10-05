#include <servo.h>

#define MOTOR1 B00
#define MOTOR2 B01
#define MOTOR3 A00
#define MOTOR4 A01

#define SERIAL_TX2 D05
#define SERIAL_RX2 D06
#define SERIAL_TX3 D08
#define SERIAL_RX3 D09
#define SERIAL_TX4 B09
#define SERIAL_RX4 B08

#define LED1 E03
#define LED2 E04

Servo esc, servo1, servo2;
unsigned long last_flash = 0;

void setup(){
  Serial.begin(9600);

  esc.attach(MOTOR1);
  servo1.attach(MOTOR2);
  servo2.attach(MOTOR3);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, HIGH);

}

void loop(){
  // Handle serial input
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

  // Flash LEDs
  if(millis() - last_flash > 500){
    last_flash = millis();
    digitalWrite(LED1, !digitalRead(LED1));
    digitalWrite(LED2, !digitalRead(LED2));
  }

}