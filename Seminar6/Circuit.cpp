#include "circuit.h"

void Circuit::SetWeather(Weather newWeather)
{
    this->vreme = newWeather;
}

void Circuit::AddCar(Car* car)
{
    if (this->nrCars > 100)
        return;
    arr[nrCars++] = car;
}

void Circuit::SetLength(int newLength)
{
    this->length = newLength;
}
