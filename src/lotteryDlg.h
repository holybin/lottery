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
//������
DECLARE_EASYSIZE

// Construction
public:
	CLotteryDlg(CWnd* pParent = NULL);	// standard constructor

	//��ʱ��ID
	UINT timerID;
	//�鵽�ı��
	int lotteryNum;
	int* lotteryNumArray;
	//�Ѿ��鵽��������
	int count;
	//�Ƿ�ʼ�齱
	bool isStarted;

	CFont m_font1;	//��������
	CFont m_font2;	//��������
	CBrush m_Brush;	//��ɫ

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
