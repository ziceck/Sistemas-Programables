#include <Servo.h>
#include <AFMotor.h>

#define MAX_SPEED 180
#define MAX_SPEED_OFFSET 40

AF_DCMotor motor1(1, MOTOR34_1KHZ);
AF_DCMotor motor2(2, MOTOR34_1KHZ);
Servo myServo;

String motorSet = "";
int speedSet = 0;

void setup() {
  myServo.attach(9);
  myServo.write(90);

  Serial.begin(9600);

  delay(1000);
}

void loop() {
  byte byteRead;

  if (Serial.available()) {
    byteRead = Serial.read();

    if (byteRead == 97) {
      turnLeft();
    }
    if (byteRead == 100) {
      turnRight();
    }
    if (byteRead == 119) {
      moveForward();
    }
    if (byteRead == 115) {
      moveBackWard();
    }
    if (byteRead == 120) {
      moveStop();
    }

    Serial.write(byteRead);
    byteRead = 0;
  }
  delay(500);  
}

void moveForward() {
  motorSet = "FORWARD";
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    motor1.setSpeed(speedSet + MAX_SPEED_OFFSET);
    motor2.setSpeed(speedSet + MAX_SPEED_OFFSET);
    delay(5);
  }
}

void moveBackWard() {
  motorSet = "BACKWARD";
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    motor1.setSpeed(speedSet + MAX_SPEED_OFFSET);
    motor2.setSpeed(speedSet + MAX_SPEED_OFFSET);
    delay(5);
  }
}

void turnRight() {
  motorSet = "RIGHT";
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void turnLeft() {
  motorSet = "LEFT";
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
