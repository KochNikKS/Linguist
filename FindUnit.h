//---------------------------------------------------------------------------
#ifndef FindUnitH
#define FindUnitH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TFindForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TLabel *Label1;
	TCheckBox *BMCase;
	TEdit *Edit1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	void __fastcall Button1Click(TObject *Sender);
	
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFindForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFindForm *FindForm;
//---------------------------------------------------------------------------
#endif
