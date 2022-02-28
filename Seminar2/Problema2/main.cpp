#include <iostream>
#include "Global.h"
using namespace std;
int main() {
	Student Razvan,Stefan;
	char string[30];
	float mate, engleza, istorie, medie;
	Razvan.SetName("Razvan");
	Razvan.SetMathGrade(5);
	Razvan.SetEnglishGrade(7);
	Razvan.SetHistoryGrade(9);
	Stefan.SetName("Stefan");
	Stefan.SetMathGrade(4);
	Stefan.SetEnglishGrade(9);
	Stefan.SetHistoryGrade(8);

	strcpy_s(string, Razvan.GetName());
	mate = Razvan.GetMathGrade();
	engleza = Razvan.GetEnglishGrade();
	istorie = Razvan.GetHistoryGrade();
	medie = Razvan.GetAverageGrade();

	printf("%s ", string);
	printf("%f ", mate);
	printf("%f ", engleza);
	printf("%f ", istorie);
	printf("%f ", medie);

	printf("%d ", compareName(Razvan, Stefan));
	printf("%d ", compareMathGrade(Razvan, Stefan));
	printf("%d ", compareEnglishGrade(Razvan, Stefan));
	printf("%d ", compareHistoryGrade(Razvan, Stefan));
	printf("%d ", compareAverageGrade(Razvan, Stefan));
}
