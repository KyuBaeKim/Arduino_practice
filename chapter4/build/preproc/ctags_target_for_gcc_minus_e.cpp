# 1 "/Users/qbae/Workspace/Arduino/chapter4/servo/ex02/app.ino"
//문제
// 구성: 버튼 1개. 능동 부저 1개. 서브 모터 1개

// 버튼을 누르면 짧게 삐 소리 내고, 서브모터를 제어하여 문을 열어 줌
// 3초 후에 자동으로 닫힘
// 3초 전에 누르면 그 시점에서 3초 후에 닫힘(시간연장)
// LCD에 현재 문의 상태(Open/Close) 출력


# 11 "/Users/qbae/Workspace/Arduino/chapter4/servo/ex02/app.ino" 2
# 12 "/Users/qbae/Workspace/Arduino/chapter4/servo/ex02/app.ino" 2
# 13 "/Users/qbae/Workspace/Arduino/chapter4/servo/ex02/app.ino" 2
# 14 "/Users/qbae/Workspace/Arduino/chapter4/servo/ex02/app.ino" 2

MiniCom com;
Servo servo;
Button btn(2); // 사용할 서보 모터명 선언

const int OPEN = true;
const int CLOSE = false;

bool door_state = CLOSE;
int timer_id = -1;

void close_door()
{
    servo.write(0);
    door_state = CLOSE;
    com.print(1,"CLOSE");
}

void open_door()
{
    SimpleTimer &timer = com.getTimer();

    if(door_state == OPEN)
    {
        timer.restartTimer(timer_id);
    }
    else{
        servo.write(90);
        timer_id = timer.setTimeout(3000, close_door);
    }
    door_state = OPEN;
    com.print(1,"OPEN");
}


void setup()
{
    com.init();
    servo.attach(5);
    com.print(0,"[[MiniCom]]");
    btn.setCallback(open_door);
    close_door();
}


void loop()
{
   btn.check();
   com.run();
}
