//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#include <vector>
#include <Unit1.h>
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
class Student
{
	public:
	AnsiString name;
	int group;
	int WinterMarks[4];
	int SummerMarks[5];
	double WinterAverage;
	double SummerAverage;
	public:
	Student(AnsiString str);
	Student(){};
	~Student(){};
	Student(int, int, int, int, int, int, int, int, int, AnsiString, int);
	AnsiString Info();
	void FillComboBoxes(TForm1 *F);
	void FillFields(TForm1 *F);
	void ChangeInfo(int, int, int, int, int, int, int, int, int, AnsiString, int);
	bool CheckZ();
	bool CheckO();
};
#endif
