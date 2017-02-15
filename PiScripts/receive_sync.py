#!/bin/env python

import serial

serial_port = serial.Serial('/dev/ttyUSB1', 9600)

while True:
    try:
        print serial_port.readline()
    except KeyboardInterrupt:
        break

serial_port.close()
