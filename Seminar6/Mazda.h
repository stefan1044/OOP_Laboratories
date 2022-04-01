#pragma once
#include "Car.h"

class Mazda : public Car {

    double fuelCapacity = 80;
    double fuelConsumption = 7;
    double averageSpeed[3] = { 70, 120, 50 };

public:
    double getFuelCapacity();
    double getFuelConsumption();
    double getAverageSpeed(Weather vreme);
};
