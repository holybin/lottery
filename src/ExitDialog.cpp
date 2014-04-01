// ExitDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lottery.h"
#include "ExitDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ExitDialog dialog


ExitDialog::ExitDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ExitDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(ExitDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ExitDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ExitDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ExitDialog, CDialog)
	//{{AFX_MSG_MAP(ExitDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ExitDialog message handlers
