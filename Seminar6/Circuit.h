#pragma once
#include "Dacia.h"

struct leaderboard {
	double time = 0;
	int index = 0;
};

class Circuit {

public:
	
	Car* arr[100];
	int notFinish[100];
	leaderboard finalRanks[100];
	int nrCars = 0;
	int nrNotFinish = 0;
	int length;
	Weather vreme;

public:
	void SetWeather(Weather newWeather);
	void SetLength(int l);
	void AddCar(Car* masina);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};
