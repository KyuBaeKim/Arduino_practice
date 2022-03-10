#include <WifiMiniCom.h>
const char *ssid = "KT_GiGA_2G_Wave2_F1D7";
const char *password = "2dfdhgb234";
WifiMiniCom com;
void setup()
{
    com.init(ssid, password);
}
void loop()
{
    com.run();
}