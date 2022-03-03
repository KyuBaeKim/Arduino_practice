#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(3, 0);
    lcd.print("Jae hee");
    lcd.setCursor(2, 1);
    lcd.print("wake up!");
}

void loop()
{
}