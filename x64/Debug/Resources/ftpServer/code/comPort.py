import serial
import time
import os

def GetTime():
    #print time.localtime()
    _time  = str(time.localtime().tm_year) + '-' + str(time.localtime().tm_mon)\
             +  '-' + str(time.localtime().tm_mday) \
             + ' ' + str(time.localtime().tm_hour) + ':'\
             + str(time.localtime().tm_min) + ':' + str(time.localtime().tm_sec)
    return _time

ser = serial.Serial("com3", 9600, timeout = 10)

print 'Port [' +  ser.port + '] monitor is running...'


while True:
    data = ser.readline().strip('\n')

    if(data != ''):
        file = open('data/user.txt', 'a')
        file.write(data)
        file.close()

        file = open('data/run.bat', 'w')
        file.write('java -jar ftp.jar ' + data)
        file.close()

        file = open('data/time.txt', 'a')
        _data = GetTime() + ' ' + data
        file.write(_data)
        file.close()

        os.system('cd data & run.bat')
        print _data

    data = ''
