#include <MiniCom.h>
#include <Led.h>

Led led(8);
MiniCom com;

void check()
{
    //저항값 읽어서 lcd로 출력
    int value = sensor.read();
    com.print(1, "value: ", value);
}

void setup()
{
    com.init();
    com.print(0, "[[MiniCom]]");
    com.setInterval(100, check); // 1초 간격으로
}
void loop()
{
    com.run();
}
