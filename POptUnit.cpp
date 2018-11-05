//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <vcl\printers.hpp>
#pragma hdrstop

#include "POptUnit.h"
#include "MainUnit.h"
#include "List.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TPOptForm *POptForm;
extern DicList *Dictionary;
//---------------------------------------------------------------------------
__fastcall TPOptForm::TPOptForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPOptForm::CancelClick(TObject *Sender)
{
POptForm->Visible = false;
MainForm->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TPOptForm::OkClick(TObject *Sender)
{
int i = 0;
int u = 1;

if (MainForm->PrintDialog1->Execute())
{Printer()->Canvas->Font->Size = FontDialog1->Font->Size;
Printer()->Canvas->Font->Name=FontDialog1->Font->Name;
Printer()->Title = "Dictionary of \"Linguist 2001LE\"";
Printer()->BeginDoc();
while(i<Dictionary->GetCounter())
{
Printer()->Canvas->TextOut (50,u*FontDialog1->Font->Size*4,Dictionary->GetText(i));
i++; u++;
if ((i%Edit1->Text.ToIntDef(40))==0) {Printer()->NewPage();u=2;}
}
Printer()->EndDoc();
}

POptForm->Visible = false;
MainForm->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TPOptForm::FontClick(TObject *Sender)
{
FontDialog1->Execute(); 	
}
//---------------------------------------------------------------------------