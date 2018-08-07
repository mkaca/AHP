/**************************************************************************/
/*!
    @file     read_simple_angle.ino
    @author   SOSAndroid (E. Ha.)
    @license  BSD (see license.txt)

  read a simple angle from AS5048B over I2C bus

    @section  HISTORY

    v1.0 - First release
*/
/**************************************************************************/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);
Adafruit_BNO055 bno2 = Adafruit_BNO055(65, 0x29); //This has the yellow wire 

//unit consts
#define U_RAW 1
#define U_TRN 2
#define U_DEG 3
#define U_RAD 4
#define U_GRAD 5
#define U_MOA 6
#define U_SOA 7
#define U_MILNATO 8
#define U_MILSE 9
#define U_MILRU 10

//float M_PI = 3.14159; 

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
  //Start serial
  Serial.begin(9600);
  while (!Serial) ; //wait until Serial ready
  Serial.print("Serial Ready");
  
  pinMode(8, OUTPUT);
    boolean toggle = true;  
  //toggle = !toggle;
  digitalWrite(8,toggle);

//==================================================================================================================================
    /* Initialise the IMU */
  if(!bno.begin())
  {
    if (!bno.begin()){Serial.print("bno1 not connected");}
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  delay(1000);
  bno.setExtCrystalUse(true);
  Serial.print("Values are printed in the following order: bnoX1, bnoY1, \
  bnoZ1, bnoX2, bnoY2, bnoZ2, Relative Roll, Relative Pitch, relative Yaw");
}

void loop() {

//==================================================================================  
  unsigned long startTime = micros();
  sensors_event_t event; 
  bno.getEvent(&event);
  unsigned long currentTime = micros();
  unsigned long ElapsedTime = currentTime - startTime;
  Serial.print("ElapsedTime: ");
  Serial.println(ElapsedTime);
  // Serial.println(startTime);
   // Serial.println(currentTime);
  /*
  Serial.print("X: ");
  Serial.print(event2.orientation.x, 5);
  Serial.print("\tY: ");
  Serial.print(event2.orientation.y, 5);
  Serial.print("\tZ: ");
  Serial.print(event2.orientation.z, 5);
  Serial.println("");
  */
  // Quaternion data
  //imu::Quaternion quat = bno.getQuat();
  
//  // Quaternion data 2
//  imu::Quaternion quat2 = bno2.getQuat();

//  Quaternion inverse = getQuaternionInverse(getQuaternion(quat2.w(),quat2.x(),quat2.y(),quat2.z()));

  //Serial.print(" Difference of bno and bno2: ");
//  Quaternion product = getQuaternionProduct(getQuaternion(quat.w(),quat.x(),quat.y(),quat.z()),inverse);
  
  //Serial.print(" Euler Angles: ");
//  double roll,pitch,yaw;
//  toEulerAngle(product, roll, pitch, yaw);
  /*
  Serial.print(" roll: ");
  Serial.print(roll*180/ 3.14159, 5);
  Serial.print(" pitch: ");
  Serial.print(pitch*180/ 3.14159, 5);
  Serial.print(" yaw: ");
  Serial.print(yaw*180/ 3.14159, 5);
  Serial.print("\n");
  */
//===============================================================================================================
  //print to serial the raw angle and degree angle
  //Serial.print("Angle sensor raw : ");
  //Serial.print("Angle degree : ");

  Serial.print(event.orientation.x, 5);
  Serial.print(", ");
  Serial.print(event.orientation.y, 5);
  Serial.print(", ");
  Serial.print(event.orientation.z, 5);
  Serial.print(", ");
//  Serial.print(event2.orientation.x, 5);
//  Serial.print(", ");
//  Serial.print(event2.orientation.y, 5);
//  Serial.print(", ");
//  Serial.print(event2.orientation.z, 5);
//  Serial.print(", ");
//  Serial.print(roll*180/ 3.14159, 5);
//  Serial.print(", ");
//  Serial.print(pitch*180/ 3.14159, 5);
//  Serial.print(", ");
//  Serial.print(yaw*180/ 3.14159, 5);
  Serial.print("\n");
  
  delay(1000);
  

}
