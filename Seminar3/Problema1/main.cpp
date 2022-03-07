#include "Math.h"
#include <stdio.h>

using namespace std;

int main() {

	int nr;
	nr=Math::Add(7, 3);
	printf("%d\n", nr);
	nr = Math::Add(7, 3,9);
	printf("%d\n", nr);
	nr = Math::Add(5.1, 1.3);
	printf("%d\n", nr);
	nr = Math::Add(5.0, 1.1, 2.3);
	printf("%d\n", nr);
	nr = Math::Add(5, 1, 2, 3, 4, 5);
	printf("%d\n", nr);

	nr = Math::Mul(1, 2);
	printf("%d\n", nr);
	nr = Math::Mul(1, 2,3);
	printf("%d\n", nr);
	nr = Math::Mul(1.1, 2.9);
	printf("%d\n", nr);
	nr = Math::Mul(1.5, 2.6,8.9);
	printf("%d\n", nr);


	char* string;
	string=Math::Add("string", " concat");
	printf("%s", string);

	return 0;
}