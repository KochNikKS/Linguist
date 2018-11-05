//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "List.h"
#include "SelUnit.h"
#include "MainUnit.h"
#include "ExamUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Menus"
#pragma resource "*.dfm"
TSelForm *SelForm;
extern DicList *Dictionary;
extern DicList *TestDic;

//---------------------------------------------------------------------------
__fastcall TSelForm::TSelForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TSelForm::ListBox2Click(TObject *Sender)
{
SpeedButton1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSelForm::ListBox1Click(TObject *Sender)
{
SpeedButton2->Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TSelForm::FormKeyPress(TObject *Sender, char &Key)
{
//exit(0);
//if (Key = (int)13)ActionList1->ExecuteAction(Action1);
}
//---------------------------------------------------------------------------

void __fastcall TSelForm::Action1Execute(TObject *Sender)
{
if (ListBox2->SelCount==1)
{
TestDic->Add(Dictionary->GetText(ListBox2->ItemIndex));
ListBox1->Items->Add(Dictionary->GetText(ListBox2->ItemIndex));
}
if (ListBox2->SelCount>1)
{
        if (ListBox2->Selected[ListBox2->ItemIndex-1])
        {
        int pos = 0;
        while (pos < ListBox2->SelCount)
               {
                TestDic->Add(Dictionary->GetText(ListBox2->ItemIndex-pos));
                ListBox1->Items->Add(Dictionary->GetText(ListBox2->ItemIndex-pos));
                pos++;
               }

        }

        if (ListBox2->Selected[ListBox2->ItemIndex+1])
        {
        int pos = 0;
        while (pos < ListBox2->SelCount)
               {
                TestDic->Add(Dictionary->GetText(ListBox2->ItemIndex+pos));
                ListBox1->Items->Add(Dictionary->GetText(ListBox2->ItemIndex+pos));
                pos++;
               }

        }


}


}
//---------------------------------------------------------------------------

void __fastcall TSelForm::Action2Execute(TObject *Sender)
{

if (TestDic->GetCounter()>0)
{TestDic->Delete(ListBox1->ItemIndex);
ListBox1->Items->Delete(ListBox1->ItemIndex);}

}
//---------------------------------------------------------------------------






void __fastcall TSelForm::BitBtn1Click(TObject *Sender)
{
TestDic->ClearList();
ListBox1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TSelForm::BitBtn2Click(TObject *Sender)
{
SelForm->Visible = false;
ExamForm->Visible = true;        
}
//---------------------------------------------------------------------------

void __fastcall TSelForm::FormHide(TObject *Sender)
{
MainForm->Enabled = true;
MainForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TSelForm::BitBtn3Click(TObject *Sender)
{
SelForm->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSelForm::FormShow(TObject *Sender)
{
SelForm->SpeedButton1->Enabled = false;
SelForm->SpeedButton2->Enabled = false;
SelForm->ListBox1->Clear();
SelForm->ListBox2->Clear();

}
//---------------------------------------------------------------------------



