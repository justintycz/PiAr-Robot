from flask import Flask, render_template, Response, request, redirect, url_for
from flask import render_template, request

app = Flask(__name__)

import serial
import time
import sys

ser = serial.Serial('/dev/ttyACM0', 9600)
ser.flush()

@app.route('/')	
def _main():
	return render_template('python.html')

@app.route('/robot/')	
@app.route('/robot/pos/', methods=(['GET', 'POST']))
def _gui():
	
	if request.method == 'POST':
		request.form['submit']
		
		val = ser.readline()
		val = val.decode()
		val = val.strip() 
		
		if request.form['submit'] == 'Home':
			ser.write(b'0')
		elif request.form['submit'] == 'Pos1':
			ser.write(b'1')
		elif request.form['submit'] == 'Pos2':
			ser.write(b'2')
		elif request.form['submit'] == 'Pos3':
			ser.write(b'3')
		elif request.form['submit'] == 'Pos4':
			ser.write(b'4')
		elif request.form['submit'] == 'Pos5':
			ser.write(b'5')
		elif request.form['submit'] == 'Pos6':
			ser.write(b'6')
		elif request.form['submit'] == 'Auto':
			ser.write(b'100')
			
	return render_template('robot.html')
	
	time.sleep(1)
	
if __name__ == '__main__':
	app.run()
