//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream.h>
#pragma hdrstop
#include "MainUnit.h"
#include "RegUnit.h"
#include "list.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRegForm *RegForm;
extern char USER[1000];
extern bool REG_MARKER;
extern bool TeacherMode;
extern char ProtectiveCode[1000];
//---------------------------------------------------------------------------
__fastcall TRegForm::TRegForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TRegForm::MaskEdit1Change(TObject *Sender)
{
        if (strcmp(ProtectiveCode, MaskEdit1->Text.c_str())==0)
        {Edit1->Enabled = true;
        Button1->Enabled = true;}
       else
       {Edit1->Enabled = false;
        Button1->Enabled = false;}

}
//---------------------------------------------------------------------------
void __fastcall TRegForm::Button1Click(TObject *Sender)
{
char h[1000]="";
strcpy (h,Edit1->Text.c_str());
strcpy(USER, h);
    char path[1000]="";
    strcpy (path, ReturnDir(12));
    strcat (path, "\\u.usr");
ofstream u_usr (path);
int  i = 0;
while (i < strlen(USER)){u_usr << convert_a_i(USER[i])<<endl; i++;}
u_usr << 364;
RegForm->Visible = false;
TeacherMode = true;
}
//---------------------------------------------------------------------------
void __fastcall TRegForm::Button2Click(TObject *Sender)
{
RegForm->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TRegForm::FormShow(TObject *Sender)
{
MainForm->Enabled = false;
Edit1->Text = USER;
}
//---------------------------------------------------------------------------

void __fastcall TRegForm::FormHide(TObject *Sender)
{
MainForm->Enabled = true;
}
//---------------------------------------------------------------------------

