#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter4/colorled/ex02/app.ino"
// 1초 간격으로 색상을 랜덤하게 변겨. --> 무드등!

// 10가지 색상을 정해서 , 1초 간격으로 순착적으로 색상 바꾸기!

#include <SimpleTimer.h>
#include <ColorLed.h>

SimpleTimer timer;
ColorLed leds(9, 10, 11);

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

#line 28 "/Users/qbae/Workspace/Arduino/chapter4/colorled/ex02/app.ino"
void check();
#line 39 "/Users/qbae/Workspace/Arduino/chapter4/colorled/ex02/app.ino"
void setup();
#line 45 "/Users/qbae/Workspace/Arduino/chapter4/colorled/ex02/app.ino"
void loop();
#line 28 "/Users/qbae/Workspace/Arduino/chapter4/colorled/ex02/app.ino"
void check()
{
    color_index = (color_index + 1) % COLOR_NUM;
    // leds.rgb(colors[color_index][0], colors[color_index][1], colors[color_index][2]);

    int *pcolor = colors[color_index];
    leds.rgb(pcolor[0], pcolor[1], pcolor[2]);

    // leds.random();
}

void setup()
{
    Serial.begin(115200);
    timer.setInterval(1000, check);
}

void loop()
{
    timer.run();
}
