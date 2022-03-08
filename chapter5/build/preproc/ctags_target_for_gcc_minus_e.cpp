# 1 "/Users/qbae/Workspace/Arduino/chapter5/RFID/ex01/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter5/RFID/ex01/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/chapter5/RFID/ex01/app.ino" 2
# 4 "/Users/qbae/Workspace/Arduino/chapter5/RFID/ex01/app.ino" 2




MFRC522 mfrc(10, 9);
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
