#include <Led.h>

#define OFF 0
#define ON 1

const int sw_pin = 2;
Led led(8);
boolean led_st = OFF;
int count = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(sw_pin, INPUT_PULLUP);
    led.setValue(led_st);
}

void loop()
{
    boolean o_sw, n_sw;

    o_sw = !digitalRead(sw_pin);
    delay(1);
    n_sw = !digitalRead(sw_pin);

    if (o_sw == OFF && n_sw == ON)
    {
        count++;               // 버튼 누른 횟수 카운트
        Serial.println(count); // 누른 횟수 출력
        led_st = !led_st;      // Led 껏다 키기
        led.setValue(led_st);
    }
}