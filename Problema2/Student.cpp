#include "Student.h"
#include <cstring>

void Student::SetName(char const nume[]) {
	strcpy_s(this->Name, nume);
}
void Student::SetMathGrade(int x) {
	if(x>=1 && x<=10)this->MathGrade = x;
}
void Student::SetEnglishGrade(int x) {
	if (x >= 1 && x <= 10)this->EnglishGrade = x;
}
void Student::SetHistoryGrade(int x) {
	if (x >= 1 && x <= 10)this->HistoryGrade = x;
}

char* Student::GetName() {
	if(strlen(this->Name))
		return this->Name;
}
float Student::GetMathGrade() {
	if (this->MathGrade >= 1 && this->MathGrade <= 10) return this->MathGrade;
}
float Student::GetEnglishGrade() {
	if (this->EnglishGrade >= 1 && this->EnglishGrade <= 10) return this->EnglishGrade;
}
float Student::GetHistoryGrade() {
	if (this->HistoryGrade >= 1 && this->HistoryGrade <= 10) return this->HistoryGrade;
}
float Student::GetAverageGrade() {
	if (this->MathGrade >= 1 && this->MathGrade <= 10 && this->EnglishGrade >= 1 && this->EnglishGrade <= 10
		&& this->HistoryGrade >= 1 && this->HistoryGrade <= 10)
		return (this->MathGrade + this->EnglishGrade + this->HistoryGrade) / 3;
	else return 0;
}