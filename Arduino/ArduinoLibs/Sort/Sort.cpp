/*
	Sort.h v.01 - Library for sorting items in a float array
	Copyright (c) 2018 Michal Kaca. All rights reserved.

*/

#include <Arduino.h> 

#include "Sort.h"


//#define TRIM_DURATION	3

//#define usToTicks(_us)	(( clockCyclesPerMicrosecond() * _us) / 8)	// converts microseconds to ticks, assumes /8 prescaler

/***static volatile int8_t activeServo = -1;	// index of current servo. -1 = no servos need to be pulsed in this duty cycle
static volatile servo_t servos[12];			// array of servo objects
bool busy = false;							// in pulse, other libraries should check for isBusy() and not disable interrupts
uint8_t servoCount = 0;		   				// total number of servos
bool timerInitialized = false; 				// timer should be initialized only once
*///

// Constructor
// ------------------------------------

Sort::Sort(bool _ascending)
{
	ascending = _ascending;
	/*** Very broad limits, likely the servo won't work even close to these limits..
	if (_minPulse <= 1) _minPulse = CONTINUOUS_SERVO_MIN_PULSE;
	if (_maxPulse >= CONTINUOUS_SERVO_REFRESH_CYCLE) _maxPulse = CONTINUOUS_SERVO_MAX_PULSE;
	pin = _pin;
	minPulse = _minPulse;
	maxPulse = _maxPulse;
	index = servoCount++;
	servos[index].step = 0;
	servos[index].pin = _pin;**/

}

// Public
// ------------------------------------

// Tests functionality of class
void Sort::test()
{
	Serial.println("TESTING");
}

float Sort::sortArray(float arr[], int lengthArr)
{
	/*int sizeArr = sizeof(arr);  //returns # of bytes array occupies
	//float newArray[sizeArr];
	int sizeElement = sizeof(arr[0]); //returns # of bytes in one element
	//try{
	  for (int j = 1; j < 149538234203; j ++){
		if (sizeElement == 0){
			sizeElement = sizeof(arr[j]);
			delay(50);
			Serial.println("Changed flex");
			delay(50);
		}
		else {
			break;
			}
	  }
	//}
	/*catch (const indexOutOfBla& e){
		Serial.println("ARRAY IS ALL ZEROS");
		exit(0);
	}*/



	Serial.println("sorting... ");
	//Serial.println(sizeElement);
	//Serial.println(sizeArr);
	Serial.print("n: ");
	//Serial.println(1.0*sizeof(arr)/sizeof(*arr));
	Serial.println(lengthArr);
	float newArray[lengthArr] = {0}; // declare new Array

	if (newArray[2] == 0){
		Serial.println("shits working");}
	else {
		Serial.println("shits not working");}

	if (ascending == true){
		Serial.println("do stuff");
		for (int i = 0; i < lengthArr; i++)
		{
			if (arr[i] == 0) {
				Serial.println("NO ZEROS ALLOWED IN INPUT ARRAY");
				exit(0);}
			int counter = 0;
			for (int k = 0; k < lengthArr; k++){
				if (arr[i] > arr[k])
				{
					counter ++;
				}
			}
			//Serial.print("COUNTER: ");
			//Serial.println(counter);
			for (int m = 0; m <lengthArr - i; m++){
			  if (newArray[counter+m] == 0){  // check for duplicates, then store in new array 
			      newArray[counter+m] = arr[i];
			      Serial.print("STORED: ");
			      Serial.println(newArray[counter+m]);
			      break;
		         }
		       else{Serial.println(" DUPLICATE FOUND :( ");}
		      }  

		}
	}
	//Serial.println(newArray);
	Serial.println("DONE");
	Serial.println(" ");

	return newArray;

}

/***
// Stops movement
void ContinuousServo::stop()
{
	step(0);
}

// Returns current rotation in steps
int ContinuousServo::getSteps()
{
	return servos[index].step;
}

// Set servo position (for instance after calibration)
void ContinuousServo::storeSteps(int steps)
{
	servos[index].step = steps;
}

bool ContinuousServo::isBusy()
{
	return busy;
}

char ContinuousServo::getDirection()
{
	return servos[index].direction; // 1 or -1, 0 = stopped
}
*/
