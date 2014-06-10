# Microsoft Developer Studio Generated NMAKE File, Based on diblook.dsp
!IF "$(CFG)" == ""
CFG=DibLook - Win32 Release
!MESSAGE No configuration specified.  Defaulting to DibLook - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DibLook - Win32 Release" && "$(CFG)" !=\
 "DibLook - Win32 Debug" && "$(CFG)" != "DibLook - Macintosh Release" &&\
 "$(CFG)" != "DibLook - Macintosh Debug" && "$(CFG)" !=\
 "DibLook - Power Macintosh Release" && "$(CFG)" !=\
 "DibLook - Power Macintosh Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "diblook.mak" CFG="DibLook - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DibLook - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DibLook - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "DibLook - Macintosh Release" (based on "Macintosh Application")
!MESSAGE "DibLook - Macintosh Debug" (based on "Macintosh Application")
!MESSAGE "DibLook - Power Macintosh Release" (based on\
 "Power Macintosh Application")
!MESSAGE "DibLook - Power Macintosh Debug" (based on\
 "Power Macintosh Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "DibLook - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\diblook.exe"

CLEAN : 
	-@erase "$(INTDIR)\dibapi.obj"
	-@erase "$(INTDIR)\dibdoc.obj"
	-@erase "$(INTDIR)\diblook.obj"
	-@erase "$(INTDIR)\diblook.pch"
	-@erase "$(INTDIR)\diblook.res"
	-@erase "$(INTDIR)\dibview.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\myfile.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(OUTDIR)\diblook.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/diblook.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/diblook.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/diblook.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/diblook.pdb" /machine:I386 /out:"$(OUTDIR)/diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dibapi.obj" \
	"$(INTDIR)\dibdoc.obj" \
	"$(INTDIR)\diblook.obj" \
	"$(INTDIR)\diblook.res" \
	"$(INTDIR)\dibview.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\myfile.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\diblook.exe"

CLEAN : 
	-@erase "$(INTDIR)\dibapi.obj"
	-@erase "$(INTDIR)\dibdoc.obj"
	-@erase "$(INTDIR)\diblook.obj"
	-@erase "$(INTDIR)\diblook.pch"
	-@erase "$(INTDIR)\diblook.res"
	-@erase "$(INTDIR)\dibview.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\myfile.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\diblook.exe"
	-@erase "$(OUTDIR)\diblook.ilk"
	-@erase "$(OUTDIR)\diblook.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/diblook.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/diblook.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/diblook.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/diblook.pdb" /debug /machine:I386 /out:"$(OUTDIR)/diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dibapi.obj" \
	"$(INTDIR)\dibdoc.obj" \
	"$(INTDIR)\diblook.obj" \
	"$(INTDIR)\diblook.res" \
	"$(INTDIR)\dibview.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\myfile.obj" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

OUTDIR=.\MacRel
INTDIR=.\MacRel

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MFILE32=mfile.exe
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/diblook.exe"

"$(OUTDIR)\diblook.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacRel\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacRel\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

LINK32=link.exe
LINK32_FLAGS=/nologo /MAC:bundle /MAC:type="APPL" /MAC:creator="DIBL"\
 /pdb:"$(OUTDIR)/diblook.pdb" /machine:M68K /out:"$(OUTDIR)/diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)/dibdoc.obj" \
	"$(INTDIR)/dibapi.obj" \
	"$(INTDIR)/diblook.obj" \
	"$(INTDIR)/myfile.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/dibview.obj" \
	"$(INTDIR)/diblmac.rsc" \
	"$(INTDIR)/diblook.rsc"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/diblook.bsc" 
BSC32_SBRS=
MRC=mrc.exe
MRC_PROJ=/D "_68K_" /D "_MAC" /D "NDEBUG" /l 0x409 /NOLOGO 
RSC=rc.exe
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/diblook.rsc" /d "_MAC" /d "_68K_" /d\
 "NDEBUG" 
CPP=cl.exe
CPP_PROJ=/nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D\
 "WIN32" /D "NDEBUG" /D "_MBCS" /Fp"$(INTDIR)/diblook.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\MacRel/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
MTL_PROJ=/nologo /D "NDEBUG" /mac 

CLEAN : 
	-@erase ".\MacRel\diblook.trg"
	-@erase ".\MacRel\diblook.exe"
	-@erase ".\MacRel\dibdoc.obj"
	-@erase ".\MacRel\diblook.pch"
	-@erase ".\MacRel\dibapi.obj"
	-@erase ".\MacRel\diblook.obj"
	-@erase ".\MacRel\myfile.obj"
	-@erase ".\MacRel\stdafx.obj"
	-@erase ".\MacRel\mainfrm.obj"
	-@erase ".\MacRel\dibview.obj"
	-@erase ".\MacRel\diblmac.rsc"
	-@erase ".\MacRel\diblook.rsc"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

OUTDIR=.\MacDbg
INTDIR=.\MacDbg

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MFILE32=mfile.exe
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/diblook.exe"

"$(OUTDIR)\diblook.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacDbg\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacDbg\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

LINK32=link.exe
LINK32_FLAGS=/nologo /MAC:bundle /MAC:type="APPL" /MAC:creator="DIBL"\
 /pdb:"$(OUTDIR)/diblook.pdb" /debug /machine:M68K /out:"$(OUTDIR)/diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)/dibdoc.obj" \
	"$(INTDIR)/dibapi.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/dibview.obj" \
	"$(INTDIR)/myfile.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/diblook.obj" \
	"$(INTDIR)/diblook.rsc" \
	"$(INTDIR)/diblmac.rsc"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/diblook.bsc" 
BSC32_SBRS=
MRC=mrc.exe
MRC_PROJ=/D "_68K_" /D "_MAC" /D "_DEBUG" /l 0x409 /NOLOGO 
RSC=rc.exe
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/diblook.rsc" /d "_MAC" /d "_68K_" /d\
 "_DEBUG" 
CPP=cl.exe
CPP_PROJ=/nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D\
 "_68K_" /D "WIN32" /D "_DEBUG" /D "_MBCS" /Fp"$(INTDIR)/diblook.pch"\
 /Yu"Stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\MacDbg/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
MTL_PROJ=/nologo /D "_DEBUG" /mac 

CLEAN : 
	-@erase ".\MacDbg\vc40.pdb"
	-@erase ".\MacDbg\diblook.pch"
	-@erase ".\MacDbg\diblook.pdb"
	-@erase ".\MacDbg\dibdoc.obj"
	-@erase ".\MacDbg\dibapi.obj"
	-@erase ".\MacDbg\mainfrm.obj"
	-@erase ".\MacDbg\dibview.obj"
	-@erase ".\MacDbg\myfile.obj"
	-@erase ".\MacDbg\stdafx.obj"
	-@erase ".\MacDbg\diblook.obj"
	-@erase ".\MacDbg\diblook.rsc"
	-@erase ".\MacDbg\diblmac.rsc"
	-@erase ".\MacDbg\diblook.trg"
	-@erase ".\MacDbg\diblook.exe"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

OUTDIR=.\PMacRel
INTDIR=.\PMacRel

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MFILE32=mfile.exe
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/diblook.exe"

"$(OUTDIR)\diblook.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacRel\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacRel\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

LINK32=link.exe
LINK32_FLAGS=/nologo /mac:bundle /mac:type="APPL" /mac:creator="DIBL"\
 /incremental:no /pdb:"$(OUTDIR)/diblook.pdb" /machine:MPPC\
 /out:"$(OUTDIR)/diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/diblook.obj" \
	"$(INTDIR)/dibdoc.obj" \
	"$(INTDIR)/dibapi.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/dibview.obj" \
	"$(INTDIR)/myfile.obj" \
	"$(INTDIR)/diblmac.rsc" \
	"$(INTDIR)/diblook.rsc"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/diblook.bsc" 
BSC32_SBRS=
MRC=mrc.exe
MRC_PROJ=/D "_MPPC_" /D "_MAC" /D "NDEBUG" /l 0x409 /NOLOGO 
RSC=rc.exe
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/diblook.rsc" /d "_MAC" /d "_MPPC_" /d\
 "NDEBUG" 
CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "_MAC" /D "_MPPC_" /D\
 "_WINDOWS" /D "WIN32" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)/diblook.pch"\
 /Yu"Stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\PMacRel/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
