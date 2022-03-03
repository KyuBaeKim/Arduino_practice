# 1 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex05/app.ino"
// 1초에 10번 가변 저항을 읽어서
// 가변 저항의 값을 lcd로 출력하시오.

# 5 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex05/app.ino" 2
# 6 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex05/app.ino" 2
# 7 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex05/app.ino" 2

LiquidCrystal_I2C lcd(0x27, 16, 2);
SimpleTimer timer;
Analog sensor(A0, 1023, 0);

void check()
{ // 저항값 읽어서. lcd로 출력
    int value = sensor.read();
    Serial.println(value);
    // lcd 출력
    // lcd.clear();

    lcd.setCursor(0, 1); // 두 번쨰 줄 출력

    //문자열 포맷팅
    char str[17]; // 1줄에 16글자로 가정하면, NULL문자 포함 --> 17크기
    sprintf(str, "value: %-4d", value);
    lcd.print(str);
}

void setup()
{
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    timer.setInterval(100, check); // 100ms 간격
    lcd.setCursor(0, 0);
    lcd.print("[reg. value]");
}

void loop()
{
    timer.run();
}
