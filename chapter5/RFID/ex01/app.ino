#include <SPI.h>
#include <MFRC522.h>
#include <Buzzer.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);
Buzzer buzzer(3);

byte myId[] = {162, 54, 10, 26};

bool equalId(byte *id1, byte *id2)
{
    for (byte i = 0; i < 4; i++)
    {
        if (id1[i] != id2[i])
        {
            return false;
        }
    }
    return true;
}
void setup()
{
    Serial.begin(115200);
    SPI.begin();
    mfrc.PCD_Init();
}
void loop()
{
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
    {

        delay(500);
        return;
    }
    if (equalId(myId, mfrc.uid.uidByte))
    {
        Serial.println("Equal");
        buzzer.beep(100);
    }
    else
    {
        Serial.println("Not Equal");
        buzzer.beep(2000);
    }
    Serial.print("Card UID:");
    buzzer.run();
    buzzer.beep();
    for (byte i = 0; i < 4; i++)
    {
        Serial.print(mfrc.uid.uidByte[i]);
        Serial.print(" ");
    }
    Serial.println();
}