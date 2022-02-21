#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


struct tuplu {
	int lung, poz;
}lista[20];

bool sortalg(tuplu i, tuplu j) {
	return j.lung < i.lung;
}

int main()
{


	printf("-----------------[EXEMPLU PROBLEMA 2]------------------------\n");
	printf("Introduceti numarul de cuvinte din propozitie: ");
	int numarCuvinte;
	scanf_s("%d", &numarCuvinte, 4);
	printf("Introduceti o propozitie: ");
	char cuvant[20];
	//scanf("%19s", cuvant);
	int counter = 0;
	char matrice[30][30]{};
	int pozitie = 0;
	while (scanf_s("%19s", cuvant, 19))
	{

		strcpy_s(matrice[pozitie], cuvant);
		matrice[pozitie][strlen(matrice[pozitie])] = '\0';
		lista[pozitie].lung = strlen(matrice[pozitie]) - 1;
		lista[pozitie].poz = pozitie;
		cout << lista[pozitie].lung << ' ' << lista[pozitie].poz;
		pozitie++;

		printf("Cuvantul citit este: %s\n", cuvant);
		counter += 1;
		if (counter >= numarCuvinte)
			break;
	}

	sort(lista, lista + pozitie, sortalg);

	for (int i = 0; i <= pozitie; i++) {
		if (lista[i].lung == lista[i + 1].lung) {
			for (int j = 0; j <= lista[i].lung - 1; j++) {
				if ((int)matrice[lista[i].poz][j] > (int)matrice[lista[i + 1].poz]) {
					swap(lista[i].poz, lista[i + 1].poz);
					break;

				}
			}
		}
	}

	for (int i = 0; i < pozitie; i++) {
		printf("%s\n", matrice[lista[i].poz]);
	}

	printf("-----------------------------------------------------");
	printf("\n\n");

	system("pause");
	return 0;
}