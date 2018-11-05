//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include "MainUnit.h"
#include "StartUnit.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TStartForm *StartForm;
extern void SetStartSettings();
//---------------------------------------------------------------------------
__fastcall TStartForm::TStartForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
