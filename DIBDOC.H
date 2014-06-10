// dibdoc.h : interface of the CDibDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1997 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include <vector>
#include <map>
#include <algorithm> 
#include <iostream>
#include <fstream>
#include "dibapi.h"
#include "Object.h"
#include "math.h"

struct HSVTRIPLE {
	double hue; /* Hue degree between 0.0 and 360.0 */
	double sat; /* Saturation between 0.0 (gray) and 1.0 */
	double val; /* Value between 0.0 (black) and 1.0 */
};
class CDibDoc : public CDocument
{
protected: // create from serialization only
	CDibDoc();
	DECLARE_DYNCREATE(CDibDoc)

// Attributes
public:
	HDIB GetHDIB() const
		{ return m_hDIB; }
	CPalette* GetDocPalette() const
		{ return m_palDIB; }
	CSize GetDocSize() const
		{ return m_sizeDoc; }
	int GetCurrE() const 
	{ return currE; }

// Operations
public:
	static int m_size;
	void ConvertToBlockedImage(CView *view);
	void trace(LPCSTR msg);
	void DoNothing(CView *view);
	void ConvertToGrayImage(CView *view);
	void ReplaceHDIB(HDIB hDIB);
	void InitDIBData();
	//
	void MedianFilter(RGBTRIPLE* src[], RGBTRIPLE* img[], int width, int height);
	void RGBToHSV(RGBTRIPLE* rgbImg[], HSVTRIPLE* hsvImg[], int width, int height);
	void BinaryImage(RGBTRIPLE* src[], HSVTRIPLE* hsvImg[], int width, int height, int minH, int maxH, double minS, double maxS);
	void Dilation(RGBTRIPLE* src[], int width, int height);
	void Erosion(RGBTRIPLE* src[], int width, int height);
	int FindObjects(RGBTRIPLE* src[], int width, int height);
	void DrawRectangle(RGBTRIPLE* src[], int width, int height, int minX, int maxX, int minY, int maxY);
	//
	long double CalculateM1(RGBTRIPLE* src[], int width, int height, int et);
	long double CalculateM8(RGBTRIPLE* src[], int width, int height, int et);
	long double CalculateW3(RGBTRIPLE* src[], int width, int height, int et);
	double CalculateW7(RGBTRIPLE* src[], int width, int height, int et);
	int CalculateMaxX(RGBTRIPLE* src[], int width, int height, int et);
	int CalculateMaxY(RGBTRIPLE* src[], int width, int height, int et);
	int CalculateMinX(RGBTRIPLE* src[], int width, int height, int et);
	int CalculateMinY(RGBTRIPLE* src[], int width, int height, int et);


// Implementation
protected:
	virtual ~CDibDoc();

	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);


protected:
	HDIB m_hDIB;
	CPalette* m_palDIB;
	CSize m_sizeDoc;
	//
	int currE;

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	virtual BOOL    OnNewDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CDibDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CEditView* m_outputView;
};

/////////////////////////////////////////////////////////////////////////////
