#coding=utf-8
import serial
import time
import os
import re

def GetTime():
    #print time.localtime()
    _time  = str(time.localtime().tm_year) + '-' + str(time.localtime().tm_mon)\
             +  '-' + str(time.localtime().tm_mday) \
             + ' ' + str(time.localtime().tm_hour) + ':'\
             + str(time.localtime().tm_min) + ':' + str(time.localtime().tm_sec)
    return _time


#main
config_file = open('pConfig', 'r')

#read config
'''
comPort
user file
time file
run.bat
sql word
'''
while True:
    username = raw_input('input username:')
    password = raw_input('input password:')
    if username == "admin" and password == "123456":
        break

print 'Login successful!'
line = config_file.readline().strip('\n')
config_list = []
while line:
    config_list.append(line)
    #print line
    line = config_file.readline().strip('\n')


comPort = config_list[0]
run_bat = config_list[1]
table = config_list[2]
column = config_list[3]


ser = serial.Serial(config_list[0], 9600, timeout = 10)
print 'Port [' +  ser.port + '] monitor is running...'


while True:
    data = ser.readline().strip('\n')
    if(data != '' and data != '\n'):
        print GetTime() + ' ' + data
        file = open(run_bat, 'w')
        word = 'java -jar mysqlServer.jar ' + table + ' ' + column + ' ' + data
        file.write(word)
        file.close()
        os.system(run_bat)
    data = ''
