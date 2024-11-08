int count; //int의 정수형 변수 선언
int amout = 5; //변수 선언과 초기화
float temperature = 23.5; //실수형
bool isOn = false; // True or False 형태의 불형변수
char character = '?';
String message = "안녕하세요! 저는 최승현입니다.";

void setup() {     //아두이노가 실행되면 최초 한번 실행
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //13번 핀을 출력모드로 사용

  Serial.begin(9600);
  Serial.println(message);
  count = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); //13번을 디지털신호로 1을 쓴다.
  delay(1000); //1000ms = 1초
  digitalWrite(13, LOW); //13번핀에 0 신호 입력
  delay(1000);

  Serial.println(count);
  count = count + 1; // +,-,*,/ = 사친연산, // : 몫 연산, % : 나머지 연산

  if(count > 5){
    Serial.println("갯수가 초과되었습니다.");
    // count = 0;
  }
  //count가 3보다 크고 5보다 자다면
  else if(count > 3 && count < 5){ // && = and 조건 연산자, || = or 조건 연산자
  // == 는 비교 연산자 != : 
    Serial.println("특정 조건입니다.");
  }
  else if(count > 10 || count < 0){
    Serial.println("count는 10보다 크거나 0보다 작습니다.");
  }
  else if(count > 20 || count < 0){
    Serial.println("count는 10보다 크거나 0보다 작습니다.");
  }
  else{
    Serial.println("정상");
  }
}