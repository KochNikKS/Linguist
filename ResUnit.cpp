//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream.h>
#pragma hdrstop

#include "ResUnit.h"
#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "piereg"
#pragma resource "*.dfm"
TResForm *ResForm;
int pos = 0;
int Mist = 0;
int Corr = 0;


void GetRec(int position)
{
Mist = 0;
Corr = 0;
char bb[5000]="";
strcat(bb, ReturnDir(12));
strcat(bb, "\\rs.sv");
ifstream fl(bb);
int y = 0;
int i = 0;
char buf [5000]="";
char *MBuf="";
fl >> i;
if (i!= -327)
{Application->MessageBox("Error in file          ","",MB_ICONERROR|MB_OK );
return;}

while (y<position)
{
ResForm->Memo1->Clear();
        do
        {
        strcpy(buf,"");
        i=0;
        while (i!= 364 && !fl.eof()){fl >>i;strcat(buf, convert_i_a(i));}
        if (strcmp(buf,"[end]")!=0 )ResForm->Memo1->Lines->Add(buf);

        MBuf = StrPos(buf, "(");
        if (MBuf){MBuf++;strncpy(MBuf, MBuf, strlen(MBuf-2));Mist = atoi(MBuf);}

        }while (strcmp(buf,"[end]")!=0 && !fl.eof());

                if (fl.eof())
                {Application->MessageBox("There is no record with such number","",MB_OK|MB_ICONERROR);
                ResForm->Edit1->Text = y;
                GetRec(y);
                return ;}

        strcpy(buf,"");
        y++;
}




ResForm->Pie1->Angles->EndAngle = Mist * 3.6;
Corr = 100 - Mist;
if (ResForm->Pie1->Angles->EndAngle == ResForm->Pie1->Angles->StartAngle) ResForm->Pie1->Visible = false;
ResForm->Panel2->Caption = Mist;
ResForm->Panel1->Caption = Corr;
}
//---------------------------------------------------------------------------
__fastcall TResForm::TResForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TResForm::Button1Click(TObject *Sender)
{
ResForm->Pie1->Angles->EndAngle = 0;
ResForm->Pie1->Angles->StartAngle = 0;
GetRec(Edit1->Text.ToIntDef(0));
}
//---------------------------------------------------------------------------

void __fastcall TResForm::BitBtn2Click(TObject *Sender)
{
pos++;
Edit1->Text = pos;
ResForm->Pie1->Angles->EndAngle = 0;
ResForm->Pie1->Angles->StartAngle = 0;
GetRec(Edit1->Text.ToIntDef(0));
}
//---------------------------------------------------------------------------

void __fastcall TResForm::BitBtn1Click(TObject *Sender)
{
if (pos > 1 )pos--;
Edit1->Text = pos;
ResForm->Pie1->Angles->EndAngle = 0;
ResForm->Pie1->Angles->StartAngle = 0;
GetRec(Edit1->Text.ToIntDef(0));

}
//---------------------------------------------------------------------------



