#include "NumberList.h"
#include <algorithm>

void NumberList:: Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	if (this->count <= 9) {
		this->numbers[count] = x;
		this->count++;
		return true;
	}
	else return false;
}

void NumberList::Sort() {
	std::sort(this->numbers, this->numbers+count);
}

void NumberList::Print() {
	for (int i = 0; i < this->count; i++) {
		printf("%d ",this->numbers[i]);
	}
}