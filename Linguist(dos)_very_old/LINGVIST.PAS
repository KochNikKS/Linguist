uses mouse,printer,windos,graph,crt,kgraph,kgraph2,dos,crtnew,newproc;
label aa;
var  ppp,scannum,gd,gm,filelength,k,numoffiles,u,o,i,n,p,f:integer;
     points,altnum,num,sit1,sit2:integer;
     period,numerror,errorword,dn, cursor,userfont:integer;
     mx,my,ms,mask,h,m,s,s1000,hour,minute,sec,sec1000,archive,a,d,x,y:word;
     snd,sd,timebuf,answer,question, stringnum,buf,buf1,dictionary,slovo:string;
     names:array[1..1000] of string[12];
     dirinfo:SearchRec;
     key:char;
     positions:array[1..1000] of word;
     tx,lpt1,fil,filename,fl:text;
     vacantion,ext,ext1,restart:boolean;
     resultpercent:real;
     namesearch,list:pchar;
     dest:array[0..fspathname] of char;
     nnn,iii,uuu,drv,rrr:integer;
     russian,other: string ;
     morf:boolean;
     oldmx,oldmy:word;
     helpstep,helplength,helppos:integer;
     helpyold:integer;
     logox:integer;

     listprog:byte;

procedure printtime;
begin
gettime(hour,minute,sec,sec1000);
uppole(530,420,620,440,7,9,1,1,0,true,true,true,true,false);
downpole(532,422,618,438,0,9,1,1,0,true,true,true,true,false);
setcolor(10);
str(hour,timebuf);
outtextxy(570,428,timebuf+':');
timebuf:='';
str(minute,timebuf);
outtextxy(600,428,timebuf);
timebuf:='';

end;

procedure fedit(nnn,x:integer;ff:string);
var
    fil,fil1:text;
    fpos:integer;

begin
russian:='';

