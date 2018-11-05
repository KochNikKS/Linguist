//---------------------------------------------------------------------------
#pragma hdrstop
#include "fstream.h"
#include "Intrfc.h"
#include "MainUnit.h"
#include "ResUnit.h"
#include "NewDicUnit.h"
#include "ChngUnit.h"
#include "FindUnit.h"
#include "ExamUnit.h"
#include "SelUnit.h"
#include "List.h"
//#include "Manual.h"
#include <vcl\vcl.h>
extern bool Modified;
extern char *DictName;
extern DicList *Dictionary;
extern char USER[1000];
//---------------------------------------------------------------------------
void InterfaceColor(int color)
{
MainForm->Color = color;
MainForm->Panel4->Color = color;
NewDicForm->Color = color;
ChngForm->Color = color;
FindForm->Color = color;
ExamForm->Color = color;
//ManualForm->Color = color;
SelForm->Color =  color;
ResForm->Color = color;

}

void InterfaceFont(TFont *fnt)
{
MainForm->Font = fnt;
NewDicForm->Font = fnt;
ChngForm->Font = fnt;
FindForm->Font = fnt;
ExamForm->Font = fnt;
//ManualForm->Font = fnt;
SelForm->Font = fnt;
ResForm->Font = fnt;
}

void OutputColor(int color)
{
MainForm->ListBox1->Color =color;
FindForm->Edit1->Color =color;
ChngForm->Edit1->Color =color;
ChngForm->Edit2->Color =color;
NewDicForm->Edit1->Color =color;
NewDicForm->DirListBox1->Color =color;
//ExamForm->Edit1->Color =color;
//ManualForm->Memo1->Color =color;
//ManualForm->TreeView1->Color = color;
/*
MainForm->Edit1->Color = color;
MainForm->Edit3->Color = color;
MainForm->Edit2->Color = color;*/
MainForm->Edit4->Color = color;
SelForm->ListBox1->Color = color;
SelForm->ListBox2->Color = color;
ResForm->Memo1->Color = color;
ResForm->Edit1->Color = color;
ExamForm->CheckListBox1->Color = color;
}

void OutputFont(TFont *f)
{
MainForm->ListBox1->Font = f;
FindForm->Edit1->Font = f;
ChngForm->Edit1->Font = f;
ChngForm->Edit2->Font = f;
NewDicForm->Edit1->Font = f;
NewDicForm->DirListBox1->Font = f;
ExamForm->Edit1-> Font = f;
//ExamForm->Memo1-> Font = f;
//ManualForm->Memo1->Font = f;
//ManualForm->TreeView1->Font = f;
/*MainForm->Edit1->Font = f;
MainForm->Edit3->Font = f;
MainForm->Edit2->Font = f;*/
MainForm->Edit4->Font = f;
SelForm->ListBox1->Font = f;
SelForm->ListBox2->Font = f;
ResForm->Memo1->Font = f;
ResForm->Edit1->Font = f;
ExamForm->CheckListBox1->Font = f;
}

void FModified()
{
if (Modified==true)
{
MainForm->Save1->Enabled = true;
MainForm->Saveas1->Enabled = true;
MainForm->SaveB->Enabled = true;
}
if (Modified==false)
{
MainForm->Save1->Enabled = false;
//MainForm->Saveas1->Enabled = false;
MainForm->SaveB->Enabled = false;
}
MainForm->StatusBar1->Panels->Items[1]->Text = DictName;
}

void SetUnLoadEnviroment()
{
//MainForm->Panel2->Visible = false;
MainForm->Edit->Enabled = false;
MainForm->R1->Enabled = false;
MainForm->R2->Enabled = false;
MainForm->ToolButton14->Enabled = false;
MainForm->Reload1->Enabled = false;
MainForm->Printdic->Enabled  = false;
MainForm->Deletedic->Enabled = false;
MainForm->StatusBar1->Panels->Items[1]->Text = "";
MainForm->StatusBar1->Panels->Items[3]->Text = "";
MainForm->Button1->Enabled = false;
MainForm->Copy2->Enabled = false;
MainForm->Addfrombuffer2->Enabled = false;
MainForm->Viewstring1->Enabled = false;
MainForm->Find2->Enabled = false;
MainForm->Change2->Enabled = false;
MainForm->Newstring1->Enabled = false;
MainForm->Invert2->Enabled = false;
MainForm->Delete2->Enabled = false;
MainForm->ListBox1->Enabled = false;
MainForm->ListBox1->Visible = false;

//MaimForm->SaveB->Enabled = false;
MainForm->DelB->Enabled = false;
MainForm->ToolButton6->Enabled = false;
MainForm->ToolButton4->Enabled = false;
MainForm->ToolButton5->Enabled = false;
MainForm->ToolButton7->Enabled = false;
MainForm->ToolButton9->Enabled = false;
MainForm->ToolButton10->Enabled = false;
MainForm->ToolButton11->Enabled = false;
MainForm->ToolButton12->Enabled = false;
MainForm->ToolButton8->Enabled = false;
MainForm->Saveas1->Enabled = false;
MainForm->Copy_paste_timer->Enabled = false;
}


