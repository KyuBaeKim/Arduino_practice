#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino"
#include <MiniCom.h>
#include <Ultra.h>

MiniCom com;
Ultra ultra(5, 6);
#line 6 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino"
void notice_in();
#line 11 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino"
void notice_out();
#line 20 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino"
void setup();
#line 26 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino"
void loop();
#line 6 "/Users/qbae/Workspace/Arduino/chapter5/Ultra/ex04/app.ino"
void notice_in()
{
    com.print(1, "NOTICE IN");
}

void notice_out()
{
    com.print(1, "NOTICE OUT");
}

// void check()
// {
// }

void setup()
{
    com.init();
    com.print(0, "[[Distance]]");
    ultra.setThreshold(40, notice_in, notice_out);
}
void loop()
{
    com.run();
    ultra.run();
}
