//---------------------------------------------------------------------------
#ifndef POptUnitH
#define POptUnitH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Dialogs.hpp>
//---------------------------------------------------------------------------
class TPOptForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Font;
	TFontDialog *FontDialog1;
	TButton *Cancel;
	TButton *Ok;
	void __fastcall CancelClick(TObject *Sender);
	void __fastcall OkClick(TObject *Sender);
	void __fastcall FontClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPOptForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TPOptForm *POptForm;
//---------------------------------------------------------------------------
#endif
