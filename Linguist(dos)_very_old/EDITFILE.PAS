program editfile(input,output,par);
uses graph,crt,newproc,dos,mouse;
var nnn,iii,uuu,drv,rrr:integer;
    {name:string;}
    russian,other: string ;
    morf:boolean;
    oldmx,oldmy,mx,my,ms,mask:word;
(****************************************************************************)
procedure fedit(nnn,x:integer;f:string);
var
    fil,fil1:text;
    fpos:integer;

begin
russian:='';

if x=1 then
begin
downpanel(103,103,417,119,15,9,1,1,1,false,true,true);
russian:=editstr(104,105,36,9,15,true,readfile('rus\'+f,nnn-12,1,40));
end;

if x = 2 then
begin
downpanel(423,103,586,119,15,9,1,1,1,false,true,true);
other:=editstr(427,105,36,9,15,true,readfile('dict\'+f,nnn-12,1,40));
end;
if russian = '' then russian:=readfile('rus\'+f,nnn-12,1,40);
if other = '' then other:=readfile('dict\'+f,nnn-12,1,40);
end;
(****************************************************************************)


procedure flist(fname:string);
label ll;
var filename2,filename1,filename:text;
    fil,fil1:file;
    t:char;
    filepos,posx,posy,numw:integer;
    buffer:string;
    {changes:array[1..1000]of integer;}
     chy:real;
     Path: PathStr;
     Dir: DirStr;
     Name: NameStr;
     Ext: ExtStr;

procedure savebac(mm:integer);
begin

assign(filename,'dict\'+fname);
reset(filename);
assign(filename2,copy(fname,1,6)+'i2.bac');
if mm = 1 then rewrite(filename2) else append(filename2);
close(filename2);
filepos:=0;
repeat
append(filename2);
readln(filename,buffer);
writeln(filename2,buffer);
filepos:=filepos+1;
close(filename2);
until buffer='';
close(filename);

assign(filename,'rus\'+fname);
reset(filename);
assign(filename2,copy(fname,1,6)+'r2.bac');
if mm = 1 then rewrite(filename2) else append(filename2);
close(filename2);
filepos:=0;
repeat
append(filename2);
readln(filename,buffer);
writeln(filename2,buffer);
filepos:=filepos+1;
close(filename2);
until buffer='';
close(filename);
buffer:='';


end;

begin
posx:=1;
mouseinit;
setfillstyle(1,7);
bar(1,1,640,480);

setfillstyle(1,8);
bar(110,110,599,370);
bar(605,110,623,398);
uppanel(100,100,589,360,3,9,1,2,1,true,true,true);
{uppanel(590,100,608,360,3,9,1,1,3,false,true,true);}
line(420,100,420,350);
iii:=100;
repeat
line(100,iii,588,iii);
iii:=iii+20
until iii>330;
uppanel(100,340,586,360,3,9,1,1,3,false,true,true);
setcolor(0);
outtextxy(105,350,'ENTER - правка; ESC -  выход; '+chr(25) +' и '+ chr(24)+ ' - листать; DEL - удалить');
uppanel(600,90,615,380,3,9,1,1,0,false,true,true);
downpanel(602,92,613,378,3,9,1,1,0,false,true,true);





assign(filename,'dict\'+fname);
reset(filename);
assign(filename2,copy(fname,1,6)+'i2.bac');
rewrite(filename2);
{fsplit('dict\'+fname,dir,name,ext);}
assign(filename1,copy(fname,1,6)+'i.bac');
rewrite(filename1);
close(filename1);
close(filename2);
filepos:=0;
repeat
append(filename1);
append(filename2);
readln(filename,buffer);
writeln(filename1,buffer);
writeln(filename2,buffer);
filepos:=filepos+1;
close(filename1);
close(filename2);
until buffer='';
close(filename);

assign(filename,'rus\'+fname);
reset(filename);
assign(filename2,copy(fname,1,6)+'r2.bac');
rewrite(filename2);
{fsplit('rus\'+fname,dir,name,ext);}
assign(filename1,copy(fname,1,6)+'r.bac');
rewrite(filename1);
close(filename1);
close(filename2);
filepos:=0;
repeat
append(filename1);
append(filename2);
readln(filename,buffer);
writeln(filename1,buffer);
writeln(filename2,buffer);
filepos:=filepos+1;
close(filename1);
close(filename2);
until buffer='';
close(filename);
buffer:='';

assign(filename,'dict\'+fname);
reset(filename);
numw:=0;

repeat
numw:=numw+1;
readln(filename,buffer);
until buffer='';
setcolor(11);
str(numw,buffer);
outtextxy(250,380,buffer+' слов в исходном словаре.');
if numw> 1000 then
begin
uppanel(150,150,450,200,7,15,8,2,1,false,true,true);
downpanel(152,152,448,198,0,15,8,1,1,false,true,true);
setcolor(13);
outtextxy(179,154,'Словарь полон. Выберите другой');
outtextxy(179,174,'    или создайте новый.');
repeat
mouseshow;
until (keypressed)or(pressloc(150,150,450,200,1))or(pressloc(1,1,640,480,2));
t:=#27;
exit;

end;

buffer:='';
posy:=numw;
chy:=256/numw;
if chy > 1 then chy:=1;
uppanel(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,7,15,0,1,0,false,true,true);

iii:=100;
uuu:=0;
setcolor(11);
repeat
buffer:=readfile('rus\'+fname,numw-12+uuu,1,40);
outtextxy(102,iii+5,buffer);
buffer:=readfile('dict\'+fname,numw-12+uuu,1,40);
outtextxy(422,iii+5,buffer);
iii:=iii+20;
uuu:=uuu+1
until uuu>11;

if posx = 1 then
begin
downpanel(103,103,417,119,11,9,1,1,1,false,true,true);
uppanel(423,103,586,119,3,9,1,1,1,false,true,true);
end;
if posx = 2 then
begin
downpanel(423,103,586,119,11,9,1,1,1,false,true,true);
uppanel(103,103,417,119,3,9,1,1,1,false,true,true);
end;
if posx=1 then setcolor(9) else setcolor(11);
outtextxy(104,105,readfile('rus\'+fname,posy-12,1,40));
if posx=2 then setcolor(9) else setcolor(11);
outtextxy(424,105,readfile('dict\'+fname,posy-12,1,20));



repeat
repeat
mouseshow;
ms:=mousegetb(mask);
until (keypressed)or(ms=1)or(ms=2);

if(ms <> 1)and(ms<>2)then t:=readkey else t:='t';
mousehide;
if ((t=#80)or (pressloc(340,345,350,355,1)))and (posy<numw+12) then posy:=posy+1;
if ((t=#72)or (pressloc(380,345,390,355,1)))and(posy>13) then posy:=posy-1;
downpanel(602,92,613,378,3,9,1,1,0,false,true,true);
uppanel(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,7,15,0,1,0,false,true,true);
if (t=#75) or (pressloc(103,103,417,119,1))then posx:=1;
if (t=#77) or (pressloc(423,103,586,119,1))then posx:=2;
if (t=#73)and(posy>23) then posy:=posy-10;
if (t=#81) and (posy<numw+1) then posy:=posy+10;
if (t=#27) or (pressloc(230,340,330,360,1)) then
begin
setcolor(14);
outtextxy(105,350,'                ESC');
delay(50);
if morf=true then
begin
setfillstyle(1,8);
bar(210,262,490,310);
uppanel(200,250,480,300,4,9,1,1,1,false,true,true);
setcolor(0);
outtextxy(230,255,'Сохранить изменения в файле ?');

setfillstyle(1,8);
bar(223,283,286,298);
uppanel(220,280,280,290,4,9,1,1,1,false,true,true);
setcolor(11);
outtextxy(240,282,'Д');
setcolor(1);
outtextxy(250,282,'a')  ;

setfillstyle(1,8);
bar(313,283,376,298);
uppanel(310,280,370,290,4,9,1,1,1,false,true,true);
setcolor(11);
outtextxy(330,282,'H');
setcolor(1);
outtextxy(340,282,'eт')  ;

setfillstyle(1,8);
bar(403,283,466,298);
uppanel(400,280,460,290,4,9,1,1,1,false,true,true);
setcolor(11);
outtextxy(410,282,'О');
setcolor(1);
outtextxy(420,282,'тмена')  ;
repeat
mouseshow;
ms:=mousegetb(mask);
if ms=1 then mouseread(mx,my,mask);
until (keypressed)or ((ms=1)and(my>280)and(my<290));
mousehide;
if ms<>1 then  t:=readkey;


if (t = 'О')or(t='о')or (t='C')or(t='c')or pressloc(400,280,460,290,1) then
begin
uppanel(400,280,460,290,11,9,1,1,1,false,true,true);
setcolor(4);
outtextxy(410,282,'О');
setcolor(4);
outtextxy(420,282,'тмена')  ;
t:='i' ;
delay(50);
uppanel(400,280,460,290,4,9,1,1,1,false,true,true);
setcolor(11);
outtextxy(410,282,'О');
setcolor(1);
outtextxy(420,282,'тмена')  ;

end;
if (t = 'д')or(t='Д')or (t='y')or(t='Y')or pressloc(220,280,280,290,1) then
begin
uppanel(220,280,280,290,11,9,1,1,1,false,true,true);
setcolor(4);
outtextxy(240,282,'Д');
setcolor(4);
outtextxy(250,282,'a')  ;
delay(50);
t:=#27 ;
end;
if (t='n')or (t='N')or (t='н')or (t='Н')or pressloc(310,280,370,290,1) then
begin
uppanel(310,280,370,290,11,9,1,1,1,false,true,true);
setcolor(4);
outtextxy(330,282,'H');
setcolor(4);
outtextxy(340,282,'eт')  ;
assign(filename1,'dict\'+fname);
assign(filename2,'rus\'+fname);
rewrite(filename1);
rewrite(filename2);
close(filename1);
close(filename2);

filepos:=1;
repeAT
append(filename1);
append(filename2);
buffer:=READFILE(copy(fname,1,6)+'i.bac',filepos,1,36);
if buffer <> '' then writeln(filename1,buffer);
buffer:=READFILE(copy(fname,1,6)+'r.bac',filepos,1,36);
if buffer <> '' then writeln(filename2,buffer);
filepos:=filepos+1;
close(filename1);
close(filename2);
UNTIL BUFFER='';
t:=#27;
end;
end
else t:=#27;
setcolor(0);
outtextxy(105,350,'                ESC');
ms:=3;

end;

if (t=#13) or (pressloc(100,340,220,360,1))
or( (pressloc(103,103,417,119,2))and(posx=1))
or( (pressloc(423,103,586,119,2))and(posx=2))
then
begin
setcolor(14);
outtextxy(105,350,'ENTER - правка');
morf:=true;
fedit(posy,posx,fname);

if posx=1 then
begin
assign(filename,'rus\'+fname);
rewrite(filename);
close(filename);
filepos:=1;
repeat
append(filename);
buffer:=readfile(copy(fname,1,6)+'r2.bac',filepos,1,36);
if filepos = posy-12 then buffer:=russian;
writeln(filename,buffer);
close(filename);
filepos:=filepos+1;
until buffer='';
savebac(1);

end;

if posx=2 then
begin
assign(filename,'dict\'+fname);
rewrite(filename);
close(filename);
filepos:=1;
repeat
append(filename);
buffer:=readfile(copy(fname,1,6)+'i2.bac',filepos,1,36);
if filepos = posy-12 then buffer:=other;
writeln(filename,buffer);
close(filename);
filepos:=filepos+1;
until buffer='';
savebac(1);
end;
setcolor(0);
outtextxy(105,350,'ENTER - правка');
if posy=numw+12 then
begin
numw:=numw+1;
chy:=256/numw;
if chy>1 then chy:=1;
other:='';
end;
end;


if pressloc(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,1) then
begin
repeat
oldmy:= 102+trunc((chy)*posy);
ms:= mousegetb(mask);
if ms= 1 then mouseread(mx,my,mask);
if (my>oldmy) and (posy<numw+12)then posy:=posy+1;
if (my<oldmy) and (posy>13)then posy:=posy-1;
uppanel(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,7,15,0,1,0,false,true,true);
setcolor(3);
line(602,102+trunc((chy)*posy)-8,613,102+trunc((chy)*posy)-8);
line(602,102+trunc((chy)*posy)+8,613,102+trunc((chy)*posy)+8);

until ms<>1;
downpanel(602,92,613,378,3,9,1,1,0,false,true,true);
uppanel(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,7,15,0,1,0,false,true,true);
end;


if (t = #83) or (pressloc(480,340,580,360,1)) then
begin
setcolor(4);
outtextxy(105,350,'                                               DEL');
morf:=true;
assign(filename,'rus\'+fname);
rewrite(filename);
close(filename);
filepos:=1;
repeat
append(filename);
buffer:=readfile(copy(fname,1,6)+'r2.bac',filepos,1,36);
if filepos <> posy-12 then writeln(filename,buffer);
close(filename);
filepos:=filepos+1;
until buffer='';
savebac(1);
assign(filename,'dict\'+fname);
rewrite(filename);
close(filename);
filepos:=1;
repeat
append(filename);
buffer:=readfile(copy(fname,1,6)+'i2.bac',filepos,1,36);
if filepos <> posy-12 then writeln(filename,buffer);
close(filename);
filepos:=filepos+1;
until buffer='';
savebac(1);
numw:=numw-1;
chy:=256/numw;
if chy>1 then chy:=1;
setcolor(0);
outtextxy(105,350,'                                               DEL');

end;


setfillstyle(1,3);
bar(101,121,587,337);
setcolor(1);

line(420,100,420,337);
iii:=100;
repeat
line(100,iii,588,iii);
iii:=iii+20
until iii>330;
setcolor(4);
setfillstyle(1,9);


nnn:=100;
uuu:=0;
setcolor(11);
repeat
if uuu<>0 then begin
buffer:=readfile('rus\' +fname,posy-12+uuu,1,40);
outtextxy(102,nnn+5,buffer);
buffer:=readfile('dict\'+fname,posy-12+uuu,1,40);
outtextxy(422,nnn+5,buffer);
end;
buffer:='';
nnn:=nnn+20;
uuu:=uuu+1;
until uuu>11;

if posx = 1 then
begin
downpanel(103,103,417,119,11,9,1,1,1,false,true,true);
uppanel(423,103,586,119,3,9,1,1,1,false,true,true);
end;
if posx = 2 then
begin
downpanel(423,103,586,119,11,9,1,1,1,false,true,true);
uppanel(103,103,417,119,3,9,1,1,1,false,true,true);
end;
if posx=1 then setcolor(9) else setcolor(11);
outtextxy(104,105,readfile('rus\'+fname,posy-12,1,40));
if posx=2 then setcolor(9) else setcolor(11);
outtextxy(424,105,readfile('dict\'+fname,posy-12,1,20));



until (t=#27);

fsplit('dict\'+fname,dir,name,ext);
assign(filename1,copy(name,1,6)+'i'+'.bac');
erase(filename1);
fsplit('rus\'+fname,dir,name,ext);
assign(filename1,copy(name,1,6)+'r'+'.bac');
erase(filename1);

assign(filename2,copy(fname,1,6)+'i2.bac');
erase(filename2);
assign(filename2,copy(fname,1,6)+'r2.bac');
erase(filename2);
end;
(****************************************************************************)

begin
initgraph(drv,rrr,'bgi');
morf:=false;
mouseinit;
flist('latin###.dic');

{paramstr(paramcount));}


end.