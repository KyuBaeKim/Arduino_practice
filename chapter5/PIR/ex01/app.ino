#include <MiniCom.h>
#include <Led.h>

Led led(8);
MiniCom com;
int pir_pin = 7;
int pirState = LOW;
int val = 0;
void check()
{
}

void setup()
{
    com.init();
    com.print(0, "[[Motion]]");
    pinMode(pir_pin, INPUT);
}
void loop()
{
    com.run();
    val = digitalRead(pir_pin);
    if(val == HIGH){
        if(pirState == LOW){ // 상승 엣지에 감지
            com.print(1, "Motion detected!");
            pirState = HIGH;
        }
    }
    else {
        if(pirState == HIGH){ // 하강 엣지에 감지
            com.print(1, "Motion ended!");
            pirState = LOW;
        }
    }
    led.setValue(val);
}