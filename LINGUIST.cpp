//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("NewDicUnit.cpp", NewDicForm);
USEUNIT("List.cpp");
USEFORM("AboutUnit.cpp", AboutForm);
USEFORM("ChngUnit.cpp", ChngForm);
USEFORM("FindUnit.cpp", FindForm);
USEFORM("StartUnit.cpp", StartForm);
USEFORM("ExamUnit.cpp", ExamForm);
USEUNIT("Intrfc.cpp");
USEFORM("POptUnit.cpp", POptForm);
USEFORM("FrameUnit.cpp", Frame1); /* TFrame: File Type */
USEFORM("SelUnit.cpp", SelForm);
USEFORM("RegUnit.cpp", RegForm);
USEFORM("ResUnit.cpp", ResForm);
USEFORM("CodeUnit.cpp", CodeForm);
USERES("Linguist.res");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TNewDicForm), &NewDicForm);
                 Application->CreateForm(__classid(TAboutForm), &AboutForm);
                 Application->CreateForm(__classid(TChngForm), &ChngForm);
                 Application->CreateForm(__classid(TFindForm), &FindForm);
                 Application->CreateForm(__classid(TStartForm), &StartForm);
                 Application->CreateForm(__classid(TExamForm), &ExamForm);
                 Application->CreateForm(__classid(TPOptForm), &POptForm);
                 Application->CreateForm(__classid(TSelForm), &SelForm);
                 Application->CreateForm(__classid(TRegForm), &RegForm);
                 Application->CreateForm(__classid(TResForm), &ResForm);
                 Application->CreateForm(__classid(TCodeForm), &CodeForm);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
