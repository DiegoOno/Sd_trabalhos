from configs import *
from utils import *

import urllib.request
import json
import datetime
import serial
import time


def urlBuild():
    return URL + '&id=' + str(CITY_ID) + '&units=' + UNITS + '&appid=' + API_KEY


def requestToURL(url):
    request = urllib.request.urlopen(url)
    response = request.read().decode('utf-8')
    request.close()
    return json.loads(response)


def getData():
    print('\nGenerating URL... ')
    url = urlBuild()
    print('URL: ' + url + '\n')

    print('Sending request to URL... \n')
    jsonResponse = requestToURL(url)
    print('Response: ' + json.dumps(jsonResponse) + '\n')

    todayDate = datetime.datetime.today()
    dateToPrint = todayDate.strftime('%d/%m/%y')
    day = str(todayDate.day)
    month = str(todayDate.month)
    year = str(todayDate.year)

    now = datetime.datetime.now().time()
    nowTimeToPrint = now.strftime('%H:%M:%S')
    seconds = str(now.second)
    minutes = str(now.minute)
    hours = str(now.hour)

    print('Date: ' + dateToPrint)
    print('Time: ' + nowTimeToPrint)
    print('Temperature: ' + str(jsonResponse['main']['temp']) + ' C')
    print('Weather: ' + jsonResponse['weather'][0]['description'] + '\n')

    temp = str(jsonResponse['main']['temp'])
    weather = str(jsonResponse['weather'][0]['description'])
    humidity = str(jsonResponse['main']['humidity'])

    data = hours + '|' + minutes + '|' + seconds + '|' + day + '|' + month + \
        '|' + year + '|' + temp + '|' + weather + '|' + humidity

    return data


def main():
    arduinoSerial = serial.Serial('/dev/ttyACM1', baudrate=9600)
    time.sleep(3)
    while True:
        data = getData()
        data = str(data)
        arduinoSerial.write(data.encode())
        print("Next data update will be in 60 minutes.\n")
        time.sleep(3600)


if __name__ == '__main__':
    main()
