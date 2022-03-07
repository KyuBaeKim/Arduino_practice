# 1 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino" 2
# 4 "/Users/qbae/Workspace/Arduino/chapter5/PIR/ex02/app.ino" 2

Led led(8);
MiniCom com;
Pir pir(7);

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
