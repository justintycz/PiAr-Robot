import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
ser.flush()

val = "OFF"

while True:
	val = ser.readline() # Read Serial
	val = val.decode() # Decode to a string
	val = val.strip() # Strip whitespace off back
	
	try:
		# Check Value to determine what to do
		if val == "ON":
			print "Servo ON"
			ser.write(b'0')
		elif val == "OFF":
			print "Servo OFF"
			ser.write(b'1')
	except:
		print "Could not read"
		
	time.sleep(1)