if x=1 then
begin
downpanel(103,103,417,119,15,9,1,1,1,false,true,true);
russian:=inwintext(readf('rus\'+ff,nnn-12,1,40),104,105,9,15,36,36);
{editstr(104,105,36,36,9,15,true,readf('rus\'+ff,nnn-12,1,40));}
end;

if x = 2 then
begin
downpanel(423,103,586,119,15,9,1,1,1,false,true,true);
other:=inwintext(readf('dict\'+ff,nnn-12,1,40),427,105,9,15,36,17);
{       editstr(427,105,36,17,9,15,true,readf('dict\'+ff,nnn-12,1,40));}
end;
if russian = '' then russian:=readf('rus\'+ff,nnn-12,1,40);
if other = '' then other:=readf('dict\'+ff,nnn-12,1,40);
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
if numw> 1000 then
begin
uppanel(150,150,450,200,7,15,8,2,1,false,true,true);
downpanel(152,152,448,198,0,15,8,1,1,false,true,true);
setcolor(13);
outtextxy(179,154,'Словарь полон. Выберите другой');
outtextxy(179,174,'    или создайте новый.');

repeat
mouseshow;
until (keypressed)or(presslock(150,150,450,200,1))or(presslock(1,1,640,480,2));
mousehide;
t:=#27;
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

exit;

end;

readln(filename,buffer);
until buffer='';
setcolor(11);
str(numw,buffer);
outtextxy(250,380,buffer+' слов в исходном словаре.');

buffer:='';
posy:=numw+12;
chy:=256/numw;
if chy > 1 then chy:=1;
uppanel(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,7,15,0,1,0,false,true,true);

iii:=100;
uuu:=0;
setcolor(11);
repeat
buffer:=readf('rus\'+fname,numw-12+uuu,1,36);
outtextxy(102,iii+5,buffer);
buffer:=readf('dict\'+fname,numw-12+uuu,1,17);
outtextxy(422,iii+5,buffer);
iii:=iii+20;
uuu:=uuu+1
until (uuu>11)or(uuu>numw-2);

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
outtextxy(104,105,readf('rus\'+fname,posy-12,1,40));
if posx=2 then setcolor(9) else setcolor(11);
outtextxy(424,105,readf('dict\'+fname,posy-12,1,20));


listprog:=0;
repeat
repeat
mouseshow;
ms:=mousegetb(mask);
until (keypressed)or(ms=1)or(ms=2);

if(ms <> 1)and(ms<>2)then t:=readkey else t:='t';

printtime;
mousehide;
if ((t=#80)or (presslock(340,345,350,355,1)))and (posy<numw+12) then posy:=posy+1;
if ((t=#72)or (presslock(380,345,390,355,1)))and(posy>13) then posy:=posy-1;
downpanel(602,92,613,378,3,9,1,1,0,false,true,true);
uppanel(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,7,15,0,1,0,false,true,true);
if (t=#75) or (presslock(103,103,417,119,1))then posx:=1;
if (t=#77) or (presslock(423,103,586,119,1))then posx:=2;
if (t=#73)and(posy>23) then posy:=posy-10;
if (t=#81) and (posy<numw+1) then posy:=posy+10;
if (t=#27) or (presslock(230,340,330,360,1)) then
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


if (t = 'О')or(t='о')or (t='C')or(t='c')or presslock(400,280,460,290,1) then
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
if (t = 'д')or(t='Д')or (t='y')or(t='Y')or presslock(220,280,280,290,1) then
begin
uppanel(220,280,280,290,11,9,1,1,1,false,true,true);
setcolor(4);
outtextxy(240,282,'Д');
setcolor(4);
outtextxy(250,282,'a')  ;
delay(50);
t:=#27 ;
end;
if (t='n')or (t='N')or (t='н')or (t='Н')or presslock(310,280,370,290,1) then
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
buffer:=READF(copy(fname,1,6)+'i.bac',filepos,1,36);
if buffer <> '' then writeln(filename1,buffer);
buffer:=READF(copy(fname,1,6)+'r.bac',filepos,1,36);
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

if (t=#13) or (presslock(100,340,220,360,1))
or( (presslock(103,103,417,119,2))and(posx=1))
or( (presslock(423,103,586,119,2))and(posx=2))
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
{buffer:=readf(copy(fname,1,6)+'r2.bac',filepos,1,36);}
if( filepos = posy-12) then buffer:=russian else buffer:=readf(copy(fname,1,6)+'r2.bac',filepos,1,36);
if (numw=1)and(filepos=1)then
begin
buffer:=russian;
numw:=numw+1;
end;


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

if (filepos = posy-12) then buffer:=other else  buffer:=readf(copy(fname,1,6)+'i2.bac',filepos,1,36);
if (numw=1)and(filepos=1)then
begin
buffer:=other;
end;
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


if presslock(604,102+trunc((chy)*posy)-5,611,102+trunc((chy)*posy)+5,1) then
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


if (t = #83) or (presslock(480,340,580,360,1)) then
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
buffer:=readf(copy(fname,1,6)+'r2.bac',filepos,1,36);
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
buffer:=readf(copy(fname,1,6)+'i2.bac',filepos,1,36);
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
buffer:=readf('rus\' +fname,posy-12+uuu,1,36);
outtextxy(102,nnn+5,buffer);
buffer:=readf('dict\'+fname,posy-12+uuu,1,17);
outtextxy(422,nnn+5,buffer);
end;
buffer:='';
nnn:=nnn+20;
uuu:=uuu+1;
until (uuu>11)or(uuu>numw-2);

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
outtextxy(104,105,readf('rus\'+fname,posy-12,1,36));
if posx=2 then setcolor(9) else setcolor(11);
outtextxy(424,105,readf('dict\'+fname,posy-12,1,17));



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


function txt(posx,posy,maxletnum,col1,col2,probel:integer):string;
var letnum:integer;
    ww,buffer:string;
    letmark:boolean;
begin
cursor:=16;
ww:='';
txt:='';
buffer:='';
if probel<>1 then letmark:=false;
ext:=false;
        letnum:=0;
        repeat
        key:=readkey;

        if key<>' ' then letmark:=true;
        if (ord(key) > 32)or (ord(key) = 8)or( ord(key)=27) or ( (letmark=true) and(ord(key) = 32)) then
        begin
        if ord(key) =8 then
        begin
        cursor:=17;
        delete(ww,length(ww),1);
        end else if length(ww)<maxletnum+1 then
        begin
        ww:=ww+key;
        cursor:=16;
        end;
        if key =#27 then
        begin
        ext:=true;
        slovo:='';
        break;
        end;


        setfillstyle(1,col2);
        if length(ww)>letnum then  letnum:=length(ww);
        bar(posx,posy,posx+letnum*8+10,posy+10);
        setcolor(col1);
        outtextxy(posx,posy,ww+chr(cursor));
        end;
        buffer:=ww;
        until key=#13;
{repeat
delete(ww,length(ww),1);
until ww[length(ww)] <>'';}

if buffer <>'' then  txt:=buffer;
end;

procedure viewfiles;
label bb;
var num:integer;
   { filename:text;}
   bf, wrd1,wrd2:string;
   fn1,fn2:text;
   searchword:boolean;
   nm:integer;

begin
 restart :=false;
 setfillstyle(1,7);
 bar(20,20,615,400);
 uppole(20,447,620,460,3,9,1,1,2,true,true,true,true,false);
 outtextxy(25,450,'F8-правка   F9-печать ESC-выход ENTER-сделать активным DEl-удалить');


       FindFirst('dict\*.dic', Archive, DirInfo);
       for i:=1 to 1000 do
       begin
       names[i]:='';
       end;
       i:=0;
        repeat
        i:=i+1;
        FindNext(DirInfo);
        names[i]:=dirinfo.name;
        until doserror <> 0;

        FindFirst('dict\*.dic', Archive, DirInfo);
        names[i]:=dirinfo.name;
        numoffiles:=i;

        setcolor(1);
   line(17,380,17,16);
   line(17,17,153,17);
   line(16,382,16,16);
   line(17,16,154,16);

   setcolor(9);
   line(17,380,152,380);
   line(152,380,152,17);
   line(17,381,153,381);
   line(153,381,153,17);
   line(17,382,154,382);
   line(154,382,154,17);
        i:=0;
        setcolor(1);
        for i:= 1 to 30 do  outtextxy(40,i*12+10,names[i]);
        {k:=num; }
        num:=1;


                        repeat
                        mouseshow;
                        delay(100);
                        repeat
                        ms:=mousegetb(mask);
                        until (keypressed) or (ms=1)or(ms=2);
                        key:='e';
                        if keypressed then key:=readkey;
                        mousehide;



       if (key=#66)or((mouselock(20,445,110,459))and( ms=1)) then
       begin
       setcolor(11);
       outtextxy(25,450,'F8-правка  ');
       morf:=false;
       if dictionary <> 'defoult.dic' then flist(dictionary);
              setcolor(1);
       outtextxy(25,450,'F8-правка  ');
            setfillstyle(1,7);
       bar(100,80,623,398);
       end;




if (key=#83)or((mouselock(460,445,560,459))and( ms=1)) then
begin
setcolor(4);
outtextxy(25,450,'                                                       DEl-удалить');
setfillstyle(1,4);
bar(160,210,490,260);
uppole(150,200,480,250,7,9,1,1,1,true,true,true,true,false);
downpole(152,202,478,248,3,9,1,1,1,true,true,true,true,false);
setcolor(4);
outtextxy(155,210,'Вы уверены ?');
uppole(250,207,260,220,3,9,1,1,1,true,true,true,true,false);
uppole(265,207,275,220,3,9,1,1,1,true,true,true,true,false);
outtextxy(252,210,'Y');
outtextxy(267,210,'N');
mouseshow;
delay(100);
ms:=3;
repeat
ms:=mousegetb(mask);
until (keypressed)or(ms=1);
mousehide;
if ms<>1 then key:=readkey;
if ((key = 'y')or(key='Y')or ((mouselock(250,207,260,220))and(ms=1))) and (dictionary<>'defoult.dic') then
begin
downpole(250,207,260,220,3,9,1,1,1,true,true,true,true,false);
outtextxy(252,210,'Y');
delay(500);
assign(filename,'dict\'+dictionary);
erase(filename);
assign(filename,'rus\'+dictionary);
erase(filename);
end
else
begin
downpole(265,207,275,220,3,9,1,1,1,true,true,true,true,false);
outtextxy(252,210,'N');
delay(500);

end;
setfillstyle(1,7);
bar(160,190,490,260);
dictionary:='defoult.dic';
numoffiles:=numoffiles-1;
restart:=true;
key:=#27;

end;



   IF (key=#67)or((mouselock(120,445,190,459))and( ms=1)) then

   begin
   setcolor(0);
   outtextxy(25,450,'            F9-печать ');
   f:=0;
  { assign(lst,'buffer.bac');
   rewrite(lst);             }
   assign(fil,'dict\'+dictionary);
   reset(fil);
   assign(filename,'rus\'+dictionary);
   reset(filename);
   ext1:=false;
   repeat
   repeat
   f:=f+1;
   readln(filename,buf);
   write(lst,buf);
   buf1:=buf1+buf;
   readln(fil,buf);
   write(lst,'-'+ buf);
   buf1:=buf1+buf;
   if length(buf1) <25 then for i:= length(buf1) to 25 do write(lst,' ') else write(lst,'   ');
   buf1:='';

   readln(filename,buf);
   write(lst,buf);
   readln(fil,buf);
   writeln(lst,'-'+ buf)


   until (f>60) or (keypressed);
   close(lst);
   setfillstyle(1,0);
   bar(210,110,610,160);
   uppole(200,100,600,150,7,9,1,1,1,true,true,true,true,false);
   downpole(202,102,598,148,4,9,1,1,1,true,true,true,true,false);
   setcolor(0);
   sound(100);
   delay(100);
   nosound;
   outtextxy(210,110,'По окончании печати страницы');
   outtextxy(210,120,'вставьте новый лист и нажмите ENTER');
   outtextxy(210,130,'или ESC для остановки печати');

   repeat
   key:=readkey;

   IF (key=#27) then

   begin
   ext1:=true;
   exit;
   end;
   until (key= #13)  ;
   f:=0;
   writeln(lst,'                                                     ');
   setfillstyle(1,7);
   bar(200,100,615,170);

   until eof(filename)or (ext1=true);


   close(filename);
   end;


   if ((key = #80)or((mouselock(130,20,145,30))and( ms=1))) and (num<numoffiles-1) then
   begin

   setcolor(14);
   outtextxy(137,1*12+10,chr(25));
   {delay(100);}
   num:=num+1;
   end;
   if ((key = #72)or((mouselock(20,20,40,30))and( ms=1))) and (num>0) then
   begin
   setcolor(14);
   outtextxy(25,1*12+10,chr(24));
   {delay(100);}
   num:=num-1;
   end;

   if (key = #68) or ((mouselock(200,445,270,459))and( ms=1)) then
   begin
   setcolor(11);
   outtextxy(201,450,'ESC-выход');
   delay(100);
   break;
   end;

   if (key = #13)or((mouselock(20,20,120,30))and( ms=2))or((mouselock(290,445,460,459))and( ms=1)) then
   begin
   if length(names[num+1])>=12 then dictionary:=names[num+1];
   end;
   setfillstyle(1,7);

   bar(18,18,154,380){,7,15,8,1,0,true,true,true,true,false);};
   setcolor(1);
   line(17,380,17,16);
   line(17,17,153,17);
   line(16,382,16,16);
   line(17,16,154,16);

   setcolor(9);
   line(17,380,152,380);
   line(152,380,152,17);
   line(17,381,153,381);
   line(153,381,153,17);
   line(17,382,154,382);
   line(154,382,154,17);
   {putpixel(154,382,11);
   putpixel(153,381,11);
   putpixel(152,380,11);}


{    p:=1;
   repeat
   if names[p+1]=dictionary then
   begin
   setcolor(11);
   outtextxy(20,p*12+10,names[p+1]);
   end;
   p:=p+1;
   until (p>30) or (p>numoffiles);}




setcolor(1);
{for i:= 1 to 30 do
begin              }
i:=0;
downpole(19,1*12+7,150,1*12+19,3,15,8,1,1,true,true,true,true,false);

repeat
i:=i+1;
setcolor(8);
outtextxy(40,i*12+10,names[num+i]);
setcolor(9);
outtextxy(25,1*12+10,chr(24));
outtextxy(137,1*12+10,chr(25));
setcolor(10);
{rectangle(18,1*12+8,120,1*12+18);}
setcolor(1);
if names[num+i]=dictionary then
begin
setcolor(11);
outtextxy(40,i*12+10,names[num+i]);
setcolor(1);
end;
until (i>= 30)or (num+i>numoffiles);
setcolor(11);
outtextxy(137,1*12+10,chr(25));
outtextxy(25,1*12+10,chr(24));
{end;}

until (key=#27);

key:=' ';

end;







begin

dictionary:='defoult.dic';
restart:=false;
randomize;
initgraph(gd,gm,'bgi');
{userfont:=installuserfont('sanseriffont.chr');
settextstyle(GothicFont,horizdir,1);USERFONT,horizdir,10);}

uppole(100,100,530,370,7,9,1,2,2,true,true,true,true,false);
downpole(105,105,525,365,7,9,1,2,2,true,true,true,true,false);
setcolor(10);

delay(500);


outtextxy(200,110,'"');
sound(50);
delay(50);
nosound;
delay(50);
outtextxy(200,110,'"K');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Ko');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Kon');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Kons');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konst');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konsta');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstan');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstant');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstanti');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin ');
{sound(50);
delay(50);
nosound;
delay(50);}outtextxy(200,110,'"Konstantin &');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & ');
{sound(50);
delay(50);
nosound;
delay(50);}outtextxy(200,110,'"Konstantin & K');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko"');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko" ');
{sound(50);
delay(50);
nosound;
delay(50);}outtextxy(200,110,'"Konstantin & Ko" p');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko" pr');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko" pre');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko" pres');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko" prese');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko" presen');
sound(50);
delay(50);
nosound;
delay(50);outtextxy(200,110,'"Konstantin & Ko" present');
sound(50);
delay(50);
nosound;
DELAY(520);outtextxy(200,110,'"Konstantin & Ko" present:');

setcolor(10);

sound(300);
DELAY(5);
nosound;
DELAY(30);
outtextxy(150,200,'В');

sound(300);
DELAY(5);
nosound;
DELAY(30);
outtextxy(150,200,'В ');

sound(300);
DELAY(5);
nosound;
DELAY(30);outtextxy(150,200,'В п');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В по');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В пом');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помо');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощ');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь ');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь и');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь из');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изу');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изуч');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изуча');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучаю');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающ');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающи');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим ');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим и');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим ин');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим ино');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим инос');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иност');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностр');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностра');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностран');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранн');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранны');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные ');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные я');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные яз');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные язы');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные язык');
sound(300);
delay(5);
nosound;
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные языки');
DELAY(30);outtextxy(150,200,'В помощь изучающим иностранные языки.');
outtextxy(150,200,'В помощь изучающим иностранные языки..');
outtextxy(150,200,'В помощь изучающим иностранные языки...');

{downpole(250,348,370,362,7,15,8,1,0,true,true,true,true,false);}



setcolor(1);
downpole(150,130,480,190,0,15,8,4,0,true,true,true,true,false);

logox:=150;
setcolor(9);
repeat
logox:=logox+1;
delay(10);
line(logox,130,logox,190 );
until  logox=480;

setfillstyle(1,9);
logox:=150;
settextstyle(Triplexfont,horizdir,6);
repeat
setcolor(9);
outtextxy(155,120,'▒▒LINGVIST▒▒ ');

{delay(2);}
logox:=logox+1;
setcolor(0);
line(logox,130,logox,190 );
bar(logox+1,130,480,190);
until  logox=480;
downpole(150,130,480,190,0,15,8,4,0,true,true,true,true,false);
settextstyle(defaultfont,horizdir,1);
setcolor(10);
{outtextxy(150,200,'В помощь изучающим иностранные языки...');}

{downpole(250,348,370,362,7,15,8,1,0,true,true,true,true,false);}


load(140,220,'l');
setcolor(8);
outtextxy(220,338,'Нажмите любую клавишу...');
settextstyle(Triplexfont,horizdir,6);
repeat
setcolor(10);
outtextxy(155,120,'▒▒LINGVIST▒▒ ');
delay(50);
setcolor(11);
outtextxy(155,120,'  LINGVIST  ');
delay(50);
setcolor(9);
outtextxy(155,120,'  LINGVIST  ');
delay(50);
setcolor(1);
outtextxy(155,120,'  LINGVIST  ');
until keypressed;
setcolor(11);
outtextxy(155,120,'  LINGVIST  ');
load(140,220,'l');
settextstyle(defaultfont,horizdir,1);
{delay(1000);}
{if txt(250,350,10,1,7,4)<>'A217.427H' then
begin
closegraph;;
halt(1);
end;}



uppole(10,10,630,470,7,9,1,2,2,true,true,true,true,false);
downpole(15,15,625,465,7,9,1,2,2,true,true,true,true,false);
uppole(20,447,620,460,3,9,1,1,2,true,true,true,true,false);

setcolor(1);
outtextxy(25,430,'Помощь - F9');
outtextxy(25,450,'F1-словари F2-создать F3-тренировка F4-проверка F5-результаты F10-выход');
outtextxy(500,20,dictionary);

{load(200,30,'w');}

{uppole(560,420,620,430,3,9,1,1,2,true,true,true,true,false);
setcolor(7);
outtextxy(560,420,'[s]ound');}

mouseinit;
mouseshow;

num:=0;
assign(fil,'dict\'+dictionary);
reset(fil);

repeat
num:=num+1;
readln(fil,buf);
until buf='';

str(num-1,stringnum);
setcolor(8);
outtextxy(480,30,'Кол-во слов: '+stringnum);

repeat

repeat
mouseshow;
ms:=mousegetb(mask);
mouseread(mx,my,mask);
until (keypressed)or(ms=1);
if ms <>1 then
begin
mx:=0;my:=0;
key:=readkey;
end;
mousehide;

{uppole(560,420,620,430,3,9,1,1,2,true,true,true,true,false);
setcolor(7);
outtextxy(560,420,'[s]ound');}

(****************************************************************)

if (key=#59)or((mx>20)and(mx<110)and(my>445)and(my<459)) then
begin

setcolor(11);
outtextxy(25,450,'F1-словари ');
delay(100);
repeat
viewfiles;
until restart<>true;
key:=' ';
num:=0;
assign(fil,'dict\'+dictionary);
reset(fil);
repeat
num:=num+1;
readln(fil,buf);
until buf='';
str(num-1,stringnum);
end;
(**************************************************************)
if (key=#67)or (presslock(25,430,70,440,1)) then
begin

filesearch(dest,'help.txt',list);
if dest[0] <> #0 then
begin

helppos:=1;
key:='s';
setfillstyle(1,8);
bar(110,60,360,310);
bar(368,62,388,310);
uppanel(100,50,350,300,3,9,1,2,1,false,true,true);
uppanel(360,50,380,300,3,9,1,2,1,false,true,true);
downpanel(362,52,378,298,3,9,1,2,1,false,true,true);

helplength:=0;

repeat
buf:=readf('help.txt',helplength,1,30);
helplength:=helplength+1;;
until buf='';
if helplength> 200 then helplength:=200;
helppos:=1;
helpstep:=trunc(346/helplength);
if helpstep>1 then helpstep:=1;
helpyold:=62+helpstep*helppos;
uppanel(364,62+helpstep*helppos-5,376,62+helpstep*helppos+5,
7,15,8,1,0,false,true,true);

repeat
setcolor(0);

outtextxy(110,70,readf('help.txt',helppos+1,1,30));
outtextxy(110,80,readf('help.txt',helppos+2,1,30));
outtextxy(110,90,readf('help.txt',helppos+3,1,30));
outtextxy(110,100,readf('help.txt',helppos+4,1,30));
outtextxy(110,110,readf('help.txt',helppos+5,1,30));
outtextxy(110,120,readf('help.txt',helppos+6,1,30));
outtextxy(110,130,readf('help.txt',helppos+7,1,30));
outtextxy(110,140,readf('help.txt',helppos+8,1,30));
outtextxy(110,150,readf('help.txt',helppos+9,1,30));
outtextxy(110,160,readf('help.txt',helppos+10,1,30));
outtextxy(110,170,readf('help.txt',helppos+11,1,30));
outtextxy(110,180,readf('help.txt',helppos+12,1,30));
outtextxy(110,190,readf('help.txt',helppos+13,1,30));
outtextxy(110,200,readf('help.txt',helppos+14,1,30));
outtextxy(110,210,readf('help.txt',helppos+15,1,30));
outtextxy(110,220,readf('help.txt',helppos+16,1,30));
outtextxy(110,230,readf('help.txt',helppos+17,1,30));
outtextxy(110,240,readf('help.txt',helppos+18,1,30));
outtextxy(110,250,readf('help.txt',helppos+19,1,30));
outtextxy(110,260,readf('help.txt',helppos+20,1,30));

repeat
mouseshow;
ms:=mousegetb(mask);
until (keypressed)or(ms=1);
if ms<>1 then key:=readkey;
if (key=#72)and(helppos>0) then helppos:=helppos-1;
if (key=#80)and(helppos<helplength) then helppos:=helppos+1;
downpanel(362,52,378,298,3,9,1,2,1,false,true,true);
uppanel(364,62+helpstep*helppos-5,376,62+helpstep*helppos+5,
7,15,8,1,0,false,true,true);
if presslock(364,62+helpstep*helppos-5,376,62+helpstep*helppos+5,1) then
begin
mousehide;
repeat
helpyold:= 62+helpstep*helppos;
ms:= mousegetb(mask);
if ms= 1 then mouseread(mx,my,mask);
if (my>helpyold) and (helppos<helplength)then helppos:=helppos+1;
if (my<helpyold) and (helppos>0)then helppos:=helppos-1;
uppanel(364,62+helpstep*helppos-5,376,62+helpstep*helppos+5,
7,15,8,1,0,false,true,true);
setcolor(3);
until ms<>1;
downpanel(362,52,378,298,3,9,1,2,1,false,true,true);
uppanel(364,62+helpstep*helppos-5,376,62+helpstep*helppos+5,
7,15,8,1,0,false,true,true);
end;
setfillstyle(1,3);
bar(100,50,350,298);

outtextxy(110,70,readf('help.txt',helppos+1,1,30));
outtextxy(110,80,readf('help.txt',helppos+2,1,30));
outtextxy(110,90,readf('help.txt',helppos+3,1,30));
outtextxy(110,100,readf('help.txt',helppos+4,1,30));
outtextxy(110,110,readf('help.txt',helppos+5,1,30));
outtextxy(110,120,readf('help.txt',helppos+6,1,30));
outtextxy(110,130,readf('help.txt',helppos+7,1,30));
outtextxy(110,140,readf('help.txt',helppos+8,1,30));
outtextxy(110,150,readf('help.txt',helppos+9,1,30));
outtextxy(110,160,readf('help.txt',helppos+10,1,30));
outtextxy(110,170,readf('help.txt',helppos+11,1,30));
outtextxy(110,180,readf('help.txt',helppos+12,1,30));
outtextxy(110,190,readf('help.txt',helppos+13,1,30));
outtextxy(110,200,readf('help.txt',helppos+14,1,30));
outtextxy(110,210,readf('help.txt',helppos+15,1,30));
outtextxy(110,220,readf('help.txt',helppos+16,1,30));
outtextxy(110,230,readf('help.txt',helppos+17,1,30));
outtextxy(110,240,readf('help.txt',helppos+18,1,30));
outtextxy(110,250,readf('help.txt',helppos+19,1,30));
outtextxy(110,260,readf('help.txt',helppos+20,1,30));
if (presslock(1,1,640,480,2)) then key:=#27;
until (key=#27);
mousehide;
end;
end;

(****************************************************************)


if (key=#60) or((mx>110)and(mx<190)and(my>445)and(my<459))then
begin

setcolor(11);
outtextxy(25,450,'           F2-создать ');
delay(100);
setfillstyle(1,0);
bar(160,210,490,260);
uppole(150,200,480,250,7,9,1,1,1,true,true,true,true,false);
downpole(152,202,478,248,3,9,1,1,1,true,true,true,true,false);
setcolor(8);
outtextxy(155,210,'Введите название нового словаря (8 букв)');
      slovo:='';
      slovo:=txt(210,230,8,11,3,1);


      if (length(slovo)<8)and(slovo<>'') then slovo:=slovo+'#######';

      if (slovo<>'') then
      begin
      slovo:=copy(slovo,1,8);
      assign(filename,'dict\'+slovo+'.dic');
      rewrite(filename);

      assign(filename,'rus\'+slovo+'.dic');
      rewrite(filename);

      close(filename);
      end;
      end;


(****************************************************************)
if (key=#62)or((mx>305)and(mx<405)and(my>445)and(my<459)) then
begin
vacantion:=true;
ppp:=0;
if dictionary='defoult.dic' then
begin
uppole(20,447,620,460,3,9,1,1,2,true,true,true,true,false);
setcolor(4);
outtextxy(25,450,'Выберите другой словарь...');
delay(100);
goto aa;
end;



setcolor(4);
outtextxy(25,450,'                                    F4-проверка ');
delay(500);
points:=0;
resultpercent:=0;
uppole(20,447,620,460,3,9,1,1,2,true,true,true,true,false);
setcolor(1);
outtextxy(25,450,'               1-малая 2-стандартная 3-полная ESC-exit');


mouseshow;
vacantion:=true;
ppp:=0;

repeat
ms:=mousegetb(mask);
until  (keypressed) or (ms =1)  ;
mousehide;
if ms =1 then mouseread(mx,my,mask);
if ms <> 1 then
begin
repeat
key:=readkey;
until (key='1') or (key='2') or (key='3')or (key=#27);
end;
u:=0;
if ((key = '1')or((mx>145)and(mx<200)and(my>445)and(my<459)))and(num>9)  then u:=10;
if ((key = '1')or((mx>145)and(mx<200)and(my>445)and(my<459)))and(num<=9)  then u:=num;
if ((key = '2')or((mx>210)and(mx<310)and(my>445)and(my<459)))and (num>49) then u:=50;
if ((key = '2')or((mx>210)and(mx<310)and(my>445)and(my<459)))and (num<=49) then u:=num;
if ((key = '3')or((mx>320)and(mx<385)and(my>445)and(my<459)))and(num<1000) then u:=num;
if ((key='3')or((mx>320)and(mx<385)and(my>445)and(my<459))) and(num>1000)then u:=1000;
if (key=#27)or((mx>390)and(mx<460)and(my>445)and(my<459)) then goto aa;


for o:=1 to 1000 do
begin
positions[o]:=0;
end;

for o:=1 to u do begin
assign(filename,'rus\'+dictionary);
reset(filename);
sit1:=0;


{for ppp:=1 to u do begin
if positions[ppp] = 0 then vacantion:=true else vacantion:=false;;
end;
ppp:=0;         }
repeat
ppp:=ppp+1;
sit1:= random(num);
if ppp>1000 then
begin
vacantion:=false
end;
until (positions[sit1] = 0)or (vacantion=false);;

question:=readfile(sit1,1,30,'rus\'+dictionary);
answer:=readfile(sit1,1,30,'dict\'+dictionary);
setfillstyle(1,0);
bar(160,210,500,260);
uppole(150,200,490,250,7,9,1,1,1,true,true,true,true,false);
downpole(152,202,488,248,3,9,1,1,0,true,true,true,true,false);
setcolor(11);
outtextxy(160,210,question+' - ');
{outtextxy(160,220,answer);}
slovo:=txt(160,220,30,1,3,0);
setfillstyle(1,7);
bar(300,330,500,430);
bar(30,40,100,60);
bar(30,60,300,80);

{if slovo[1] =' 'then delete(slovo,1,1);}
slovo:=copy(slovo,1,length(answer));
if slovo = answer then
begin
setfillstyle(1,7);
bar(30,40,100,60);
bar(30,60,600,80);
sound(100);
delay(50);
nosound;
points:=points+1;
printtime;

end;

if slovo <> answer then
begin
sound(1000);
delay(500);
nosound;
setcolor(4);
outtextxy(30,40,'ERROR');
{outtextxy(30,60,'Верный ответ: '+answer);}
printtime;
end;


str(o,buf1);
str(points,buf);
outtextxy(300,330,'Верно: '+buf+' из '+buf1);
resultpercent:=(points/o)*100;
str(resultpercent:3:2,buf);
outtextxy(300,340,'( '+buf+'% )');
close(filename);
printtime;
positions[sit1]:=1;

if vacantion=false then break;

end;

setfillstyle(1,0);
bar(160,210,500,260);
uppole(150,200,490,250,7,9,1,1,1,true,true,true,true,false);
downpole(152,202,488,248,3,9,1,1,0,true,true,true,true,false);
setcolor(0);
outtextxy(160,210,'Введите своё имя: ');
slovo:='';
slovo:=txt(160,220,36,1,3,0);
if slovo='' then slovo:= '* No_name *';
downpole(15,15,625,465,7,9,1,2,2,true,true,true,true,false);
setfillstyle(1,0);
bar(110,110,360,390);
uppole(100,100,350,380,3,9,1,2,2,true,true,true,true,false);

assign(filename,'Result.rs');
append(filename);

setcolor(8);
outtextxy(110,110,'Название словаря: '+dictionary);
writeln(filename,'*****************************');
writeln(filename,'Название словаря: '+dictionary);
close(filename);

setcolor(8);
outtextxy(110,130,'Имя испытуемого: '+copy(slovo,1,12));
append(filename);
writeln(filename,'Имя испытуемого: '+copy(slovo,1,12));
close(filename);

str(u,buf);
setcolor(8);
outtextxy(110,150,'Общее количество слов: '+buf);
append(filename);
writeln(filename,'Общее количество слов: '+buf);
close(filename);

str(points,buf);
setcolor(8);
outtextxy(110,170,'Верных ответов: '+buf);

append(filename);
writeln(filename,'Верных ответов: '+buf);
close(filename);

points:=trunc( (points*10)/u );
str(points,buf);
setcolor(8);
outtextxy(110,300,'Набрано балов (по 10-ти');
outtextxy(110,315,'бальной системе): '+buf);

append(filename);
writeln(filename,'Набрано балов (по 10-ти бальной системе): '+buf);
close(filename);

outtextxy(130,340,'Нажмите любую клавишу...');
repeat
ms:=mousegetb(mask);
until (keypressed)or (ms=1);
aa:
delay(100);
ms:=3;
mx:=1000;
end;
uppole(10,10,630,470,7,9,1,2,2,true,true,true,true,false);
downpole(15,15,625,465,7,9,1,2,2,true,true,true,true,false);
uppole(20,447,620,460,3,9,1,1,2,true,true,true,true,false);
setcolor(1);
outtextxy(25,430,'Помощь - F9');
outtextxy(25,450,'F1-словари F2-создать F3-тренировка F4-проверка F5-результаты F10-выход');
outtextxy(500,20,dictionary);

if (key = #63)or(mouselock(405,445,510,459)and( ms=1))then
{((mx>405)and(mx<510)and(my>445)and(my<459))then}
begin
{filesearch(dest,namesearch,list);
if dest[0] = #0 then
begin
assign(fl,'result.rs');
rewrite(fl);
close(fl);
end;}
setfillstyle(1,0);
bar(110,110,390,390);
uppole(100,100,380,380,11,15,7,2,2,false,false,false,false,false);

uppole(110,360,120,370,11,15,7,2,2,false,false,false,false,false);
uppole(360,360,370,370,11,15,7,2,2,false,false,false,false,false);
setcolor(0);
outtextxy(110,360,chr(27));
outtextxy(360,360,chr(26));
outtextxy(110,120,readfile(1,1,30,'Result.rs'));
outtextxy(110,130,readfile(2,1,30,'Result.rs'));
outtextxy(110,140,readfile(3,1,30,'Result.rs'));
outtextxy(110,150,readfile(4,1,30,'Result.rs'));
outtextxy(110,160,readfile(5,1,30,'Result.rs'));
outtextxy(110,170,readfile(6,1,30,'Result.rs'));
outtextxy(110,180,readfile(6,32,30,'Result.rs'));
delay(100);
o:=1;

setcolor(11);
outtextxy(25,450,'                                                F5-результаты');

repeat

repeat
mouseshow;
ms:=mousegetb(mask);
mouseread(mx,my,mask);
until (keypressed )or (ms=1) or(ms=2);

if (ms<>1)and(ms<>2) then key:=readkey;
mousehide;
if ms = 2 then
begin
key:='f';
break;
end;

if key = #27 then
begin
key:='f';
break;
end;



if (key = #77) or((mx>360)and(mx<370)and(my>360)and(my<370))then
begin
mousesetpos(371,371);
o:=o+6;
key:='f';
downpole(360,360,370,370,11,15,7,2,2,false,false,false,false,false);
delay(100);
end;
if ((key = #75)or((mx>110)and(mx<120)and(my>360)and(my<370))) and(o>6) then
begin
mousesetpos(121,371);
o:=o-6;
key:='f';
downpole(110,360,120,370,11,15,7,2,2,false,false,false,false,false);
delay(100);
end;


setfillstyle(1,0);
bar(110,110,390,390);
uppole(100,100,380,380,11,15,7,2,2,false,false,false,false,false);
setcolor(0);
outtextxy(110,110,readfile(o,1,30,'Result.rs'));
outtextxy(110,120,readfile(o+1,1,30,'Result.rs'));
outtextxy(110,130,readfile(o+2,1,30,'Result.rs'));
outtextxy(110,140,readfile(o+3,1,30,'Result.rs'));
outtextxy(110,150,readfile(o+4,1,30,'Result.rs'));
outtextxy(110,170,readfile(o+5,1,30,'Result.rs'));
outtextxy(110,180,readfile(o+5,32,30,'Result.rs'));

uppole(110,360,120,370,11,15,7,2,2,false,false,false,false,false);
uppole(360,360,370,370,11,15,7,2,2,false,false,false,false,false);
setcolor(0);
outtextxy(110,360,chr(27));
outtextxy(360,360,chr(26));

outtextxy(110,340,'Листайте курсорами');
outtextxy(110,350,'или ESC (либо правую кнопку ');
outtextxy(150,360,'        мыши) для выхода');

until key= #27;

END;

(****************************************************************)
if (key=#61)or((mx>195)and(mx<300)and(my>445)and(my<459)) then
begin

setfillstyle(1,0);
bar(160,210,490,260);
uppole(150,200,490,250,7,9,1,1,1,true,true,true,true,false);
downpole(152,202,488,248,3,9,1,1,0,true,true,true,true,false);
setcolor(11);
outtextxy(160,210,'После появления слова введите его перевод');
outtextxy(160,220,'на соответствующий язык (без пробелов в ');
outtextxy(160,230,' начале строки).Для выхода введите ESC');

repeat
key:=readkey;
until (key<>#13) and(key<>#27);


points:=0;
i:=0;
period:=1;
numerror:=0;
repeat
assign(filename,'rus\'+dictionary);
reset(filename);
sit1:= random(num);
if (errorword<>0) then
begin
if  (period = 1) then
begin
sit1:=errorword;
numerror:=numerror+1;
end;
end;
period :=-period;

if numerror> 5 then
begin
numerror:=0;
errorword:=0;

end;
i:=i+1;
question:=readfile(sit1,1,30,'rus\'+dictionary);
answer:=readfile(sit1,1,30,'dict\'+dictionary);
setfillstyle(1,0);
bar(160,210,500,260);
uppole(150,200,490,250,7,9,1,1,1,true,true,true,true,false);
downpole(152,202,488,248,3,9,1,1,0,true,true,true,true,false);
setcolor(11);
outtextxy(160,210,question+' - ');
{outtextxy(160,220,answer);}
slovo:=txt(160,220,30,1,3,0);
setfillstyle(1,7);
bar(300,330,500,430);
bar(30,40,100,60);
bar(30,60,300,80);

{if slovo[1] =' 'then delete(slovo,1,1);}


slovo:=copy(slovo,1,length(answer));
if slovo = answer then
begin
setfillstyle(1,7);
bar(30,40,100,60);
bar(30,60,600,80);
sound(50);
delay(10);
nosound;
points:=points+1;
printtime;
end;

if slovo <> answer then
begin
errorword:=sit1;
sound(100);
delay(50);
nosound;
setcolor(4);
outtextxy(30,40,'ERROR');
outtextxy(30,60,'Верный ответ: '+answer);
printtime;
end;


str(i,buf1);
str(points,buf);
{outtextxy(300,330,'Верно: '+buf+' из '+buf1);}
resultpercent:=(points/i)*100;
str(resultpercent:3:2,buf);
{outtextxy(300,340,'( '+buf+'% )');}
close(filename);
printtime;
until ext=true;
key :='f';
end ;

uppole(10,10,630,470,7,9,1,2,2,true,true,true,true,false);
downpole(15,15,625,465,7,9,1,2,2,true,true,true,true,false);
uppole(20,447,620,460,3,9,1,1,2,true,true,true,true,false);
setcolor(1);
outtextxy(25,430,'Помощь - F9');
outtextxy(25,450,'F1-словари F2-создать F3-тренировка F4-проверка F5-результаты  F10-выход');
outtextxy(500,20,dictionary);
outtextxy(480,30,'Кол-во слов: '+stringnum);
printtime;
{if snd = '1' then uppole(560,420,620,430,3,9,1,1,2,true,true,true,true,false);
if snd = '0' then downpole(560,420,620,430,3,9,1,1,2,true,true,true,true,false);
setcolor(7);
if snd = '1' then setcolor(0);
outtextxy(560,422,'[s]ound');}
{if (key ='s')or((mouselock(560,420,620,430))and (ms=1)) then
begin
if snd ='1' then snd:='0' else snd:='1';
assign(fil,'sound.cfg');
rewrite(fil);
write(fil,snd);
close(fil);
end;}

if (key = #68)or((mx>520)and(mx<620)and(my>445)and(my<459)) then
begin
setfillstyle(1,0);
bar(160,210,490,260);
uppole(150,200,490,250,7,9,1,1,1,true,true,true,true,false);
downpole(152,202,488,248,4,9,1,1,0,true,true,true,true,false);
setcolor(0);
outtextxy(155,210,'Вы точно хотите покинуть программу ? (y/n)');
setfillstyle(1,0);

bar(205,245,245,255);
bar(405,245,445,255);
bar(210,260,250,270);
bar(410,260,450,270);

uppole(200,240,240,260,3,9,1,1,1,true,true,true,true,false);
uppole(400,240,440,260,3,9,1,1,1,true,true,true,true,false);
setcolor(9);
outtextxy(218,250,'Y');
outtextxy(418,250,'N');
mouseshow;
repeat
ms:=mousegetb(mask);
if ms = 1 then mouseread(mx,my,mask);

until (keypressed) or ((mx >200)and(mx<240)and(my>240)and(my<260))or((mx >400)and(mx<440)and(my>240)and(my<260));
if ms<>1 then key :=readkey;
if (key='y')or (key='Y')or ((mx >200)and(mx<240)and(my>240)and(my<260))then
begin
key:=#68;
mousehide;
uppole(200,240,240,260,10,9,1,1,1,true,true,true,true,false);
delay(100);
end;

if (key<>'y')and (key <>'Y') and (mouselock(400,240,440,260)=true) then
begin
key:='r';
mousehide;
uppole(400,240,440,260,10,9,1,1,1,true,true,true,true,false);
delay(100);
end;

setfillstyle(1,7);
bar(140,190,500,380);
end;

until (key = #68);



(****************************************************************)
{if key = #62 then
begin
gettime


end; }



closegraph;
end.