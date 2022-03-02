#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino"
#include <Led.h>
#include <MsTimer2.h>

boolean led_val = LOW;
Led led(8);

#line 7 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino"
void setup();
#line 14 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino"
void loop();
#line 18 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino"
void flash();
#line 7 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino"
void setup()
{
    // 타이머2 인터럽트 설정 및 동작 시작
    MsTimer2::set(500, flash); // 500ms 인터럽트 주기 설정, flash() 함수 실행
    MsTimer2::start();         // 타이머2 동작 시작
}

void loop()
{
}

void flash()
{
    led_val = !led_val;
    led.setValue(led_val);
}
