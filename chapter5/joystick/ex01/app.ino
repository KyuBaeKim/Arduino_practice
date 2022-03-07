#include <MiniCom.h>
#include <Analog.h>
#include <Button.h>
#include <Servo.h>

Servo servo;
MiniCom com;
// Analog x(A1, 180, 0);    // 서보모터 방향 제어
Analog x(A1, 180, 0); //rc카의 속도 및 좌우 방향제어
Analog y(A0, -100, 100); // rc카의 속도 및 방향제어
Analog z(A2);
void check()
{
    int dx, dy;
    boolean sw;
    dx = x.read();
    dy = y.read();
    sw = z.read();

    servo.write(dx);

    char buf[17];
    sprintf(buf, "%d, %d [%d]", dx, dy, sw);
    com.print(1, buf);
}

void setup()
{
    com.init();
    com.setInterval(100, check); // 0.1초 간격으로
    com.print(0, "[[Joystick]]");
    servo.attach(3);
    servo.write(0); // close
}
void loop()
{
    com.run();
}