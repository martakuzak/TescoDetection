; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "diblook.h"

ClassCount=7
Class1=CDibDoc
Class2=CDibLookApp
Class3=CAboutDlg
Class4=CDibView
Class5=CMainFrame

ResourceCount=9
Resource1=IDR_DIBTYPE (English (U.S.))
Resource2=IDD_PARAMETERDIALOG
Resource3=IDD_ABOUTBOX
Resource4=IDR_MAINFRAME (_MAC)
Resource5=IDR_DIBTYPE (_MAC)
Resource6=IDR_DIBTYPE (English (U.S.) - _MAC)
Resource7=IDR_MAINFRAME (English (U.S.) - _MAC)
LastClass=CParameterDialog
Class6=COutputDoc
Resource8=IDD_ABOUTBOX (English (U.S.))
Class7=CParameterDialog
Resource9=IDR_MAINFRAME (English (U.S.))

[CLS:CDibDoc]
Type=0
HeaderFile=dibdoc.h
ImplementationFile=dibdoc.cpp
LastObject=CDibDoc
Filter=N

[CLS:CDibLookApp]
Type=0
HeaderFile=diblook.h
ImplementationFile=diblook.cpp
LastObject=CDibLookApp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CAboutDlg]
Type=0
HeaderFile=diblook.cpp
ImplementationFile=diblook.cpp
LastObject=CAboutDlg

[CLS:CDibView]
Type=0
HeaderFile=dibview.h
ImplementationFile=dibview.cpp
LastObject=ID_BLOCK
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp
LastObject=CMainFrame
Filter=T

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME (_MAC)]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
CommandCount=7

[MNU:IDR_DIBTYPE (_MAC)]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT_SETUP
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
CommandCount=19
Class=CDibView

[ACL:IDR_MAINFRAME (_MAC)]
Type=1
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_APP_EXIT
Command6=ID_FILE_SAVE
Command7=ID_EDIT_PASTE
Command8=ID_NEXT_PANE
Command9=ID_PREV_PANE
Command10=ID_FILE_CLOSE
Command11=ID_EDIT_CUT
Command12=ID_EDIT_UNDO
CommandCount=12

[MNU:IDR_DIBTYPE (English (U.S.))]
Type=1
Class=CDibView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_GRAY
Command16=ID_BLOCK
Command17=ID_VIEW_TOOLBAR
Command18=ID_VIEW_STATUS_BAR
Command19=ID_WINDOW_NEW
Command20=ID_WINDOW_CASCADE
Command21=ID_WINDOW_TILE_HORZ
Command22=ID_WINDOW_ARRANGE
Command23=ID_APP_ABOUT
CommandCount=23

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.) - _MAC)]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
CommandCount=7

[MNU:IDR_DIBTYPE (English (U.S.) - _MAC)]
Type=1
Class=CDibView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT_SETUP
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
CommandCount=19

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[ACL:IDR_MAINFRAME (English (U.S.) - _MAC)]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_APP_EXIT
Command6=ID_FILE_SAVE
Command7=ID_EDIT_PASTE
Command8=ID_NEXT_PANE
Command9=ID_PREV_PANE
Command10=ID_FILE_CLOSE
Command11=ID_EDIT_CUT
Command12=ID_EDIT_UNDO
CommandCount=12

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[CLS:COutputDoc]
Type=0
HeaderFile=OutputDoc.h
ImplementationFile=OutputDoc.cpp
BaseClass=CDocument
Filter=N

[DLG:IDD_PARAMETERDIALOG]
Type=1
Class=CParameterDialog
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_SIZEEDIT,edit,1350631552

[CLS:CParameterDialog]
Type=0
HeaderFile=ParameterDialog.h
ImplementationFile=ParameterDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SIZEEDIT

