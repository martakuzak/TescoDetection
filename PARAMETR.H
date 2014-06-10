#if !defined(AFX_PARAMETERDIALOG_H__59FA0565_6A94_11D1_98F7_000000000000__INCLUDED_)
#define AFX_PARAMETERDIALOG_H__59FA0565_6A94_11D1_98F7_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ParameterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CParameterDialog dialog

class CParameterDialog : public CDialog
{
// Construction
public:
	CParameterDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CParameterDialog)
	enum { IDD = IDD_PARAMETERDIALOG };
	int		m_size;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParameterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CParameterDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETERDIALOG_H__59FA0565_6A94_11D1_98F7_000000000000__INCLUDED_)
