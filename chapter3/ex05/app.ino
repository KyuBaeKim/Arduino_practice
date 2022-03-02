// Switch 눌려질 때마다 4개의 LED 순차 점멸(1개 LED만 on)
#include <Led.h>
#include <Button.h>

Button btn(2);

Led leds[4] = {
    Led(8), Led(9), Led(10), Led(11)};

Led led(7);

int out_no = -1; // 출력 패턴 번호(0-3)

void move_led()
{
    out_no = (++out_no)1 % 4; // 다음 출력 패턴 번호 설정
    Serial.println(out_no);
    for (int n = 0; n < 4; n++)
    {
        leds[n].setValue(n == out_no);
    }
}

void setup()
{
    btn.setCallback(move_led); // 함수명 : 함수 주소 -> 함수에 대한 포인터 ( void(* 함수이름)(매개변수))  ex)move_led
    // callback <- 뒤에서 함수를 호출한다는 뜻 (이벤트 헨들러 라고도 한다.)
}
void loop()
{
    led.blink(1000);
    btn.check();
}