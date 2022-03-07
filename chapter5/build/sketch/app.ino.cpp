#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
#include <MiniCom.h>
#include <Led.h>
#include <Pir.h>

Led led(8);
MiniCom com;
Pir pir(7);

#line 9 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
void detect_on();
#line 15 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
void detect_off();
#line 20 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
void check();
#line 24 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
void setup();
#line 30 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
void loop();
#line 9 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
void detect_on()
{
    com.print(1, "Motion detected!");
    led.on();
}

void detect_off()
{
    com.print(1, "Motion ended!");
    led.off();
}
void check()
{
}

void setup()
{
    com.init();
    com.print(0, "[[Motion]]");
    pir.setCallback(detect_on, detect_off);
}
void loop()
{
    com.run();
    pir.check();
}
