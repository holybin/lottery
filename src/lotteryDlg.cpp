// lotteryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lottery.h"
#include "lotteryDlg.h"
#include "ExitDialog.h"
#include "ResetDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_EASYSIZE_MAP(CLotteryDlg)
	//标题
	EASYSIZE(IDC_TITLE,ES_BORDER,ES_BORDER,ES_BORDER,ES_KEEPSIZE,ES_HCENTER)
	EASYSIZE(IDC_TOTAL_NUMBER,IDC_TITLE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_TOTAL,IDC_TITLE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	//奖号框
	EASYSIZE(IDC_NUMBER,IDC_TITLE,ES_BORDER,IDC_TITLE,ES_KEEPSIZE,0)
	//EASYSIZE(IDC_NUMBER,IDC_TITLE,ES_BORDER,ES_KEEPSIZE,ES_BORDER,0)

	//三个按钮
	EASYSIZE(IDC_START,IDC_TITLE,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_STOP,IDC_TITLE,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_RESET,IDC_TITLE,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	//logo
	EASYSIZE(IDC_LOGO,IDC_TITLE,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	//版权
	EASYSIZE(IDC_VERSION,IDC_TITLE,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
END_EASYSIZE_MAP

/////////////////////////////////////////////////////////////////////////////
// CLotteryDlg dialog

CLotteryDlg::CLotteryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLotteryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLotteryDlg)
	m_total_num = 100;
	m_number = _T("000");
	lotteryNum = 0;
	isStarted = false;
	lotteryNumArray = new int[100];
	count = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLotteryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLotteryDlg)
	DDX_Text(pDX, IDC_TOTAL_NUMBER, m_total_num);
	DDV_MinMaxInt(pDX, m_total_num, 1, 999);
	DDX_Text(pDX, IDC_NUMBER, m_number);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLotteryDlg, CDialog)
	//{{AFX_MSG_MAP(CLotteryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_EN_CHANGE(IDC_TOTAL_NUMBER, OnChangeTotalNumber)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_SIZING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLotteryDlg message handlers

BOOL CLotteryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//改变标题字体
	LOGFONT logfont1;
	CWnd* pTitle = GetDlgItem(IDC_TITLE);
	CFont* pTitleFont = pTitle -> GetFont();
	pTitleFont->GetLogFont(&logfont1);
	logfont1.lfHeight = -28;
	logfont1.lfWeight = FW_BOLD;
	m_font1.CreateFontIndirect(&logfont1);
	pTitle->SetFont(&m_font1);

	//改变奖号字体
	LOGFONT logfont2;
	CWnd* pGroup = GetDlgItem(IDC_NUMBER);
	CFont* pGroupFont = pGroup -> GetFont();
	pGroupFont->GetLogFont(&logfont2);
	logfont2.lfHeight = -70;
	logfont2.lfWeight = FW_BOLD;
	m_font2.CreateFontIndirect(&logfont2);
	pGroup->SetFont(&m_font2);

	//奖号内容垂直居中
	CRect rect;
	CWnd* pEdit1 = GetDlgItem(IDC_NUMBER);
	pEdit1->GetClientRect(&rect);
	::OffsetRect(&rect, 0, 10);
	::SendMessage(pEdit1->m_hWnd, EM_SETRECT, 0, (LPARAM)&rect);

	//初始化宏
	INIT_EASYSIZE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLotteryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLotteryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//添加背景
		CPaintDC dc(this);   
		CRect rect;   
		GetClientRect(&rect);   
		CDC dcMem;   
		dcMem.CreateCompatibleDC(&dc);   
		CBitmap bgMap;   
        bgMap.LoadBitmap(IDB_BITMAP1); 
		
		BITMAP bitmap;   
		bgMap.GetBitmap(&bitmap);   
		CBitmap* pbmpOld = dcMem.SelectObject(&bgMap);   
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);   

		//CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLotteryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLotteryDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int tmpLottery = rand() % m_total_num + 1;
	//bool isChosen = true;
	while(1)
	{
		int i = 0;
		for(; i < count; i++)
		{
			//如果已经被抽中过，就重新再抽
			if(tmpLottery == lotteryNumArray[i])
			{
				tmpLottery = rand() % m_total_num + 1;
				break;
			}
		}
		//没被抽中过
		if(i == count)
		{
			lotteryNum = tmpLottery;
			break;
		}
	}
	m_number.Format(_T("%.3d"), lotteryNum);
	UpdateData(FALSE);
	
	CDialog::OnTimer(nIDEvent);
}

