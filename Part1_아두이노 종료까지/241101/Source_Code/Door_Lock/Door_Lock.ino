int pw[6] = {9, 5, 5, 8, 8, 2}; // 비밀번호 배열
int count = 3; // 시도 횟수

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // 사용자 입력을 문자열로 읽기.
    int num[6]; // 비밀번호 입력을 저장할 배열

    // 입력된 문자열에서 각 숫자를 정수로 변환하여 num 배열에 저장
    for (int i = 0; i < 6; i++) {
      num[i] = input.charAt(i) - '0'; // 각 문자를 정수로 변환
    }

    bool isCorrect = true; // 비밀번호가 맞는지 체크하는 변수

    for (int i = 0; i < 6; i++) {
      if (pw[i] != num[i]) {
        Serial.println("틀렸습니다!");
        count--; // 시도 횟수 감소
        isCorrect = false; // 비밀번호가 틀렸음을 기록
        break; // 비밀번호가 틀렸으면 더 이상 확인할 필요 없음
      }
    }

    if (isCorrect) {
      Serial.println("문이 열렸습니다!"); // 비밀번호가 맞을 때
    }

    if (count <= 0) {
      Serial.println("관리자에게 문의하세요"); // 시도 횟수가 0일 때
      count = 3; // 초기화
    }
  }
}
