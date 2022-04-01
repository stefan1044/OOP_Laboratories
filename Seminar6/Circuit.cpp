#pragma once
#include "circuit.h"
#include <algorithm>
#include <iostream>

void Circuit::SetWeather(Weather newWeather)
{
	this->vreme = newWeather;
}
void Circuit::SetLength(int newLength)
{
	this->length = newLength;
}

void Circuit::AddCar(Car* car)
{
	if (this->nrCars > 100)
		return;
	arr[nrCars++] = car;
}

bool compareMethod(leaderboard a, leaderboard b) {
	return (a.time < b.time);
}

void Circuit::Race() {

	for (int i = 0; i < this->nrCars; i++) {
		double fuelCapacity = this->arr[i]->getFuelCapacity();
		std::cout << fuelCapacity << ' ';
		double fuelConsumption = this->arr[i]->getFuelConsumption();
		std::cout << fuelConsumption << ' ';
		double speed = this->arr[i]->getAverageSpeed(this->vreme);
		std::cout << speed << ' ';

		double distance = fuelCapacity / fuelConsumption * 100;
		std::cout << distance << '\n';

		if (distance < this->length) {
			this->notFinish[this->nrNotFinish++] = i;
		}
		else {
			this->finalRanks[i].index = i;
			this->finalRanks[i].time = this->length / speed;
		}
	}

	std::sort(this->finalRanks, this->finalRanks + this->nrCars, compareMethod);

}

void Circuit::ShowFinalRanks() {
	for (int i = 0; i < (this->nrCars - this->nrNotFinish); i++) {
		std::cout <<"Car with index "<< this->finalRanks[i].index << " finished in time " << this->finalRanks[i].time << " hours\n";
	}
}
void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < this->nrNotFinish; i++) {
		std::cout << "Car with index " << this->notFinish[i] << " did not finish\n";
	}
}


