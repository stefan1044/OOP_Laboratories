#include "Sort.h"
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
#include <iostream>
#include <algorithm>

Sort::Sort(int count, int min, int max) {
	this->numberOfElements = count;
	time_t t;
	srand((unsigned)time(&t));

	this->vec = new int[count];

	for (int i = 0; i < count; i++) {
		vec[i] = min + rand() % (max - min + 1);
	}

}

Sort::Sort() :vec(new int[5]{ 1,2,3,4,5 }) {
	this->numberOfElements = 5;
}

Sort::Sort(int arr[], int count) {
	this->numberOfElements = count;
	this->vec = new int[count];
	for (int i = 0; i < count; i++) {
		vec[i] = arr[i];
	}
}

Sort::Sort(int count, ...) {
	va_list v1;
	va_start(v1, count);
	this->vec = new int[count];
	this->numberOfElements = count;
	for (int i = 0; i < count; i++) {
		this->vec[i] = va_arg(v1, int);
	}
	//va_end(v1);
}

Sort::Sort(char string[]) {
	int count = 1;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == ',') count++;
	}
	this->vec = new int[count];
	this->numberOfElements = count;

	int numar = 0, poz = 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == ',') {
			this->vec[poz] = numar;
			poz++;
			numar = 0;
		}
		else {
			numar = numar * 10 + (int)string[i] - 48;
		}
	}
	this->vec[poz] = numar;
}

void Sort::InsertSort(bool ascendent) {
	int i, key, j;
	for (i = 1; i < this->numberOfElements; i++)
	{
		key = this->vec[i];
		j = i - 1;

		while (j >= 0 && this->vec[j] > key)
		{
			this->vec[j + 1] = this->vec[j];
			j = j - 1;
		}
		this->vec[j + 1] = key;
	}

	if (ascendent == true) {
		for (int i = 0; i < this->numberOfElements/2; i++) {
			std::swap(this->vec[i], this->vec[this->numberOfElements - i - 1]);
		}
	}
}

void Sort::BubbleSort(bool ascendent) {
	int i, j;
	for (i = 0; i < this->numberOfElements - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < this->numberOfElements - i - 1; j++)
			if (this->vec[j] > this->vec[j + 1])
				std::swap(this->vec[j], this->vec[j + 1]);

	if (ascendent == true) {
		for (int i = 0; i < this->numberOfElements / 2; i++) {
			std::swap(this->vec[i], this->vec[this->numberOfElements - i - 1]);
		}
	}
}

void Sort::QuickSort(bool ascendent) {

	qs(0, this->numberOfElements-1);

	if (ascendent == true) {
		for (int i = 0; i < this->numberOfElements / 2; i++) {
			std::swap(this->vec[i], this->vec[this->numberOfElements - i - 1]);
		}
	}
}

void Sort::Print() {
	for (int i = 0; i < this->numberOfElements; i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';
}

int Sort::GetElementsCount() {
	return this->numberOfElements;
}

int Sort::GetElementFromIndex(int index) {
	return this->vec[index];
}


int Sort::partition(int beg, int end){
	int pivot = this->vec[beg];

	int pivPlace = 0;
	for (int i = beg + 1; i <= end; i++) {
		if (this->vec[i] <= pivot)
			pivPlace++;
	}

	int pivotIndex = beg + pivPlace;
	std::swap(this->vec[pivotIndex], this->vec[beg]);

	int p1 = beg;
	int p2 = end;

	while (p1 < pivotIndex && p2 > pivotIndex) {
		while (this->vec[p1] <= pivot) {
			p1++;
		}
		while (this->vec[p2] > pivot) {
			p2--;
		}
		if (p1 < pivotIndex && p2 > pivotIndex) {
			std::swap(this->vec[p1++], this->vec[p2--]);
		}
	}

	return pivotIndex;
}

void Sort::qs(int beg, int end){
	if (beg >= end)
		return;
	int p = partition(beg, end);
	qs(beg, p - 1);
	qs(p + 1, end);
}