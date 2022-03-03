#include <LiquidCrystal_I2C.h>
// 김
uint8_t name_s[8] = {0x1D,
                     0x05,
                     0x09,
                     0x11,
                     0x0E,
                     0x0A,
                     0x0E,
                     0x00};
uint8_t name_d[8] = {0x1E,
                     0x02,
                     0x02,
                     0x04,
                     0x1F,
                     0x0A,
                     0x0A,
                     0x00};
uint8_t name_u[8] = {0x03,
                     0x17,
                     0x1F,
                     0x17,
                     0x1F,
                     0x03,
                     0x03,
                     0x00};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init(); // 초기화
    lcd.backlight();

    lcd.createChar(0, name_s);
    lcd.createChar(1, name_d);
    lcd.createChar(2, name_u);
}

void loop()
{
    lcd.setCursor(0, 0);          // 커서 2행 1열(0, 1)
    lcd.print("Hello, Arduino!"); // 문자열 표시
    lcd.setCursor(0, 1);          // 커서 2행 1열(0, 1)
    lcd.print("My name is ");     // 문자열 표시
    lcd.write(0);
    lcd.write(1);
    lcd.write(2);
}