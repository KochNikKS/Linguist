//---------------------------------------------------------------------------

#ifndef SelUnitH
#define SelUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
#include "Menus.hpp"
//---------------------------------------------------------------------------
class TSelForm : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
        TListBox *ListBox2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TLabel *Label1;
        TLabel *Label2;
        TActionList *ActionList1;
        TAction *Action1;
        TAction *Action2;
        TMainMenu *MainMenu1;
        TMenuItem *Actions1;
        TMenuItem *Add1;
        TMenuItem *Delete1;
        TMenuItem *Clear1;
        TMenuItem *Runtraningexam1;
        TMenuItem *Returntomainwindow1;
        TMenuItem *Choosearange1;
        TMenuItem *Run1;
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall Action1Execute(TObject *Sender);
        void __fastcall Action2Execute(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSelForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSelForm *SelForm;
//---------------------------------------------------------------------------
#endif
