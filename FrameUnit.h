//---------------------------------------------------------------------------


#ifndef FrameUnitH
#define FrameUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFrame1 : public TFrame
{
__published:	// IDE-managed Components
        TImage *Image1;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame1 *Frame1;
//---------------------------------------------------------------------------
#endif
