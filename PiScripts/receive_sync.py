#!/bin/env python

import serial

serial_port = serial.Serial('/dev/ttyACM0', 9600)
f = open("image.jpg", "wb")
read = False
i = 1
while True:
    try:
        serial_port.reset_input_buffer()
        while serial_port.inWaiting() >= 1:
          read = True
          print "Reading %d" % i
          c = serial_port.read()
          f.write(c)
          i += 1
        
        #if read:
          #break
    except KeyboardInterrupt:
        break

f.close()
serial_port.close()
