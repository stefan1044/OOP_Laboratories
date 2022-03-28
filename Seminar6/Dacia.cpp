#include "Dacia.h"

int Dacia::getFuelCapacity()
{
    return this->fuelCapacity;
}

int Dacia::getFuelConsumption()
{
    return this->fuelConsumption;
}

int Dacia::getAverageSpeed(Weather vreme)
{
    return this->averageSpeed[vreme];
}