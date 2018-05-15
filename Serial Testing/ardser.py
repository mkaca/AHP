#!/usr/bin/python
import serial
import syslog
import time

#The following line is for serial over GPIO
port = '/dev/ttyACM2'  # change this depending on port


ser = serial.Serial(port,9600,timeout=5)
time.sleep(2) # wait for Arduino

i = 0

while (i < 8):
    # Serial write section

    setTempCar1 = 63
    setTempCar2 = 37
    ser.flush()
    setTemp1 = str(setTempCar1)
    setTemp2 = str(setTempCar2)
    print ("Python value sent: ")
    print (setTemp1)
    ser.write(setTemp1)
    time.sleep(0.5) # I shortened this to match the new value in your Arduino code

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