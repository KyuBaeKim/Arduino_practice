#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter5/joystick/ex01/app.ino"
#include <MiniCom.h>
#include <Analog.h>
#include <Button.h>

MiniCom com;
Analog x(A0);
Analog y(A1);
Analog z(A2);
#line 9 "/Users/qbae/Workspace/Arduino/chapter5/joystick/ex01/app.ino"
void check();
#line 22 "/Users/qbae/Workspace/Arduino/chapter5/joystick/ex01/app.ino"
void setup();
#line 28 "/Users/qbae/Workspace/Arduino/chapter5/joystick/ex01/app.ino"
void loop();
#line 9 "/Users/qbae/Workspace/Arduino/chapter5/joystick/ex01/app.ino"
void check()
{
    int dx, dy;
    boolean sw;
    dx = x.read();
    dy = y.read();
    sw = z.read();

    char buf[17];
    sprintf(buf, "%d, %d [%d]", dx, dy, sw);
    com.print(1, buf);
}

void setup()
{
    com.init();
    com.setInterval(100, check); // 0.1초 간격으로
    com.print(0, "[[Joystick");
}
void loop()
{
    com.run();
}
