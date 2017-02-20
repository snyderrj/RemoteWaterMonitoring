#!/bin/env python

import serial

serial_port = serial.Serial('/dev/ttyUSB0', 9600, serial.EIGHTBITS, serial.PARITY_NONE,  serial.STOPBITS_ONE)

f = open("image.jpg", "wb")
read = False
i = 1
while True:
    try:
        serial_port.reset_input_buffer()
        while serial_port.inWaiting() >= 1:
          print "Reading %d" % i
          c = serial_port.read(8)
          f.write(c)
          
          if(c[-1]=='0xd9' and c[-2] == '0xff'):
            read = True
          i += 1
        
        #if read:
          #break
    except KeyboardInterrupt:
        break

f.close()
serial_port.close()