// void CLotteryDlg::OnTimer(UINT nIDEvent) 
// {
// 	// TODO: Add your message handler code here and/or call default
// 	//哈哈你懂的!!
// 	double probability = 0.0;
// 	//本身就有40%以上的概率则不变
// 	if(m_total_num <= 50)
// 		probability = 20.0 / m_total_num;
// 	//低于40%则控制40%的概率
// 	else
// 		probability = 0.4;
// 	//大小概率
// 	int preProb = 1000 * probability;
// 	//int posProb = 1000 - preProb;
// 	//分界数
// 	int partionNum = rand() % 1000 + 1;
// 	//进入前面20个
// 	if(partionNum <= preProb)
// 	{
// 		int tmpLottery = rand() % 20 + 1;
// 		while(1)
// 		{
// 			int i = 0;
// 			for(; i < count; i++)
// 			{
// 				//如果已经被抽中过，就重新再抽
// 				if(tmpLottery == lotteryNumArray[i])
// 				{
// 					tmpLottery = rand() % 20 + 1;
// 					break;
// 				}
// 			}
// 			//没被抽中过
// 			if(i == count)
// 			{
// 				lotteryNum = tmpLottery;
// 				break;
// 			}
// 		}
// 	}
// 	//进入后面的数字
// 	else
// 	{
// 		int tmpLottery = rand() % (m_total_num - 20) + 21;
// 		while(1)
// 		{
// 			int i = 0;
// 			for(; i < count; i++)
// 			{
// 				//如果已经被抽中过，就重新再抽
// 				if(tmpLottery == lotteryNumArray[i])
// 				{
// 					tmpLottery = rand() % (m_total_num - 20) + 21;
// 					break;
// 				}
// 			}
// 			//没被抽中过
// 			if(i == count)
// 			{
// 				lotteryNum = tmpLottery;
// 				break;
// 			}
// 		}
// 	}
// 
// 	m_number.Format(_T("%.3d"), lotteryNum);
// 	UpdateData(FALSE);
// 
// 	CDialog::OnTimer(nIDEvent);
// }

void CLotteryDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	//如果没有开始抽奖
	if(!isStarted)
	{
		timerID = SetTimer(1, 30, NULL);//定时器间隔时间30ms
		isStarted = true;
	}
}

void CLotteryDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	//如果已经开始
	if(isStarted)
	{
		KillTimer(timerID);
		isStarted = false;

		lotteryNumArray[count++] = lotteryNum;
	}
}

void CLotteryDlg::OnChangeTotalNumber() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	UpdateData(FALSE);
	
}

void CLotteryDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	ResetDialog resetDlg;
	INT_PTR nRes = resetDlg.DoModal(); 
	if(nRes == IDCANCEL)
		return;

	//清除抽奖记录
	for(int i = 0; i < count; i++)
		lotteryNumArray[i] = 0;
	m_number = _T("000");

	UpdateData(FALSE);
}

void CLotteryDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	ExitDialog closeDlg;
	INT_PTR nRes = closeDlg.DoModal();
	if(IDCANCEL == nRes)
		return;

	//delete [] lotteryNumArray;

	CDialog::OnClose();
}

HBRUSH CLotteryDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	//标题字体颜色
	if (pWnd->GetDlgCtrlID() == IDC_TITLE)
	{
		pDC->SetTextColor(RGB(255, 0, 0));  //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
		// TODO: Return a different brush if the default is not desired
		//return (HBRUSH)::GetStockObject(BLACK_BRUSH);  // 设置背景色
	}
	//编辑框字体颜色
	if (pWnd->GetDlgCtrlID() == IDC_NUMBER )
	{
		pDC->SetTextColor(RGB(0, 0, 255));  //设置字体颜色
		pDC->SetBkMode(TRANSPARENT); //设置字体背景为透明
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CLotteryDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	UPDATE_EASYSIZE;
	// TODO: Add your message handler code here
	
}

void CLotteryDlg::OnSizing(UINT fwSide, LPRECT pRect) 
{
	CDialog::OnSizing(fwSide, pRect);
	EASYSIZE_MINSIZE(811, 534, fwSide, pRect);
	// TODO: Add your message handler code here
	
}

//取消enter和ESC键退出功能
void CLotteryDlg::OnOK()
{
}

BOOL CLotteryDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_ESCAPE)   
    {   
		//将ESC键的消息替换为回车键的消息，这样，按ESC的时候 
		//也会去调用OnOK函数，而OnOK什么也不做，这样ESC也被屏蔽
		pMsg->wParam = VK_RETURN;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
