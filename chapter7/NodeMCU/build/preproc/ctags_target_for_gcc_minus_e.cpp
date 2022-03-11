# 1 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino"
# 2 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino" 2
# 3 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino" 2
# 4 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino" 2

const char *ssid = "KT_GiGA_2G_Wave2_F1D7";
const char *password = "2dfdhgb234";
const char *mqtt_server = "172.30.1.32"; // mqtt broker ip address
MqttCom com;
DHT dht11(D6, DHT11); // DHT11 객체 생성
Analog cds(A0, 0, 1023, 0, 100);

void publish()
{
    char msg[50];
    float fh, fc;
    fh = dht11.readHumidity(); // 습도 측정
    fc = dht11.readTemperature(); // 섭씨 온도 측정
    int illu = cds.read(); // 조도 측정

    if (isnan(fh) || isnan(fc))
    { // 측정 실패시에는 출력없이 리턴

        Serial.println("DHT11 read failed!!");
        return;
    }
    com.publish("iot/temp", fc);
    com.publish("iot/humi", fh);
    com.publish("iot/illu", illu);
}
void setup()
{
    com.init(ssid, password);
    com.setServer(mqtt_server, 
# 33 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino" 3 4
                              __null
# 33 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino"
                                  , 
# 33 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino" 3 4
                                    __null
# 33 "/Users/qbae/Workspace/Arduino/chapter7/NODEMCU/ex06/app.ino"
                                        );
    com.setInterval(2000, publish);
    dht11.begin();
}
void loop()
{
    com.run();
}
