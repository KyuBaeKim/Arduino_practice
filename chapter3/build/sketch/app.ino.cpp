#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter3/ex02/app.ino"
#include <Led.h>

const int in_pu_sw_pin = 2;
Led led(8);

#line 6 "/Users/qbae/Workspace/Arduino/chapter3/ex02/app.ino"
void setup();
#line 11 "/Users/qbae/Workspace/Arduino/chapter3/ex02/app.ino"
void loop();
#line 6 "/Users/qbae/Workspace/Arduino/chapter3/ex02/app.ino"
void setup()
{
    pinMode(in_pu_sw_pin, INPUT_PULLUP); // INPUT_PULLUP INPUT 외부저항
}

void loop()
{
    boolean in_pu_sw;
    in_pu_sw = !digitalRead(in_pu_sw_pin);
    led.setValue(in_pu_sw);
}
