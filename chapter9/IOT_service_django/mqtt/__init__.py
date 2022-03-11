import paho.mqtt.client as mqtt



# 브로커 접속 시도 결과 처리 콜백 함수
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+ str(rc))
    if rc==0:
        client.subscribe("iot/#") #연결 성공시 토픽 구독 신청
    else:
        print('연결 실패 : ', rc)
        

# 관련 초픽 메시지 수신 콜백 함수
def on_message(client, userdata, msg):
    from .models import Sensors
    value = float(msg.payload.decode())
    (_, user, place, sensor) = msg.topic.split('/')
   # 모델을 사용해서 저장
    s = Sensors(user=user, place=place, sensor=sensor, value=value)
    s.save()
    

client = mqtt.Client()

client.on_connect = on_connect
client.on_message = on_message

try:
    client.connect("localhost")
    client.loop_start() # 새로운 스레드 실행 --> demon 스레드 -> main 스레드 종료시에 강제 종료됨.
except Exception as err:
    print(f'에러 : {err}')
 


                
                
