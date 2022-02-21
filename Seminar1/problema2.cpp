//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	////Exemplificare printf
	//printf("-----------------[EXEMPLU CU PRINTF]------------------------\n");
	//int a = 123;
	//printf("Valoare lui a este: %d\n", a);
	//char c = 123;
	//printf("Valoarea lui c (char) este: %c\n", c);
	//printf("Valoarea numerica a lui c este: %d\n", c);
	//char sir[20] = "ana are mere\0";
	//printf("Sirul meu are valoarea: %s\n", sir);
	//printf("-----------------------------------------------------");
	//printf("\n\n");


	printf("-----------------[EXEMPLU PROBLEMA 1]------------------------\n");
	FILE* fp;
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		printf("Am deschis fisierul cu success!\n");
		char myString[200];
		/*
		if (fgets(myString, 200, fp))
		{
			printf("Am citit din fisier: %s\n", myString);
		}
		*/
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
	printf("-----------------------------------------------------");
	printf("\n\n");
	return 0;
}