//온습도 측정 센서
#include <MiniCom.h>
#include <DHT.h>

MiniCom com;
DHT dht11(12, DHT11); // DHT11 객체 생성
void check()
{
    float fh, fc, ff;

    // DHT 온습도 센서 읽기
    fh = dht11.readHumidity();        //습도
    fc = dht11.readTemperature();     //섭씨 default : false
    ff = dht11.readTemperature(true); //화씨 true

    if (isnan(fh) || isnan(fc)||isnan(ff)){
        com.print(1, "Failed!!");
        return;
    }
    com.print(1, "T:", fc, " H:", fh);
}

void setup()
{
    com.init();
    com.setInterval(2000, check); // 2초 간격으로
    dht11.begin();
    com.print(0, "[[DHT11]]");
    com.print(1, "Preparing DHT11");
}
void loop()
{
    com.run();
}