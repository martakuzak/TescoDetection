// OutputDoc.cpp : implementation file
//

#include "stdafx.h"
#include "diblook.h"
#include "OutDoc.h"
#include "afxext.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputDoc

IMPLEMENT_DYNCREATE(COutputDoc, CDocument)

COutputDoc::COutputDoc()
{
}

BOOL COutputDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

COutputDoc::~COutputDoc()
{
}


BEGIN_MESSAGE_MAP(COutputDoc, CDocument)
	//{{AFX_MSG_MAP(COutputDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputDoc diagnostics

#ifdef _DEBUG
void COutputDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COutputDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COutputDoc serialization

void COutputDoc::Serialize(CArchive& ar)
{
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COutputDoc commands
