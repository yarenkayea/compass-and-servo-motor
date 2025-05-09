#include <Wire.h>
#include <MechaQMC5883.h>
#include <Servo.h>
#include "compass.h"
#include "servo.h"

void setup() {
  Serial.begin(9600);
  Wire.begin();
  qmc.init();  
  myservo.attach(9);  
}

void loop() {
  float heading = getHeading();  
  float targetAngle = map(heading, 0, 1023, 0, 180);  
  moveServo(targetAngle);  

  
  String direction = getDirectionText(heading);
  Serial.print("Pusula Açısı: ");
  Serial.print(heading, 1);
  Serial.print("° | Yön: ");
  Serial.println(direction);

  delay(200);  
}
