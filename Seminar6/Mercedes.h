#pragma once
#include "Car.h"

class Mercedes : public Car {

    double fuelCapacity = 75;
    double fuelConsumption = 13;
    double averageSpeed[3] = { 100, 160, 75 };

public:
    double getFuelCapacity();
    double getFuelConsumption();
    double getAverageSpeed(Weather vreme);
};
