import paho.mqtt.client as mqtt
import sqlite3

con = sqlite3.connect('iot.db')
cursor = con.cursor()

# 브로커 접속 시도 결과 처리 콜백 함수
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+ str(rc))
    if rc==0:
        client.subscribe("iot/#") #연결 성공시 토픽 구독 신청
    else:
        print('연결 실패 : ', rc)
        

# 관련 초픽 메시지 수신 콜백 함수
def on_message(client, userdata, msg):
    value = float(msg.payload.decode())
    (_, user, place, sensor) = msg.topic.split('/')
    sql = f'''INSERT INTO sensors(user, place, sensor, value)
                values('{user}', '{place}', '{sensor}', {value})'''
    cursor.execute(sql)
    con.commit()
    
# 1. MQTT 클라이언트 객체 인스턴스화
client = mqtt.Client()

# 2. 관련 이벤트에 대한 콜백 함수 등록
client.on_connect = on_connect
client.on_message = on_message

try:
    # 3. 브로커 연결
    client.connect("localhost")
    
    # 4. 메시지 루프 - 이벤트 발생시 해당 콜백 함수 호출됨
    client.loop_forever() # 새로운 스레드 실행 --> demon 스레드 -> main 스레드 종료시에 강제 종료됨.
except Exception as err:
    print(f'에러 : {err}')
 


                
                
