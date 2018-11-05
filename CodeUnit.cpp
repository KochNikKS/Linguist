//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "CodeUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCodeForm *CodeForm;
static int Counter = 0;
extern bool TeacherMode;
extern char ProtectiveCode[1000];
//---------------------------------------------------------------------------
__fastcall TCodeForm::TCodeForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCodeForm::FormShow(TObject *Sender)
{
MainForm->Enabled = false;
MaskEdit1->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TCodeForm::FormHide(TObject *Sender)
{
MainForm->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCodeForm::BitBtn1Click(TObject *Sender)
{
if (strcmpi(MaskEdit1->Text.c_str(), ProtectiveCode)==0)
{TeacherMode = true;CodeForm->Hide();}
else {TeacherMode = false; Counter++;
Application->MessageBox("Incorrect code","Error",MB_OK|MB_ICONERROR);
if (Counter>=3)Application->Terminate();
CodeForm->Hide();
}
}
//---------------------------------------------------------------------------

void __fastcall TCodeForm::BitBtn2Click(TObject *Sender)
{
CodeForm->Hide();        
}
//---------------------------------------------------------------------------

