/*
	Sort.h v.01 - Library for sorting items in a float array
	Copyright (c) 2018 Michal Kaca. All rights reserved.

*/

#ifndef Sort_h
#define Sort_h


#ifndef CONTINUOUS_SERVO_REFRESH_CYCLE
#define CONTINUOUS_SERVO_REFRESH_CYCLE 20000 // 20ms, 20000us. Standard for most servos. Decrease if the servo is jittering
#endif // CONTINUOUS_SERVO_REFRESH_CYCLE

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

typedef struct {
	unsigned int pin;
	long step;
	long targetStep;
	int direction;
	unsigned int stepSize; // in ticks
	bool active;
	void (*callback)();
} servo_t;

class Sort
{
public:
	Sort(bool ascending = true, float items[] = NULL);
	/*void stepTo(int absoluteStep, void (*isr)() = NULL);
	void stop();
	int getSteps();
	void storeSteps(int steps);
	char getDirection();
	bool isBusy();
private:
	uint8_t index;
	int pin;
	unsigned int minPulse;
	unsigned int maxPulse;
*/
};

#endif // ContinuousServo_h