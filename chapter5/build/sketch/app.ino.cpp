#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
// '*' 누르면 입력시작
// 숫자 -> interrupts()
// '#' 완료
#include <MiniCom.h>
#include <NumberPad.h>
#include <Servo.h>

Servo servo;
MiniCom com;
NumberPad keypad;

String input = "";
String dumy_input = "";
bool b_input = false;

int timer_id = -1;
const String PASSWORD = "2345";

const int buzzer_pin = 9;

#line 21 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void open_door();
#line 30 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void close_door();
#line 35 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void cancel_input();
#line 45 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void start_input();
#line 55 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void end_input();
#line 81 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void key_input(char key);
#line 88 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void key_process(char key);
#line 105 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void setup();
#line 115 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void loop();
#line 21 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
void open_door()
{
    SimpleTimer &timer = com.getTimer();

    servo.write(90);
    timer.restartTimer(timer_id);
    timer_id = timer.setTimeout(5000, close_door);
}

void close_door()
{
    servo.write(0);
}

void cancel_input()
{
    b_input = false;
    input = "";
    dumy_input = "";
    com.print(1, "");
    timer_id = -1;
    com.offLcd();
}

void start_input()
{

    b_input = true;
    input = "";
    dumy_input = "";
    timer_id = com.getTimer().setTimeout(5000, cancel_input);
    com.onLcd();
}

void end_input()
{
    //입력 완료

    Serial.print("입력완료:");
    Serial.println(input);
    if (input == PASSWORD)
    {
        open_door();
    }
    else
    {
        digitalWrite(buzzer_pin, HIGH);
        delay(200);

        digitalWrite(buzzer_pin, LOW);
        delay(100);
    }
    b_input = false;

    com.print(1, "");
    com.getTimer().deleteTimer(timer_id);
    timer_id = -1;
    com.offLcd();
}

void key_input(char key)
{
    input += key;
    dumy_input += '*';
    com.print(1, dumy_input.c_str());
    com.getTimer().restartTimer(timer_id); //취소 연장
}
void key_process(char key)
{

    if (key == '*')
    {
        start_input();
    }
    else if (key == '#')
    {
        end_input();
    }
    else if (key && b_input)
    {
        key_input(key);
    }
}

void setup()
{
    com.init();
    com.offLcd();
    com.print(0, "[[Keypad Test]]");
    servo.attach(3);
    servo.write(0); // close
    pinMode(buzzer_pin, OUTPUT);
}

void loop()
{
    com.run();
    char key = keypad.getKey();
    key_process(key);
}

