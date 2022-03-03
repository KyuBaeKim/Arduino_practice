#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino"
#include <Led.h>
#include <Button.h>
Led led(8);
Button btn(2);
boolean led_st = LOW;
#line 6 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino"
void flash(void);
#line 13 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino"
void setup();
#line 17 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino"
void loop();
#line 6 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino"
void flash(void)
{
    if (!btn.debounce())
        return;
    led_st = !led_st; // LED 상태 반전
    led.setValue(led_st);
}
void setup()
{
    btn.attachInterrupt(flash, FALLING);
}
void loop() {}
