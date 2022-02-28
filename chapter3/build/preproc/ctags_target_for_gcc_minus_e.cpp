# 1 "/Users/qbae/Workspace/Arduino/chapter3/ex02/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter3/ex02/app.ino" 2

const int in_pu_sw_pin = 2;
Led led(8);

void setup()
{
    pinMode(in_pu_sw_pin, 0x2); // INPUT_PULLUP INPUT 외부저항
}

void loop()
{
    boolean in_pu_sw;
    in_pu_sw = !digitalRead(in_pu_sw_pin);
    led.setValue(in_pu_sw);
}
