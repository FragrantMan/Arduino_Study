// Serial.read 계산기 예제
int count = 0;
int number1 = 0; // 전역변수(Global variable)
char oper;
int number2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // PC -> Arduino
  if(Serial.available() > 0)
  {
    //int number1 = Serial.read(); // 시리얼 모니터의 메시지를 읽는다. 반환형(리턴형)이 정수인 함수
    //Serial.println(number1); // ASCII 코드의 10진수로 반환
    if(count == 0){
      number1 = Serial.parseInt();
      Serial.println(number1);
      count++;
    }
    else if(count == 1){
      oper = Serial.read();
      Serial.println(oper);
      count++;
    }
    else{
      number2 = Serial.parseInt();
      Serial.println(number2);
      count = 0;

      Serial.print(number1);
      Serial.print(oper);
      Serial.print(number2);
      Serial.print('=');

      if(oper == '+'){
        Serial.println(number1 + number2);
      }
      else if(oper == '-'){
        Serial.println(number1 - number2);
      }
      else if(oper == '*'){
        Serial.println(number1 * number2);
      }
      else if(oper == '/'){
        Serial.println(number1 / number2);
      }   
    }



    // 간단한 사칙연산 계산기 (3 + 2 = 5)
  }
}
