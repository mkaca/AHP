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

Sort::Sort(bool _ascending, float _items[])
{
	/*** Very broad limits, likely the servo won't work even close to these limits..
	if (_minPulse <= 1) _minPulse = CONTINUOUS_SERVO_MIN_PULSE;
	if (_maxPulse >= CONTINUOUS_SERVO_REFRESH_CYCLE) _maxPulse = CONTINUOUS_SERVO_MAX_PULSE;
	pin = _pin;
	minPulse = _minPulse;
	maxPulse = _maxPulse;
	index = servoCount++;
	servos[index].step = 0;
	servos[index].pin = _pin;**//

}

// Public
// ------------------------------------

// Sets absolute position (steoTo(0) will return to start position)
void ContinuousServo::test()
{
	Serial.println("TESTING");
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
