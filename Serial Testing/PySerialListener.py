import time
import serial
# Establish the connection on a specific port
timeCurrentMilli = lambda: int(round(time.time() * 1000))
ser = serial.Serial('/dev/ttyACM2', 9600) # use on ubuntu
#ser = serial.Serial('COM3', 9600)  # use on windows 
print('test1')
counter = 32 # Below 32 everything in ASCII is gibberish
currentTime = timeCurrentMilli()
superStart = timeCurrentMilli()

while currentTime- superStart < 20000:
     counter +=1
     startTime = timeCurrentMilli()
     ser.write('test')
     #ser.write(str(chr(counter))) # Convert the decimal number to ASCII then send it to the Arduino
     #print ('test,', ser.readline()) # Read the newest output from the Arduino
     #time.sleep(.1) # Delay for one tenth of a second
     print(ser.read())
     if counter == 255:
     	counter = 32
     currentTime = timeCurrentMilli()
     print('timeDiff',currentTime-startTime)
     #
ser.close()  #closes serial

#ser.write('110,')