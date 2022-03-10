#include <Arduino.h>
#line 1 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex02/app.ino"
#include <WifiMiniCom.h>
const char *ssid = "KT_GiGA_2G_Wave2_F1D7";
const char *password = "2dfdhgb234";
WifiMiniCom com;
#line 5 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex02/app.ino"
void setup();
#line 9 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex02/app.ino"
void loop();
#line 5 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex02/app.ino"
void setup()
{
    com.init(ssid, password);
}
void loop()
{
    com.run();
}
