int leds[] = {2,3,4,5,6,7,8,9}; // led 개수
int led_num = 8; //7seg led
int button = 13; //13핀은 버튼
int num = 0; //led에 표시되고 있는 숫자

int set_number[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0}, //3
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},//5
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0},
};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < led_num; i++){
    pinMode(leds[i], OUTPUT);
  }

  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button) == LOW){
    if(num == 9) num = 0;
    else num++;
  }
  for (int j = 0; j < led_num; j++){
    digitalWrite(leds[j], set_number[num][j]);
  }
  
  delay(150);
}