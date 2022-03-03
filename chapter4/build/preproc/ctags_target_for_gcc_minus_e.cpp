# 1 "/Users/qbae/Workspace/Arduino/chapter4/buzzer/ex02/app.ino"
# 9 "/Users/qbae/Workspace/Arduino/chapter4/buzzer/ex02/app.ino"
int melody[49] = { // 곰 세마리
    // 도도도도도 // 미솔솔미도
    262 /* 4옥타브 도*/, 262 /* 4옥타브 도*/, 262 /* 4옥타브 도*/, 262 /* 4옥타브 도*/, 262 /* 4옥타브 도*/, //도도도도도
    330 /* 4옥타브 미*/, 392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 330 /* 4옥타브 미*/, 262 /* 4옥타브 도*/, //미솔솔미도
    392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 330 /* 4옥타브 미*/, 392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 330 /* 4옥타브 미*/, //솔솔미솔솔미
    262 /* 4옥타브 도*/, 262 /* 4옥타브 도*/, 262 /* 4옥타브 도*/, //도도도

    392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 330 /* 4옥타브 미*/, 262 /* 4옥타브 도*/, //솔솔 미도
    392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, //솔솔솔
    392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 330 /* 4옥타브 미*/, 262 /* 4옥타브 도*/, //솔솔 미도
    392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, //솔솔솔
    392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 330 /* 4옥타브 미*/, 262 /* 4옥타브 도*/, // 솔솔미도
    392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 392 /* 4옥타브 솔*/, 440 /* 4옥타브 라*/, 392 /* 4옥타브 솔*/, // 솔솔솔라솔
    523 /* 5옥타브 레*/, 392 /* 4옥타브 솔*/, 523 /* 5옥타브 레*/, 392 /* 4옥타브 솔*/, //도솔도솔
    330 /* 4옥타브 미*/, 294 /* 4옥타브 레*/, 262 /* 4옥타브 도*/}; // 미레도

// 음표 길이
int noteDuration[49] = {
    4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 8, 8, 4, 8, 8, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 8, 8, 8, 8, 2, 4, 4, 4, 4, 4, 4, 2};
const int speaker_pin = 9;
void setup()
{
    pinMode(speaker_pin, 0x1);
}

void loop()
{
    int m, d, dd;
    for (m = 0; m < 49; m++)
    {
        d = 1000 / noteDuration[m];
        dd = d * 1.3; // 음 출력 시간(4분 음표 325ms)
        tone(speaker_pin, melody[m], d);
        delay(dd);
    }
    delay(1000);
}
