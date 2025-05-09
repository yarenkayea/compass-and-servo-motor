#include <Wire.h>
#include <MechaQMC5883.h>
#include <Servo.h>
#include "compass.h"
#include "servo.h"


Servo myservo;  
float currentAngle = 0;  


void moveServo(float targetAngle) {
  if (abs(targetAngle - currentAngle) > 1.0) {
    currentAngle = targetAngle;
    myservo.write(currentAngle);  
  }
}
