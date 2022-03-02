# 1 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/chapter3/Timer/app.ino" 2

boolean led_val = 0x0;
Led led(8);

void setup()
{
    // 타이머2 인터럽트 설정 및 동작 시작
    MsTimer2::set(500, flash); // 500ms 인터럽트 주기 설정, flash() 함수 실행
    MsTimer2::start(); // 타이머2 동작 시작
}

void loop()
{
}

void flash()
{
    led_val = !led_val;
    led.setValue(led_val);
}