MTL_PROJ=/nologo /D "NDEBUG" 

CLEAN : 
	-@erase ".\PMacRel\diblook.trg"
	-@erase ".\PMacRel\diblook.exe"
	-@erase ".\PMacRel\stdafx.obj"
	-@erase ".\PMacRel\diblook.obj"
	-@erase ".\PMacRel\diblook.pch"
	-@erase ".\PMacRel\dibdoc.obj"
	-@erase ".\PMacRel\dibapi.obj"
	-@erase ".\PMacRel\mainfrm.obj"
	-@erase ".\PMacRel\dibview.obj"
	-@erase ".\PMacRel\myfile.obj"
	-@erase ".\PMacRel\diblmac.rsc"
	-@erase ".\PMacRel\diblook.rsc"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

OUTDIR=.\PMacDbg
INTDIR=.\PMacDbg

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MFILE32=mfile.exe
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/diblook.exe"

"$(OUTDIR)\diblook.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacDbg\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacDbg\diblook.exe\
 "$(MFILE32_DEST):diblook.exe">"$(OUTDIR)\diblook.trg"

LINK32=link.exe
LINK32_FLAGS=/nologo /mac:bundle /mac:type="APPL" /mac:creator="DIBL"\
 /incremental:yes /pdb:"$(OUTDIR)/diblook.pdb" /debug /machine:MPPC\
 /out:"$(OUTDIR)/diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)/dibview.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/diblook.obj" \
	"$(INTDIR)/dibdoc.obj" \
	"$(INTDIR)/dibapi.obj" \
	"$(INTDIR)/myfile.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/diblook.rsc" \
	"$(INTDIR)/diblmac.rsc"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/diblook.bsc" 
