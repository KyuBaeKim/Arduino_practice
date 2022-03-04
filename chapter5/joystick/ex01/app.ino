#include <MiniCom.h>
#include <Analog.h>
#include <Button.h>

MiniCom com;
Analog x(A0);
Analog y(A1);
Analog z(A2);
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
    com.print(0, "[[Joystick]]");
}
void loop()
{
    com.run();
}