#include <LiquidCrystal.h>

#define BUTTON 3
 
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);


String day, month, year, hour, minute, second, temp, humi, weather;
int IDay, IMonth, IYear, ISecond, IMinute, IHour, timeCount;
int clickCtrl;

String aux;
char aux2[200];
 
void getData(char *data) {
  
  hour = strtok(data, "|");
  minute = strtok(NULL, "|");
  second = strtok(NULL, "|");
  day = strtok(NULL, "|");
  month = strtok(NULL, "|");
  year = strtok(NULL, "|");
  temp = strtok(NULL, "|");
  weather = strtok(NULL, "|");
  humi = strtok(NULL, "|");
  
  // Convert strings to integers
  IHour = hour.toInt();
  IMinute = minute.toInt();
  ISecond = second.toInt();
  IDay = day.toInt();
  IMonth = month.toInt();
  IYear = year.toInt();

  ISecond < 10 ? second = "0" + String(ISecond) : second = String(ISecond);  
  IMinute < 10 ? minute = "0" + String(IMinute) : minute = String(IMinute);
  IHour < 10 ? hour = "0" + String(IHour) : hour = String(IHour);
  IDay < 10 ? day = "0" + String(IDay) : day = String(IDay);
  IMonth < 10 ? month = "0" + String(IMonth) : month = String(IMonth);
}

void printFirstScreen() {
  lcd.setCursor(4, 0);
  lcd.print(hour + ":" + minute + ":" + second);
  lcd.setCursor(3, 1);
  lcd.print(day + "/" + month + "/" + year);
}

void printSecondScreen() {
  lcd.setCursor(0, 0);
  lcd.print(temp + " C / H " + humi + "%");
  lcd.setCursor(0, 1);
  lcd.print(weather);
}

int isLeapYear(int year) {
  if(year % 4 == 0) {
    return 1;
  }
  if(year % 400 == 0) {
    return 1;
  }
  return 0;
}

void changeScreen() {
  if(clickCtrl == 1) {
    clickCtrl = 2;
    lcd.clear();
    delay(10);
    printSecondScreen();
  } else {
    if(clickCtrl == 2) {
      clickCtrl = 1;
      lcd.clear();
      delay(10);
      printFirstScreen();
    }
  }
}

void updateTime() {
  if(ISecond == 59) {
    ISecond = 0;
    IMinute += 1;
    if(IMinute > 59) {
      IMinute = 0;
      IHour += 1;
      if(IHour > 23) {
        IHour = 0;
        IDay += 1;
        if(IMonth == 1 || IMonth == 3 || IMonth == 5 || IMonth == 7 || IMonth == 8 || IMonth == 10 || IMonth == 12) {
          if(IDay > 31) {
            IDay = 1;
            IMonth += 1;
            if(IMonth > 12) {
              IMonth = 1;
              IYear += 1;
            }
          }
        }
        if(IMonth == 4 || IMonth == 6 || IMonth == 9 || IMonth == 11) {
          if(IDay > 30) {
            IDay = 1;
            IMonth += 1;
          }
        }
        if(IMonth == 2) {
          if(isLeapYear(IYear)) {
            if(IDay > 29) {
              IDay = 1;
              IMonth += 1;
            }
          } else {
            if(IDay > 28) {
              IDay = 1;
              IMonth += 1;
            }
          }
        }
      }
    }
  }
  ISecond += 1;
  ISecond < 10 ? second = "0" + String(ISecond) : second = String(ISecond);  
  IMinute < 10 ? minute = "0" + String(IMinute) : minute = String(IMinute);
  IHour < 10 ? hour = "0" + String(IHour) : hour = String(IHour);
  IDay < 10 ? day = "0" + String(IDay) : day = String(IDay);
  IMonth < 10 ? month = "0" + String(IMonth) : month = String(IMonth);
  year = String(IYear);
}

void setup() {
  
  lcd.begin(16, 2);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), changeScreen, FALLING);
  Serial.begin(9600);
  clickCtrl = 1;
}
 
void loop() {
  timeCount = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waiting data...");
  
  while(Serial.available() <= 0){}
  lcd.clear();
  lcd.print("Found data");
  aux = Serial.readString();
    
  aux.toCharArray(aux2, sizeof(aux2));
  getData(aux2);
  
  lcd.clear();
  while(timeCount < 3600) {
    
    if(clickCtrl == 1) {
      printFirstScreen();
    } else {
      if(clickCtrl == 2) {
        printSecondScreen();
      }
    }
     
    delay(999); //Maybe need change the delay time
    updateTime();
    timeCount += 1;  
  }
}
