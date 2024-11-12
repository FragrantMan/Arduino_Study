int val = 0;
int LedPin = 3;
int YelPin = 5;
int GrePin = 6;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0); //1023
  Serial.println(val);
  delay(100);

  if(val<350){
    int val1 = val/2;
    analogWrite(LedPin, val1);
    analogWrite(YelPin, LOW);
    analogWrite(GrePin, LOW);
    Serial.println(val1);
  }
  else if(val > 350 && val < 700){
    analogWrite(LedPin, LOW);
    analogWrite(YelPin, LOW);
    analogWrite(GrePin, LOW);
    
    val = val-350;
    int val2 = val/2;
    analogWrite(LedPin, LOW);
    analogWrite(YelPin, val2);
    analogWrite(GrePin, LOW);
    Serial.println(val2);
  }
  else{
    analogWrite(LedPin, LOW);
    analogWrite(YelPin, LOW);
    analogWrite(GrePin, LOW);
    
    val = val-700;
    int val3 = val/2;
    analogWrite(LedPin, LOW);
    analogWrite(YelPin, LOW);
    analogWrite(GrePin, val3);
    Serial.println(val3);
  }
}