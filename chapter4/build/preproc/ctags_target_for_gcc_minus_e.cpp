# 1 "/Users/qbae/Workspace/Arduino/chapter4/buzzer/ex01/app.ino"
// 부저 울리기(능동 부저)
const int buzzer_pin = 9;


void setup()
{
    pinMode(buzzer_pin, 0x1);
}

void loop()
{
    digitalWrite(buzzer_pin, 0x1);
    delay(200);

    digitalWrite(buzzer_pin, 0x0);
    delay(100);
}
