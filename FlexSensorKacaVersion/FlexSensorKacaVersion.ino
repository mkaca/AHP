
/******************************************************************************
Michal Kaca
July 29, 2018

Create a voltage divider circuit combining a flex sensor with a 10k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 5V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.

******************************************************************************/
#include <Sort.h>
#include <math.h>

const int FLEX_PIN = A0; // Pin connected to voltage divider output

const float VCC = 4.98; // Measured voltage of Ardunio 5V line
//const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

float calStrRes = 0; //calibrated straight resistance
Sort sortobject = Sort();


void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  //calibrate for straight resistance
  int arrSize = 7;
  float arrayCalib[arrSize];
  for (int i = 0; i++; i < arrSize){
    arrayCalib[i] = analogRead(FLEX_PIN) * VCC / 1023.0;
  }
  float* arrayFlex = sortobject.sortArray(arrayCalib, arrSize);
  for (int j=0;j++; j < arrSize){
  Serial.print("Array looks like this:");
  Serial.println(arrayFlex[j]);
  }
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * VCC / 1023.0;
  //float flexR = R_DIV * (VCC / flexV - 1.0);
  Serial.print("flexV");
  Serial.println(flexADC);
  Serial.println(flexV);
  Serial.println(" ");
  delay(2000);
  //Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
   /***float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();*/

  delay(200);
}
