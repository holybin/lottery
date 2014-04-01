; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLotteryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lottery.h"

ClassCount=4
Class1=CLotteryApp
Class2=CLotteryDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_RESET_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_JACKPOT_DIALOG
Resource4=IDD_ABOUTBOX
Resource5=IDD_LOTTERY_DIALOG
Class4=ExitDialog
Resource6=IDD_EXIT_DIALOG

[CLS:CLotteryApp]
Type=0
HeaderFile=lottery.h
ImplementationFile=lottery.cpp
Filter=N

[CLS:CLotteryDlg]
Type=0
HeaderFile=lotteryDlg.h
ImplementationFile=lotteryDlg.cpp
Filter=W
LastObject=CLotteryDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=lotteryDlg.h
ImplementationFile=lotteryDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LOTTERY_DIALOG]
Type=1
Class=CLotteryDlg
ControlCount=9
Control1=IDC_TITLE,static,1342308865
Control2=IDC_NUMBER,edit,1350699141
Control3=IDC_START,button,1342308352
Control4=IDC_STOP,button,1342308352
Control5=IDC_TOTAL,static,1342308865
Control6=IDC_TOTAL_NUMBER,edit,1350705281
Control7=IDC_RESET,button,1342308352
Control8=IDC_LOGO,static,1342308366
Control9=IDC_VERSION,static,1342308366

[DLG:IDD_JACKPOT_DIALOG]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_PRE,static,1342308865
Control3=IDC_BACK,static,1342308865
Control4=IDC_JACKPOT_NUM,edit,1350699137

[DLG:IDD_RESET_DIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342308352
Control3=IDC_STATIC,static,1342308865

[DLG:IDD_EXIT_DIALOG]
Type=1
Class=ExitDialog
ControlCount=4
Control1=IDOK,button,1342308353
Control2=IDCANCEL,button,1342308352
Control3=IDC_STATIC,static,1342308865
Control4=IDC_STATIC,static,1342308865

[CLS:ExitDialog]
Type=0
HeaderFile=ExitDialog.h
ImplementationFile=ExitDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ExitDialog

