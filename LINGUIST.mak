# ---------------------------------------------------------------------------
VERSION = BCB.01
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = LINGUIST.exe
OBJFILES = LINGUIST.obj MainUnit.obj NewDicUnit.obj List.obj AboutUnit.obj \
   "\User\Konst\projects\Linguist 2000 LE\ChngUnit.obj" \
   "\User\Konst\projects\Linguist 2000 LE\FindUnit.obj" \
   "\User\Konst\projects\Linguist 2000 LE\StartUnit.obj" \
   "\User\Konst\projects\Linguist 2000 LE\ExamUnit.obj" \
   "\User\Konst\projects\Linguist 2000 LE\Intrfc.obj" \
   "\User\Konst\projects\Linguist 2000 LE\POptUnit.obj" \
   "\User\Konst\projects\Linguist 2000 LE\Manual.obj"
RESFILES = "\User\Konst\projects\Linguist 2000 LE\Linguist.res"
RESDEPEN = $(RESFILES) MainUnit.dfm NewDicUnit.dfm AboutUnit.dfm \
   "\User\Konst\projects\Linguist 2000 LE\ChngUnit.dfm" \
   "\User\Konst\projects\Linguist 2000 LE\FindUnit.dfm" \
   "\User\Konst\projects\Linguist 2000 LE\StartUnit.dfm" \
   "\User\Konst\projects\Linguist 2000 LE\ExamUnit.dfm" \
   "\User\Konst\projects\Linguist 2000 LE\POptUnit.dfm" \
   "\User\Konst\projects\Linguist 2000 LE\Manual.dfm"
LIBFILES = 
DEFFILE = 
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Hc -w -k -r- -y -v -vi- -c -a4 -b- -w-par -w-inl -Vx -Ve -x -g255
CFLAG2 = -Ic:\user;"d:\ibm-hdd.20\user\konst\docs\delphy examples\—ортировка массива обменом";"d:\ibm-hdd.20\user\konst\docs\delphy examples\¬вод из memo";$(BCB)\projects;"d:\ibm-hdd.20\user\konst\projects\old builder\lingvist bad";.;$(BCB)\bin;$(BCB)\include;$(BCB)\include\vcl \
   -H=$(BCB)\lib\vcld.csm 
PFLAGS = -Uc:\user;"d:\ibm-hdd.20\user\konst\docs\delphy examples\—ортировка массива обменом";"d:\ibm-hdd.20\user\konst\docs\delphy examples\¬вод из memo";$(BCB)\projects;"d:\ibm-hdd.20\user\konst\projects\old builder\lingvist bad";.;$(BCB)\bin;$(BCB)\lib\obj;$(BCB)\lib \
   -Ic:\user;"d:\ibm-hdd.20\user\konst\docs\delphy examples\—ортировка массива обменом";"d:\ibm-hdd.20\user\konst\docs\delphy examples\¬вод из memo";$(BCB)\projects;"d:\ibm-hdd.20\user\konst\projects\old builder\lingvist bad";.;$(BCB)\bin;$(BCB)\include;$(BCB)\include\vcl \
   -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE -v \
   -$Y -$W -$O- -JPHNV -M     
RFLAGS = -ic:\user;"d:\ibm-hdd.20\user\konst\docs\delphy examples\—ортировка массива обменом";"d:\ibm-hdd.20\user\konst\docs\delphy examples\¬вод из memo";$(BCB)\projects;"d:\ibm-hdd.20\user\konst\projects\old builder\lingvist bad";.;$(BCB)\bin;$(BCB)\include;$(BCB)\include\vcl 
LFLAGS = -Lc:\user;"d:\ibm-hdd.20\user\konst\docs\delphy examples\—ортировка массива обменом";"d:\ibm-hdd.20\user\konst\docs\delphy examples\¬вод из memo";$(BCB)\projects;"d:\ibm-hdd.20\user\konst\projects\old builder\lingvist bad";.;$(BCB)\bin;$(BCB)\lib\obj;$(BCB)\lib \
   -aa -Tpe -x -v -V4.0 
IFLAGS = 
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0w32.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) vcl.lib import32.lib cp32mt.lib 
# ---------------------------------------------------------------------------
.autodepend

$(PROJECT): $(OBJFILES) $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) @&&!
    $(LFLAGS) +
    $(ALLOBJ), +
    $(PROJECT),, +
    $(ALLLIB), +
    $(DEFFILE), +
    $(ALLRES) 
!

.pas.hpp:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.pas.obj:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.cpp.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $* 

.c.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $**

.rc.res:
    $(BCB)\BIN\brcc32 $(RFLAGS) $<
#-----------------------------------------------------------------------------
