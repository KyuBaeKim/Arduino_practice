#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter2/led/ex07/app.ino"
#include <Led.h>

Led leds[4] = {Led(3), Led(4), Led(5), Led(6)};
int out_no = 0; // 출력 값 출력 순서 번호 (0~3)
#line 5 "/Users/qbae/Workspace/Arduino/chapter2/led/ex07/app.ino"
void setup();
#line 9 "/Users/qbae/Workspace/Arduino/chapter2/led/ex07/app.ino"
void loop();
#line 5 "/Users/qbae/Workspace/Arduino/chapter2/led/ex07/app.ino"
void setup()
{
}

void loop()
{
    for (int n = 0; n < 4; n++)
    {   
        leds[n].setValue( n == out_no);
        // if (n == out_no)
        // {
        //     leds[n].on();
        // }
        // else
        // {
        //     leds[n].off();
        // }
    }
    out_no == (++out_no) % 4; // if(out_no == 4) out_no = 0 ; 과 같은의미
    delay(1000);
}
