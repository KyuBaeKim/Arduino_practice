#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter4/buzzer/ex01/app.ino"
// 부저 울리기(능동 부저)
const int buzzer_pin = 9;


#line 5 "/Users/qbae/Workspace/Arduino/chapter4/buzzer/ex01/app.ino"
void setup();
#line 10 "/Users/qbae/Workspace/Arduino/chapter4/buzzer/ex01/app.ino"
void loop();
#line 5 "/Users/qbae/Workspace/Arduino/chapter4/buzzer/ex01/app.ino"
void setup()
{
    pinMode(buzzer_pin, OUTPUT);
}

void loop()
{
    digitalWrite(buzzer_pin, HIGH);
    delay(200);

    digitalWrite(buzzer_pin, LOW);
    delay(100);
}
