// Switch 눌려질 때마다 4개의 LED 순차 점멸(1개 LED만 on)
#include <Led.h>
#include "Button.h"

Button btn(2);

const int sw_pin = 2; // 스위치 연결핀
Led leds[4] = {
    Led(8), Led(9), Led(10), Led(11)};
int out_no = -1; // 출력 패턴 번호(0-3)


void move_led()
{
    out_no = (++out_no) % 4; // 다음 출력 패턴 번호 설정
    Serial.println(out_no);
    for (int n = 0; n < 4; n++)
    {
        leds[n].setValue(n == out_no);
    }
}

void setup()
{
    btn.setCallback(move_led);
}
void loop()
{
   btn.check();
}