void SetLoadEnviroment()
{
MainForm->Edit->Enabled = true;
MainForm->R1->Enabled = true;
MainForm->R2->Enabled = true;
MainForm->ToolButton14->Enabled = true;
MainForm->Reload1->Enabled = true;
MainForm->Printdic->Enabled  = true;
MainForm->Deletedic->Enabled = true;
MainForm->StatusBar1->Panels->Items[1]->Text = DictName;
char *p="";itoa(Dictionary->GetCounter(),p,10);
MainForm->StatusBar1->Panels->Items[3]->Text = p;
MainForm->Button1->Enabled = true;
MainForm->Copy2->Enabled = true;
MainForm->Addfrombuffer2->Enabled = true;
MainForm->Viewstring1->Enabled = true;
MainForm->Find2->Enabled = true;
MainForm->Change2->Enabled = true;
MainForm->Newstring1->Enabled = true;
MainForm->Invert2->Enabled = true;
MainForm->Delete2->Enabled = true;
MainForm->ListBox1->Enabled = true;
MainForm->ListBox1->Visible = true;
MainForm->Saveas1->Enabled = true;
//MaimForm->SaveB->Enabled = true;
MainForm->DelB->Enabled = true;
MainForm->ToolButton6->Enabled = true;
MainForm->ToolButton4->Enabled = true;
MainForm->ToolButton5->Enabled = true;
MainForm->ToolButton7->Enabled = true;
MainForm->ToolButton9->Enabled = true;
MainForm->ToolButton10->Enabled = true;
MainForm->ToolButton11->Enabled = true;
MainForm->ToolButton12->Enabled = true;
MainForm->ToolButton8->Enabled = true;
MainForm->Copy_paste_timer->Enabled = true;
}

void ClipBoard_Empty(){MainForm->Addfrombuffer1->Enabled = false;MainForm->Addfrombuffer2->Enabled = false;MainForm->ToolButton12->Enabled  = false;}
void ClipBoard_Full (){MainForm->Addfrombuffer1->Enabled = true; MainForm->Addfrombuffer2->Enabled = true; MainForm->ToolButton12->Enabled  = true;}

void SetStartSettings()
{
ifstream fname;
fname.open("interface.cfg");
int  col=0;
char buffer[100] = "";
TFont *fnt = new TFont();


	if (fname)
	{
    fname.getline(buffer,1000,'\n');
    col = atoi(buffer);InterfaceColor(col);

    fname.getline(buffer,1000,'\n');fnt->Name = buffer;
    fname.getline(buffer,1000,'\n'); col = atoi(buffer);
    fnt->Size = col;
    fname.getline(buffer,1000,'\n');col = atoi(buffer);
    fnt->Color = col;
    InterfaceFont(fnt);

    fname.getline(buffer,1000,'\n');
    col = atoi(buffer);OutputColor(col);

    fname.getline(buffer,1000,'\n');fnt->Name = buffer;

    fname.getline(buffer,1000,'\n'); col = atoi(buffer);
    fnt->Size = col;
    fname.getline(buffer,1000,'\n');col = atoi(buffer);
    fnt->Color = col;
    //fname.getline(buffer,1000,'\n');col = atoi(buffer);
    //fnt->Style = col;

    OutputFont(fnt);

   	}
    char path[1000]="";
    strcpy (path, ReturnDir(12));
    strcat (path, "\\u.usr");
    ifstream fn (path);
    int num = 0;
    while (fn>>num){strcat(USER,convert_i_a(num));}


}
