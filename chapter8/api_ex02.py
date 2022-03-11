from requests import get

def download(url, file_name):
    with open(file_name, "wb") as file :
        response = get(url) # get request
        file.write(response.content) #write to file
        
if __name__ == '__main__':
    url = "https://www.instagram.com/static/images/homepage/screenshots/screenshot4-2x.png/8e9224a71939.png"
    download(url,"arduino.png")