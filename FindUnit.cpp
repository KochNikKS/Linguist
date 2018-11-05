//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "FindUnit.h"
#include "MainUnit.h"
#include "List.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFindForm *FindForm;
extern DicList *Dictionary;

void GoFind(int D)
{
int Index = -1; bool MCase = FindForm->BMCase->Checked;

Index  = Dictionary->Find(FindForm->Edit1->Text.c_str(),MCase,
MainForm->ListBox1->ItemIndex,D);

if (Index > -1)
{Mes ("String was found","Report");
MainForm->ListBox1->Selected[MainForm->ListBox1->ItemIndex]= false;
MainForm->ListBox1->Selected[Index]= true;}
else Mes("String not found","Report");
}
//---------------------------------------------------------------------------
__fastcall TFindForm::TFindForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::Button1Click(TObject *Sender)
{
GoFind(-1);
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::FormShow(TObject *Sender)
{
MainForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::FormHide(TObject *Sender)
{
MainForm->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::Button2Click(TObject *Sender)
{
GoFind(1);
}
//---------------------------------------------------------------------------
void __fastcall TFindForm::Button3Click(TObject *Sender)
{
FindForm->Visible = false;	
}
//---------------------------------------------------------------------------
