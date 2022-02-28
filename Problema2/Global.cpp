#include "Global.h"
#include <cstring>
int compareName(Student& student1, Student& student2) {
	char nume1[30], nume2[30];
	strcpy_s(nume1, student1.GetName());
	strcpy_s(nume2, student2.GetName());
	int rezultat = strcmp(nume1, nume2);
	if (rezultat == 0) return 0;
	else if (rezultat > 0) return 1;
	else return -1;
}
int compareMathGrade(Student& student1, Student& student2) {
	float numar1, numar2;
	numar1 = student1.GetMathGrade();
	numar2 = student2.GetMathGrade();
	if (numar1 == numar2) return 0;
	else if (numar1 > numar2) return 1;
	else return -1;
}
int compareEnglishGrade(Student& student1, Student& student2) {
	float numar1, numar2;
	numar1 = student1.GetEnglishGrade();
	numar2 = student2.GetEnglishGrade();
	if (numar1 == numar2) return 0;
	else if (numar1 > numar2) return 1;
	else return -1;
}
int compareHistoryGrade(Student& student1, Student& student2) {
	float numar1, numar2;
	numar1 = student1.GetHistoryGrade();
	numar2 = student2.GetHistoryGrade();
	if (numar1 == numar2) return 0;
	else if (numar1 > numar2) return 1;
	else return -1;
}
int compareAverageGrade(Student& student1, Student& student2) {
	float numar1, numar2;
	numar1 = student1.GetAverageGrade();
	numar2 = student2.GetAverageGrade();
	if (numar1 == numar2) return 0;
	else if (numar1 > numar2) return 1;
	else return -1;
}
