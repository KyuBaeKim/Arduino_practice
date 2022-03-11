import requests as req
import json

API_KEY = '376a73fb8c391aa2f729c342e2e962b0'

def get_weather(city='Seoul'):
    URL = f'http://api.openweathermap.org/data/2.5/weather?q={city}&APPID={API_KEY}&lang=kr&units=metric'
    # 섭씨온도 얻는법 &units=metric
    print(URL)
    weather = {}
    res = req.get(URL)
    if res.status_code == 200:
        result = res.json()
        weather['main'] = result['weather'][0]['main']
        weather['description'] = result['weather'][0]['description']
        print(result['weather'][0]['description'])
        icon = result['weather'][0]['icon']
        weather['icon'] = f'http://openweathermap.org/img/w/{icon}.png' 
        weather['etc'] = result['main']
    else:
        print('error', res.status_code)
        
    return weather   

weather = get_weather()
print(json.dumps(weather, indent=4, ensure_ascii=False))