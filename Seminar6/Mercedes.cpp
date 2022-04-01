#pragma once
#include "Mercedes.h"

double Mercedes::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Mercedes::getFuelConsumption()
{
    return this->fuelConsumption;
}

double Mercedes::getAverageSpeed(Weather vreme)
{
    return this->averageSpeed[vreme];
}