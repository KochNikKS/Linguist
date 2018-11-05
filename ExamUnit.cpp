//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <fstream.h>
#include <dos.h>
#pragma hdrstop
#include "List.h"
#include "ExamUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TExamForm *ExamForm;
extern DicList *Dictionary;
extern DicList *TestDic;
extern DicList *ErrDic;
extern char USER[1000];
extern bool TeacherMode;
extern char SEC_USER[1000];
extern bool EXAMINATION;
extern bool TestMode();
extern bool TestMode(bool);
char Answer[1000]="", Question[1000]="", TrueAnswer[1000]="";
int QNumber = 0;
int  Amount = 0,Mistakes = 0, RightAnsw = 0;
int WasMistake = 0;
int Col = 0;
void onMistake();
bool err = false;
int EN = 0;
int AnswTime=0;

void SaveResults()
{/*

char path [1000]="";
strcpy(path, ReturnDir(12));
strcat(path, "\\rs.sv");
ofstream fname (path,ios::app);
char sv[50000]="";
char buf[100]="";
struct date DATE;getdate(&DATE);
struct time TIME;gettime(&TIME);
strcat (sv, "User: ");
if (!TestMode(false))strcat (sv, SEC_USER);else strcat (sv, USER);
strcat(sv, "\nDate: ");
itoa(DATE.da_year,buf, 10);strcat(sv, buf);strcat(sv, ":");
itoa(DATE.da_mon ,buf, 10);strcat(sv, buf);strcat(sv, ":");
itoa(DATE.da_day ,buf, 10);strcat(sv, buf);
strcat(sv, "   ");
strcat(sv, "Time: ");
itoa(TIME.ti_hour,buf, 10);strcat(sv, buf);strcat(sv, ":");
itoa(TIME.ti_min ,buf, 10);strcat(sv, buf);


strcat (sv, "\nUsed dictionary: "); strcat (sv, Dictionary->GetDicName());

strcat (sv, "\nMode: ");
if (EXAMINATION)strcat(sv, "examination");
if (!EXAMINATION)strcat(sv, "training");

strcat (sv, "\nDirection: ");
if (MainForm->CheckBox4->Checked==true) strcat(sv, "Right to left");
if (MainForm->CheckBox3->Checked==true) strcat(sv, "Random");
if (!MainForm->CheckBox4->Checked==true && !MainForm->CheckBox4->Checked==true)strcat(sv, "Left to right");

strcat (sv, "\nSelection: ");
if (MainForm->RadioButton3->Checked==true) strcat(sv, "From the first to the last");
if (MainForm->RadioButton4->Checked==true) strcat(sv, "Random selection");
if (MainForm->RadioButton5->Checked==true) strcat(sv, "From the last to the first");

itoa(Amount,buf, 10);strcat (sv, "\nAmount of expressions: "); strcat (sv, buf);

int b = 0;

itoa(RightAnsw,buf, 10);strcat (sv, "\nAmount of correct answers: "); strcat (sv, buf);
if (Amount)b = (float)RightAnsw/(float)Amount*100; else b =0;
itoa(b, buf,10); strcat(sv," (");strcat (sv, buf);strcat(sv,"%)");

itoa(Mistakes,buf, 10);strcat (sv, "\nAmount of mistakes: "); strcat (sv, buf);
if (Amount)b = (float)Mistakes/(float)Amount*100;else b = 0;
itoa(b, buf,10); strcat(sv," (");strcat (sv, buf);strcat(sv,"%)");

strcat(sv,"\n[end]\n");

int l = 0;
while (l<strlen(sv)){fname << convert_a_i(sv[l])<<"\n"; l++;}

*/}

