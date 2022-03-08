#include <BtMiniCom.h>
#include <Car.h>

void receive_msg(String msg); // receive_msg 변수를 인식시키기 위해서 추가
                              // 함수의 순서를 정리할떄 유용핟.

BtMiniCom com(13, 12, receive_msg);
int count = 0;
Car car(3, 5, 4, 9, 8, 7);

void receive_msg(String msg)
{
    if (msg == "F")
    {
        //전진
        car.forward();
    }
    else if (msg == "B")
    {
        //후진
        car.backward();
    }
    else if (msg == "L")
    {
        //좌회전
        car.turn_left();
    }
    else if (msg == "R")
    {
        //우회전
        car.turn_right();
    }
    else if (msg == "S")
    {
        //정지
        car.stop();
    }
}

void setup()
{
    com.init();
}

void loop()
{
    com.run();
}
