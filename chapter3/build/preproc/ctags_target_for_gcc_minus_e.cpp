# 1 "/Users/qbae/Workspace/Arduino/chapter3/ex03/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter3/ex03/app.ino" 2




const int sw_pin = 2;
Led led(8);
boolean led_st = 0;
int count = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(sw_pin, 0x2);
    led.setValue(led_st);
}

void loop()
{
    boolean o_sw, n_sw;

    o_sw = !digitalRead(sw_pin);
    delay(1);
    n_sw = !digitalRead(sw_pin);

    if (o_sw == 0 && n_sw == 1)
    {
        count++; // 버튼 누른 횟수 카운트
        Serial.println(count); // 누른 횟수 출력
        led_st = !led_st; // Led 껏다 키기
        led.setValue(led_st);
    }
}
