// ParameterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "diblook.h"
#include "Parametr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParameterDialog dialog


CParameterDialog::CParameterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CParameterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParameterDialog)
	m_size = 0;
	//}}AFX_DATA_INIT
}


void CParameterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParameterDialog)
	DDX_Text(pDX, IDC_SIZEEDIT, m_size);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParameterDialog, CDialog)
	//{{AFX_MSG_MAP(CParameterDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParameterDialog message handlers
