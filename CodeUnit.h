//---------------------------------------------------------------------------

#ifndef CodeUnitH
#define CodeUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TCodeForm : public TForm
{
__published:	// IDE-managed Components
        TMaskEdit *MaskEdit1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCodeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCodeForm *CodeForm;
//---------------------------------------------------------------------------
#endif
