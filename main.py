import serial
import time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0.3)

ser.write('99')
time.sleep(0.1)
while 1:
 if ser.read() != 'o':
  print 'no'
 else:
  print 'ok'
  break

ser.write('66')
time.sleep(0.1)
while 1:
 if ser.read() != 'o':
  print 'no'
 else:
  print 'ok'
  break

ser.write('99')
time.sleep(0.1)
while 1:
 if ser.read() != 'o':
  print 'no'
 else:
  print 'ok'
  break





