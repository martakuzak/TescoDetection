#if !defined(AFX_OUTPUTDOC_H__4165D5B4_4E38_11D1_98BD_000000000000__INCLUDED_)
#define AFX_OUTPUTDOC_H__4165D5B4_4E38_11D1_98BD_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OutputDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputDoc document

class COutputDoc : public CDocument
{
protected:
	COutputDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(COutputDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COutputDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(COutputDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTDOC_H__4165D5B4_4E38_11D1_98BD_000000000000__INCLUDED_)
