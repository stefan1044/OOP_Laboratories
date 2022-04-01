#pragma once
#include "Car.h"

class Toyota : public Car {

    double fuelCapacity = 80;
    double fuelConsumption = 5;
    double averageSpeed[3] = { 50, 130, 40 };

public:
    double getFuelCapacity();
    double getFuelConsumption();
    double getAverageSpeed(Weather vreme);
};
