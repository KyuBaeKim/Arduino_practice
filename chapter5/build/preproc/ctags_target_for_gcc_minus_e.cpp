# 1 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino"
// '*' 누르면 입력시작
// 숫자 -> interrupts()
// '#' 완료
# 5 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino" 2
# 6 "/Users/qbae/Workspace/Arduino/chapter5/keypad/ex02/app.ino" 2

MiniCom com;
NumberPad keypad;

String input = "";
String dumy_input = "";
bool b_input = false;

int timer_id = -1;

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
    b_input = false;
    Serial.print("입력완료:");
    Serial.println(input);
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
    com.print(0, "[[Keypad Test]]");
}

void loop()
{
    com.run();
    char key = keypad.getKey();
    key_process(key);
}