BSC32_SBRS=
MRC=mrc.exe
MRC_PROJ=/D "_MPPC_" /D "_MAC" /D "_DEBUG" /l 0x409 /NOLOGO 
RSC=rc.exe
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/diblook.rsc" /d "_MAC" /d "_MPPC_" /d\
 "_DEBUG" 
CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /GX /Zi /Od /D "_DEBUG" /D "_MAC" /D "_MPPC_" /D\
 "_WINDOWS" /D "WIN32" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)/diblook.pch"\
 /Yu"Stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\PMacDbg/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
MTL_PROJ=/nologo /D "_DEBUG" 

CLEAN : 
	-@erase ".\PMacDbg\vc40.pdb"
	-@erase ".\PMacDbg\diblook.pch"
	-@erase ".\PMacDbg\diblook.ilk"
	-@erase ".\PMacDbg\dibview.obj"
	-@erase ".\PMacDbg\stdafx.obj"
	-@erase ".\PMacDbg\diblook.obj"
	-@erase ".\PMacDbg\dibdoc.obj"
	-@erase ".\PMacDbg\dibapi.obj"
	-@erase ".\PMacDbg\myfile.obj"
	-@erase ".\PMacDbg\mainfrm.obj"
	-@erase ".\PMacDbg\diblook.rsc"
	-@erase ".\PMacDbg\diblmac.rsc"
	-@erase ".\PMacDbg\diblook.pdb"
	-@erase ".\PMacDbg\diblook.trg"
	-@erase ".\PMacDbg\diblook.exe"

!ENDIF 


!IF "$(CFG)" == "DibLook - Win32 Release" || "$(CFG)" ==\
 "DibLook - Win32 Debug" || "$(CFG)" == "DibLook - Macintosh Release" ||\
 "$(CFG)" == "DibLook - Macintosh Debug" || "$(CFG)" ==\
 "DibLook - Power Macintosh Release" || "$(CFG)" ==\
 "DibLook - Power Macintosh Debug"
SOURCE=.\dibapi.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_CPP_DIBAP=\
	".\dibapi.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibapi.obj" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_CPP_DIBAP=\
	".\dibapi.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibapi.obj" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\dibapi.obj" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\dibapi.obj" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\dibapi.obj" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_CPP_DIBAP=\
	".\dibapi.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibapi.obj" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBAP) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ENDIF 

SOURCE=.\dibdoc.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_CPP_DIBDO=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibdoc.obj" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_CPP_DIBDO=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibdoc.obj" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\dibdoc.obj" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\dibdoc.obj" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\dibdoc.obj" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_CPP_DIBDO=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibdoc.obj" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBDO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ENDIF 

SOURCE=.\diblmac.r

!IF  "$(CFG)" == "DibLook - Win32 Release"

!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

NODEP_MRC_DIBLM=\
	".\mrc\balloons.r"\
	".\mrc\types.r"\
	

"$(INTDIR)\diblmac.rsc" : $(SOURCE) $(DEP_MRC_DIBLM) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/diblmac.rsc" /D "_68K_" /D "_MAC" /D "NDEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

