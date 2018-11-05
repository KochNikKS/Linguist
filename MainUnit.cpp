//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <vcl\printers.hpp>
#include <vcl\clipbrd.hpp>
#include <Dialogs.hpp>
#include <fstream.h>
#include <stdio.h>
#include <dos.h>
#pragma  hdrstop
#include "Intrfc.h"
#include "ChngUnit.h"
#include "MainUnit.h"
#include "NewDicUnit.h"
#include "FindUnit.h"
#include "AboutUnit.h"
#include "StartUnit.h"
#include "ExamUnit.h"
#include "CodeUnit.h"
#include "SelUnit.h"
#include "RegUnit.h"
#include "ResUnit.h"
#include "Intrfc.h"
#include "List.h"
#include "POptUnit.h"
#include "Manual.h"
//---------------------------------------------------------------------------
#pragma link "Grids"
#pragma resource "*.dfm"
TMainForm *MainForm;
TCursor crHandCur = -21;
bool TeacherMode = false;
bool REG_MARKER = false;
bool EXAMINATION = false;

char *DictName="";
char *flDictName="";
DicList *Dictionary=new DicList(2000);
DicList *TestDic=new DicList(2000);
DicList *ErrDic=new DicList(2000);

int IC = 0,  OC = 0;
TFont *IF = new TFont(), *OF = new TFont();

bool LoadFlag =false, Modified=false;
int STATUS = 0;
struct  time t;
TClipboard *BUFFER = new TClipboard();

char USER[1000] = "";
char ProtectiveCode[1000]="";
char SEC_USER[1000]="";
//*****************************************************************************
bool LoadDictionary(char j[]);
void UnLoadDictionary();
void ShowDictionary();

bool TestMode()
{
if (!TeacherMode)                     
{Application->MessageBox("In the mode of the limited access\n such opportunities are not given","Access error", MB_OK|MB_ICONERROR);
return false;}
else return true;
}

bool TestMode(bool marker)
{
if (!TeacherMode)
{
if (marker)Application->MessageBox("In the mode of the limited access\n such opportunities are not given","Access error", MB_OK|MB_ICONERROR);
return false;}
else return true;
}


bool LoadDictionary(char *name)
{
ifstream RFile(name);
bool ret = true;
if (!RFile){Mes("File can't be open", "Access error",16);
Modified  = false;RFile.close();return false;}
else
{
RFile.close();
Dictionary->SetDicName(name);
//MainForm->Panel4->Caption = "Loading dictionary . . .";
MainForm->Panel4->Visible = true;MainForm->Panel4->Repaint();

char AS[2000]=""; int counter=0;
int status = 1;
while (status!=-1 && ret)
{
status = RLF(name,AS,counter);
if (status == 1){Dictionary->Add(AS);ret = true;}
if (status == 0) {Mes("Error in file or incorrect file format","Readings error",16);ret = false;}
}

LoadFlag = true;
//MainForm->Panel4->Caption = "Sorting dictionary . . .";
MainForm->Panel4->Repaint();
Dictionary->Sorter();
//MainForm->Panel4->Caption = "Loading dictionary . . .";
MainForm->Panel4->Repaint();
MainForm->Panel4->Visible = false;
Modified  = false;
//MainForm->ListBox1->Visible = true;
return ret;

}

}//end of function


void ShowDictionary()
{
int i = 0;
MainForm->ListBox1->Clear();
while (i < Dictionary->GetCounter())
{char buf[2050]="";
if (strlen(Dictionary->GetText(i))>0)
{itoa(i+1,buf,10);strcat(buf,"  ");
strcat(buf,Dictionary->GetText(i));
MainForm->ListBox1->Items->Add(buf);}
i++;}
i = Dictionary->GetCounter();
char b[1000] = "";itoa (i,b,10);
MainForm->StatusBar1->Panels->Items[3]->Text = b;
}




void UnLoadDictionary()
{
Dictionary->ClearList();
MainForm->ListBox1->Clear();
//MainForm->ListBox1->Visible = false;
Modified = false;

}


