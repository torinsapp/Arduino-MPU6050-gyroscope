#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
int Xavg, Yavg, Zavg, timer1, newX, newY, newZ, FR=0, FL=0, BR=0, BL=0, pos=0;

void setup() 
{
  Serial.begin(9600);
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }


  delay(100);
    do{
  Vector normAccel = mpu.readNormalizeAccel();
  timer1 = timer1 + 1;
  Xavg = Xavg + normAccel.XAxis;
  Yavg = Yavg + normAccel.YAxis;
  Zavg = Zavg + normAccel.ZAxis;
  delay(10);
  }while(timer1 <=99);
  if(timer1 = 100)
  {
    Xavg = Xavg / 100;
    Yavg = Yavg / 100;
    Zavg = Zavg / 100;
    Serial.println("SYCNED!!");
  }
}
void loop()
{
  Vector normAccel = mpu.readNormalizeAccel();
  newX=Xavg-normAccel.XAxis;
  newY=Yavg-normAccel.YAxis;
  newZ=Xavg-normAccel.ZAxis;
  if(newX >= 6 && FR == 0 && BR == 0)
  {
    Serial.println("Right ");
    Serial.print(newX-6);
    FL = 0;
    FR = 0;
    BL = 0;
    BR = 0;
    pos = 4;
  }
   if(newX <= -6 && FL ==0 && BL == 0)
  {
    Serial.println("Left ");
     Serial.print(newX+6);
    FL = 0;
    FR = 0;
    BL = 0;
    BR = 0;
    pos = 3;
  }
  if(newY >= 6 && FR == 0 && FL == 0)
  {
    Serial.println("Forward "); 
  Serial.print(newY-6);   
    FL = 0;
    FR = 0;
    BL = 0;
    BR = 0;
    pos = 1;
  }  
if(newY <= -6 && BL == 0 && BR ==0)
  {
    Serial.println("Back ");
     Serial.print(newX+6);
    FL = 0;
    FR = 0;
    BL = 0;
    BR = 0;
    pos = 2;
  }
  if(pos = 1)
  {
    
  }
  if(pos = 2)
  {
    
  }
  if(pos = 3)
  {
    
  }
  if(pos = 4)
  {
    
  }
}
