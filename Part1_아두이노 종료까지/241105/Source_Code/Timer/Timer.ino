//millis()
unsigned long currentTime;
unsigned long previousTime;
unsigned long sec;
unsigned long min;
unsigned long hour;

void setup() {
  Serial.begin(9600);

}

void loop() {
  currentTime = millis();
  
  if(currentTime - previousTime > 1000)
  {
    sec++;
    previousTime = currentTime;    
  }
  
  if(sec > 59){
    min++;
    sec = 0;
  }
  
  if(min > 59){
    hour++;
    min = 0;
  }

  if(hour>23){
    hour = 0;
  }
  
  Serial.print(hour);
  Serial.print(":");
  Serial.print(min);
  Serial.print(":");
  Serial.println(sec);
  
}