//void Random(int begin, int end, int counter){}

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{Screen->Cursors[crHandCur] = LoadCursor(HInstance, "HandCur");
Screen->Cursor = crHandCur;MainForm->Caption = "";
randomize();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Newdictionary1Click(TObject *Sender)
{if (!TestMode()) return;NewDicForm->Visible = true;}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Loaddictionary1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{if (LoadFlag ) {UnLoadDictionary();}
DictName = MainForm->OpenDialog1->FileName.c_str();
if (LoadDictionary(DictName)>0){ShowDictionary();FModified();SetLoadEnviroment();}
}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeletedicClick(TObject *Sender)
{if (!TestMode()) return;
if (Application->MessageBox("Are you sure?","",1)==1){remove (DictName);
UnLoadDictionary();FModified(); SetUnLoadEnviroment();
}}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Viewstring1Click(TObject *Sender)
{Application->MessageBox(Dictionary->GetText(ListBox1->ItemIndex),"",0);}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Reload1Click(TObject *Sender)
{if (LoadFlag) {UnLoadDictionary();}LoadDictionary(DictName);ShowDictionary();
FModified();}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintdicClick(TObject *Sender)
{if (!TestMode()) return;
POptForm->Visible = true;
MainForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Change1Click(TObject *Sender)
{
if (!TestMode())return;
STATUS = 1;
ChngForm->Edit1->Text = Dictionary->GetTextL(ListBox1->ItemIndex);
ChngForm->Edit2->Text = Dictionary->GetTextR(ListBox1->ItemIndex);
ChngForm->Visible = true;
}                                                  
//---------------------------------------------------------------------------
void __fastcall TMainForm::Copy1Click(TObject *Sender)
{
if (!TestMode())return;
if (ListBox1->SelCount == 1){ BUFFER->SetTextBuf(Dictionary->GetText(ListBox1->ItemIndex));}

if (ListBox1->SelCount>1)
{ //1
int SelVector =0;
if (ListBox1->ItemIndex>0 && ListBox1->ItemIndex < Dictionary->GetCounter()-1)
{
if (ListBox1->Selected[ListBox1->ItemIndex - 1]) SelVector = -1;
if (ListBox1->Selected[ListBox1->ItemIndex + 1]) SelVector =  1;
}
if (ListBox1->ItemIndex==0) {SelVector =1;}
if (ListBox1->ItemIndex==Dictionary->GetCounter()-1){ SelVector =-1;}

int i = 0; char buf[2000]="";
//ListBox2->Clear();
Memo1->Clear();
while (abs(i)< ListBox1->SelCount)
{
strcat(buf,Dictionary->GetText(ListBox1->ItemIndex+i));
strcat(buf," ;");
Memo1->Lines->Add(buf);
i+=SelVector;
strcpy(buf,"");
}

Memo1->SelectAll(); Memo1->CopyToClipboard();
}//1


}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Addfrombuffer1Click(TObject *Sender)
{
if (!TestMode())return;
Memo1->Clear();
Memo1->PasteFromClipboard();
char buf[2000]=" ";

int i = 0, n = 0, counter = 0;
while (strlen(buf)>0 && buf[0] != '\n')
{//if (counter){}
strncpy(buf,strcut(Memo1->Lines->Text.c_str(),n,';',i),2000);n = i+1;
Dictionary->Add(buf);
strncpy(buf,strcut(Memo1->Lines->Text.c_str(),n,'\n',i),2000);n = i+1;
counter++;}

Dictionary->Sorter();
ShowDictionary();
Modified = true;
FModified();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Invert1Click(TObject *Sender)
{
if (!TestMode())return;
//MainForm->Panel4->Caption = "Processing . . .";
MainForm->Panel4->Visible = true;
MainForm->Panel4->Repaint();
//char buf1[10000]="", buf2[10000]="";//, buf3[10000]="",
char res[10000] = "";
int SelVector =0;
if (ListBox1->ItemIndex>0 && ListBox1->ItemIndex < Dictionary->GetCounter()-1)
{
if (ListBox1->Selected[ListBox1->ItemIndex - 1]) SelVector = -1;
if (ListBox1->Selected[ListBox1->ItemIndex + 1]) SelVector =  1;
}
if (ListBox1->ItemIndex==0) {SelVector =1;}
if (ListBox1->ItemIndex==Dictionary->GetCounter()-1){ SelVector =-1;}

int i =0;
while (i<ListBox1->SelCount)
{
strcpy(res, Dictionary->GetTextR(MainForm->ListBox1->ItemIndex+i*SelVector));
strcat(res," ~ " );
strcat(res,Dictionary->GetTextL(MainForm->ListBox1->ItemIndex+i*SelVector));
Dictionary->ChangeText(res,ListBox1->ItemIndex+i*SelVector);
i++;
}
//MainForm->Panel4->Caption = "Sorting dictionary . . .";
MainForm->Panel4->Repaint();
Dictionary->Sorter();
//MainForm->Panel4->Caption = "Processing . . .";
MainForm->Panel4->Repaint();
ShowDictionary();Modified=true;FModified();
MainForm->Panel4->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Delete1Click(TObject *Sender)
{
if (!TestMode())return;
if (ListBox1->SelCount == 1){Dictionary->Delete(ListBox1->ItemIndex);ShowDictionary();}

if (ListBox1->SelCount > 1)
{
int SelVector =0;

if (ListBox1->ItemIndex>0 && ListBox1->ItemIndex < Dictionary->GetCounter()-1)
{
if (ListBox1->Selected[ListBox1->ItemIndex - 1]) SelVector = -1;
if (ListBox1->Selected[ListBox1->ItemIndex + 1]) SelVector =  0;
}
if (ListBox1->ItemIndex==0) {SelVector =0;}
if (ListBox1->ItemIndex==Dictionary->GetCounter()-1){ SelVector =-1;}

int i =0;
while (i<ListBox1->SelCount)
{Dictionary->Delete(ListBox1->ItemIndex+i*SelVector);i++;}
ShowDictionary();Modified = true; FModified();
}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Save1Click(TObject *Sender)
{
if (!TestMode()) return;
ofstream FName(DictName,ios::out);
if (FName)
{
int i =0; char *buf ="";

while (i<Dictionary->GetCounter())
{
buf = Dictionary->GetText(i);

int spos = 0;
while (spos <= strlen(buf))
{
int ff = convert_a_i(buf[spos]);
if(ff)FName << ff<< endl;
spos++;
}
i++;
}

Modified = false;FModified();
}
else Application->MessageBox("File isn't accessible","Error",16);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Saveas1Click(TObject *Sender)
{
if (!TestMode()) return;
if (SaveDialog1->Execute())
{
char jj[1000] = "";
strncpy(jj,SaveDialog1->FileName.c_str(),1000);
strcpy(jj, strtok(jj,"."));
if (strlen(jj)<1) {strcpy(jj,"Buffer");}
strcat(jj,".ldf");
ofstream FName(jj,ios::out);
if (FName)
{
int i =0; char *buf ="";
while (i<Dictionary->GetCounter())
{
buf = Dictionary->GetText(i);

int spos = 0;
while (spos <= strlen(buf))
{
int ff = convert_a_i(buf[spos]);
if(ff)FName << ff<< endl;
spos++;
}
i++;
}
Modified = false;FModified();
strcpy(DictName,SaveDialog1->FileName.c_str());
MainForm->StatusBar1->Panels->Items[1]->Text = DictName;
}else Application->MessageBox("File isn't accessible","Error",16);

}

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Find1Click(TObject *Sender)
{
FindForm->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::About1Click(TObject *Sender)
{
AboutForm->Visible= true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::New1Click(TObject *Sender)
{
if (!TestMode())return;
STATUS = 2;
ChngForm->Visible = true;
FModified();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Options1Click(TObject *Sender)
{
ListBox1->Enabled = false;
ToolBar1->Enabled = false;
ToolBar2->Enabled = false;

PageControl1->Visible = true;
}
//---------------------------------------------------------------------------}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
PageControl1->Visible = false;
ListBox1->Enabled = true;
ToolBar1->Enabled = true;
ToolBar2->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
MainForm->Visible = false;
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
Modified = false;
FModified();
SetUnLoadEnviroment();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Copy_paste_timerTimer(TObject *Sender)
{
if (ListBox1->SelCount > 0 )
{Copy1->Enabled = true;Copy2->Enabled = true;Btn7->Enabled= true;}
else{Copy1->Enabled = false;Copy2->Enabled = false;Btn7->Enabled= false;}
if (BUFFER->HasFormat(CF_TEXT))ClipBoard_Full();else{ClipBoard_Empty();}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Converter1Click(TObject *Sender)
{
Converter->DoVerb(ovPrimary);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn3Click(TObject *Sender)
{
Edit3->Text = "";
Edit1->Text = "";
RadioButton3->Checked = true;
RadioButton1->Checked = false;
CheckBox1->Checked = true;
CheckBox2->Checked = true;
CheckBox4->Checked = false;
CheckBox5->Checked = false;
PageControl1->Visible = false;
ListBox1->Enabled = true;
ToolBar1->Enabled = true;
ToolBar2->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BitBtn5Click(TObject *Sender)
{

ColorDialog1->Execute();Panel3->Color =ColorDialog1->Color; 
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn6Click(TObject *Sender)
{

FontDialog1->Execute();Label3->Font = FontDialog1->Font;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn7Click(TObject *Sender)
{

ColorDialog2->Execute();Panel5->Color = ColorDialog2->Color; 
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn8Click(TObject *Sender)
{

FontDialog2->Execute();
Label4->Font = FontDialog2->Font;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Action1Execute(TObject *Sender)
{
char t[5000] = "";
strcpy(t,ReturnDir(12));
strcat(t,"manual\\Linguist.hlp");
WinHelp(MainForm->Handle,t,HELP_CONTEXT,999 );
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RadioButton3Click(TObject *Sender)
{
Edit3->Enabled = true;
Edit1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RadioButton4Click(TObject *Sender)
{
Edit1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::R1Click(TObject *Sender)
{
if (!TeacherMode) strcpy(SEC_USER, InputBox("Enter your name:", "","Unnamed").c_str());
MainForm->Enabled = false;
MainForm->Visible = false;

char *h = "";

int begin = Edit3->Text.ToIntDef(0);
int end = Edit2->Text.ToIntDef(0);
int am = 0;
int direction = 0;
int selection = 0;


if (begin <= 1) begin = 1;
if (begin > Dictionary->GetCounter()-1)     begin = 1;
begin--;
if (end   <= begin) end = begin + 1;
if (end   > Dictionary->GetCounter()) end = Dictionary->GetCounter();
//begin + 1;

if (Edit1->Enabled == true) am = Edit1->Text.ToIntDef(end-begin); else am = end-begin;
if (am > (end-begin))am = end - begin;

SelForm->SpeedButton1->Enabled = false;
SelForm->SpeedButton2->Enabled = false;
SelForm->ListBox1->Clear();
SelForm->ListBox2->Clear();


while (begin < end && begin < am )
{TestDic->Add(Dictionary->GetText(begin));
SelForm->ListBox1->Items->Add(Dictionary->GetText(begin));begin+=1;}
int i = 0;
while (i < Dictionary->GetCounter())
{SelForm->ListBox2->Items->Add(Dictionary->GetText(i));i++;}

EXAMINATION = false;
if(CheckBox5->Checked == true) SelForm->Visible = true;
else ExamForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Actions1Click(TObject *Sender)
{
MainForm->R1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BitBtn10Click(TObject *Sender)
{
if (!TestMode()) return;
char dirbuf[2000]="";
strcpy(dirbuf,ReturnDir(12));strcat(dirbuf,"\\");strcat(dirbuf,"interface.cfg");
ofstream OptFile (dirbuf);
IC=ColorDialog1->Color;
IF=FontDialog1->Font;
OC=ColorDialog2->Color;
OF=FontDialog2->Font;

if (OptFile)
{
      OptFile << IC <<endl;
      OptFile << IF->Name.c_str()  << endl<< IF->Size  << endl<< IF->Color << endl;
      OptFile << OC <<endl;
      OptFile << OF->Name.c_str()  << endl << OF->Size  << endl<< OF->Color << endl;
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn8MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
BitBtn2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
BitBtn2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PageControl4Change(TObject *Sender)
{
PageControl1->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BitBtn2Click(TObject *Sender)
{
IC=ColorDialog1->Color;
IF=FontDialog1->Font;
OC=ColorDialog2->Color;
OF=FontDialog2->Font;
InterfaceColor(IC);
InterfaceFont(IF);
OutputColor(OC);
OutputFont(OF);
//PageControl1->Visible = false;
//ListBox1->Enabled = true;
//ToolBar1->Enabled = true;
//ToolBar2->Enabled = true;
//MainMenu1->Enabled = true;
}
//---------------------------------------------------------------------------






void __fastcall TMainForm::ListBox1KeyPress(TObject *Sender, char &Key)
{
TObject *a;
if (Key == (int)32)Change1Click(a);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CheckBox3Click(TObject *Sender)
{
CheckBox4->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CheckBox4Click(TObject *Sender)
{
CheckBox3->Checked = false;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ExitBClick(TObject *Sender)
{
TObject*a;
if (Modified)
{
int n = Application->MessageBox("Do You want to save changes?","Linguist 2000 LE",35/*3*/);
switch (n)
{
case 7: exit(0);break;
case 6: Save1Click(a);exit(0);break;
case 2: break;
}

}else {exit(0);}
       
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MinBClick(TObject *Sender)
{
Application->Minimize();
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ToolButton14MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
PopupMenu2->Popup(X+MainForm->Left+50,Y+MainForm->Top+40);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::R2Click(TObject *Sender)
{
randomize();
if (!TeacherMode) strcpy(SEC_USER, InputBox("Enter your name:", "","Unnamed").c_str());
MainForm->Enabled = false;
MainForm->Visible = false;

int begin = Edit3->Text.ToIntDef(0);
int end = Edit2->Text.ToIntDef(0);
int am = 0;
int direction = 0;
int selection = 0;

if (begin <= 1) begin = 1;
if (begin > Dictionary->GetCounter()-1)     begin = 1;
begin--;
if (end   <= begin) end = begin + 1;
if (end   > Dictionary->GetCounter()) end = Dictionary->GetCounter();


if (Edit1->Enabled == true) am = Edit1->Text.ToIntDef(end-begin);
else am = end-begin;
if (am > end - begin) am = end - begin;

SelForm->SpeedButton1->Enabled = false;
SelForm->SpeedButton2->Enabled = false;
SelForm->ListBox1->Clear();
SelForm->ListBox2->Clear();

if (RadioButton3->Checked)
{int i=begin;
while (i < end){TestDic->Add(Dictionary->GetText(i));
SelForm->ListBox1->Items->Add(Dictionary->GetText(i));
i++;}
}

if (RadioButton5->Checked)
{int i = end;
while (i >= begin){TestDic->Add(Dictionary->GetText(i));
SelForm->ListBox1->Items->Add(Dictionary->GetText(i));
i--;}
}

if (RadioButton4->Checked)
{int i = 0;int y = 0;
while (i <  am){y = random(end-begin)+begin;
if (TestDic->AddIFNF(Dictionary->GetText(y) )) i++;}
}
EXAMINATION = true;
ExamForm->Visible = true ;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::STARTExecute(TObject *Sender)
{
Timer2->Enabled = false;
MainForm->Show();

char bb[5000]="";strcat(bb, ReturnDir(12));strcat(bb, "\\rs.sv");ifstream fl(bb);
int i = 0;fl >> i;
if (i!= -327)
{Application->MessageBox("Program LINGUIST 2002 LE will be closed","Error in results file",MB_ICONERROR|MB_OK );
Application->Terminate();}



StartForm->Hide();
SetStartSettings();

  char path[1000]="";
    strcpy (path, ReturnDir(12));
    strcat (path, "\\cde.sv");
    ifstream fn (path);
    if (!fn)
    {Application->MessageBox("Program LINGUIST 2002 LE will be closed","Error in code file",MB_ICONERROR|MB_OK );
    Application->Terminate();}
       int num = 0;
    int marker = -1;

    while (fn>>num)
    {
    if (num == 313) {marker*=-1; }
    if (marker  == 1)strcat(ProtectiveCode,convert_i_a(num));
    }
    if (strlen(ProtectiveCode)<1)
    {
        Application->MessageBox("Program LINGUIST 2002 LE will be closed","Error in code file",MB_ICONERROR|MB_OK );
        Application->Terminate();
    }

if (strlen(ParamStr(ParamCount()-ParamCount()+1).c_str())>0)
{
strcpy(DictName,ParamStr(ParamCount()-ParamCount()+1).c_str());
if (LoadDictionary(DictName)>0){ShowDictionary();FModified();SetLoadEnviroment();}
}

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Newuser1Click(TObject *Sender)
{
RegForm->Visible = true;
RegForm->MaskEdit1->Text = "";
}
//---------------------------------------------------------------------------





void __fastcall TMainForm::Allowediting1Click(TObject *Sender)
{
CodeForm->Visible = true;
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::Clear1Click(TObject *Sender)
{
if (!TestMode()) return;        
if (Application->MessageBox("Do You really want to clear file?","",MB_YESNO|MB_ICONQUESTION)==6)
{char bb[5000]="";
strcat(bb, ReturnDir(12));
strcat(bb, "\\rs.sv");
ofstream fl(bb);
fl << -327<<endl;
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Show1Click(TObject *Sender)
{
ResForm->Visible = true;        
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BitBtn11Click(TObject *Sender)
{
if (ListBox1->Visible==true)MainForm->ListBox1->Visible = false;
 else MainForm->ListBox1->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RadioButton5Click(TObject *Sender)
{
Edit1->Enabled = false;
}
//---------------------------------------------------------------------------





