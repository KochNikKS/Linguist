//---------------------------------------------------------------------------
#ifndef IntrfcH
#define IntrfcH
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
void InterfaceColor(int);
void InterfaceFont(TFont *);
void OutputColor(int);
void OutputFont(TFont *);

void FModified();
void SetUnLoadEnviroment();
void SetLoadEnviroment();
void ClipBoard_Empty();
void ClipBoard_Full ();
void SetStartSettings();
#endif
