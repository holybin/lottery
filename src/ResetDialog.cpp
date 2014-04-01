// ResetDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lottery.h"
#include "ResetDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ResetDialog dialog


ResetDialog::ResetDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ResetDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(ResetDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ResetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ResetDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ResetDialog, CDialog)
	//{{AFX_MSG_MAP(ResetDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ResetDialog message handlers
