// lotteryDlg.h : header file
//

#if !defined(AFX_LOTTERYDLG_H__B12D0F83_9FDE_44EB_B23D_4AACAEB12039__INCLUDED_)
#define AFX_LOTTERYDLG_H__B12D0F83_9FDE_44EB_B23D_4AACAEB12039__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLotteryDlg dialog

class CLotteryDlg : public CDialog
{
//声明宏
DECLARE_EASYSIZE

// Construction
public:
	CLotteryDlg(CWnd* pParent = NULL);	// standard constructor

	//定时器ID
	UINT timerID;
	//抽到的编号
	int lotteryNum;
	int* lotteryNumArray;
	//已经抽到奖的人数
	int count;
	//是否开始抽奖
	bool isStarted;

	CFont m_font1;	//标题字体
	CFont m_font2;	//奖号字体
	CBrush m_Brush;	//颜色

// Dialog Data
	//{{AFX_DATA(CLotteryDlg)
	enum { IDD = IDD_LOTTERY_DIALOG };
	int		m_total_num;
	CString	m_number;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLotteryDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLotteryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnOK();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnChangeTotalNumber();
	afx_msg void OnReset();
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOTTERYDLG_H__B12D0F83_9FDE_44EB_B23D_4AACAEB12039__INCLUDED_)
