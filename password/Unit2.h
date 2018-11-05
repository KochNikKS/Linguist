//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <OleCtnrs.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TMaskEdit *MaskEdit1;
        TBitBtn *BitBtn1;
        TOleContainer *OleContainer1;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall MaskEdit1Change(TObject *Sender);
        void __fastcall ApplicationEvents1Deactivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
