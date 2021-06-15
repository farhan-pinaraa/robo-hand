#include <Servo.h>
#include <SoftwareSerial.h>
#include"pwm12.h"
Servo myservo1, myservo2, myservo3;
int bluetoothTx= 0;
int bluetoothRx= 1;
SoftwareSerial bluetooth(0, 1);
void setup()
{
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  Serial.begin(9600);
  bluetooth.begin(9600); 
}
void loop()
{
  if(bluetooth.available()>=2)
 {
  unsigned int Servopos= bluetooth.read();
  unsigned int Servopos1=bluetooth.read();
  unsigned int realServo= (Servopos1 *256)+Servopos;
  Serial.println(realServo);
  if(realServo>=1000&&realServo<1180)
  {
    int Servo1= realServo;
    Servo1= map (Servo1, 1000,1180,0,180);
    myservo1.write(Servo1);
    Serial.println("Servo1 on");
    delay(10);
  }
  if(realServo>=2000&&realServo<2180)
  {
    int Servo2= realServo;
    Servo2= map (Servo2, 2000,2180,0,180);
     myservo2.write(Servo2);
     Serial.println("Servo2 on");
     delay(10);
  }
   if(realServo>=3000&&realServo<3180)
   {
    int Servo3= realServo;
    Servo3= map (Servo3, 3000,3180,0,180);
    myservo3.write(Servo3);
    Serial.println("Servo3 on");
    delay(10);
   }
 }
}
