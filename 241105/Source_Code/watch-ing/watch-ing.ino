#include <RtcDS1302.h>

// 핀 연결 설정
// DS1302 CLK/SCLK --> 5
// DS1302 DAT/IO --> 4
// DS1302 RST/CE --> 2
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

// DS1302 객체 설정
ThreeWire myWire(9, 8, 10); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

// 버튼 핀 설정
const int buttonPin = 2; // 버튼 핀 번호
int buttonState = 0;     // 버튼 상태
int lastButtonState = 0; // 이전 버튼 상태
unsigned long lastDebounceTime = 0; // 마지막 디바운스 시간
unsigned long debounceDelay = 200;  // 디바운스 시간 (200ms)

// 모드 변수
int mode = 1; // 1: 현재 시간, 2: 알람 설정, 3: 남은 시간

// 알람 시간 변수
RtcDateTime alarmTime(2024, 11, 5, 0, 0, 0); // 기본 알람 시간 (초기 값)
int alarmHour = 0;
int alarmMinute = 0;
int alarmSecond = 0;
bool alarmSet = false; // 알람 시간 설정 여부

void setup() {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);

    Rtc.Begin();

    // RTC 초기화 및 확인
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    if (!Rtc.IsDateTimeValid()) {
        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected()) {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning()) {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }
}

void loop() {
    // 버튼 상태 체크
    int reading = digitalRead(buttonPin);

    // 버튼 상태 변화 감지
    if (reading != lastButtonState) {
        lastDebounceTime = millis(); // 상태 변화가 있으면 시간을 기록
    }

    // 디바운스 시간 이후에만 버튼 상태 확인
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) {
            buttonState = reading;

            // 버튼이 눌렸을 때 (HIGH로 변할 때)
            if (buttonState == HIGH) {
                mode = (mode % 3) + 1; // 모드 변경
                Serial.print("Mode changed to: ");
                Serial.println(mode);
            }
        }
    }

    lastButtonState = reading;

    // 모드에 따른 동작
    switch (mode) {
        case 1:
            printCurrentTime();
            break;
        case 2:
            setAlarmTime();
            break;
        case 3:
            printTimeDifference();
            break;
    }
}

// 현재 시간 출력 함수
void printCurrentTime() {
    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    Serial.println();
}

// 알람 시간 설정 함수 (초까지 입력 받음)
void setAlarmTime() {
    Serial.println("Enter hours (0-23):");
    while (Serial.available() == 0) {}  // 입력이 있을 때까지 기다림
    alarmHour = Serial.parseInt();  // 시 입력 받기
    
    Serial.println("Enter minutes (0-59):");
    while (Serial.available() == 0) {}  // 입력이 있을 때까지 기다림
    alarmMinute = Serial.parseInt();  // 분 입력 받기

    Serial.println("Enter seconds (0-59):");
    while (Serial.available() == 0) {}  // 입력이 있을 때까지 기다림
    alarmSecond = Serial.parseInt();  // 초 입력 받기

    // 알람 시간 설정
    alarmTime = RtcDateTime(2024, 11, 5, alarmHour, alarmMinute, alarmSecond);
    alarmSet = true;

    // 설정된 알람 시간 출력
    Serial.print("Alarm Time set to: ");
    printDateTime(alarmTime);
    Serial.println();
}

// 알람 시간과 현재 시간의 차이를 계산하여 출력 (모드 3)
void printTimeDifference() {
    if (!alarmSet) {
        Serial.println("Alarm time not set yet!");
        return;
    }

    RtcDateTime now = Rtc.GetDateTime();
    long currentTimeInSeconds = now.Hour() * 3600 + now.Minute() * 60 + now.Second();
    long alarmTimeInSeconds = alarmTime.Hour() * 3600 + alarmTime.Minute() * 60 + alarmTime.Second();
    
    long remainingTimeInSeconds = alarmTimeInSeconds - currentTimeInSeconds;
    
    if (remainingTimeInSeconds < 0) {
        remainingTimeInSeconds += 24 * 3600;  // 알람 시간이 지나면 24시간을 더하여 표시
    }

    // 남은 시간 계산
    long hoursLeft = remainingTimeInSeconds / 3600;
    remainingTimeInSeconds %= 3600;  // 시간을 빼고 나서 남은 초에서 분을 계산
    
    long minutesLeft = remainingTimeInSeconds / 60;
    long secondsLeft = remainingTimeInSeconds % 60;

    // 시간, 분, 초 출력
    Serial.print("Time remaining to alarm: ");
    char timestring[9];
    snprintf_P(timestring, sizeof(timestring), PSTR("%02u:%02u:%02u"),
               hoursLeft, minutesLeft, secondsLeft);
    Serial.println(timestring);
}

// 날짜 및 시간 출력 함수
void printDateTime(const RtcDateTime& dt) {
    char datestring[26];
    snprintf_P(datestring, countof(datestring),
               PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
               dt.Month(), dt.Day(), dt.Year(),
               dt.Hour(), dt.Minute(), dt.Second());
    Serial.print(datestring);
}

#define countof(a) (sizeof(a) / sizeof(a[0]))
