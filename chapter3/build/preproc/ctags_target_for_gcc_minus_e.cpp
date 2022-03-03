# 1 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/chapter3/interrupt/ex02/app.ino" 2
Led led(8);
Button btn(2);
boolean led_st = 0x0;
void flash(void)
{
    if (!btn.debounce())
        return;
    led_st = !led_st; // LED 상태 반전
    led.setValue(led_st);
}
void setup()
{
    btn.attachInterrupt(flash, 2);
}
void loop() {}
