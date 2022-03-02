// Switch 눌려질 때마다 4개의 LED 순차 점멸(1개 LED만 on)
#include <Led.h>
#define OFF 0
#define ON 1
const int sw_pin = 2; // 스위치 연결핀
Led leds[4] = {
    Led(8), Led(9), Led(10), Led(11)};
int out_no = -1; // 출력 패턴 번호(0-3)
void setup()
{
    Serial.begin(115200);
    pinMode(sw_pin, INPUT_PULLUP); // Switch 연결핀 입력 설정
}
void loop()
{
    boolean o_sw, n_sw;
    o_sw = !digitalRead(sw_pin);   // 스위치 첫 번째 상태 읽기
    delay(10);                     // 10ms 지연
    n_sw = !digitalRead(sw_pin);   // 스위치 두 번째 상태 읽기
    if (o_sw == OFF && n_sw == ON) // 앞 상태 OFFand 뒤 상태 ON
    {
        move_led();
    }
}

void move_led()
{
    out_no = (++out_no) % 4; // 다음 출력 패턴 번호 설정
    Serial.println(out_no);
    for (int n = 0; n < 4; n++)
    {
        leds[n].setValue(n == out_no);
    }
}