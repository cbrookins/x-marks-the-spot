#include "x.h"

X::X(){}

void X::drawWatchFace(){
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.drawBitmap(45, 37, x, 110, 124, GxEPD_WHITE);
    drawTime();
    drawWDay();
    drawDate();
    drawSteps();
    drawTemperature();
    drawBattery();
    for(uint8_t i=0; i<3; i++){
        // Reduce ghosting
        display.display(true);
    }
}

void X::drawTime(){
    int16_t  x1, y1;
    uint16_t w, h;
    String hour;
    String minutes;
    //display.setFont(&LcdSolid27pt7b);
    display.setTextSize(5);
    if(currentTime.Hour < 10){
        display.print("0");
    }
    hour = currentTime.Hour;
    display.getTextBounds(hour, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(75, 100-h/2);
    display.print(hour);
    display.setCursor(128, 195);
    if(currentTime.Minute < 10){
        display.print("0");
    }
    minutes = currentTime.Minute;
    display.getTextBounds(minutes, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(175, 100-h/2);
    display.print(minutes);
}

void X::drawWDay(){
    //display.setFont(&LcdSolid9pt7b);
    display.setTextSize(2);
    display.setCursor(159, 91);
    String dayOfWeek = dayShortStr(currentTime.Wday);
    dayOfWeek.toUpperCase();
    display.print(String(dayOfWeek));
}

void X::drawDate(){
    //display.setFont(&LcdSolid8pt7b);
    display.setTextSize(2);
    display.setCursor(4, 195);
    String monthStr = String(currentTime.Month);
    String dayStr = String(currentTime.Day);
    monthStr = currentTime.Month < 10 ? "0" + monthStr : monthStr;
    dayStr = currentTime.Day < 10 ? "0" + dayStr : dayStr;
    String dateStr = dayStr + "." + monthStr;
    display.print(String(dateStr));
}

void X::drawSteps(){
    //display.setFont(&LcdSolid8pt7b);
    display.setTextSize(2);
    display.setCursor(141, 106);
    uint32_t stepCount = sensor.getCounter();
    String stepStr = String(stepCount);
    for(int i=1; i<5; i++){
        stepStr = stepCount < pow(10, i) ? "0" + stepStr : stepStr;
    }
    if(currentTime.Hour == 23 && currentTime.Minute == 59){
        sensor.resetStepCounter();
    }
    display.print(String(stepStr));
}

void X::drawTemperature(){
    bool Fh;
    Fh = true;
    //display.setFont(&LcdSolid8pt7b);
    display.setTextSize(2);
    display.setCursor(4, 181);
    uint8_t temperatureRTC = RTC.temperature() / 4;
    if (Fh == true) {
      temperatureRTC = temperatureRTC * (9/5) + 32;
    }
    if(temperatureRTC < 10){
    display.print("0");
    }
    display.print(temperatureRTC);
    if (Fh == true) {
      display.print("Fh");
    } else {
      display.print("c");
    }
}

void X::drawBattery(){
    display.setTextColor(GxEPD_WHITE);
    //display.setFont(&LcdSolid9pt7b);
    display.setTextSize(1.5);
    display.setCursor(187, 17);
    display.print(">");
    display.setCursor(165, 17);
    float BATTV = getBatteryVoltage();
    if(BATTV > 4.10){
        display.print("xxx");
    }
    else if(BATTV > 3.85 && BATTV <= 4.10){
        display.print(" xx");
    }
    else if(BATTV > 3.60 && BATTV <= 3.85){
        display.print("  x");
    }
}
