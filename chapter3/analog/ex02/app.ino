#include <PWMLed.h>

PWMLed led(9);

// LED에 PWM 신호 출력하기

const int led_pin = 9;

void setup()
{
}

void loop()
{
    int pwm_val;

    for (pwm_val = 0; pwm_val < 256; pwm_val += 5) // 서서히 밝아짐.
    {
        led.setValue(pm_val); // PWM 신호 출력
        delay(100);
    }
    dled.off();
    delay(2000); // 2초대기
}