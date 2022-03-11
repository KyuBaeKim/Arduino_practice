import requests
url = 'http://localhost:8000/api/greet/?name=hong&age=30'

res = requests.get(url)
print(res.json())