NODEP_MRC_DIBLM=\
	".\mrc\balloons.r"\
	".\mrc\types.r"\
	

"$(INTDIR)\diblmac.rsc" : $(SOURCE) $(DEP_MRC_DIBLM) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/diblmac.rsc" /D "_68K_" /D "_MAC" /D "_DEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

NODEP_MRC_DIBLM=\
	".\mrc\balloons.r"\
	".\mrc\types.r"\
	

"$(INTDIR)\diblmac.rsc" : $(SOURCE) $(DEP_MRC_DIBLM) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/diblmac.rsc" /D "_MPPC_" /D "_MAC" /D "NDEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

NODEP_MRC_DIBLM=\
	".\mrc\balloons.r"\
	".\mrc\types.r"\
	

"$(INTDIR)\diblmac.rsc" : $(SOURCE) $(DEP_MRC_DIBLM) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/diblmac.rsc" /D "_MPPC_" /D "_MAC" /D "_DEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ENDIF 

SOURCE=.\diblook.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_CPP_DIBLO=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\dibview.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\diblook.obj" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_CPP_DIBLO=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\dibview.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\diblook.obj" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\diblook.obj" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\diblook.obj" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\diblook.obj" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_CPP_DIBLO=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\dibview.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\diblook.obj" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBLO) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ENDIF 

SOURCE=.\diblook.rc

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_RSC_DIBLOO=\
	".\res\dibdoc.ico"\
	".\res\diblook.ico"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\diblook.res" : $(SOURCE) $(DEP_RSC_DIBLOO) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_RSC_DIBLOO=\
	".\res\dibdoc.ico"\
	".\res\diblook.ico"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\diblook.res" : $(SOURCE) $(DEP_RSC_DIBLOO) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\diblook.rsc" : $(SOURCE) $(DEP_RSC_DIBLOO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\diblook.rsc" : $(SOURCE) $(DEP_RSC_DIBLOO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\diblook.rsc" : $(SOURCE) $(DEP_RSC_DIBLOO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_RSC_DIBLOO=\
	".\res\dibdoc.ico"\
	".\res\diblook.ico"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\diblook.rsc" : $(SOURCE) $(DEP_RSC_DIBLOO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\dibview.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_CPP_DIBVI=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\dibview.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibview.obj" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_CPP_DIBVI=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\dibview.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibview.obj" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\dibview.obj" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\dibview.obj" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\dibview.obj" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_CPP_DIBVI=\
	".\dibapi.h"\
	".\dibdoc.h"\
	".\diblook.h"\
	".\dibview.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\dibview.obj" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIBVI) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ENDIF 

SOURCE=.\mainfrm.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_CPP_MAINF=\
	".\diblook.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_CPP_MAINF=\
	".\diblook.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_CPP_MAINF=\
	".\diblook.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ENDIF 

SOURCE=.\myfile.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_CPP_MYFIL=\
	".\dibapi.h"\
	".\stdafx.h"\
	

"$(INTDIR)\myfile.obj" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_CPP_MYFIL=\
	".\dibapi.h"\
	".\stdafx.h"\
	

"$(INTDIR)\myfile.obj" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\myfile.obj" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\myfile.obj" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\myfile.obj" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_CPP_MYFIL=\
	".\dibapi.h"\
	".\stdafx.h"\
	

"$(INTDIR)\myfile.obj" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MYFIL) "$(INTDIR)"\
 "$(INTDIR)\diblook.pch"

!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\diblook.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/diblook.pch" /Yc /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\diblook.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/diblook.pch" /Yc /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "DibLook - Macintosh Release"

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\diblook.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "DibLook - Macintosh Debug"

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\diblook.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Release"

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\diblook.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "DibLook - Power Macintosh Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	
BuildCmds= \
	$(CPP) /nologo /MDd /W3 /GX /Zi /Od /D "_DEBUG" /D "_MAC" /D "_MPPC_" /D\
 "_WINDOWS" /D "WIN32" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)/diblook.pch" /Yc\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\diblook.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

SOURCE=.\dibapi.h
SOURCE=.\dibdoc.h
SOURCE=.\diblook.h
SOURCE=.\dibview.h
SOURCE=.\mainfrm.h
SOURCE=.\stdafx.h
SOURCE=.\res\dibdoc.ico
SOURCE=.\res\diblook.ico
SOURCE=.\res\toolbar.bmp

!ENDIF 

