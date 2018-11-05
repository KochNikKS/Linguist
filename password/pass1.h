//---------------------------------------------------------------------------

#ifndef pass1H
#define pass1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <OleCtnrs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMaskEdit *MaskEdit1;
        TBitBtn *BitBtn1;
        TTimer *Timer1;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall MaskEdit1Change(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
