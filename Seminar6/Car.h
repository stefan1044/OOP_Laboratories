#pragma once
#include "Weater.h"
class Car {
public:
	virtual double getAverageSpeed(Weather vreme) = 0;
	virtual double getFuelCapacity() = 0;
	virtual double getFuelConsumption() = 0;
};

