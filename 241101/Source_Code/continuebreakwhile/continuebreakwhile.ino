void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 20; i++) {
    if(i > 10 && i < 15) {
      continue;  // 10 초과 15 미만의 i를 스킵
    }
    
    Serial.print("For 반복문 값 : ");
    Serial.println(i);

    if(i == 18) {
      break;  // i가 18일 때 반복문 종료
    }
  }

  int i = 0;
  while(i < 50) {
    if(i > 20 && i < 40) {
      i++;  // i를 증가시킨 후 continue로 넘어감
      continue;  // 20 초과 40 미만의 i를 스킵
    }

    Serial.print("While 반복문 값 : ");
    Serial.println(i);
    i++;  // 여기서 i를 증가시킴

    if(i == 45) {
      break;  // i가 45일 때 반복문 종료
    }
  }
}

void loop() {
  // loop 함수는 비워둡니다.
}