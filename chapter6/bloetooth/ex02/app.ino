#include <BtMiniCom.h>
#include <Servo.h>

void receive_msg(String msg); // receive_msg 변수를 인식시키기 위해서 추가
                              // 함수의 순서를 정리할떄 유용핟.

BtMiniCom com(13, 12, receive_msg);
int count = 0;

void receive_msg(String msg)
{
    if (msg == "open")
    {
        servo.write(90);
    }
    else if (msg == "close")
    {
        servo.write(0);
    }
    com.print(1, msg.c_str());
}

void setup()
{
    com.init();
    com.print(0, "[[Bluetooth]]");
}

void loop()
{
    com.run(); // bl 수신 & callback 호출(처리) -> 타이머 운영
}
