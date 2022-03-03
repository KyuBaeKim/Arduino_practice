#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex02/app.ino"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#line 5 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex02/app.ino"
void setup();
#line 15 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex02/app.ino"
void loop();
#line 5 "/Users/qbae/Workspace/Arduino/chapter4/lcd/ex02/app.ino"
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
