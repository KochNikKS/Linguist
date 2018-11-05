//---------------------------------------------------------------------------

#ifndef RegUnitH
#define RegUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TRegForm : public TForm
{
__published:	// IDE-managed Components
        TMaskEdit *MaskEdit1;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall MaskEdit1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TRegForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegForm *RegForm;
//---------------------------------------------------------------------------
#endif
