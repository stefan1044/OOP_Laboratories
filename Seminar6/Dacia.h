#include "Car.h"

class Dacia : public Car {

    int fuelCapacity = 55;
    int fuelConsumption = 9;
    int averageSpeed[3] = { 70, 100, 30 };

public:
    int getFuelCapacity();
    int getFuelConsumption();
    int getAverageSpeed(Weather vreme);
};
