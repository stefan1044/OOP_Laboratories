#pragma once
#include "Car.h"

class Ford : public Car {

    double fuelCapacity = 65;
    double fuelConsumption = 9;
    double averageSpeed[3] = { 35, 110, 45 };

public:
    double getFuelCapacity();
    double getFuelConsumption();
    double getAverageSpeed(Weather vreme);
};
