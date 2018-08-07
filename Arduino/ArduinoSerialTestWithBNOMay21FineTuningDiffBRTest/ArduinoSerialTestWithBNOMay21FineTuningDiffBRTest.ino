#include <Adafruit_Sensor.h>

/**************************************************************************/
/*!
    @file     read_simple_angle.ino
    @author   mskaca (E. Ha.)
    @license  KacaCorp (see license.txt)

  read a simple angle from BNO055 over I2C bus 

  REQUIRES: ardser.py to send messages to the Serial Bus
  ANTIREQ: Ensure that the arduino console is closed
    @section  HISTORY

    v1.0 - First release
*/
/**************************************************************************/

#include <Wire.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

//float M_PI = 3.14159; 

int setPoint = 55;           // random value
String readString;           // notn eeded
unsigned short timeStart,timeEnd,timeDiff;  // required to find out how fast bus is

// Where a Quaternion takes the form a +bi +cj +dk , where i,j,k are imaginary
struct Quaternion{
     float a;   //real number      w
     float b;   //complex number   x ...i
     float c;   //complex number   y ...j
     float d;   //complex number   z ...k
}; 

// Converts any 4 values to a quaternion (usage:  quat = a + bi + cj + dk)
Quaternion getQuaternion (float a, float b, float c, float d)
{
  Quaternion quat;
  quat.a = a;
  quat.b = b;
  quat.c = c;
  quat.d = d;
  return quat; 
}

//Returns the inverse of a quaternion
Quaternion getQuaternionInverse(Quaternion quat)
{
  Quaternion inversedQuat;
  float dividend = quat.a*quat.a + quat.b*quat.b + quat.c*quat.c + quat.d*quat.d;
  inversedQuat.a =  quat.a/dividend;
  inversedQuat.b = (-1)*(quat.b/dividend);
  inversedQuat.c = (-1)*(quat.c/dividend);
  inversedQuat.d = (-1)*(quat.d/dividend);
  return inversedQuat;           
}

// Returns Quaternion product 
Quaternion getQuaternionProduct(Quaternion q1, Quaternion q2)
{
  Quaternion product;
  product.a = q1.a*q2.a - q1.b*q2.b - q1.c*q2.c - q1.d*q2.d;
  product.b = q1.a*q2.b +  q1.b*q2.a +q1.c*q2.d - q1.d*q2.c;
  product.c = q1.a*q2.c - q1.b*q2.d + q1.c*q2.a + q1.d*q2.b;
  product.d = q1.a*q2.d + q1.b*q2.c - q1.c*q2.b + q1.d*q2.a;
  return product;
}

static void toEulerAngle(Quaternion q, double& roll, double& pitch, double& yaw)
{
  // roll (x-axis rotation)
  double sinr = +2.0 * (q.a * q.b + q.c * q.d);
  double cosr = +1.0 - 2.0 * (q.b * q.b + q.c * q.c);
  roll = atan2(sinr, cosr);

  // pitch (y-axis rotation)
  double sinp = +2.0 * (q.a * q.b - q.d * q.b);
        if (fabs(sinp) >= 1)
            pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
        else
      pitch = asin(sinp);

  // yaw (z-axis rotation)
  double siny = +2.0 * (q.a * q.d + q.b * q.c);
  double cosy = +1.0 - 2.0 * (q.c * q.c + q.d * q.d);  
  yaw = atan2(siny, cosy);
}

void setup() {
  Serial.end();
  //Start serial
  Serial.begin(9600);
  while (!Serial) ; //wait until Serial ready
  Serial.println("Serial Ready");

//==================================================================================================================================
    /* Initialise the IMU */
   /*** pinMode(8,OUTPUT);
  delay(10);
  digitalWrite(8,HIGH);
  delay(200);
  digitalWrite(8,LOW);*/
  if(!bno.begin())
  {
    if (!bno.begin()){Serial.print("bno1 not connected");}
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  else{
    Serial.println("BNO CONNECTED");
  }
  
  delay(1000);
  bno.setExtCrystalUse(true);
  //Serial.print("Values are printed in the following order: bnoX1, bnoY1, \
  //bnoZ1, bnoX2, bnoY2, bnoZ2, Relative Roll, Relative Pitch, relative Yaw");
}

void loop() {

////////////////////////////////////////////////////////////////////////////////////////
 while (!Serial.available()) {} // wait for data to arrive
 
  // serial read section
  while (Serial.available()){
    timeStart = micros();
    delay(1);  //delay to allow buffer to fill 
    if (Serial.available() >0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      readString = c; //makes the string readString ... took out the +=
    }
    
  if (readString.length() >0)
  {
    //Serial.print("Arduino received: ");  
    //Serial.println(readString); //see what was received
    
    //==================================================================================  
  unsigned long startTime = micros();
  sensors_event_t event; 
  bno.getEvent(&event);
 // Serial.print("ElapsedTime: ");
 // Serial.println(ElapsedTime);
  // Serial.println(startTime);
   // Serial.println(currentTime);

  Serial.print(event.orientation.x, 5);
  Serial.print(", ");
  Serial.print(event.orientation.y, 5);
  Serial.print(", ");
  Serial.print(event.orientation.z, 5);
  Serial.print(", ");
  Serial.print("\n");
  //delay(1000);
   timeEnd = micros();
   timeDiff = timeEnd - timeStart;
   Serial.print("time diff: ");
   Serial.println(timeDiff);
   //unsigned long currentTime = micros();
  //unsigned long elapsedTime = currentTime - startTime;
  //Serial.print("elapsedTime: ");
 // Serial.println(elapsedTime);
  }

  delay(1);

  // serial write section

  char ard_sends = '1';
 // Serial.print("Arduino sends: ");
  //Serial.println(ard_sends);
  Serial.print("\n");
  //Serial.write(ard_sends);a
  Serial.flush();

  }
}
