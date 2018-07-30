#!/usr/bin/python
import serial
import syslog
import time

#The following line is for serial over GPIO
port = '/dev/ttyACM1'  # change this depending on port


ser = serial.Serial(port,9600,timeout=5)
time.sleep(2) # wait for Arduino

i = 0

while (i < 100):
    # Serial write section

    setTempCar1 = 63
    ser.flush()
    setTemp1 = str(setTempCar1)
    print ("Python value sent: ")
    print (setTemp1)
    ser.write(setTemp1)
    #time.sleep(0.01) # I shortened this to match the new value in my Arduino code
    time.sleep(0.1)
    # Serial read section
    print('waity boys',ser.inWaiting())
    msg = ser.read(ser.inWaiting()) # read all characters in buffer
    print ("Message from arduino: ")
    print (msg)
    i = i + 1
else:
    print ("Exiting")
exit()

################ TO DOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO ######################## : MODIFY VALUES TO DECREASE TEST TIME...
## THEN ADD IMU AND SEE HOW FAST YOU TRANSMIT DATA