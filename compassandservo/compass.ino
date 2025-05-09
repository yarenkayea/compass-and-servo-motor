#include <Wire.h>
#include <MechaQMC5883.h>
#include "compass.h"


MechaQMC5883 qmc;


float getHeading() {
  int x, y, z;
  qmc.read(&x, &y, &z);  

  
  float heading = atan2(y, x) * 180 / PI;
  if (heading < 0) heading += 360;
  return heading;
}


String getDirectionText(float heading) {
  if (heading >= 337.5 || heading < 22.5) return "Kuzey";
  if (heading >= 22.5 && heading < 67.5) return "Kuzeydoğu";
  if (heading >= 67.5 && heading < 112.5) return "Doğu";
  if (heading >= 112.5 && heading < 157.5) return "Güneydoğu";
  if (heading >= 157.5 && heading < 202.5) return "Güney";
  if (heading >= 202.5 && heading < 247.5) return "Güneybatı";
  if (heading >= 247.5 && heading < 292.5) return "Batı";
  if (heading >= 292.5 && heading < 337.5) return "Kuzeybatı";
  return "Bilinmiyor";
}
