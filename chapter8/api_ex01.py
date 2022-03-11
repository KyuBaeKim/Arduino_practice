import requests
url = "https://www.naver.com"
response = requests.get(url)
print("status code :", response.status_code)
print(response.text)