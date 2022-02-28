// 4개의 순차점멸 (LED 풀다운)
const int led1_pin = 3;
const int led2_pin = 4;
const int led3_pin = 5;
const int led4_pin = 6;
void setup()
{
    pinMode(led1_pin, OUTPUT);
    pinMode(led2_pin, OUTPUT);
    pinMode(led3_pin, OUTPUT);
    pinMode(led4_pin, OUTPUT);
}

void loop()
{
    // LED1만 ON
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, LOW);
    delay(1000);

    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, HIGH);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, LOW);
    delay(1000);

    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, HIGH);
    digitalWrite(led4_pin, LOW);
    delay(1000);

    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, HIGH);
    delay(1000);
}