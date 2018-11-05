//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <fstream.h>
#pragma hdrstop

class rfile
{
public:
rfile (char *, char);
rfile (char *, int );
~rfile ();
void readfile (char*, int, int);
char *readfile (int);
private:
int stop_index;
char stop_symbol;
ifstream filename ;
unsigned char opened;
};


rfile::rfile (char *fname, char sym)
{
filename.open(fname,ios::in);
if (!filename)
{Application->MessageBox("File can't be opened","Access error",0);
opened = 0;}
else{opened = 1;
if(sym < 32) stop_symbol = 13; else stop_symbol = sym;
stop_index = 10000;}
}

rfile::rfile (char *fname, int ind)
{
filename.close();
filename.open(fname,ios::in);
if (!filename)
{Application->MessageBox("File can't be opened","Access error",0);
opened = 0;}
else{opened = 1;stop_symbol = 0; stop_index = ind;}

}

rfile::~rfile()
{filename.close();}

void rfile::readfile (char *acceptor, int position,int amount)
{
if (position <0)position =0; if (amount > 10000)amount = 10000;
for (int u = 0; u < amount; u++){acceptor[u]=0;acceptor[u+1]='\0' ;}
if (opened){filename.seekg(position);filename.read(acceptor, amount);}
}

char *rfile::readfile (int strpos)
{//function begin 1
char END[2]=""; END[0]=-1;

if (strpos <0)strpos =0;
char return_value[10001]="";
	if (opened)
	{//2
    filename.seekg(0);
	int pos = 0;
		while(pos <= strpos && !filename.eof())
		{//3
		if (stop_symbol)filename.getline(return_value,stop_index,stop_symbol);
        else filename.getline(return_value,stop_index,NULL);
        pos++;
        }//3

      if (filename.eof()) {return "";}
	  return return_value;

    }else return "";//2

}//end of function 1

#include "openfile.h"
//---------------------------------------------------------------------------
