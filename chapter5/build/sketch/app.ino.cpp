#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino"
#include <MiniCom.h>
#include <Analog.h>

MiniCom com;
Analog cds(A0, 0, 100);

#line 7 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino"
void check();
#line 13 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino"
void setup();
#line 19 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino"
void loop();
#line 7 "/Users/qbae/Workspace/Arduino/chapter5/cds/ex01/app.ino"
void check()
{
    int value = cds.read();
    com.print(1, "Illu: ", value);
}

void setup()
{
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[CDS Test]]");
}
void loop()
{
    com.run();
}
