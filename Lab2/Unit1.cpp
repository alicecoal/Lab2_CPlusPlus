//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>
#include <string.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <memory>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TStringList* tmp = new TStringList;
TFileStream *fl = NULL;
Student* Students;
int Ssize = 0;
int index;
int enable = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OpenClick(TObject *Sender)
{
	if (Ssize != 0) {
		ShowMessage("Before opening a new file, be shure that you have saved everything.");
	}
	if (!OpenDialog1->Execute()){
		ShowMessage("You didn't choose anything.");
		return;
	}
	try
	{
		List->Lines->LoadFromFile(OpenDialog1->FileName);
		tmp->LoadFromFile(OpenDialog1->FileName);
	}
	catch (...)
	{
		ShowMessage("There is no such file. Created new one.");
		fl = new TFileStream(OpenDialog1->FileName, fmCreate);
		fl->Free();
	}
	Students = new Student[tmp->Count];
	for (int i = 0; i < tmp->Count; i++) {
		Students[i] = Student(tmp->Strings[i]);
	}
	Ssize = tmp->Count;
	WriteList();
    	Check();
	enable = 0;
}
//---------------------------------------------------------------------------
void TForm1::WriteList()
{
	ComboBox1->Items->Clear();
	List->Lines->Clear();
	//List->Lines->Add(IntToStr(Ssize));
	for (int i = 0; i < Ssize; i++) {
		Students[i].FillComboBoxes(Form1);
		List->Lines->Add(Students[i].Info());
	}
}
//--------------------------------------------------------------------------
void TForm1::Check()
{
	Zadoljennosti->Lines->Clear();
	Otchisleno->Lines->Clear();
	for (int i = 0; i < Ssize; i++) {
		if (Students[i].CheckZ()==true) Zadoljennosti->Lines->Add(Students[i].Info());
		if (Students[i].CheckO()==true) Otchisleno->Lines->Add(Students[i].Info());
	}
}
//--------------------------------------------------------------------------
void TForm1::ClearFields()
{
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";
	Edit5->Text = "";
	Edit6->Text = "";
	Edit7->Text = "";
	Edit8->Text = "";
	Edit9->Text = "";
	ComboBox1->Text = "";
	Group->Text = "";
}
//---------------------------------------------------------------------------
bool comp(const Student& a, const Student& b)
{
	if (a.group != b.group) {
		return a.group < b.group;
	}
	else if (a.name != b.name) {
		return a.name < b.name;
	}
	else return false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SortClick(TObject *Sender)
{
	for (int i = 0; i < Ssize - 1; i++)
	{
		for (int j = 0; j < Ssize - i - 1; j++)
		{
			if (Students[j].group != Students[j+1].group)
			{
				if (Students[j].group > Students[j+1].group)
				{
					Student x = Students[j];
					Students[j] = Students[j + 1];
					Students[j + 1] = x;
				}
			}
			else if (Students[j].name > Students[j+1].name)
				{
					Student x = Students[j];
					Students[j] = Students[j + 1];
					Students[j + 1] = x;
				}
			}
	}
	WriteList();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddClick(TObject *Sender)
{
	try
	{
		int x1 = StrToInt(Edit1->Text);
		int x2 = StrToInt(Edit2->Text);
		int x3 = StrToInt(Edit3->Text);
		int x4 = StrToInt(Edit4->Text);
		int y1 = StrToInt(Edit5->Text);
		int y2 = StrToInt(Edit6->Text);
		int y3 = StrToInt(Edit7->Text);
		int y4 = StrToInt(Edit8->Text);
		int y5 = StrToInt(Edit9->Text);
		int g = StrToInt(Group->Text);
		AnsiString n = ComboBox1->Text;
		Student* arr = new Student[Ssize + 1];
		for (int i = 0; i < Ssize; i++)
		{
			arr[i] = Students[i];
		}
		arr[Ssize] = Student(x1, x2, x3, x4, y1, y2, y3, y4, y5, n, g);
		Students = arr;
		Ssize++;
		enable = 0;
		WriteList();
		ClearFields();
		Check();
	}
	catch (...)
	{
		ComboBox1->Text = "";
		Edit1->Text = "ERROR";
		Edit2->Text = "ERROR";
		Edit3->Text = "ERROR";
		Edit4->Text = "ERROR";
		Edit5->Text = "ERROR";
		Edit6->Text = "ERROR";
		Edit7->Text = "ERROR";
		Edit8->Text = "ERROR";
		Edit9->Text = "ERROR";
		Group->Text = "ERROR";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveClick(TObject *Sender)
{
    if (!SaveDialog1->Execute()) {
		ShowMessage("You didn't choose anything!");
		return;
	}
	List->Lines->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Find1Click(TObject *Sender)
{
		Find1->Text = "";
		Founded->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchClick(TObject *Sender)
{
	AnsiString data = Find1->Text;
	Founded->Lines->Clear();
	for (int i = 0; i < Ssize; i++) {
		if (Students[i].name == data)Founded->Lines->Add(Students[i].Info());
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
	if (enable == 1)
	{
		enable = 0;
		Ssize--;
		Student* arr = new Student[Ssize];
		int x = Form1->ComboBox1->ItemIndex;
		for (int i = 0; i < x; i++)
		{
			arr[i] = Students[i];
		}
		for (int i = x; i < Ssize; i++)
		{
		arr[i] = Students[i + 1];
		}
		Students = arr;
		ClearFields();
		WriteList();
		Check();
		Form1->ComboBox1->DeleteSelected();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Click(TObject *Sender)
{
	enable = 1;
	index = ComboBox1->ItemIndex;
	Students[index].FillFields(Form1);
}
//---------------------------------------------------------------------------


