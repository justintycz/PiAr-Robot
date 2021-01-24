/*
Programming Information

Servo Part Numbers
------------------------------
Servo 0: MG996R
Servo 1: DS3218R
Servo 2: MG996R
Servo 3: MG996R
Servo 4: MG996R


Servo Limits      +     -
-------------------------------
Servo 0:          90    450
Servo 1:          180   360
Servo 2:          70    180
Servo 3:          370   130
Servo 4:          380   280  


Servo Home Positions
-------------------------------
Servo 0:          270
Servo 1:          250
Servo 2:          140
Servo 3:          250
Servo 4:          280

*/


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Global Variables
int globalDelay = 5000;

// Servo Home Positions
int s0_PosHome = 270;
int s1_PosHome = 250;
int s2_PosHome = 140;
int s3_PosHome = 250;
int s4_PosHome = 280;

// Servo Current Positions
// It is important to track these as best as possible
int posCurrent[5];

// Servo Controller - Connects to "Adafruit PCA9685 16-Channel Servo Driver"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates

  yield();

  // Sends the Robot home upon startup
  Home();
}

// Sends the Robot Home
void Home() {
  delay(500);
  // Send Servo 1 Home
  pwm.setPWM(1, 0, s1_PosHome);
  delay(500);
  posCurrent[1] = s1_PosHome;
  // Sends Servo 2 Home
  pwm.setPWM(2, 0, s2_PosHome);
  delay(500);
  posCurrent[2] = s2_PosHome;
  // Send Servo 3 Home
  pwm.setPWM(3, 0, s3_PosHome);
  delay(500);
  posCurrent[3] = s3_PosHome;
  // Send Servo 4 Home
  pwm.setPWM(4, 0, s4_PosHome);
  delay(500);
  posCurrent[4] = s4_PosHome;
  // Send Servo 0 Home
  pwm.setPWM(0, 0, s0_PosHome);
  delay(500);
  posCurrent[0] = s0_PosHome;
}

// Sends Robot to a position incrementally, this will allow you to control the speed
void servoIncrement(int servoNum, int delayTime, int currentPos, int targetPos) {
  int cur = currentPos;
  int pos = targetPos;
  int del = delayTime;

  if(cur < pos) {
    for(int i=cur; i <= pos; i++) {
    pwm.setPWM(servoNum, 0, i);
    delay(delayTime);
    posCurrent[servoNum] = i;
  }
  }
  else if(cur > pos) {
    for(int i=cur; i >= pos; i--) {
    pwm.setPWM(servoNum, 0, i);
    delay(delayTime);
    posCurrent[servoNum] = i;
  }
  }
}

// Display Servo Current Positions
void displayPositions() {
  Serial.println();
  Serial.print("Servo 0 Current Position: ");
  Serial.println(posCurrent[0]);

  Serial.print("Servo 1 Current Position: ");
  Serial.println(posCurrent[1]);

  Serial.print("Servo 2 Current Position: ");
  Serial.println(posCurrent[2]);

  Serial.print("Servo 3 Current Position: ");
  Serial.println(posCurrent[3]);

  Serial.print("Servo 4 Current Position: ");
  Serial.println(posCurrent[4]);
  Serial.println();
}

// Main Programming Loop
void loop() {
  Home();
  delay(1000);
}
