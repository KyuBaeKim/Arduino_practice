#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init(); // 초기화
    lcd.backlight();

    lcd.setCursor(0, 0); // 커서 (0,0)
    lcd.print("oh!wow!lol!oh!wow!lol!oh!wow!lol!oh!wow!lol!");

    lcd.setCursor(0, 1);
    lcd.print("oh!wow!lol!oh!wow!lol!oh!wow!lol!oh!wow!lol!");
}

void loop()
{
    int n;
    for (n = 0; n < 80; n++)
    {
        lcd.scrollDisplayLeft();
        delay(500);
    }
    delay(4000);

    for (n = 0; n < 80; n++)
    {
        lcd.scrollDisplayRight();
        delay(500);
    }
    delay(4000);
}