# 1 "/Users/qbae/Workspace/Arduino/chapter3/analog/ex03/Analog.cpp"
# 2 "/Users/qbae/Workspace/Arduino/chapter3/analog/ex03/Analog.cpp" 2

Analog::Analog(int pin, int to_min, int to_max) : pin(pin), from_min(0), from_max(0), to_min(to_min), to_max(to_max)
{
}
void Analog::setRange(int to_min, int to_max)
{
    this->to_min = to_min;
    this->to_max = to_max;
}

int Analog::read()
{
    int value = analogRead(pin);
    return map(value, from_min, from_max, to_min, to_max);
}
# 1 "/Users/qbae/Workspace/Arduino/chapter3/analog/ex03/app.ino"

# 3 "/Users/qbae/Workspace/Arduino/chapter3/analog/ex03/app.ino" 2

Analog sensor(A0, 255, 0);
PWMLed led(9);
void setup()
{
}
void loop()
{
    int pwm_val = sensor.read();
    led.setValue(pwm_val);
}
