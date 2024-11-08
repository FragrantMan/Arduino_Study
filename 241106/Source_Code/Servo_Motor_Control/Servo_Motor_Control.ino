void setup() {
  Serial.begin(9600);

}

void loop() {
  if

  for(pos = 0; pos <= 360; pos += 1){
    myservo.write(pos);
    delay(15);
  }
}
