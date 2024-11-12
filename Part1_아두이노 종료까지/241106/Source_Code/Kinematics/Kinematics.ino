#include <Math.h>

const float L1 = 30.0; // 첫 번째 축 길이 (cm)
const float L2 = 30.0; // 두 번째 축 길이 (cm)

void setup() {
  Serial.begin(9600);
  Serial.println("각도를 입력하세요 (도 단위):");
}

void loop() {
  if (Serial.available() > 0) {
    // 첫 번째 각도 입력
    float angle1 = Serial.parseFloat();
    Serial.print("첫 번째 각도: ");
    Serial.println(angle1);
    
    // 딜레이 후 두 번째 각도 입력
    delay(1000); // 1초 대기
    Serial.println("두 번째 각도를 입력하세요 (도 단위):");

    float angle2 = 0; // 두 번째 각도 초기화
    while (true) {
      String inputString = ""; // 입력 문자열 초기화
      
      // 두 번째 각도 입력 대기
      while (true) {
        if (Serial.available() > 0) {
          char c = Serial.read(); // 한 문자 읽기
          if (c == '\n') { // 엔터 키 입력 확인
            break; // 엔터 키가 눌리면 루프 종료
          } else {
            inputString += c; // 입력 문자열에 추가
          }
        }
      }

      // 두 번째 각도 변환
      angle2 = inputString.toFloat();

      // 각도가 0.00이면 아무 메시지도 출력하지 않고 다시 입력 대기
      if (angle2 == 0.0) {
        continue; // 루프의 처음으로 돌아가서 다시 입력 받기
      }

      // 두 각도를 바탕으로 XY 좌표 계산
      float rad1 = radians(angle1);
      float rad2 = radians(angle2);
      float x = L1 * cos(rad1) + L2 * cos(rad1 + rad2);
      float y = L1 * sin(rad1) + L2 * sin(rad1 + rad2);

      // 결과 출력
      Serial.print("X 좌표: ");
      Serial.println(x);
      Serial.print("Y 좌표: ");
      Serial.println(y);

      // 다음 입력을 위한 안내 메시지
      Serial.println("다음 각도를 입력하세요 (도 단위):");
      break; // 유효한 각도를 입력받았으므로 루프 종료
    }
  }
}
