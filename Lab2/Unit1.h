//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:// IDE-managed Components
	TMemo *List;
	TComboBox *ComboBox1;
	TEdit *Edit1;
	TButton *Add;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TLabel *Label1;
	TMemo *Otchisleno;
	TLabel *Label;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label4;
	TEdit *Edit4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TButton *Open;
	TButton *Sort;
	TButton *Save;
	TButton *Delete;
	TLabel *Label14;
	TEdit *Group;
	TEdit *Find1;
	TLabel *Label15;
	TLabel *Label16;
	TButton *Search;
	TMemo *Founded;
	TMemo *Zadoljennosti;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	void __fastcall SortClick(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall SaveClick(TObject *Sender);
	void __fastcall Find1Click(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall OpenClick(TObject *Sender);
	void __fastcall ComboBox1Click(TObject *Sender);
private:
	void WriteList();
	void Check();
	void ClearFields();
	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
