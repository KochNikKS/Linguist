//---------------------------------------------------------------------------
#ifndef StartUnitH
#define StartUnitH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TStartForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
private:	// User declarations
public:		// User declarations
	__fastcall TStartForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TStartForm *StartForm;
//---------------------------------------------------------------------------
#endif
