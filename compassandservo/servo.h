#ifndef SERVO_H
#define SERVO_H

#include <Servo.h>


extern Servo myservo; 

extern float currentAngle; 


void moveServo(float targetAngle);

#endif
