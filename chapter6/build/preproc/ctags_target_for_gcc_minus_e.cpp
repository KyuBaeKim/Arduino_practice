# 1 "/Users/qbae/Workspace/Arduino/chapter6/dcmotor/ex01/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter6/dcmotor/ex01/app.ino" 2

// //오른쪽 모터
// int ENAPin = 3; // enable 핀 설정
// int in1Pin = 5; // in1 핀 설정
// int in2Pin = 4; // in2 핀 설정

// //왼쪽 모터
// int ENBPin = 9; // enable 핀 설정
// int in3Pin = 8;
// int in4Pin = 7;
Car car(3, 5, 4, 9, 8, 7);

void setup()
{
    car.stop();
}

void loop()
{
    car.forward();
    delay(1000);

    car.backward();
    delay(1000);

    car.turn_left();
    delay(1000);

    car.turn_right();
    delay(1000);

    car.stop();
    delay(5000);
}
