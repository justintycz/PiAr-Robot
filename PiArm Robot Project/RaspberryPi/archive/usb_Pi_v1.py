import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
ser.flush()

val = "OFF"

while True:

	try:
		val = ser.readline()
		val = val.decode()
		val = val.strip()
		print val
		if val == "Home":
		print "Servo Home"
		ser.write(b'1')
		elif val == "Pos1":
		print "Servo Position 1"
		ser.write(b'0')
	except:
		print "Could not read"

	time.sleep(1) 
