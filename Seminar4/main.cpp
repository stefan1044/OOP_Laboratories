#include "Sort.h"

using namespace std;

int main() {
	Sort a(3,1,9);
	a.Print();

	Sort b;
	b.Print();

	int v[] = {8,7,9,10};
	Sort c(v,4);
	c.Print();

	Sort d(5, 2, 1, 3, 4,5);
	d.Print();

	char car[] = "1,5,9,21";
	Sort e(car);
	e.Print();

	int v1[] = { 8,7,9,10 };
	Sort s1(v1, 4);
	s1.InsertSort();
	s1.Print();

	int v2[] = { 7,12,9,0 };
	Sort s2(v2, 4);
	s2.BubbleSort();
	s2.Print();

	int v3[] = { 8,7,9,10 ,4,11};
	Sort s3(v3, 6);
	s3.QuickSort(true);
	s3.Print();

	return 0;
}