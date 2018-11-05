//---------------------------------------------------------------------------
#ifndef ListH
#define ListH
//---------------------------------------------------------------------------

void Mes(const char*);
void Mes();
void Mesh();
void Mes(const char*,const char*);
int Mes(const char*,const char*, int);
char* ClrSpc(char *s);
char *strcut(char *s,int start, char symbol,int &reti);
//int rf(char *,char *,int);
char *convert_i_a(int);
int convert_a_i(char i);
int RLF(char * , char*, int&);
char *freeUpKey(char*);
char * ReturnDir (int);
void GetPart(char *recip,  const char *source, int start, int end);
//******************************************
class Node
{
public:
Node(int);
Node(char*,int);
char* GetString();
void SetString(char*);
int GetIndex();
void SetIndex(int );
void SetLink(Node*);
Node * GetLink();
bool Value;
bool Selected;
private:
int index;
char record[10000];
Node *nextNode;
int str_size;
};
//****************************************************
class DicList
{
public:
      DicList(int);
	  ~DicList();
char* GetText (int);
char* GetTextL (int);
char* GetTextR (int);
void  Add (char*);
bool  AddIFNF (char*);
void  Insert (char*,int);
void  Delete (int);
void  ChangeText (char*, int);
int   Find (char*,bool,int,int);
void  ClearList();
int   GetCounter();
void  Sorter();
void  ReNumber();               
void  SetDicName(char*);
char *GetDicName();
void SetChecked(int );
void SetUnchecked(int );
bool Checked(int );
private:
char *DictionaryName;
bool StrFind (char*,int,bool);  /*V*/
void  ReSort();
void  ReSort2();
Node *BegPtr;
Node *EndPtr;
int Counter;
int StringSize;
char* ClearSpaces(char*);       /*V*/
char* UpKey(char*);             /*V*/

};



#endif
