#pragma once
#include "Ford.h"

double Ford::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Ford::getFuelConsumption()
{
    return this->fuelConsumption;
}

double Ford::getAverageSpeed(Weather vreme)
{
    return this->averageSpeed[vreme];
}