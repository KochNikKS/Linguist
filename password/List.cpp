//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include "List.h"
//#include "MainUnit.h"
#include <fstream.h>

//---------------------------------------------------------------------------
void Mes(const char*source)
{Application->MessageBox(source,"",0);}
void Mes()
{Application->MessageBox("","",0);}
void Mesh()
{Application->MessageBox("Hello!","Marker",0);}

void Mes(const char*source,const char*metka)
{Application->MessageBox(source,metka,0);}

int Mes(const char*source,const char*metka, int d)
{return Application->MessageBox(source,metka,d);}


Node::Node(int size)
{str_size = (size<10001)?size:10000;
nextNode = 0;strcpy(record,"");
Value = false;
}

Node::Node(char *add_string,int size)
{str_size = (size<10001)?size:10000;
nextNode = 0;char t[10000] ="";
strncpy(t,add_string,str_size);
strcpy(record,t);
Value = false;
}

char* Node::GetString()
{return record;}

void Node::SetString(char* txt)
{char t[10000]="";
strncpy(t,txt,str_size); strcpy(record,t);//Mes(record);
}

int Node::GetIndex (){return index;}
void Node::SetIndex (int i){index = (i>=0)?i:0;}


void Node::SetLink(Node* linkval)
{nextNode = linkval;}

Node* Node::GetLink()
{return nextNode;}

//bool Node::Tested(){return tst;}
//void Node::Test(bool s){tst = s;}


//############################################

DicList::DicList(int y){StringSize = (y<10001)?y:10000;
BegPtr = new Node(StringSize);EndPtr = BegPtr;Counter = 1;}

