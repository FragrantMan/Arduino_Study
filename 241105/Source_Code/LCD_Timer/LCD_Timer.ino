#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

unsigned long currentTime;
unsigned long previousTime;
unsigned long sec;
unsigned long min;
unsigned long hour;

void setup()
{
  Serial.begin(9600);
  lcd.init();               // initialize the lcd 
  lcd.clear();
  lcd.backlight();
}

void loop()
{
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

  lcd.setCursor(0,0);
  lcd.print("Current Time");

  lcd.setCursor(0,1); //LCD 시작 위치
  lcd.print(hour);
  lcd.print(":");
  lcd.print(min);
  lcd.print(":");
  lcd.print(sec); 

}