//---------------------------------------------------------------------------
__fastcall TExamForm::TExamForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TExamForm::Button1Click(TObject *Sender)
{

if (!EXAMINATION)
{//!exam
if (err)
{
Timer3->Enabled = false;
ExamForm->Visible = false;
MainForm->Visible = true;
MainForm->Enabled = true;
SaveResults();
return;
}


if (ErrDic->GetCounter()>0 && strlen(ErrDic->GetText(0))>0
&& MainForm->RadioButton2->Checked==true)
{
Timer3->Enabled = false;
int t = Application->MessageBox("Do You want to repeat expressions with mistakes?","",MB_YESNO);
switch (t)
{
case 7:SaveResults();TestDic->ClearList();ExamForm->Visible = false;
MainForm->Visible = true;MainForm->Enabled = true;break;
case 6:Edit3->Text = "";int h = 0;TestDic->ClearList();
strcpy(Question, ErrDic->GetTextL(ErrDic->GetCounter()-1));
strcpy(TrueAnswer, ErrDic->GetTextR(ErrDic->GetCounter()-1));
Edit2->Text = Question; err=true;
Timer3->Enabled = true;break;}
}
else
{

        if (Application->MessageBox("Do You really want to finish your studying?","",MB_YESNO)==6)
        {
        Timer3->Enabled = false;
        SaveResults();
        ExamForm->Visible = false;
        MainForm->Visible = true;
        MainForm->Enabled = true;
        TestDic->ClearList();
        }

}

}//!exam
if (EXAMINATION)
{
if (QNumber > TestDic->GetCounter())
{
Timer3->Enabled = false;
SaveResults();
ExamForm->Visible = false;
MainForm->Visible = true;
MainForm->Enabled = true;
TestDic->ClearList();
}else Mes("Examination isn't finished");
}


}
//---------------------------------------------------------------------------
void __fastcall TExamForm::FormShow(TObject *Sender)
{
randomize();
MainForm->Enabled = false;
MainForm->Visible = false;
err = false;
WasMistake = 0;
QNumber = 0;
AnswTime=0;
Amount = 0;
Timer3->Enabled = false;
strcpy(Question,"");strcpy(Answer,"");strcpy(TrueAnswer,"");
Button1->Caption = (EXAMINATION)?"Finish":"Terminate";
if (MainForm->CheckBox6->Checked) AnswTime = MainForm->Edit4->Text.ToIntDef(5);
CheckListBox1->Clear();
ExamForm->Height = 147;
}
//---------------------------------------------------------------------------
void __fastcall TExamForm::Edit3Enter(TObject *Sender)
{
Edit3->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TExamForm::FormHide(TObject *Sender)
{
if (EXAMINATION && QNumber < TestDic->GetCounter())SaveResults();
ExamForm->Visible = false;
MainForm->Visible = true;
MainForm->Enabled = true;
Edit1->Text ="";
Edit3->Text ="";
Edit2->Text ="";
Amount = 0;
Button3->Caption = "Start";
Timer3->Enabled = false;
ExamForm->Height = MainForm->Height - 200;
}
//---------------------------------------------------------------------------

void __fastcall TExamForm::Action1Execute(TObject *Sender)
{
      /*if (!EXAMINATION){//*****************************************}


TObject *a;
Edit3->Text = "";
if (QNumber==0 && strcmp(Button3->Caption.c_str(),"Start")==0)
{

Edit1->Enabled = true;
if (MainForm->RadioButton5->Checked == true) QNumber = TestDic->GetCounter()-1;
if (MainForm->RadioButton4->Checked == true) QNumber = random (TestDic->GetCounter());
if (MainForm->RadioButton3->Checked == true) QNumber = 0;
GetNewQuestionExecute(a);
Edit2->Text = Question;
Button3->Caption = "Next >>";
if (MainForm->CheckBox6->Checked)Timer3->Enabled = true;
return;
}

if (err)
{//a
        if (EN > ErrDic->GetCounter())
        {//a.1
        Mes("Examination is finished");
        SaveResults();
        ErrDic->ClearList();
        MainForm->Visible = true;MainForm->Enabled = true;ExamForm->Visible = false;
        }//a.1

        Col = MainForm->Color;
        strcpy(Answer, freeUpKey(ClrSpc(Edit1->Text.c_str() )));

        if (strcmpi(TrueAnswer,Answer)==0)
        {//a.2
            //ErrDic->Delete(ErrDic->GetCounter()-1);
         strcpy(Question, ErrDic->GetTextL(EN));
         strcpy(TrueAnswer, ErrDic->GetTextR(EN));
         Edit2->Text = Question;EN++;
        }//a.2
        else{ExamForm->Color = clRed;Timer2->Enabled = true;Edit3->Text = TrueAnswer;}

}//a
else
                {//1
Amount++;
Label7->Caption = Amount;

strcpy(Answer, Edit1->Text.c_str());
Edit1->Text="";

if (strcmpi(TrueAnswer,freeUpKey(ClrSpc(Answer)))==0){WasMistake = 0;++RightAnsw;}
else{ExamForm->Edit3->Text = TrueAnswer;WasMistake = 1;++Mistakes;}

Label12->Caption = RightAnsw;
Label9->Caption = Mistakes;
Label16->Caption = int((float)RightAnsw/(float)Amount *100);
Label17->Caption = int((float)Mistakes/(float)Amount*100);

switch (WasMistake)
{
case 0:GetNewQuestionExecute(a);break;
case 1:onMistakeExecute(a);break;
}
Edit2->Text = Question;
                }//1

        }//*****************************************

if (EXAMINATION)
{//0

if (QNumber==0 && strcmp(Button3->Caption.c_str(),"Start")==0)
{//1

Edit1->Enabled = true;

if (MainForm->CheckBox4->Checked == false && MainForm->CheckBox3->Checked == false)
                {strncpy(Question, TestDic->GetTextL(QNumber),997); strncpy(TrueAnswer, TestDic->GetTextR(QNumber),997);}
if (MainForm->CheckBox4->Checked == true)
                {strncpy(Question, TestDic->GetTextR(QNumber),997); strncpy(TrueAnswer, TestDic->GetTextL(QNumber),997);}
if (MainForm->CheckBox3->Checked == true)
                {int i =0; i = random(2);if (i==0)
                {strncpy(Question, TestDic->GetTextL(QNumber),997); strncpy(TrueAnswer, TestDic->GetTextR(QNumber),997);}
                if (i==1){strncpy(Question, TestDic->GetTextR(QNumber),997);strncpy(TrueAnswer, TestDic->GetTextL(QNumber),997);}}
//CheckListBox1->Items->Add(TestDic->GetText(0));
QNumber++;Edit2->Text = Question;Button3->Caption = "Next >>";
if (MainForm->CheckBox6->Checked)Timer3->Enabled = true;
return;
}//1

if (QNumber <= TestDic->GetCounter())

{//2

Amount++;
Label7->Caption = Amount;

strcpy(Answer, Edit1->Text.c_str());
Edit1->Text="";

if (strcmpi(TrueAnswer,freeUpKey(ClrSpc(Answer)))==0)
{
WasMistake = 0;++RightAnsw;
TestDic->SetChecked(QNumber);
}
else{WasMistake = 1;++Mistakes;}

Label12->Caption = RightAnsw;
Label9->Caption = Mistakes;
Label16->Caption = int((float)RightAnsw/(float)Amount *100);
Label17->Caption = int((float)Mistakes/(float)Amount*100);

if (MainForm->CheckBox4->Checked == false && MainForm->CheckBox3->Checked == false)
                {strncpy(Question, TestDic->GetTextL(QNumber),997); strncpy(TrueAnswer, TestDic->GetTextR(QNumber),997);}
if (MainForm->CheckBox4->Checked == true)
                {strncpy(Question, TestDic->GetTextR(QNumber),997); strncpy(TrueAnswer, TestDic->GetTextL(QNumber),997);}
if (MainForm->CheckBox3->Checked == true)
                {int i =0; i = random(2);if (i==0)
                {strncpy(Question, TestDic->GetTextL(QNumber),997); strncpy(TrueAnswer, TestDic->GetTextR(QNumber),997);}
                if (i==1){strncpy(Question, TestDic->GetTextR(QNumber),997);strncpy(TrueAnswer, TestDic->GetTextL(QNumber),997);}}
QNumber++;
Edit2->Text = Question;
}//2

if (QNumber > TestDic->GetCounter())
{
if (((float)RightAnsw/(float)Amount) >= (float)1.2/(float)2){Application->MessageBox("Testing is completed","The results is too bad",MB_ICONEXCLAMATION|MB_OK);goto a;}
if (((float)RightAnsw/(float)Amount) > (float)1.2/(float)2){Application->MessageBox("Testing is completed","Satisfactorily...",MB_ICONEXCLAMATION|MB_OK);goto a;}
if (((float)RightAnsw/(float)Amount) > (float)1.5/(float)2){Application->MessageBox("Testing is completed!","Well!",MB_ICONEXCLAMATION|MB_OK);goto a;}
if (((float)RightAnsw/(float)Amount) > (float)1.8/(float)2){Application->MessageBox("Testing is completed!","Congratulations!",MB_ICONEXCLAMATION|MB_OK);goto a;}
a:

int w = 0;
CheckListBox1->Clear();
while (w < TestDic->GetCounter())
{CheckListBox1->Items->Add(TestDic->GetText(w));
if (TestDic->Checked(w))CheckListBox1->Checked[w]=true;
w++;
}


CheckListBox1->Visible = true;
ExamForm->Top = 20;
ExamForm->Height = 147+200;
}


}//0
        */
}
//---------------------------------------------------------------------------

void __fastcall TExamForm::GetNewQuestionExecute(TObject *Sender)
{         /*

if (MainForm->CheckBox4->Checked == false && MainForm->CheckBox3->Checked == false)
                {
                strncpy(Question, TestDic->GetTextL(QNumber),997);
                strncpy(TrueAnswer, TestDic->GetTextR(QNumber),997);
                }

if (MainForm->CheckBox4->Checked == true)
                {
                strncpy(Question, TestDic->GetTextR(QNumber),997);
                strncpy(TrueAnswer, TestDic->GetTextL(QNumber),997);
                }

if (MainForm->CheckBox3->Checked == true)
                {
                int i =0; i = random(2);
                if (i==0)
                {strncpy(Question, TestDic->GetTextL(QNumber),997);
                strncpy(TrueAnswer, TestDic->GetTextR(QNumber),997);}
                if (i==1)
                {strncpy(Question, TestDic->GetTextR(QNumber),997);
                strncpy(TrueAnswer, TestDic->GetTextL(QNumber),997);}
                }

                if (MainForm->RadioButton3->Checked == true)
{if (QNumber < TestDic->GetCounter()){QNumber++;}else QNumber = 0;}

if (MainForm->RadioButton5->Checked == true)
{if (QNumber > 0){QNumber--;}else QNumber = TestDic->GetCounter()-1;}

if (MainForm->RadioButton4->Checked == true)
{QNumber = random (TestDic->GetCounter());}
*/}
//---------------------------------------------------------------------------
void __fastcall TExamForm::onMistakeExecute(TObject *Sender)
{ /*
Edit3->Text = TrueAnswer;
Col = MainForm->Color;

if (MainForm->RadioButton1->Checked)
{ExamForm->Color = clRed;
Timer2->Enabled = true;}

if (MainForm->RadioButton2->Checked)
{ExamForm->Color = clRed;
Timer2->Enabled = true;
ErrDic->AddIFNF(TestDic->GetText(QNumber));
TObject *a;
GetNewQuestionExecute(a);
}
    */
}
//---------------------------------------------------------------------------
void __fastcall TExamForm::Timer2Timer(TObject *Sender)
{
ExamForm->Color = Col;
Timer2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TExamForm::Edit1Change(TObject *Sender)
{
Edit3->Text ="";
}
//---------------------------------------------------------------------------

void __fastcall TExamForm::Button2Click(TObject *Sender)
{
SaveResults();
}
//---------------------------------------------------------------------------





void __fastcall TExamForm::Timer3Timer(TObject *Sender)
{
static int j = 0;
j+=1;
if (j > AnswTime){Button3->Click();j = 0;}
}
//---------------------------------------------------------------------------



