// 4개의 순차점멸(LED 풀업 연결) 배열 이동
const int led_pin[4] = {3, 4, 5, 6}; // LED 연결 핀번호

const int led_out[4][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
    };
int out_no = 0;

void setup()
{
    int n;

    for(n = 0; n < 4; n++){
        pinMode(led_pin[n], OUTPUT);
        digitalWrite(led_pin[n], LOW);
    }
}

void loop()
{

    int n;

    for(n=0; n<4; n++){
        digitalWrite(led_pin[n], led_out[out_no][n]);

    }

    out_no++;
    if(out_no ==4)
    out_no = 0;

    delay(1000);
}