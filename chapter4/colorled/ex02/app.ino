// 1초 간격으로 색상을 랜덤하게 변겨. --> 무드등!

// 10가지 색상을 정해서 , 1초 간격으로 순착적으로 색상 바꾸기!

// 버튼을 누르면 색상 변경 시간을 0.5초 -> 1초 -> 2초 

#include <SimpleTimer.h>
#include <ColorLed.h>
#include <Button.h>

SimpleTimer timer;
ColorLed leds(9, 10, 11);
Button btn(2);

const int COLOR_NUM = 10;
int colors[COLOR_NUM][3] = {
    {255, 20, 147}, //단일 색상
    {127, 255, 0},
    {0, 255, 255},
    {100, 149, 237},
    {240, 255, 255},
    {255, 240, 245},
    {211, 211, 211},
    {150, 150, 150},
    {238, 130, 238},
    {176, 196, 222},

};

int color_index = -1; // 현재 배열의 인데스

int INTERVAL_NUM = 3;
int INTERVALS[] = {500, 1000, 2000};
int interval_index = 0;
int timer_id = -1; //현재 가동중인 Timer의 ifdef constant-expression


void check()
{
    color_index = (color_index + 1) % COLOR_NUM;
    // leds.rgb(colors[color_index][0], colors[color_index][1], colors[color_index][2]);

    int *pcolor = colors[color_index];
    leds.rgb(pcolor[0], pcolor[1], pcolor[2]);

    // leds.random();
}

// 버튼의 콜백 함수
void change_interval()
{
    // 1. 기존 타이머 제거
    timer.deleteTimer(timer_id);
    // 2. interval_index 조정
    interval_index = (interval_index + 1) % INTERVAL_NUM;
    // 3. 타이머 재설정
    timer_id = timer.setInterval(INTERVALS[interval_index], check);


}

void setup()
{
    Serial.begin(115200);
    timer_id = timer.setInterval(INTERVALS[0], check); // 첫번째 인터벌 설정
    btn.setCallback(change_interval);

}

void loop()
{
    btn.check();
    timer.run();
}