#include<Wire.h>
const int MPU=0x68; 
int16_t GyY,Tmp;
int motorPin = 3;
int motorPin2 = 5;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode ( motorPin , OUTPUT );
  pinMode ( motorPin2 , OUTPUT ); 
}

void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);    
  GyY=Wire.read()<<8|Wire.read();   
  Serial.print("Gyroscope: ");
  Serial.print(" | Y = "); Serial.print(GyY);

  if (GyY < -2000 )// If "GyY" value is less than -2000 turn off the motor
   {digitalWrite ( motorPin ,0) ; 
    digitalWrite ( motorPin2 ,0);}
  
  if (GyY > -2000) // If "GyY" value is more than -2000 turn on the motor
   {digitalWrite ( motorPin ,1) ; 
    digitalWrite ( motorPin2 ,1);}
}
