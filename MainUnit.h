//---------------------------------------------------------------------------
#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ComCtrls.hpp>
//#include <vcl\ISP.hpp>
#include <vcl\OleCtrls.hpp>
#include <vcl\GraphSvr.hpp>
#include <vcl\ExtCtrls.hpp>
#include "Grids.hpp"
#include <vcl\OleCtnrs.hpp>
#include <Graphics.hpp>
#include <ActnList.hpp>
#include <MPlayer.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TStatusBar *StatusBar1;
	TPanel *Panel2;
	TBitBtn *Btn1;
	TBitBtn *Btn7;
	TBitBtn *Btn6;
	TBitBtn *Btn8;
	TBitBtn *Btn2;
	TBitBtn *Btn3;
	TBitBtn *Btn5;
	TBitBtn *Btn4;
	TSpeedButton *Button1;
	TFontDialog *FontDialog2;
	TColorDialog *ColorDialog2;
	TTimer *Copy_paste_timer;
	TTimer *Timer2;
	TTimer *Timer1;
	TFontDialog *FontDialog1;
	TColorDialog *ColorDialog1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Newdictionary1;
	TMenuItem *N3;
	TMenuItem *Loaddictionary1;
	TMenuItem *Reload1;
	TMenuItem *N4;
	TMenuItem *Save1;
	TMenuItem *Saveas1;
	TMenuItem *N5;
	TMenuItem *Printdic;
	TMenuItem *N2;
	TMenuItem *Deletedic;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TMenuItem *Edit;
	TMenuItem *Copy1;
	TMenuItem *Addfrombuffer1;
	TMenuItem *N11;
	TMenuItem *Change1;
	TMenuItem *New1;
	TMenuItem *Invert1;
	TMenuItem *N10;
	TMenuItem *Find1;
	TMenuItem *N7;
	TMenuItem *Delete1;
	TMenuItem *Utils1;
	TMenuItem *Converter1;
	TMenuItem *Actions1;
        TMenuItem *R1;
        TMenuItem *R2;
	TMenuItem *Options1;
	TMenuItem *Results1;
	TMenuItem *Informations1;
	TMenuItem *Manual1;
	TMenuItem *About1;
	TSaveDialog *SaveDialog1;
	TPrintDialog *PrintDialog1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Options2;
	TMenuItem *N12;
	TMenuItem *Viewstring1;
	TMenuItem *Find2;
	TMenuItem *N6;
	TMenuItem *Copy2;
	TMenuItem *Addfrombuffer2;
	TMenuItem *N8;
	TMenuItem *Change2;
	TMenuItem *Newstring1;
	TMenuItem *Invert2;
	TMenuItem *N9;
	TMenuItem *Delete2;
	TOpenDialog *OpenDialog1;
        TOleContainer *Converter;
	TPanel *Panel4;
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TBitBtn *BitBtn1;
	TTabSheet *TabSheet1;
	TImage *Image9;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TLabel *Label1;
	TBitBtn *BitBtn2;
	TMemo *Memo1;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
        TActionList *ActionList1;
        TAction *Action1;
        TPanel *Panel5;
        TGroupBox *GroupBox3;
        TImage *Image2;
        TImage *Image3;
        TPanel *Panel3;
        TGroupBox *GroupBox4;
        TImage *Image4;
        TImage *Image5;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TLabel *Label3;
        TLabel *Label4;
        TAction *MTD;
        TMenuItem *N13;
        TAction *Random;
        TAction *OnOrder;
        TAction *RunTraining;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TBitBtn *BitBtn10;
        TCheckBox *CheckBox1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *SaveB;
        TToolButton *ToolButton6;
        TImageList *ImageList1;
        TToolBar *ToolBar2;
        TToolButton *DelB;
        TToolButton *MinB;
        TToolButton *ExitB;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton7;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton12;
        TToolButton *ToolButton8;
        TMenuItem *N14;
        TMenuItem *Newuser1;
        TToolButton *ToolButton14;
        TPopupMenu *PopupMenu2;
        TMenuItem *Runtraining1;
        TMenuItem *Runexamination2;
        TAction *START;
        TMenuItem *Allowediting1;
        TBitBtn *BitBtn9;
        TMenuItem *Show1;
        TMenuItem *Clear1;
        TLabel *Label5;
        TToolButton *ToolButton15;
        TGroupBox *GroupBox2;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox6;
        TEdit *Edit4;
	void __fastcall Newdictionary1Click(TObject *Sender);
	void __fastcall Loaddictionary1Click(TObject *Sender);
	void __fastcall DeletedicClick(TObject *Sender);

	void __fastcall Viewstring1Click(TObject *Sender);
	void __fastcall Reload1Click(TObject *Sender);

	void __fastcall PrintdicClick(TObject *Sender);

    void __fastcall Change1Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);

	void __fastcall Addfrombuffer1Click(TObject *Sender);
	void __fastcall Invert1Click(TObject *Sender);

	void __fastcall Delete1Click(TObject *Sender);

	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Saveas1Click(TObject *Sender);

	void __fastcall Find1Click(TObject *Sender);

	void __fastcall About1Click(TObject *Sender);

	void __fastcall New1Click(TObject *Sender);

	void __fastcall Options1Click(TObject *Sender);

	void __fastcall BitBtn1Click(TObject *Sender);

	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

	void __fastcall Copy_paste_timerTimer(TObject *Sender);

	void __fastcall Converter1Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall BitBtn8Click(TObject *Sender);
        void __fastcall Action1Execute(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall R1Click(TObject *Sender);
        void __fastcall Actions1Click(TObject *Sender);
        void __fastcall BitBtn10Click(TObject *Sender);
        void __fastcall BitBtn8MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall BitBtn2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall PageControl4Change(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall ListBox1KeyPress(TObject *Sender, char &Key);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall ExitBClick(TObject *Sender);
        void __fastcall MinBClick(TObject *Sender);
        void __fastcall ToolButton14MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall R2Click(TObject *Sender);
        void __fastcall STARTExecute(TObject *Sender);
        void __fastcall Newuser1Click(TObject *Sender);
        void __fastcall Allowediting1Click(TObject *Sender);
        void __fastcall Clear1Click(TObject *Sender);
        void __fastcall Show1Click(TObject *Sender);
        void __fastcall BitBtn11Click(TObject *Sender);
        void __fastcall RadioButton5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
