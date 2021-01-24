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
Servo 0:          90    520
Servo 1:          180   400
Servo 2:          80    220
Servo 3:          400   130
Servo 4:         0   280  


Servo Home Positions
-------------------------------
Servo 0:          300
Servo 1:          250
Servo 2:          180
Servo 3:          280
Servo 4:          280

*/


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Global Variables
int globalDelay = 5000;

// Servo Home Positions
int s0_PosHome = 300;
int s1_PosHome = 250;
int s2_PosHome = 180;
int s3_PosHome = 280;
int s4_PosHome = 280;

// Servo Current Positions
// It is important to track these as best as possible
int posCurrent[5];

// Servo Controller - Connects to "Adafruit PCA9685 16-Channel Servo Driver"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

void setup() {
  Serial.begin(9600);

  pwm.begin();
 
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates

  yield();

  // Sends the Robot home upon startup
  Home();
  Serial.println("Home");
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

// Sends the Robot to Home SLOWLY
void controlledHome() {
  // Send Servo 1
  servoIncrement(1, 4, posCurrent[1], s1_PosHome);
  // Sends Servo 2
  servoIncrement(2, 4, posCurrent[2], s2_PosHome);
  // Send Servo 3
  servoIncrement(3, 4, posCurrent[3], s3_PosHome);
  // Send Servo 4
  //servoIncrement(4, 4, posCurrent[4], s4_PosHome);
  // Send Servo 0
  servoIncrement(0, 4, posCurrent[0], s0_PosHome);
}

// Sends the Robot to Position 1
void Position_1() {
  // Send Servo 1
  servoIncrement(1, 4, posCurrent[1], s1_PosHome);
  // Sends Servo 2
  servoIncrement(2, 4, posCurrent[2], s2_PosHome);
  // Send Servo 3
  servoIncrement(3, 4, posCurrent[3], s3_PosHome);
  // Send Servo 4
  //servoIncrement(4, 4, posCurrent[4], s4_PosHome);
  // Send Servo 0
  servoIncrement(0, 4, posCurrent[0], 100);
}

// Sends the Robot to Position 2
void Position_2() {
  // Sends Servo 2
  servoIncrement(2, 5, posCurrent[2], 100);
  // Send Servo 1
  servoIncrement(1, 5, posCurrent[1], 375);
  // Send Servo 3
  servoIncrement(3, 4, posCurrent[3], s3_PosHome);
  // Send Servo 4
  servoIncrement(4, 4, posCurrent[4], s4_PosHome);
  // Send Servo 0
  servoIncrement(0, 4, posCurrent[0], 100);
}

// Sends the Robot to Position 3
void Position_3() {
  // Sends Servo 2
  servoIncrement(2, 5, posCurrent[2], 150);
  // Send Servo 1
  servoIncrement(1, 4, posCurrent[1], 375);
  // Send Servo 3
  servoIncrement(3, 4, posCurrent[3], s3_PosHome);
  // Send Servo 4
  servoIncrement(4, 4, posCurrent[4], 480);
  // Send Servo 0
  servoIncrement(0, 4, posCurrent[0], 100);
}

// Sends the Robot to Position 4
void Position_4() {
  // Sends Servo 2
  servoIncrement(2, 5, posCurrent[2], 100);
  // Send Servo 1
  servoIncrement(1, 5, posCurrent[1], 375);
  // Send Servo 3
  servoIncrement(3, 4, posCurrent[3], s3_PosHome);
  // Send Servo 4
  servoIncrement(4, 4, posCurrent[4], 480);
  // Send Servo 0
  servoIncrement(0, 4, posCurrent[0], 100);
}

// Sends the Robot to Position 5
void Position_5() {
  // Sends Servo 2
  servoIncrement(2, 5, posCurrent[2], 100);
  // Send Servo 1
  servoIncrement(1, 5, posCurrent[1], 375);
  // Send Servo 3
  servoIncrement(3, 4, posCurrent[3], s3_PosHome);
  // Send Servo 4
  servoIncrement(4, 4, posCurrent[4], 480);
  // Send Servo 0
  servoIncrement(0, 4, posCurrent[0], s0_PosHome);
}

// Sends the Robot to Position 6
void Position_6() {
  // Sends Servo 2
  servoIncrement(2, 5, posCurrent[2], 80);
  // Send Servo 1
  servoIncrement(1, 5, posCurrent[1], 375);
  // Send Servo 3
  servoIncrement(3, 4, posCurrent[3], s3_PosHome);
  // Send Servo 4
  servoIncrement(4, 4, posCurrent[4], 280);
  // Send Servo 0
  servoIncrement(0, 4, posCurrent[0], s0_PosHome);
}

void Auto_Cycle() {
  Position_1();
  Position_2();
  Position_3();
  Position_4();
  Position_1();
  controlledHome();
  Position_5();
  Position_6();
  controlledHome();
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
  if(Serial.available()) {
    // Read Data from Pi
    String command = Serial.readString();

    if(command == "0") {
      controlledHome();
      Serial.println("Home");
    }
    else if(command == "1") {
      Position_1();
      Serial.println("Pos1");
    }
    else if(command == "2") {
      Position_2();
      Serial.println("Pos2");
    }
    else if(command == "3") {
      Position_3();
      Serial.println("Pos3");
    }
    else if(command == "4") {
      Position_4();
      Serial.println("Pos4");
    }
    else if(command == "5") {
      Position_5();
      Serial.println("Pos5");
    }
    else if(command == "6") {
      Position_6();
      Serial.println("Pos6");
    }
    else if(command == "100") {
      Auto_Cycle();
      Serial.println("Home");
    }
  }
}
