//---------------------------------------------------------------------------

#ifndef ResUnitH
#define ResUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include "piereg.h"
//---------------------------------------------------------------------------
class TResForm : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TBitBtn *BitBtn2;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        TButton *Button1;
        TLabel *Label1;
        TPie *Pie1;
        TShape *Shape1;
        TLabel *Label2;
        TPanel *Panel1;
        TLabel *Label3;
        TPanel *Panel2;
        TLabel *Label4;
        TLabel *Label5;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResForm *ResForm;
//---------------------------------------------------------------------------
#endif
