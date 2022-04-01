#pragma once
#include "Car.h"

class Dacia : public Car {

    double fuelCapacity = 55;
    double fuelConsumption = 9;
    double averageSpeed[3] = { 70, 100, 30 };

public:
    double getFuelCapacity();
    double getFuelConsumption();
    double getAverageSpeed(Weather vreme);
};
