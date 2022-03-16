# 1 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 4 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 5 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 6 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 7 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 8 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 9 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2
# 10 "/Users/qbae/Workspace/Arduino/test/RFID/app.ino" 2




SimpleTimer timer;
Button btn(2);
MFRC522 mfrc(10, 9);
Buzzer buzzer(3);
Led led_G(4); // 초록색 LED
Led led_R(5); // 빨강색 LED
Servo door;
MiniCom com;

byte myId[] = {0, 0, 0, 0};
int EEPROM_Number;
byte pass_code[] = {0, 0, 0, 0};
boolean state = false;
boolean state_b = false;
boolean led_st = false;

void state_false()
{
    state_b = false;
}

void push_button()
{
    state_b = true;
    com.print(1, "touch card");
    timer.setTimeout(5000, state_false);
}

void inId(byte *id1, byte *id2)
{
    for (byte i = 0; i < 4; i++)
    {
        id1[i] = id2[i];
    }
}

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

// close door
void close_door()
{
    door.write(0);
    com.print(1, "Close door");
}

// open door
void open_door(byte *key_code, byte *card_code)
{
    if ((key_code[0] == card_code[0]) && (key_code[1] == card_code[1]) && (key_code[2] == card_code[2]) && (key_code[3] == card_code[3]))
    {
        door.write(90);
        com.print(1, "Open door");
        timer.setTimeout(5000, close_door);
    }
}

void setup()
{
    com.init();
    com.print(0, "[[STATE]]");

    Serial.begin(115200);
    SPI.begin();
    mfrc.PCD_Init();
    btn.setCallback(push_button);
    door.attach(6);
    door.write(0);
}

void loop()
{
    com.run();
    btn.check();
    timer.run();
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
    {

        return;
    }

    inId(myId, mfrc.uid.uidByte);
    push_button();
    if (state_b == true)
    {
        for (int i = 0; i < 4; i++)
        {
            EEPROM.write(i, myId[i]);
        }

        for (int i = 0; i < 4; i++)
        {
            EEPROM_Number = EEPROM.read(i);
            Serial.print(" ");
            pass_code[i] = EEPROM_Number;
            Serial.print(pass_code[i]);
        }
    }

    open_door(pass_code, mfrc.uid.uidByte);
    state = equalId(pass_code, mfrc.uid.uidByte);
    if (state == true)
    {
        led_G.on();
        buzzer.beep(100);
        delay(1000);
        led_G.off();
        state = false;
    }
    else
    {
        led_R.on();
        buzzer.beep(1000);
        led_R.off();
        com.print(1, "card is not equal");
    }
}
