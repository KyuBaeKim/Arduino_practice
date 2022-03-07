//조도센서
#include <MiniCom.h>
#include <Analog.h>
#include <Led.h>

MiniCom com;
Analog cds(A0, 0, 100);
Led led(8);

void check()
{
    int value = cds.read();
    led.setValue(value > 50);
    com.print(1, "Illu: ", value);
}

void setup()
{
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[CDS Test]]");
}
void loop()
{
    com.run();
}