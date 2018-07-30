/*
	Sort.h v.01 - Library for sorting items in a float array
	Copyright (c) 2018 Michal Kaca. All rights reserved.

*/

#ifndef Sort_h
#define Sort_h


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
	Sort(bool _ascending = true); //, float  _items[] = NULL);
	void test();
	float sortArray(float arr[], int lengthArr);
	/*void stepTo(int absoluteStep, void (*isr)() = NULL);
	void stop();
	int getSteps();
	void storeSteps(int steps);
	char getDirection();
	bool isBusy();*/
private:
	bool ascending;

};

#endif // ContinuousServo_h