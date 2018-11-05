//---------------------------------------------------------------------------
#ifndef ManualH
#define ManualH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\ComCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include "FrameUnit.h"
#include <Buttons.hpp>
#include "FrameUnit.h"
#include "Trayicon.h"
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TManualForm : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView1;
	TMemo *Memo1;
	TImageList *ImageList1;
        TFrame1 *Frame11;
private:	// User declarations
public:		// User declarations
	__fastcall TManualForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TManualForm *ManualForm;
//---------------------------------------------------------------------------
#endif
