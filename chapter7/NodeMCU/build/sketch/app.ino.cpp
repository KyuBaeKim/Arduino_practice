#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex05/app.ino"
#include <MqttCom.h>
#include <Led.h>
const char *ssid = "KT_GiGA_2G_Wave2_F1D7";
const char *password = "2dfdhgb234";
const char *mqtt_server = "172.30.1.50"; // mqtt broker ip address
MqttCom com;
Led led(BUILTIN_LED);
int value = 0;
#line 9 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex05/app.ino"
void callback(char *topic, byte *payload, unsigned int length);
#line 9 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex05/app.ino"
void callback(char *topic, byte *payload, unsigned int length)
{
    char buf[128];
    memcpy(buf, payload, length);
    buf[length] = '\0';
    com.print(0, topic);
    com.print(1, buf);
    if (buf[0] == '1')
    {
        led.setValue(LOW);
    }
    else
    {
        led.setValue(HIGH);
    }
}
