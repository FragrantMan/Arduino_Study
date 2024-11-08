int ledPin = 13; //정수 13을 ledPin에 저장
int count;

void setup() {
  pinMode(ledPin, OUTPUT); // ledPin = 13 이니까 pinMode(13, OUTPUT); 과 같다.
  Serial.begin(9600);
}
// 실습 : 숫자 입력 받아. 숫자만 큼 반복 점멸 led 만들기
// 실습2 : 로봇암 End Effector(X, Y, Z) 있을때 100ms로 x번, 500ms로 y번, 300ms로 z번 반복 점멸
void loop() {
  if(Serial.available() > 0){
    count = Serial.parseInt();
    Serial.println(count);
    
    for(int i = 0; i < count; i++){
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    Serial.println(i);
    }
  }
}