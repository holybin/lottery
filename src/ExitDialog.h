#if !defined(AFX_EXITDIALOG_H__782C3139_FC4D_453B_A9EA_AD571015FF98__INCLUDED_)
#define AFX_EXITDIALOG_H__782C3139_FC4D_453B_A9EA_AD571015FF98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExitDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ExitDialog dialog

class ExitDialog : public CDialog
{
// Construction
public:
	ExitDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ExitDialog)
	enum { IDD = IDD_EXIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ExitDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ExitDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXITDIALOG_H__782C3139_FC4D_453B_A9EA_AD571015FF98__INCLUDED_)
