#pragma once
#include "Dacia.h"

double Dacia::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Dacia::getFuelConsumption()
{
    return this->fuelConsumption;
}

double Dacia::getAverageSpeed(Weather vreme)
{
    return this->averageSpeed[vreme];
}