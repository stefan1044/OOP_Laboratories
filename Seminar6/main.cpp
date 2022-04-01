#pragma once

#include "Dacia.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Ford.h"
#include "Mazda.h"
#include "Circuit.h"
#include <iostream>

using namespace std;

int main() {

	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Snow);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	//cout << c.nrCars << ' ' << c.nrNotFinish<<'\n';
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();
	

	


	return 0;
}