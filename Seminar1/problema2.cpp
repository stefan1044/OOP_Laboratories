//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	FILE* fp;
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		printf("Am deschis fisierul cu success!\n");
		char myString[200];
		int total = 0;
		while (fgets(myString, 200, fp)) {
			int numar = 0;
			int p = 1;

			for (int i = 0; i < strlen(myString) - 1; i++) {
				int cifra = myString[i] - '0';
				numar = numar * 10 + cifra;
			}

			cout << numar;

			total += numar;
			printf("Am citit din fisier: %s\n", myString);
		}
		printf("%d \n", total);
	}
	printf("\n");
	return 0;
}
