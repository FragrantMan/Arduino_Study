void setup() {
  pinMode(12, OUTPUT);  // 12번 핀을 출력으로 설정
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);  // LED 켜기
  digitalWrite(13, LOW);
  delay(300);              // 1초 대기
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);   // LED 끄기
  delay(300);              // 1초 대기
}
