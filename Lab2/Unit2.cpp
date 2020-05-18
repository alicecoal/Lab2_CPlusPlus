//---------------------------------------------------------------------------
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Student::Student(AnsiString str)
{
	std::vector<AnsiString> info;
	int pos = 0, count = 0;

	for (int i = 1, len = str.Length(); i <= len;)
	{
		if (str[i] != '|')
		{
			count++;
			i++;
		}
		else
		{
			count--;
			AnsiString st = str.SubString(pos, count);
			info.push_back(st);
			i += 2;
			pos = i;
			count = 0;
		}
	}
	name = info[0];
	group = StrToInt(info[1]);
	WinterMarks[0] = StrToInt(info[2]);
	WinterMarks[1] = StrToInt(info[3]);
	WinterMarks[2] = StrToInt(info[4]);
	WinterMarks[3] = StrToInt(info[5]);
	SummerMarks[0] = StrToInt(info[6]);
	SummerMarks[1] = StrToInt(info[7]);
	SummerMarks[2] = StrToInt(info[8]);
	SummerMarks[3] = StrToInt(info[9]);
	SummerMarks[4] = StrToInt(info[10]);
	double s = 0;
	for (int i = 0; i < 4; i++)
	{
		s+=WinterMarks[i];
	}
	WinterAverage = int((s/4)*100 + 0.5)/100.0;
	s = 0;
	for (int i = 0; i < 5; i++)
	{
		s+=SummerMarks[i];
	}
	SummerAverage = int((s/5)*100 + 0.5)/100.0;
};

Student::Student(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int y5, AnsiString n, int g)
{
	name = n;
	group = g;
	WinterMarks[0] = x1;
	WinterMarks[1] = x2;
	WinterMarks[2] = x3;
	WinterMarks[3] = x4;
	SummerMarks[0] = y1;
	SummerMarks[1] = y2;
	SummerMarks[2] = y3;
	SummerMarks[3] = y4;
	SummerMarks[4] = y5;
	double s = 0;
	double x = 0;
	for (int i = 0; i < 4; i++)
	{
		s+=WinterMarks[i];
	}
	x = s / 4;
	WinterAverage = int(x*100 + 0.5)/100.0;
	s = 0; x = 0;
	for (int i = 0; i < 5; i++)
	{
		s+=SummerMarks[i];
	}
	x = s / 5;
	SummerAverage = int(x*100 + 0.5)/100.0;
}

AnsiString Student::Info()
{
	AnsiString info;
	AnsiString wmarks;
	AnsiString smarks;
	wmarks = IntToStr(WinterMarks[0]) + " | " + IntToStr(WinterMarks[1]) + " | " + IntToStr(WinterMarks[2]) + " | " + IntToStr(WinterMarks[3]);
	smarks = IntToStr(SummerMarks[0]) + " | " + IntToStr(SummerMarks[1]) + " | " + IntToStr(SummerMarks[2]) + " | " + IntToStr(SummerMarks[3])+ " | " + IntToStr(SummerMarks[4]);
	info = name + " | " + IntToStr(group) + " | " + wmarks + " | " + smarks + " | " + FloatToStr(WinterAverage) + " | " + FloatToStr(SummerAverage) + " | ";
	return info;
}

void Student::FillComboBoxes(TForm1 *F)
{
	F->ComboBox1->Items->Add(name);
}

void Student::FillFields(TForm1 *F)
{
	F->Edit1->Text = IntToStr(WinterMarks[0]);
	F->Edit2->Text = IntToStr(WinterMarks[1]);
	F->Edit3->Text = IntToStr(WinterMarks[2]);
	F->Edit4->Text = IntToStr(WinterMarks[3]);
	F->Edit5->Text = IntToStr(SummerMarks[0]);
	F->Edit6->Text = IntToStr(SummerMarks[1]);
	F->Edit7->Text = IntToStr(SummerMarks[2]);
	F->Edit8->Text = IntToStr(SummerMarks[3]);
	F->Edit9->Text = IntToStr(SummerMarks[4]);
	F->Group->Text = IntToStr(group);
}

void Student::ChangeInfo(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int y5, AnsiString n, int g)
{
	name = n;
	group = StrToInt(g);
	WinterMarks[0] = StrToInt(x1);
	WinterMarks[1] = StrToInt(x2);
	WinterMarks[2] = StrToInt(x3);
	WinterMarks[3] = StrToInt(x4);
	SummerMarks[0] = StrToInt(y1);
	SummerMarks[1] = StrToInt(y2);
	SummerMarks[2] = StrToInt(y3);
	SummerMarks[3] = StrToInt(y4);
	SummerMarks[4] = StrToInt(y5);
    double s = 0;
	for (int i = 0; i < 4; i++)
	{
		s+=WinterMarks[i];
	}
	WinterAverage = int((s/4)*100 + 0.5)/100.0;
	s = 0;
	for (int i = 0; i < 5; i++)
	{
		s+=SummerMarks[i];
	}
	SummerAverage = int((s/5)*100 + 0.5)/100.0;
}

bool Student::CheckZ()
{
	int f = 0;
	for (int i = 0; i < 4; i++)
	{
		if (WinterMarks[i]<4)
		{
		   f++;
		}
	}
	if (f>0) return true;
	else return false;
}

bool Student::CheckO()
{
	int f1 = 0;
	int f2 = 0;
	for (int i = 0; i < 4; i++)
	{
		if (WinterMarks[i]<4)
		{
		   f1++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (SummerMarks[i]<4)
		{
		   f2++;
		}
	}
	if ((f1>0) && (f2>1)) return true;
	else return false; ;
}
