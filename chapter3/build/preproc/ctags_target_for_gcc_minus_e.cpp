# 1 "/Users/qbae/Workspace/Arduino/chapter3/analog/ex01/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter3/analog/ex01/app.ino" 2

SimpleTimer timer;

const int var_pin = A0;
int analog_val;

void check()
{
    int digital_val;
    float ff;

    digital_val = analogRead(var_pin); // 아날로그값 디지털 변환
    ff = (float)digital_val / 1023. * 5.0; // 전압값 계산

    Serial.print("Input Voltage(0~5V) = ");
    Serial.println(ff); // 입력 전압값 출력

    Serial.print("Digital Value(0~1023) = ");
    Serial.println(digital_val); // 변환된 디지털 값 출력(0~1023)
    Serial.println("----------------------------------------");
}

void setup()
{
    Serial.begin(115200);
    timer.setInterval(2000, check);
}

void loop()
{

    timer.run();
}