DicList::~DicList()
{
Node *r = BegPtr;
while (r!=EndPtr)
{
Node *l = r;;
r = r->GetLink();
delete l;

}
delete r;
delete BegPtr;
delete EndPtr;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++ other functions +++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void DicList::Sorter(){ReSort2();}

int   DicList::GetCounter()
{return Counter;}

void DicList::Add(char *srce)
{
char source [10000]="";
strncpy(source,srce,StringSize);
//+++ убрать из общего варианта+++++++++++++++
if (strlen(source)<2) return;
//if (strchr(source,(int)';')){strcpy(source,strtok(source,";"));}
strcpy(source, ClearSpaces(source));
if (strlen(source)<2) return;
strcpy(source,UpKey(source));
if (!strchr(source,(int)'~')) source[strlen(source)/2]='~';
//++++++++++++++++++++++++++++++++++++++++++++
Node* AddPtr;
AddPtr = new Node(StringSize);
AddPtr->SetString(source);

if (Counter==1 && strlen(BegPtr->GetString())<1)BegPtr->SetString(source);
else {EndPtr->SetLink(AddPtr) ;EndPtr = AddPtr;AddPtr = 0;Counter++;}
}

bool DicList::AddIFNF(char *srce)
{
int ii = 0;

while (ii<Counter)
{
if (strcmpi(srce, GetText(ii))==0) {return false;}
ii++;
}

char source [10000]="";
strncpy(source,srce,StringSize);
//+++ убрать из общего варианта+++++++++++++++
if (strlen(source)<2) return false;strcpy(source, ClearSpaces(source));
if (strlen(source)<2) return false;strcpy(source,UpKey(source));
if (!strchr(source,(int)'~')) source[strlen(source)/2]='~';
//++++++++++++++++++++++++++++++++++++++++++++
Node* AddPtr;
AddPtr = new Node(StringSize);
AddPtr->SetString(source);

if (Counter==1 && strlen(BegPtr->GetString())<1)BegPtr->SetString(source);
else {EndPtr->SetLink(AddPtr) ;EndPtr = AddPtr;AddPtr = 0;Counter++;}
return true;
}




void DicList::Insert(char *source, int index)
{
//+++ убрать из общего варианта+++++++++++++++
if (strlen(source)<2) return;
//if (strchr(source,(int)';')){strcpy(source,strtok(source,";"));}
  strcpy(source, ClearSpaces(source));
source = UpKey(source);
if (!strchr(source,(int)'~')) source[strlen(source)/2]='~';
//++++++++++++++++++++++++++++++++++++++++++++
if (index < 0) index = 0;
Node *InsPtr = new Node (source,StringSize);

if (index == 0){InsPtr->SetLink(BegPtr);
BegPtr = InsPtr;}

if (index > Counter-1) {EndPtr->SetLink(InsPtr);
EndPtr = InsPtr;}

if (index>0 && index <= Counter-1)
{
int i = 0;
Node* CurPtr = BegPtr;
while (i < index-1){CurPtr = CurPtr->GetLink();i++;}
InsPtr->SetLink(CurPtr->GetLink());
CurPtr->SetLink(InsPtr);
}
Counter++;
//delete CurPtr;
}// end of function

void  DicList::ChangeText (char* source, int ind)
{
//if (strchr(source,(int)';')){strcpy(source,strtok(source,";"));}
strcpy(source, ClearSpaces(source));
source = UpKey(source);
if (!strchr(source,(int)'~')&&strlen(source)>=2) source[strlen(source)/2]='~';
if (strlen(source)<2) return;

int i = 0;if (ind>Counter-1) ind = Counter - 1;Node *PosPtr = BegPtr;

while (i < ind){PosPtr=PosPtr->GetLink();i++;}
PosPtr->SetString(source);
}

void DicList::Delete(int ind)
{
Node*CurPtr=BegPtr;

if (ind==0){BegPtr = BegPtr->GetLink();delete CurPtr;Counter-- ; return;}

if (ind>0 && ind <Counter-1)
{int i = 0; while (i<ind-1) {CurPtr = CurPtr->GetLink();i++;}
Node* DelPtr = CurPtr->GetLink();
CurPtr->SetLink(DelPtr->GetLink());
delete DelPtr;
Counter-- ;
return;
}

if (ind == Counter-1)
{
int i = 0; while (CurPtr->GetLink()!= EndPtr) {CurPtr = CurPtr->GetLink();i++;}
EndPtr = CurPtr; EndPtr->SetLink(0);
Node* DelPtr = EndPtr->GetLink(); delete DelPtr;
Counter-- ;
return;
}

}



bool DicList::StrFind (char*b,int i, bool marker)
{
char a[10000]="";
strcpy (a,GetText(i));
char *pt = a;
int nn = 0;
while (strcmp(pt,"\0")!=0)
{
if (marker)nn = strncmp(pt,b,strlen(b)); else nn = strncmpi(pt,b,strlen(b));
if (nn==0) {return true;};
pt++;
}
return false;
}




int DicList::Find(char* sample, bool MCase, int Pos, int direction)
{
if (direction==1)
{int i = Pos+1;while (i < Counter){if (StrFind(sample,i,MCase))return i; i++;}}

if (direction!=1)
{int i = Pos-1;while (i >=0){if (StrFind(sample,i,MCase))return i; i--;}}

return -1;
}


void DicList::ReSort()
{
int y = 0;
bool changed = true;
int Length = Counter-1;

	do{
    changed = false;
    y = 0;
		while (y<Length)
		{//y
		char buf1[10000]="";char buf2[10000]="";
        strcpy(buf1,GetText(y));strcpy(buf2,GetText(y+1));
		if (strcmpi(buf1,buf2) >0)
		{
		ChangeText(buf2,y  );
		ChangeText(buf1,y+1);
		changed = true;}
		y++;
		}

	Length--;
	}
	while (changed);
}


void DicList::ReSort2()
{
//if (mar) SortForm->Visible = true;
int i = 0, chngd=0; char buf[10000] = "";
Node *sortPtr= BegPtr, *bufferPtr=sortPtr;
do{chngd = 0;
while (i < Counter-1&&sortPtr!=EndPtr)
{

if (strcmpi(sortPtr->GetString(), sortPtr->GetLink()->GetString())>0)
{//if (mar)SortForm->Label1->Caption = sortPtr->str;
strcpy(buf,sortPtr->GetString());
sortPtr->SetString(sortPtr->GetLink()->GetString());
sortPtr->GetLink()->SetString(buf);
chngd = 1;}

i+=1; sortPtr=sortPtr->GetLink();
}
i=0;sortPtr = BegPtr;}while(chngd);
//if (mar) SortForm->Visible = false;

}
//******************************************
void DicList::ReNumber()
{
Node* CurPtr = BegPtr;
int i = 0;
while (CurPtr)
{
CurPtr->SetIndex(i);
CurPtr = CurPtr->GetLink();
i++;
}
}

//********************************************
char* DicList::ClearSpaces(char *s)
{
int i = 0;while (s[i]!= '\0'){if (s[i]=='\n') s[i]=' ';i++;}
i = strlen(s)-1; while (s[i] == ' '){s[i]='' ; i--;}
i = 0; while (s[i] == ' '){s[i]= '';i++;}
i = 0;

while (i<strlen(s))
{
if (s[i]==' ' && (s[i+1]==' '||s[i+1] == '.'||s[i+1]==','||
s[i+1] =='!' || s[i+1] == '?' || s[i+1] == '\'' || s[i+1]==';'||
s[i+1] == '%' || s[i+1]==':')) {s[i] = '';}
i++;
}

char *ff = s; i =0;
while (*ff!='\0'){if (*ff!=''){s[i] = *ff;i++;}ff++;}
s[i]='\0';

//MarkSpaces(t);
//ClearMarks(t);
return s;}

char* DicList::UpKey(char* s)
{char c = s[0];
switch (c){
case 'a': c = 'A';break;case 'b': c = 'B';break;
case 'c': c = 'C';break;case 'd': c = 'D';break;
case 'e': c = 'E';break;case 'f': c = 'F';break;
case 'h': c = 'H';break;case 'i': c = 'I';break;
case 'g': c = 'G';break;case 'k': c = 'K';break;
case 'l': c = 'L';break;case 'm': c = 'M';break;
case 'n': c = 'N';break;case 'o': c = 'O';break;
case 'p': c = 'P';break;case 'q': c = 'Q';break;
case 'r': c = 'R';break;case 's': c = 'S';break;
case 't': c = 'T';break;case 'u': c = 'U';break;
case 'v': c = 'V';break;case 'w': c = 'W';break;
case 'x': c = 'X';break;case 'y': c = 'Y';break;
case 'z': c = 'Z';break;case 'а': c = 'А';break;
case 'н': c = 'Н';break;case 'б': c = 'Б';break;
case 'о': c	= 'О';break;case 'п': c = 'П';break;
case 'р': c = 'Р';break;case 'в': c = 'В';break;
case 'с': c = 'С';break;case 'г': c = 'Г';break;
case 'д': c = 'Д';break;case 'т': c = 'Т';break;
case 'у': c = 'У';break;case 'ё': c = 'Ё';break;
case 'ф': c = 'Ф';break;case 'ж': c = 'Ж';break;
case 'х': c = 'Х';break;case 'з': c = 'З';break;
case 'ц': c = 'Ц';break;case 'и': c = 'И';break;
case 'ч': c = 'Ч';break;case 'к': c = 'К';break;
case 'ш': c = 'Ш';break;case 'л': c = 'Л';break;
case 'щ': c = 'Щ';break;case 'м': c = 'М';break;
case 'э': c = 'Э';break;case 'ю': c = 'Ю';break;
case 'я': c = 'Я';break;case 'е': c = 'Е';break;
}
s[0] = c; return s;}

char* freeUpKey(char* s)
{char c = s[0];
switch (c){
case 'a': c = 'A';break;case 'b': c = 'B';break;
case 'c': c = 'C';break;case 'd': c = 'D';break;
case 'e': c = 'E';break;case 'f': c = 'F';break;
case 'h': c = 'H';break;case 'i': c = 'I';break;
case 'g': c = 'G';break;case 'k': c = 'K';break;
case 'l': c = 'L';break;case 'm': c = 'M';break;
case 'n': c = 'N';break;case 'o': c = 'O';break;
case 'p': c = 'P';break;case 'q': c = 'Q';break;
case 'r': c = 'R';break;case 's': c = 'S';break;
case 't': c = 'T';break;case 'u': c = 'U';break;
case 'v': c = 'V';break;case 'w': c = 'W';break;
case 'x': c = 'X';break;case 'y': c = 'Y';break;
case 'z': c = 'Z';break;case 'а': c = 'А';break;
case 'н': c = 'Н';break;case 'б': c = 'Б';break;
case 'о': c	= 'О';break;case 'п': c = 'П';break;
case 'р': c = 'Р';break;case 'в': c = 'В';break;
case 'с': c = 'С';break;case 'г': c = 'Г';break;
case 'д': c = 'Д';break;case 'т': c = 'Т';break;
case 'у': c = 'У';break;case 'ё': c = 'Ё';break;
case 'ф': c = 'Ф';break;case 'ж': c = 'Ж';break;
case 'х': c = 'Х';break;case 'з': c = 'З';break;
case 'ц': c = 'Ц';break;case 'и': c = 'И';break;
case 'ч': c = 'Ч';break;case 'к': c = 'К';break;
case 'ш': c = 'Ш';break;case 'л': c = 'Л';break;
case 'щ': c = 'Щ';break;case 'м': c = 'М';break;
case 'э': c = 'Э';break;case 'ю': c = 'Ю';break;
case 'я': c = 'Я';break;case 'е': c = 'Е';break;
}
s[0] = c; return s;}



char*DicList::GetText(int ind)
{if (ind >= Counter) ind = Counter -1;
Node *PosPtr = BegPtr; int i =0;
while  (i<ind){PosPtr=PosPtr->GetLink();i++;}
if (strlen(PosPtr->GetString())>0) return UpKey(ClearSpaces(PosPtr->GetString()));
else return "";
}


char*DicList::GetTextL(int ind)
{char s[10000]=""; strcpy(s,GetText(ind));
if (strlen(s)>0)
{char*buf=s ;
strcpy(buf, strtok(buf,"~"));
strcpy(buf, ClearSpaces(buf));
return buf;}
else return "";
}

char*DicList::GetTextR(int ind)
{
char s[10000]=""; strcpy(s,GetText(ind));
if (strlen(s)>0)
{
char*buf2=s ;
while (*buf2++!='~'){};
char *buf;
buf = strtok(buf2,";");
buf = UpKey(ClearSpaces(buf));
return buf;}
else return "";
}




void  DicList::ClearList()
{
//int i =0; Node *j = BegPtr, *l ;while (i<Counter){l = j;delete l;j = j->GetLink();}
EndPtr = BegPtr = new Node(StringSize);Counter = 1;
}

void  DicList::SetDicName(char *nm){DictionaryName = nm;}
char *DicList::GetDicName(){return DictionaryName;}



void DicList::SetChecked(int ind)
{
ind--;
if (ind >= Counter) ind = Counter -1;
Node *PosPtr = BegPtr; int i =0;
while  (i<ind){PosPtr=PosPtr->GetLink();i++;}
PosPtr->Value = true;
}

void DicList::SetUnchecked(int ind)
{
ind--;
if (ind >= Counter) ind = Counter -1;
Node *PosPtr = BegPtr; int i =0;
while  (i<ind){PosPtr=PosPtr->GetLink();i++;}
PosPtr->Value = false;
}

bool DicList::Checked(int ind)
{
if (ind >= Counter) ind = Counter -1;
Node *PosPtr = BegPtr;
int i =0;
while  (i<ind){PosPtr=PosPtr->GetLink();i++;}
return PosPtr->Value;
}

char* ClrSpc(char *s)
{
int i = 0;while (s[i]!= '\0'){if (s[i]=='\n') s[i]=' ';i++;}
i = strlen(s)-1; while (s[i] == ' '){s[i]='' ; i--;}
i = 0; while (s[i] == ' '){s[i]= '';i++;}
i = 0;

while (i<strlen(s))
{
if (s[i]==' ' && (s[i+1]==' '||s[i+1] == '.'||s[i+1]==','||
s[i+1] =='!' || s[i+1] == '?' || s[i+1] == '\'' || s[i+1]==';'||
s[i+1] == '%' || s[i+1]==':')) {s[i] = '';}
i++;
}

char *ff = s; i =0;
while (*ff!='\0'){if (*ff!=''){s[i] = *ff;i++;}ff++;}
s[i]='\0';
return s;
}

char *strcut(char *s,int start, char symbol,int &reti)
{
int end = reti;
char inSource[10000]=""; int u = start; int i = 0;
while (s[u]!= symbol && s[u]!='\0' && u <strlen(s) && i < 10000)
{inSource[i]  = s[u];u++; i++;inSource[i]  = '\0';}
if (u<=strlen(s)){reti = u; return inSource;} else return "";
}

void GetPart(char *recip,  const char *source, int start, int amount)
{
int i  = 0 , u = 0;
if (amount >= strlen(source)-start) amount = strlen(source)-start-1;
while (i<=amount){recip[i]= source[i+start];i++;recip[i]='\0';}

}

char *convert_i_a(int i)
{
char key[100] = "";
switch (i){
case 193:strcpy (key, "a"); break; case 662:strcpy (key, "b"); break;
case 432:strcpy (key, "c"); break; case 449:strcpy (key, "d"); break;
case 124:strcpy (key, "e"); break; case 695:strcpy (key, "f"); break;
case 547:strcpy (key, "j");break;
case 618:strcpy (key, "h"); break; case 645:strcpy (key, "i"); break;
case 400:strcpy (key, "g"); break; case 863:strcpy (key, "k"); break;
case 308:strcpy (key, "l"); break; case 252:strcpy (key, "m"); break;
case 585:strcpy (key, "n"); break; case 163:strcpy (key, "o"); break;
case 343:strcpy (key, "p"); break; case 173:strcpy (key, "q"); break;
case 829:strcpy (key, "r"); break; case 903:strcpy (key, "s"); break;
case 200:strcpy (key, "t"); break; case 936:strcpy (key, "u"); break;
case 953:strcpy (key, "v"); break; case 643:strcpy (key, "w"); break;
case 106:strcpy (key, "x"); break; case 422:strcpy (key, "y"); break;
case 430:strcpy (key, "z"); break; case 369:strcpy (key, "а"); break;
case 385:strcpy (key, "н"); break; case 244:strcpy (key, "б"); break;
case 179:strcpy (key, "о"); break; case 756:strcpy (key, "п"); break;
case 845:strcpy (key, "р"); break; case 690:strcpy (key, "в"); break;
case 761:strcpy (key, "с"); break; case 720:strcpy (key, "г"); break;
case 521:strcpy (key, "д"); break; case 212:strcpy (key, "т"); break;
case 490:strcpy (key, "у"); break; case 882:strcpy (key, "ё"); break;
case 403:strcpy (key, "ф"); break; case 139:strcpy (key, "ж"); break;
case 519:strcpy (key, "х"); break; case 833:strcpy (key, "з"); break;
case 182:strcpy (key, "ц"); break; case 268:strcpy (key, "и"); break;
case 688:strcpy (key, "ч"); break; case 475:strcpy (key, "к"); break;
case 558:strcpy (key, "ш"); break; case 419:strcpy (key, "л"); break;
case 927:strcpy (key, "щ"); break; case 428:strcpy (key, "м"); break;
case 159:strcpy (key, "э"); break; case 966:strcpy (key, "ю"); break;
case 619:strcpy (key, "я"); break; case 810:strcpy (key, "е"); break;
case 100:strcpy (key, "й"); break; case -100:strcpy (key, "Й"); break;
case -193: strcpy (key, "A");break;case -662: strcpy (key, "B");break;
case -432: strcpy (key, "C");break;case -449: strcpy (key, "D");break;
case -124: strcpy (key, "E");break;case -695: strcpy (key, "F");break;
case -547:strcpy (key, "J"); break;
case -618: strcpy (key, "H");break;case -645: strcpy (key, "I");break;
case -400: strcpy (key, "G");break;case -863: strcpy (key, "K");break;
case -308: strcpy (key, "L");break;case -252: strcpy (key, "M");break;
case -555: strcpy (key, "N");break;case -163: strcpy (key, "O");break;
case -343: strcpy (key, "P");break;case -173: strcpy (key, "Q");break;
case -829: strcpy (key, "R");break;case -903: strcpy (key, "S");break;
case -200: strcpy (key, "T");break;case -936: strcpy (key, "U");break;
case -953: strcpy (key, "V");break;case -643: strcpy (key, "W");break;
case -106: strcpy (key, "X");break;case -422: strcpy (key, "Y");break;
case -430: strcpy (key, "Z");break;case -369: strcpy (key, "А");break;
case -385: strcpy (key, "Н");break;case -244: strcpy (key, "Б");break;
case -179: strcpy (key, "О");break;case -756: strcpy (key, "П");break;
case -845: strcpy (key, "Р");break;case -690: strcpy (key, "В");break;
case -761: strcpy (key, "С");break;case -720: strcpy (key, "Г");break;
case -521: strcpy (key, "Д");break;case -212: strcpy (key, "Е");break;
case -490: strcpy (key, "У");break;case -882: strcpy (key, "Ё");break;
case -403: strcpy (key, "Ф");break;case -139: strcpy (key, "Ж");break;
case -519: strcpy (key, "Х");break;case -833: strcpy (key, "З");break;
case -182: strcpy (key, "Ц");break;case -268: strcpy (key, "И");break;
case -688: strcpy (key, "Ч");break;case -475: strcpy (key, "К");break;
case -558: strcpy (key, "Ш");break;case -419: strcpy (key, "Л");break;
case -927: strcpy (key, "Щ");break;case -428: strcpy (key, "М");break;
case -159: strcpy (key, "Э");break;case -966: strcpy (key, "Ю");break;
case -619: strcpy (key, "Я");break;case -810: strcpy (key, "Т");break;
case 384: strcpy  (key, "ы"); break; case 551: strcpy (key , "ъ"); break;
case 103: strcpy (key , "ь"); break;case -103: strcpy (key , "Ь"); break;
case -384: strcpy (key , "Ы"); break; case -551: strcpy (key , "Ъ"); break;

case 111:strcpy (key, "1"); break; case 777:strcpy (key, "7"); break;
case 222:strcpy (key, "2"); break; case 888:strcpy (key, "8"); break;
case 333:strcpy (key, "3"); break; case 999:strcpy (key, "9"); break;
case 444:strcpy (key, "4"); break; case 767:strcpy (key, "0"); break;
case 555:strcpy (key, "5"); break; case 606:strcpy (key, "6"); break;
case 345:strcpy (key, "!"); break;
case 837:strcpy (key, "^"); break;
case 509:strcpy (key, "@"); break; case 189:strcpy (key, "&"); break;
case 161:strcpy (key, "#"); break; case 933:strcpy (key, "*"); break;
case 207:strcpy (key, "$"); break; case 935:strcpy (key, "("); break;
case 149:strcpy (key, "%"); break; case 899:strcpy (key, ")"); break;
case 920:strcpy (key, "]"); break; case 464:strcpy (key, ":"); break;
case 319:strcpy (key, "["); break; case 644:strcpy (key, "\"");break;
case 633:strcpy (key, "}"); break; case 613:strcpy (key, "\'");break;
case 293:strcpy (key, "{"); break; case 516:strcpy (key, "/"); break;
case 364:strcpy (key, "\0"); break;case 709:strcpy (key, "\\");break;
case 934:strcpy (key, ","); break;case 686:strcpy (key, "."); break;
case 238:strcpy (key, "_"); break;case 527:strcpy (key, "<"); break;
case 629:strcpy (key, "-"); break;case 225:strcpy (key, ">"); break;
case 302:strcpy (key, "="); break;case 973:strcpy (key, "?"); break;
case 763:strcpy (key, "~"); break;case 586:strcpy (key, "|"); break;
case 765:strcpy (key, " "); break;default: strcpy (key,  ""); break;
}
return key;
}




int RLF (char *filename, char *Dest, int &count)
{
ifstream fl (filename, ios::binary);
if (!fl) return 0;
fl.seekg(count);
strcpy (Dest,"");
char key[1]="" ;int shifr = 0;char buf[100]="";

while (fl>>buf)
{
shifr = atoi(buf);
if (shifr==0) {fl.close();return 0;}
else
{strcpy(key, convert_i_a(shifr));
strcat(Dest, key);
count =  fl.tellg();
if (shifr == 364){fl.close();return 1;}
}

}
fl.close();
return -1;
}


int convert_a_i(char i)
{
int j = 0;
switch (i)
{
case 'a': j = 193;break;case 'b': j = 662;break;
case 'c': j = 432;break;case 'd': j = 449;break;
case 'e': j = 124;break;case 'f': j = 695;break;
case 'j': j = 547;break;
case 'h': j = 618;break;case 'i': j = 645;break;
case 'g': j = 400;break;case 'k': j = 863;break;
case 'l': j = 308;break;case 'm': j = 252;break;
case 'n': j = 585;break;case 'o': j = 163;break;
case 'p': j = 343;break;case 'q': j = 173;break;
case 'r': j = 829;break;case 's': j = 903;break;
case 't': j = 200;break;case 'u': j = 936;break;
case 'v': j = 953;break;case 'w': j = 643;break;
case 'x': j = 106;break;case 'y': j = 422;break;
case 'z': j = 430;break;case 'а': j = 369;break;
case 'н': j = 385;break;case 'б': j = 244;break;
case 'о': j = 179;break;case 'п': j = 756;break;
case 'р': j = 845;break;case 'в': j = 690;break;
case 'с': j = 761;break;case 'г': j = 720;break;
case 'д': j = 521;break;case 'т': j = 212;break;
case 'у': j = 490;break;case 'ё': j = 882;break;
case 'ф': j = 403;break;case 'ж': j = 139;break;
case 'х': j = 519;break;case 'з': j = 833;break;
case 'ц': j = 182;break;case 'и': j = 268;break;
case 'ч': j = 688;break;case 'к': j = 475;break;
case 'ш': j = 558;break;case 'л': j = 419;break;
case 'щ': j = 927;break;case 'м': j = 428;break;
case 'э': j = 159;break;case 'ю': j = 966;break;
case 'я': j = 619;break;case 'е': j = 810;break;
                        case 'й': j = 100;break;
case 'A': j = -193;break;case 'B': j = -662;break;
case 'C': j = -432;break;case 'D': j = -449;break;
case 'E': j = -124;break;case 'F': j = -695;break;
case 'J': j = -547;break;
case 'H': j = -618;break;case 'I': j = -645;break;
case 'G': j = -400;break;case 'K': j = -863;break;
case 'L': j = -308;break;case 'M': j = -252;break;
case 'N': j = -555;break;case 'O': j = -163;break;
case 'P': j = -343;break;case 'Q': j = -173;break;
case 'R': j = -829;break;case 'S': j = -903;break;
case 'T': j = -200;break;case 'U': j = -936;break;
case 'V': j = -953;break;case 'W': j = -643;break;
case 'X': j = -106;break;case 'Y': j = -422;break;
case 'Z': j = -430;break;case 'А': j = -369;break;
case 'Н': j = -385;break;case 'Б': j = -244;break;
case 'О': j = -179;break;case 'П': j = -756;break;
case 'Р': j = -845;break;case 'В': j = -690;break;
case 'С': j = -761;break;case 'Г': j = -720;break;
case 'Д': j = -521;break;case 'Е': j = -212;break;
case 'У': j = -490;break;case 'Ё': j = -882;break;
case 'Ф': j = -403;break;case 'Ж': j = -139;break;
case 'Х': j = -519;break;case 'З': j = -833;break;
case 'Ц': j = -182;break;case 'И': j = -268;break;
case 'Ч': j = -688;break;case 'К': j = -475;break;
case 'Ш': j = -558;break;case 'Л': j = -419;break;
case 'Щ': j = -927;break;case 'М': j = -428;break;
case 'Э': j = -159;break;case 'Ю': j = -966;break;
case 'Я': j = -619;break;case 'Т': j = -810;break;
case 'Ы': j = -384;break;
case 'ы': j = 384;break;case 'ъ': j = 551;break;
case 'ь': j = 103;break;case 'Й': j = -100;break;
case 'Ь': j = -103;break;case 'Ъ': j = -551;break;

case '1': j = 111;break;case '7': j = 777;break;
case '2': j = 222;break;case '8': j = 888;break;
case '3': j = 333;break;case '9': j = 999;break;
case '4': j = 444;break;case '0': j = 767;break;
case '5': j = 555;break;case '6': j = 606;break;

case '!': j = 345;break;case '^': j = 837;break;
case '@': j = 509;break;case '&': j = 189;break;
case '#': j = 161;break;case '*': j = 933;break;
case '$': j = 207;break;case '(': j = 935;break;
case '%': j = 149;break;case ')': j = 899;break;
case ']': j = 920;break;case ':': j = 464;break;
case '[': j = 319;break;case '\"':j = 644;break;
case '}': j = 633;break;case '\'':j = 613;break;
case '{': j = 293;break;case '/': j = 516;break;
case '\\': j = 709;break;
case ';': j = 364;break;case ',': j = 934;break;
case '.': j = 686;break;case '_': j = 238;break;
case '<': j = 527;break;case '-': j = 629;break;
case '>': j = 225;break;case '=': j = 302;break;
case '?': j = 973;break;case '~': j = 763;break;
case '|': j = 586;break;case ' ': j = 765;break;
case '\n': j = 364;break;case '\0': j = 364;break;
}
return j;
}

char* ReturnDir ()
{
char *buf="";
char buf1[1000]="";
buf =  Application->ExeName.c_str();
strncpy(buf1, buf, strlen(buf)- 12);
return buf1;
}
