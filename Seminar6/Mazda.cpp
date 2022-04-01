#pragma once
#include "Mazda.h"

double Mazda::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Mazda::getFuelConsumption()
{
    return this->fuelConsumption;
}

double Mazda::getAverageSpeed(Weather vreme)
{
    return this->averageSpeed[vreme];
}