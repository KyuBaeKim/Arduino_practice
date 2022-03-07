#include <MiniCom.h>
#include <Ultra.h>
#include <Buzzer.h>

MiniCom com;
Ultra ultra(5, 6);
Buzzer buzzer(7);

void check()
{
    int distance = ultra.getDistance();
    com.print(1, "Dist.(cm)", distance);

    if (distance < 50 && distance >= 30)
    {
        buzzer.setOffTime(1000);
    }
    else if (distance < 30 && distance >= 20)
    {
        buzzer.setOffTime(500);
    }
    else if (distance < 20 && distance >= 10)
    {
        buzzer.setOffTime(200);
    }
    else if (distance < 10)
    {
        buzzer.setOffTime(100);
    }
    else
    {
        buzzer.stop();
    }
}

void setup()
{
    com.init();
    com.setInterval(100, check); // 0.1초 간격으로
    com.print(0, "[[Distance]]");
    buzzer.stop();
}
void loop()
{
    com.run();
    buzzer.run();
}