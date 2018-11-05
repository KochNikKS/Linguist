//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include "MainUnit.h"
#include "List.h"
#include "ChngUnit.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TChngForm *ChngForm;
extern DicList *Dictionary;
extern int STATUS;
extern bool Modified;
extern ShowDictionary();
extern TCursor crHandCur = -21;
extern FModified();
//---------------------------------------------------------------------------
__fastcall TChngForm::TChngForm(TComponent* Owner)
	: TForm(Owner)
{
BitBtn1->Cursor= crHandCur;
BitBtn2->Cursor = crHandCur;
}
//---------------------------------------------------------------------------
void __fastcall TChngForm::BitBtn2Click(TObject *Sender)
{
Edit1->Text="";
Edit2->Text="";
ChngForm->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TChngForm::BitBtn1Click(TObject *Sender)
{
char ChString[10000]="";
strcpy(ChString,Edit1->Text.c_str());
strcat(ChString," ~ ");
strcat(ChString,Edit2->Text.c_str());
switch (STATUS)
{
case 1: Dictionary->ChangeText(ChString,MainForm->ListBox1->ItemIndex);
		Dictionary->Sorter();break;
case 2: if (strlen(Dictionary->GetText(MainForm->ListBox1->ItemIndex))>0)
{Dictionary->Add(ChString);Dictionary->Sorter();}
else{Dictionary->ChangeText(ChString,MainForm->ListBox1->ItemIndex);
Dictionary->Sorter();}break;
}
Modified = true;
FModified();
ShowDictionary();
ChngForm->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TChngForm::Edit1Change(TObject *Sender)
{
if (Edit1->Text!=""&&Edit2->Text!="")BitBtn1->Enabled = true;
else BitBtn1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TChngForm::FormHide(TObject *Sender)
{
MainForm->Enabled = true;	
}
//---------------------------------------------------------------------------
void __fastcall TChngForm::FormShow(TObject *Sender)
{
MainForm->Enabled = false;
BitBtn1->Enabled = false;
}
//---------------------------------------------------------------------------
