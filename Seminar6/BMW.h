#include "Car.h"

class BMW : public Car {

    int fuelCapacity = 75;
    int fuelConsumption = 13;
    int averageSpeed[3] = { 100, 150, 75 };

public:
    int getFuelCapacity();
    int getFuelConsumption();
    int getAverageSpeed(Weather vreme);
};
