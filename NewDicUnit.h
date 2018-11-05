//---------------------------------------------------------------------------
#ifndef NewDicUnitH
#define NewDicUnitH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\FileCtrl.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TNewDicForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TDirectoryListBox *DirListBox1;
	TLabel *Label1;
	TLabel *Label2;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TNewDicForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TNewDicForm *NewDicForm;
//---------------------------------------------------------------------------
#endif
