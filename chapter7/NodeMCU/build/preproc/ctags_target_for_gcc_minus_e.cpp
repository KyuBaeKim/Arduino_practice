# 1 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex03/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex03/app.ino" 2
const char *ssid = "KT_GiGA_2G_Wave2_F1D7";
const char *password = "2dfdhgb234";
WifiMiniCom com;
WiFiServer server(80); //80: Web Server 표준 포트
void setup() { com.init(ssid, password); server.begin();
}
void loop()
{
    WiFiClient client = server.available();
    if (!client)
    {
        return;
    }
    // Wait until the client sends some data
    Serial.println("new client");
    while (!client.available())
    {
        delay(1);
    }
    // Read the first line of the request
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println(""); // do not forget this one
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.print("HELLO WORLD!");
    client.println("</html>");
    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}
