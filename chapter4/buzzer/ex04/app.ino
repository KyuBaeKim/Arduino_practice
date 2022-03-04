#include <MiniCom.h>
#include <Button.h>
#include <Melody.h>
#include <songs/pirates.h>

MiniCom com;
Button btn(2);
int length = sizeof(notes) / sizeof(int);
Melody melody(9, notes, durations, length);

void check()
{
    bool bplay = melody.toggle(true);
    if (bplay)
    {
        com.print(1, "play");
    }
    else
    {
        com.print(1, "pause");
    }
}

void setup()
{
    com.init();
    btn.setCallback(check);
    melody.play();
    com.print(1, "play");
}
void loop()
{
    com.run();
    melody.run();
    btn.check();
}
