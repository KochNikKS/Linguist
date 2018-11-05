//---------------------------------------------------------------------------
#ifndef ChngUnitH
#define ChngUnitH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TChngForm : public TForm
{
__published:	// IDE-managed Components
	
	TEdit *Edit1;
	TEdit *Edit2;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	
	
	void __fastcall FormHide(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TChngForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TChngForm *ChngForm;
//---------------------------------------------------------------------------
#endif
