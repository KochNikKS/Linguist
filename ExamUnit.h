//---------------------------------------------------------------------------
#ifndef ExamUnitH
#define ExamUnitH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <ActnList.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TExamForm : public TForm
{
__published:	// IDE-managed Components
	
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button3;
        TTimer *Timer1;
        TEdit *Edit2;
        TEdit *Edit3;
        TLabel *Label10;
        TLabel *Label11;
        TPanel *Panel2;
        TLabel *Label9;
        TLabel *Label12;
        TLabel *Label7;
        TLabel *Label6;
        TLabel *Label13;
        TLabel *Label8;
        TLabel *Label16;
        TLabel *Label17;
        TActionList *ActionList1;
        TAction *Action1;
        TAction *GetNewQuestion;
        TAction *onMistake;
        TTimer *Timer2;
        TLabel *Label2;
        TLabel *Label3;
        TCheckListBox *CheckListBox1;
        TTimer *Timer3;

	void __fastcall Button1Click(TObject *Sender);

        void __fastcall FormShow(TObject *Sender);
        void __fastcall Edit3Enter(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall Action1Execute(TObject *Sender);
        void __fastcall GetNewQuestionExecute(TObject *Sender);
        void __fastcall onMistakeExecute(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TExamForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TExamForm *ExamForm;
//---------------------------------------------------------------------------
#endif
