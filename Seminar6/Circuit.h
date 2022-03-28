#include "Dacia.h"

class Circuit {
	Car* arr[100];
	int nrCars=0;
	int lenght;
	Weather vreme;

	void SetLength( int l);
	void AddCar(Car* masina);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};
