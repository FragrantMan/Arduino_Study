#include <Servo.h>
Servo myservo;
int val = 0;
int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  for(pos = 0; pos <= 360; pos += 1){
    myservo.write(pos);
    delay(15);
  }
}
