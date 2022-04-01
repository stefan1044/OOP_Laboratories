#pragma once
#include "Toyota.h"

double Toyota::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Toyota::getFuelConsumption()
{
    return this->fuelConsumption;
}

double Toyota::getAverageSpeed(Weather vreme)
{
    return this->averageSpeed[vreme];
}