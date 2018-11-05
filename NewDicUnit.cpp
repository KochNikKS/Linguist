//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include <fstream.h>
#include "NewDicUnit.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TNewDicForm *NewDicForm;
//---------------------------------------------------------------------------
__fastcall TNewDicForm::TNewDicForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNewDicForm::Button1Click(TObject *Sender)
{
char buf[5000] ="";
strcat(buf,DirListBox1->Directory.c_str());
strcat (buf, "\\");
strcat (buf, Edit1->Text.c_str());
if (strchr(buf,(int)'.')) strcpy(buf ,strtok(buf,"."));
strcat(buf,".ldf");
ofstream newfilename (buf,ios::out);
if (!newfilename)Application->MessageBox("This file can't be created!","Error",16);
else
{
Application->MessageBox("New dictionary is succesfully created","",0);
NewDicForm->Visible = false;}
}
//---------------------------------------------------------------------------
void __fastcall TNewDicForm::Edit1Change(TObject *Sender)
{
if (Edit1->Text != "") BitBtn1->Enabled = true;
else BitBtn1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TNewDicForm::Button2Click(TObject *Sender)
{
NewDicForm->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TNewDicForm::FormActivate(TObject *Sender)
{
if (Edit1->Text != "") BitBtn1->Enabled = true;
else BitBtn1->Enabled = false;

}
//---------------------------------------------------------------------------