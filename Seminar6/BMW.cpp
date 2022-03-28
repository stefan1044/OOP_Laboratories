#include "BMW.h"

int BMW::getFuelCapacity()
{
    return this->fuelCapacity;
}

int BMW::getFuelConsumption()
{
    return this->fuelConsumption;
}

int BMW::getAverageSpeed(Weather vreme)
{
    return this->averageSpeed[vreme];
}