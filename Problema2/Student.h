class Student {
	char Name[30];
	float MathGrade, EnglishGrade, HistoryGrade;

public:
	void SetName(char const nume[]);
	void SetMathGrade(int x);
	void SetEnglishGrade(int x);
	void SetHistoryGrade(int x);
	char* GetName();
	float GetMathGrade();
	float GetEnglishGrade();
	float GetHistoryGrade();
	float GetAverageGrade();

};
