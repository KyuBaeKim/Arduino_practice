#include <EEPROM.h>

byte myID[] = {162, 54, 10, 26};

void setup()
{
    // myID를 EEPROM에 기록하라.
    for (int i = 0; i < 4; i++)
    {
        EEPROM.write(i, myID[i]);
    }
}

void loop()
{
    // EEPROM 저장된 ID 읽기
    byte saveID[4];
    for (in i = 0; i < 4; i++)
    {

        saveID[i] = EEPROM.read(i);
        Serial.print(saveID[i])
            Serail.print(' ');
    }
    Serial.println();
    delay(5000);
}
