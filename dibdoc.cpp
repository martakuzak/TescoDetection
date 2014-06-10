// dibdoc.cpp : implementation of the CDibDoc class
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

#include "stdafx.h"
#include "diblook.h"
#include <limits.h>
#include <cmath>
#include "dibdoc.h"
#include "dibview.h"
#include "outDoc.h"
#include "afxext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDibDoc

IMPLEMENT_DYNCREATE( CDibDoc, CDocument )

	BEGIN_MESSAGE_MAP( CDibDoc, CDocument )
		//{{AFX_MSG_MAP(CDibDoc)
		//}}AFX_MSG_MAP
	END_MESSAGE_MAP( )

	/////////////////////////////////////////////////////////////////////////////
	// CDibDoc construction/destruction

	int CDibDoc::m_size = 8;

	CDibDoc::CDibDoc( )
	{
		m_hDIB = NULL;
		m_palDIB = NULL;
		m_sizeDoc = CSize( 1, 1 );     // dummy value to make CScrollView happy
		m_outputView = NULL;
		currE = 100;
	}

	CDibDoc::~CDibDoc( )
	{
		if( m_hDIB != NULL )
		{
			::GlobalFree( (HGLOBAL)m_hDIB );
		}
		if( m_palDIB != NULL )
		{
			delete m_palDIB;
		}
	}

	BOOL CDibDoc::OnNewDocument( )
	{
		if( !CDocument::OnNewDocument( ) )
			return FALSE;
		return TRUE;
	}

	void CDibDoc::InitDIBData( )
	{
		if( m_palDIB != NULL )
		{
			delete m_palDIB;
			m_palDIB = NULL;
		}
		if( m_hDIB == NULL )
		{
			return;
		}
		// Set up document size
		LPSTR lpDIB = ( LPSTR ) ::GlobalLock( (HGLOBAL)m_hDIB );
		if( ::DIBWidth( lpDIB ) > INT_MAX || ::DIBHeight( lpDIB ) > INT_MAX )
		{
			::GlobalUnlock( (HGLOBAL)m_hDIB );
			::GlobalFree( (HGLOBAL)m_hDIB );
			m_hDIB = NULL;
			CString strMsg;
			strMsg.LoadString( IDS_DIB_TOO_BIG );
			MessageBox( NULL, strMsg, NULL, MB_ICONINFORMATION | MB_OK );
			return;
		}
		m_sizeDoc = CSize( ( int ) ::DIBWidth( lpDIB ), ( int ) ::DIBHeight( lpDIB ) );
		::GlobalUnlock( (HGLOBAL)m_hDIB );
		// Create copy of palette
		m_palDIB = new CPalette;
		if( m_palDIB == NULL )
		{
			// we must be really low on memory
			::GlobalFree( (HGLOBAL)m_hDIB );
			m_hDIB = NULL;
			return;
		}
		if( ::CreateDIBPalette( m_hDIB, m_palDIB ) == NULL )
		{
			// DIB may not have a palette
			delete m_palDIB;
			m_palDIB = NULL;
			return;
		}
	}


	BOOL CDibDoc::OnOpenDocument( LPCTSTR lpszPathName )
	{
		CFile file;
		CFileException fe;
		if( !file.Open( lpszPathName, CFile::modeRead | CFile::shareDenyWrite, &fe ) )
		{
			ReportSaveLoadException( lpszPathName, &fe,
				FALSE, AFX_IDP_FAILED_TO_OPEN_DOC );
			return FALSE;
		}

		DeleteContents( );
		BeginWaitCursor( );

		// replace calls to Serialize with ReadDIBFile function
		TRY
		{
			m_hDIB = ::ReadDIBFile( file );
		}
		CATCH( CFileException, eLoad )
		{
			file.Abort( ); // will not throw an exception
			EndWaitCursor( );
			ReportSaveLoadException( lpszPathName, eLoad,
				FALSE, AFX_IDP_FAILED_TO_OPEN_DOC );
			m_hDIB = NULL;
			return FALSE;
		}
		END_CATCH

			InitDIBData( );
		EndWaitCursor( );

		if( m_hDIB == NULL )
		{
			// may not be DIB format
			CString strMsg;
			strMsg.LoadString( IDS_CANNOT_LOAD_DIB );
			MessageBox( NULL, strMsg, NULL, MB_ICONINFORMATION | MB_OK );
			return FALSE;
		}
		SetPathName( lpszPathName );
		SetModifiedFlag( FALSE );     // start off with unmodified
		return TRUE;
	}


	BOOL CDibDoc::OnSaveDocument( LPCTSTR lpszPathName )
	{
		CFile file;
		CFileException fe;

		if( !file.Open( lpszPathName, CFile::modeCreate |
			CFile::modeReadWrite | CFile::shareExclusive, &fe ) )
		{
			ReportSaveLoadException( lpszPathName, &fe,
				TRUE, AFX_IDP_INVALID_FILENAME );
			return FALSE;
		}

		// replace calls to Serialize with SaveDIB function
		BOOL bSuccess = FALSE;
		TRY
		{
			BeginWaitCursor( );
			bSuccess = ::SaveDIB( m_hDIB, file );
			file.Close( );
		}
		CATCH( CException, eSave )
		{
			file.Abort( ); // will not throw an exception
			EndWaitCursor( );
			ReportSaveLoadException( lpszPathName, eSave,
				TRUE, AFX_IDP_FAILED_TO_SAVE_DOC );
			return FALSE;
		}
		END_CATCH

			EndWaitCursor( );
		SetModifiedFlag( FALSE );     // back to unmodified

		if( !bSuccess )
		{
			// may be other-style DIB (load supported but not save)
			//  or other problem in SaveDIB
			CString strMsg;
			strMsg.LoadString( IDS_CANNOT_SAVE_DIB );
			MessageBox( NULL, strMsg, NULL, MB_ICONINFORMATION | MB_OK );
		}

		return bSuccess;
	}

	void CDibDoc::ReplaceHDIB( HDIB hDIB )
	{
		if( m_hDIB != NULL )
		{
			::GlobalFree( (HGLOBAL)m_hDIB );
		}
		m_hDIB = hDIB;
	}

	/////////////////////////////////////////////////////////////////////////////
	// CDibDoc diagnostics

#ifdef _DEBUG
	void CDibDoc::AssertValid( ) const
	{
		CDocument::AssertValid( );
	}

	void CDibDoc::Dump( CDumpContext& dc ) const
	{
		CDocument::Dump( dc );
	}

#endif //_DEBUG

	/////////////////////////////////////////////////////////////////////////////
	// CDibDoc commands

	long calcm( RGBTRIPLE* pic[ 512 ], int p, int q, int width, int height, int et = 254)
	{
		long res = 0;
		for( int x = 0; x < width; x++ )
		{
			for( int y = 0; y<height; y++ )
			{
				if(pic[y][x].rgbtRed == et ) {
					//int gray = pic[ y ][ x ].rgbtRed;
					//gray = gray > 128 ? 1 : 0;
					int gray = 1;
					res += ( (long)( std::pow( ( (double)( x + 1 ) ), p )*std::pow( ( (double)( y + 1 ) ), q )*( (double)gray ) ) );
				}
			}
		}
		return res;
	}

	////////

	/////////
	void CDibDoc::ConvertToGrayImage( CView *view )
	{
		trace( "start ConvertToGrayImage\r\n" );

		RGBTRIPLE* rows[ 512 ];
		RGBTRIPLE* tmp[ 512 ];


		for( int i = 0; i < 512; ++i )
		{
			tmp[ i ] = new RGBTRIPLE[ 512 ];
		}
		int width, height;
		int S = 0;
		int L = 0;
		long m00, m01, m10, m11, m02, m20;
		double M20, M02, M1, M7, M11;
		if( GetDIBRowsRGB( m_hDIB, rows, &width, &height ) )
		{
			m00 = calcm( rows, 0, 0, width, height);
			m10 = calcm( rows, 1, 0, width, height);
			m01 = calcm( rows, 0, 1, width, height);
			m11 = calcm( rows, 1, 1, width, height);
			m20 = calcm( rows, 2, 0, width, height);
			m02 = calcm( rows, 0, 2, width, height);

			M11 = double( m11 ) - double( m10 )*double( m01 ) / double( m00 );
			M02 = double( m02 ) - double( m01 )*double( m01 ) / double( m00 );
			M20 = double( m20 ) - double( m10 )*double( m10 ) / double( m00 );
			M1 = ( M20 + M02 ) / std::pow( double( m00 ), 2 );
			M7 = ( M20 * M02 - M11*M11 ) / std::pow( double( m00 ), 4 );

			for( int x = 0; x < width; x++ )
			{
				for( int y = 0; y < height; y++ )
				{
					int gray = rows[ y ][ x ].rgbtBlue + rows[ y ][ x ].rgbtRed + rows[ y ][ x ].rgbtGreen;
					gray /= 3;
					if( gray <= 128 )
					{
						++S;
						rows[ y ][ x ].rgbtRed = 200;
						rows[ y ][ x ].rgbtGreen = 0;
						rows[ y ][ x ].rgbtBlue = 0;
					}
					tmp[ y ][ x ].rgbtBlue = rows[ y ][ x ].rgbtBlue;
					tmp[ y ][ x ].rgbtGreen = rows[ y ][ x ].rgbtGreen;
					tmp[ y ][ x ].rgbtRed = rows[ y ][ x ].rgbtRed;
				}
			}

			for( int x = 1; x < width - 1; x++ )
			{
				for( int y = 1; y < height - 1; y++ )
				{
					int gray = 0;
					int sum = 0;
					for( int p = -1; p <= 1; ++p )
					{
						for( int q = -1; q <= 1; ++q )
						{
							gray = rows[ y + p ][ x + q ].rgbtRed;
							sum += gray;
						}
					}

					if( sum == 0 || sum == 200 * 9 )
					{
						tmp[ y ][ x ].rgbtRed = 0;
						tmp[ y ][ x ].rgbtGreen = 200;
						tmp[ y ][ x ].rgbtBlue = 0;
					}
				}
			}

			for( int x = 0; x < width; x++ )
			{
				for( int y = 0; y < height; y++ )
				{
					if( tmp[ y ][ x ].rgbtRed == 200 )
					{
						++L;
					}
				}
			}

			FreeDIBRows( m_hDIB );
		}
		UpdateAllViews( NULL );

		for( int i = 0; i < 512; ++i )
		{
			delete[] tmp[ i ];
		}
		char* buf = new char[ 50 ];
		sprintf( buf, "S: %d\r\nL: %d\r\n", S, L );
		trace( buf );

		double W3 = 0.5*( (double)L ) / std::sqrt( 3.14*( (double)S ) ) - 1.0;
		sprintf( buf, "W3: %f\r\n", W3 );
		trace( buf );
		sprintf( buf, "m00: %d\r\n", m00 );
		trace( buf );
		sprintf( buf, "m01: %d\r\n", m01 );
		trace( buf );
		sprintf( buf, "m10: %d\r\n", m10 );
		trace( buf );
		sprintf( buf, "m20: %d\r\n", m20 );
		trace( buf );
		sprintf( buf, "m02: %d\r\n", m02 );
		trace( buf );
		sprintf( buf, "M11: %f\r\n", M11 );
		trace( buf );
		sprintf( buf, "M02: %f\r\n", M02 );
		trace( buf );
		sprintf( buf, "M20: %f\r\n", M20 );
		trace( buf );
		sprintf( buf, "M1: %f\r\n", M1 );
		trace( buf );
		sprintf( buf, "M7: %f\r\n", M7 );
		trace( buf );
		trace( "stop ConvertToGrayImage\r\n" );
		delete[] buf;
	}


	void CDibDoc::DoNothing( CView *view )
	{
	}

	void CDibDoc::trace( LPCSTR msg )
	{
		COutputDoc* pOut;
		if( m_outputView == NULL )
		{
			pOut = (COutputDoc*)( (CDibLookApp*)AfxGetApp( ) )->m_outputTemplate->OpenDocumentFile( NULL );
			pOut->SetModifiedFlag( TRUE );
			pOut->UpdateAllViews( NULL );
			POSITION pos = pOut->GetFirstViewPosition( );
			CView* pFirstView = pOut->GetNextView( pos );
			m_outputView = (CEditView *)pFirstView;
		}
		else
			pOut = (COutputDoc*)m_outputView->GetDocument( );
		m_outputView->GetEditCtrl( ).ReplaceSel( msg );
		pOut->SetModifiedFlag( FALSE );
	}
	////////////////////////////////////
	bool compare (const std::pair<int,int>& a, const std::pair<int,int>& b)
	{
		return ( a.second < b.second );
	}
	bool compareObj (const Object& a, const Object& b) {
		return a.getCenterX() < b.getCenterX();
	}
	void CDibDoc::ConvertToBlockedImage( CView * view )
	{
		trace( "start ConvertToBlockedImage\r\n" );

		RGBTRIPLE* rows[ 512 ];
		RGBTRIPLE* img[ 512 ];
		HSVTRIPLE* hsvImg [512];
		/*RGBTRIPLE* tmp2[ 512 ];*/
		for( int i = 0; i < 512; ++i )
		{
			img[ i ] = new RGBTRIPLE[ 512 ];
			hsvImg[i] = new HSVTRIPLE[512];
		}

		int width, height;
		if( GetDIBRowsRGB( m_hDIB, rows, &width, &height ) )
		{
			MedianFilter(rows, img, width, height);
			RGBToHSV(img, hsvImg, height, width);
			BinaryImage(img, hsvImg, width, height, 345, 12, 0.3, 1.01 );

			Erosion(img, width, height);
			Dilation(img,width,height);
			//SobelFilter(img, width, height);
			currE = FindObjects(img, width, height); //etykietowanie roznych obiektow
			//po tej operacji obiekty maja przydzielone inne "kolory"
			//(0,0,0) - tlo, (1,1,1) - pierwszy obiekt, (2,2,2) - drugi...


			std:: vector<Object> ts;
			std:: vector<Object> es;
			std:: vector<Object> ss;
			std:: vector<Object> cs;
			std:: vector<Object> os;
			int objNum = 0;

			for (int i = 1; i < currE + 1; ++ i) {
				long double M1 = CalculateM1(img, width, height, i);
				if(M1 != NULL) {
					long double W3 = CalculateW3(img, width, height, i);
					double W7 = CalculateW7(img, width, height, i);
					long m00 = calcm(img, 0, 0, width, height, i);
					int maxX = CalculateMaxX(img, width, height, i);
					int maxY = CalculateMaxY(img, width, height, i);
					int minX = CalculateMinX(img, width, height, i);
					int minY = CalculateMinY(img, width, height, i);
					//liczenie srodka ciezkosci
					long m10 = calcm(img, 1, 0, width, height, i);
					long m01 = calcm(img, 0, 1, width, height, i);
					int ic = (int) ((double)m10/(double)m00); //srodek ciezkosci
					int jc = (int) ((double)m01/(double)m00);

					//identyfikacja znaku
					SIGN sign = NOTHING;
					if(M1 > 0.28 && M1 < 0.36 && W3 > 0.75 && W3 < 0.93 && W7 < 0.01 ) {
						sign = T;
					}
					if(M1 > 0.25 && M1 < 0.33 && W3 > 1.04 && W3 < 1.23 && W7 < 0.01 ) {
						sign = E;
					}
					if(M1 > 0.24 && M1 < 0.32 && W3 > 1.35 && W3 < 1.7 && W7 < 0.01 ) {
						sign = S;
					}
					if(M1 > 0.34 && M1 < 0.42 && W3 > 1.01 && W3 < 1.41 && W7 < 0.28 && W7 > 0.12 ) {
						sign = C;
					}
					if(M1 > 0.29 && M1 < 0.37 && W3 > 1.32 && W3 < 1.61  && W7 < 0.52 && W7 > 0.34) {
						sign = O;
					}
					if(sign != NOTHING) {
						Object obj(sign);
						obj.setXY(minX, maxX, minY, maxY);
						obj.setM00(m00);
						obj.setCenter(ic, jc);

						switch(sign) {
						case T:
							ts.push_back(obj);
							break;
						case E:
							es.push_back(obj);
							break;
						case S:
							ss.push_back(obj);
							break;
						case C:
							cs.push_back(obj);
							break;
						case O:
							os.push_back(obj);
							break;
						default:
							break;
						}
					}

				}
			}

			if(!ts.size() && !es.size() && !ss.size() && !cs.size() && !os.size()) {
				trace("Logo nieodnalezione\r\n");
				return;
			}

			bool success = false;
			int minXLogo = 0;
			int maxXLogo = 0;
			int minYLogo = 0;
			int maxYLogo = 0;
			int o_height = 0;
			for (int tt = 0; tt < ts.size(); ++ tt) { //po potencjalnych literach t
				Object t_obj = ts.at(tt);
				minXLogo = t_obj.getMinX();
				maxXLogo = t_obj.getMaxX();
				minYLogo = t_obj.getMinY();
				maxYLogo = t_obj.getMaxY();
				for (int ee = 0; ee < es.size(); ++ ee) { //po e
					Object e_obj = es.at(ee);
					double dist = sqrt((double)std::pow(e_obj.getCenterX() - t_obj.getCenterX(),2) + (double)std::pow(e_obj.getCenterY() - t_obj.getCenterY(), 2));
					double heightProp = (double)t_obj.getHeight()/(double)e_obj.getHeight();
					double widthProp = (double)t_obj.getWidth()/(double)e_obj.getWidth();

					if(t_obj.getMinX() < e_obj.getMinX() && heightProp > 0.92 && heightProp < 1.1 && widthProp > 1.15 && widthProp < 1.5 && dist > 0.3*(t_obj.getWidth() + e_obj.getWidth()) && dist < 0.7*(t_obj.getWidth() + e_obj.getWidth()) ) {
						maxXLogo = e_obj.getMaxX();
						maxYLogo = max(maxYLogo, e_obj.getMaxY());
						minYLogo = min(minYLogo, e_obj.getMinY());
						for (int s = 0; s < ss.size(); ++ s) {//po s
							Object s_obj = ss.at(s);
							double dist = sqrt((double)std::pow(e_obj.getCenterX() - s_obj.getCenterX(),2) + (double)std::pow(e_obj.getCenterY() - s_obj.getCenterY(), 2));
							double heightProp = (double)e_obj.getHeight()/(double)s_obj.getHeight();
							double widthProp = (double)e_obj.getWidth()/(double)s_obj.getWidth();

							if(e_obj.getMinX() < s_obj.getMinX() &&heightProp > 0.88 && heightProp < 1.04 && widthProp > 0.85 && widthProp < 0.96 && dist > 0.3*(s_obj.getWidth() + e_obj.getWidth()) && dist < 0.7*(s_obj.getWidth() + e_obj.getWidth()) ) {
								maxXLogo = s_obj.getMaxX();
								maxYLogo = max(maxYLogo, s_obj.getMaxY());
								minYLogo = min(minYLogo, s_obj.getMinY());
								for (int c = 0; c < cs.size(); ++ c) {// po c
									Object c_obj = cs.at(c);
									double dist = sqrt((double)std::pow(c_obj.getCenterX() - s_obj.getCenterX(),2) + (double)std::pow(c_obj.getCenterY() - s_obj.getCenterY(), 2));
									double heightProp = (double)s_obj.getHeight()/(double)c_obj.getHeight();
									double widthProp = (double)s_obj.getWidth()/(double)c_obj.getWidth();

									if(s_obj.getMinX() < c_obj.getMinX() &&heightProp > 0.95 && heightProp < 1.1 && widthProp > 0.85 && widthProp < 0.97 && dist > 0.3*(s_obj.getWidth() + c_obj.getWidth()) && dist < 0.7*(s_obj.getWidth() +c_obj.getWidth()) ) {
										maxXLogo = c_obj.getMaxX();
										maxYLogo = max(maxYLogo, c_obj.getMaxY());
										minYLogo = min(minYLogo, c_obj.getMinY());
										for (int o = 0; o < os.size(); ++ o) {//po o
											Object o_obj = os.at(o);
											double dist = sqrt((double)std::pow(c_obj.getCenterX() - o_obj.getCenterX(),2) + (double)std::pow(c_obj.getCenterY() - o_obj.getCenterY(), 2));
											double heightProp = (double)c_obj.getHeight()/(double)o_obj.getHeight();
											double widthProp = (double)c_obj.getWidth()/(double)o_obj.getWidth();

											if(c_obj.getMinX() < o_obj.getMinX() &&heightProp > 0.94 && heightProp < 1.05 && widthProp > 0.78 && widthProp < 0.85 && dist > 0.3*(c_obj.getWidth() + o_obj.getWidth()) && dist < 0.7*(c_obj.getWidth() + o_obj.getWidth()) ) {
												maxXLogo = o_obj.getMaxX();
												maxYLogo = max(maxYLogo, o_obj.getMaxY());
												minYLogo = min(minYLogo, o_obj.getMinY());
												//DrawRectangle(rows, width, height, minXLogo, maxXLogo, minYLogo, maxYLogo);
												success = true;
												o_height = o_obj.getHeight();
												break;
											}
										}
									}

									if(success)
										break;
								}
							}

							if(success)
								break;
						}
					}

					if(success)
						break;
				}

				if(success)
					break;
			}

			if(!success) {//nie znaleziono napisu
				trace("Logo nieodnalezione\r\n");
				return;
			}

			//wykrywanie niebieskich znaczkow
			//MedianFilter(rows, img, width, height);
			//RGBToHSV(rows, hsvImg, height, width);
			BinaryImage(img, hsvImg, width, height, 200, 250, 0.3, 1.01);
			Erosion(img, width, height);
			Dilation(img,width,height);
			currE = FindObjects(img, width, height); //etykietowanie roznych obiektow


			std::vector<Object> blues;
			for (int i = 1; i < currE + 1; ++ i) {

				//liczenie srodka ciezkosci
				long m00 = calcm(img, 0, 0, width, height, i);
				long m10 = calcm(img, 1, 0, width, height, i);
				long m01 = calcm(img, 0, 1, width, height, i);
				if(m00) {
					int ic = (int) ((double)m10/(double)m00); //srodek ciezkosci
					int jc = (int) ((double)m01/(double)m00);

					if((double)jc > ((double)minYLogo - o_height) && jc < minYLogo) {
						long double M1 = CalculateM1(img, width, height, i);
						if(M1 != NULL) {
							long double W3 = CalculateW3(img, width, height, i);
							int maxX = CalculateMaxX(img, width, height, i);
							int maxY = CalculateMaxY(img, width, height, i);
							int minX = CalculateMinX(img, width, height, i);
							int minY = CalculateMinY(img, width, height, i);
							//identyfikacja znaku
							SIGN sign = NOTHING;
							if(M1 > 0.23 && M1 < 0.36 && W3 > 0.21 && W3 < 0.49) {
								sign = BLUE;
							}
							if(sign == BLUE) {
								Object obj(sign);
								obj.setXY(minX, maxX, minY, maxY);
								obj.setM00(m00);
								obj.setCenter(ic, jc);
								blues.push_back(obj);
							}
						}
					}
				}
			}
			if(blues.size() < 5) {
				trace("Logo nieodnalezionen\r\n");
				FreeDIBRows( m_hDIB );
				UpdateAllViews(NULL);	
				trace( "stop ConvertToBlockedImage\r\n" );
				//return;
			}
			std::sort (blues.begin(), blues.end(), compareObj); //od najmniejszego x do najwiekszego
			int tmp = 0;
			for (int i0 = 0; i0 < blues.size(); ++ i0) { 
				int s0 = blues.at(i0).getM00();
				int centerX0 = blues.at(i0).getCenterX();
				int centerY0 = blues.at(i0).getCenterY();
				minXLogo = min(minXLogo, blues.at(i0).getMinX());
				minYLogo = blues.at(i0).getMinY();
				for (int i1 = i0 + 1; i1 < blues.size(); ++ i1) {
					int s1 = blues.at(i1).getM00();
					int centerX1 = blues.at(i1).getCenterX();
					int centerY1 = blues.at(i1).getCenterY();
					int dist10 = sqrt(std::pow(centerX1 - centerX0, 2) + std::pow(centerY1 - centerY0, 2));

					if((double)s1/s0 < 1.13 && (double)s1/s0 > 0.8 && dist10 < 1.7*blues.at(i1).getWidth()&& dist10 > 0.7*blues.at(i1).getWidth()) {

						minYLogo = min(minYLogo, blues.at(i1).getMinY()) ;
						for (int i2 = i1 + 1; i2 < blues.size(); ++ i2) {
							int s2 = blues.at(i2).getM00();
							int centerX2 = blues.at(i2).getCenterX();
							int centerY2 = blues.at(i2).getCenterY();
							int dist21 = sqrt(std::pow(centerX1 - centerX2, 2) + std::pow(centerY1 - centerY2, 2));

							if((double)s2/s1 < 1.13 && (double)s2/s1 > 0.8 && dist21 < 1.8*blues.at(i2).getWidth() && dist21 > 0.7*blues.at(i2).getWidth()) {
								minYLogo = min(minYLogo, blues.at(i2).getMinY()) ;
								for (int i3 = i2 + 1; i3 < blues.size(); ++ i3) {
									int s3 = blues.at(i3).getM00();
									int centerX3 = blues.at(i3).getCenterX();
									int centerY3 = blues.at(i3).getCenterY();
									int dist32 = sqrt(std::pow(centerX3 - centerX2, 2) + std::pow(centerY3 - centerY2, 2));

									if((double)s2/s3 < 1.13 && (double)s2/s3 > 0.8 && dist32 < 1.8*blues.at(i3).getWidth() && dist32 > 0.7*blues.at(i3).getWidth()) {
										minYLogo = min(minYLogo, blues.at(i3).getMinY()) ;
										for (int i4 = i3 + 1; i4 < blues.size(); ++ i4) {
											int s4 = blues.at(i4).getM00();
											int centerX4 = blues.at(i4).getCenterX();
											int centerY4 = blues.at(i4).getCenterY();
											int dist43 = sqrt(std::pow(centerX3 - centerX4, 2) + std::pow(centerY3 - centerY4, 2));

											if((double)s4/s3 < 1.13 && (double)s4/s3 > 0.8 && dist43 < 1.8*blues.at(i4).getWidth() && dist43 > 0.7*blues.at(i4).getWidth()) {
												minYLogo = min(minYLogo, blues.at(i4).getMinY()) ;
												maxXLogo = max(maxXLogo, blues.at(i4).getMaxX());
												trace("Odnaleziono logo\r\n");
												DrawRectangle(rows, width, height, minXLogo, maxXLogo, minYLogo, maxYLogo);
												FreeDIBRows( m_hDIB );
												UpdateAllViews(NULL);	
												trace( "stop ConvertToBlockedImage\r\n" );
												return;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			trace("Logo nieodnalezione\r\n");

		}
		FreeDIBRows( m_hDIB );
		UpdateAllViews(NULL);	
		trace( "stop ConvertToBlockedImage\r\n" );
	}


	int CDibDoc:: FindObjects(RGBTRIPLE* src[], int width, int height) {

		short int * et[257]; //etykiety
		int * binImg [257];


		for (int j = 0; j < width + 2; ++j) {
			et[j] =  new short[257];
			binImg[j] = new int[257];
			for (int i = 0; i < height + 2; ++i) {
				et[j][i] = 0;
				if(j && j < width + 1 && i && i < height + 1) {
					binImg[j][i] = src[i-1][j-1].rgbtBlue/255;
				}
			}
		}

		//pierwsza maska

		for (int j = 1; j < width + 1; ++j) {
			for (int i = 1; i < height + 1; ++i) {
				if(binImg[j][i]) { //jesli piksel jest bialy
					if (binImg[j-1][i-1] || binImg[j-1][i] || binImg[j-1][i+1] || binImg[j][i-1]) { //jesli ktorykolwiek z pikseli z maski jest bialy
						unsigned short min = currE + 1;
						if(et[j-1][i-1] && (et[j-1][i-1] < min)) 
							min = et[j-1][i-1];
						if(et[j-1][i] && (et[j-1][i] < min)) 
							min = et[j-1][i];
						if(et[j-1][i + 1] && (et[j-1][ i+1] < min)) 
							min = et[j-1][ i + 1];
						if(et[j][i-1] && (et[j][i -1] < min)) 
							min = et[j][i -1];
						et[j][i] = min;
					}
					else
						et[j][i] = ++currE;
				}

			}
		}


		//laczenie obszarow wspolnych
		bool change = true;
		while(change) {
			change = false;

			for (int j = 1; j < width + 1; ++j) {
				for (int i = 1; i < height + 1; ++i) {
					if(et[j][i]) { //jesli piksel jest bialy
						unsigned short min = et[j][i];
						if(et[j-1][i] && et[j-1][i] < min)
							min = et[j-1][i];
						if(et[j-1][i-1] && et[j-1][i-1] < min)
							min = et[j-1][i-1];
						if(et[j][i-1] && et[j][i-1] < min)
							min = et[j][i-1];
						if(et[j+1][i] && et[j+1][i] < min)
							min = et[j+1][i];
						if(et[j+1][i-1] && et[j+1][i-1] < min)
							min = et[j+1][i-1];
						if(et[j-1][i + 1] && et[j-1][i + 1] < min)
							min = et[j-1][i + 1];
						if(et[j][i+1] && et[j][i+1] < min)
							min = et[j][i+1];
						if(et[j+1][i+1] && et[j+1][i+1] < min)
							min = et[j+1][i+1];				
						if(min < et[j][i]) {
							et[j][i] = min;
							change = true;
						}
					}
				}
			}
		}

		for(int x = 1; x < width + 1; ++ x) {				
			for (int y = 1; y < height + 1; ++ y) {
				src[y-1][x-1].rgbtBlue = et[x][y];
				src[y-1][x-1].rgbtRed = et[x][y];
				src[y-1][x-1].rgbtGreen = et[x][y];
			}
		}

		return currE;
	}
	void CDibDoc:: RGBToHSV(RGBTRIPLE* rgbImg[], HSVTRIPLE* hsvImg[], int width, int height) {
		if(rgbImg == NULL)
			return;
		for (int y = 0; y < height; ++ y) {
			for (int x = 0; x < width; ++ x) {
				double hue = 0.0;
				double sat = 0.0;
				double val = 0.0;

				double red = (double) (rgbImg[y][x].rgbtRed)/(double)255;
				double green = (double) rgbImg[y][x].rgbtGreen/(double)255;
				double blue = (double) rgbImg[y][x].rgbtBlue/(double)255;

				double cmax = max(max(red, blue), green);
				double cmin = min(min(red, blue), green);
				double delta = cmax - cmin;
				double d = 0.0;
				double h = 0.0;
				if(!delta) {
					hue = 0.0;
					sat = 0.0;
					val = cmax;
					//return;
				}

				else if (cmin == red) {
					d = green - blue;
					h = 3;
				}
				else if (cmin == green) {
					d = blue - red;
					h = 5;
				}
				else if (cmin == blue) {
					d = red - green;
					h = 1;
				}
				hue = 60*(h - d/delta);
				if(hue < 0)
					hue += 360;
				sat = delta/cmax;
				val = cmax;
				hsvImg[y][x].hue = hue;
				hsvImg[y][x].sat = sat;
				hsvImg[y][x].val = val;
			}
		}
	}
	void CDibDoc:: Dilation (RGBTRIPLE* rows[], int width, int height) {
		RGBTRIPLE* img[ 512 ];
		for( int i = 0; i < 512; ++i ) {
			img[ i ] = new RGBTRIPLE[ 512 ];
		}
		for (int y = 1; y < height - 1; ++ y) {
			for (int x = 1; x < width - 1; ++ x) {
				bool one = false;
				for (int yy = y - 1; yy < y + 2; ++ yy) {
					for (int xx = x - 1; xx < x + 2; ++ xx) {
						if(rows[yy][xx].rgbtBlue == 255) 
							one = true;
					}
				}
				if(one) {
					img[y][x].rgbtBlue = 255;
					img[y][x].rgbtGreen = 255;
					img[y][x].rgbtRed = 255;
				}
				else {
					img[y][x].rgbtBlue = 0;
					img[y][x].rgbtGreen = 0;
					img[y][x].rgbtRed = 0;
				}
			}
		}

		for (int y = 0; y < height; ++ y) {
			for (int x = 0; x < width; ++ x) {
				rows[y][x].rgbtBlue = img[y][x].rgbtBlue;		
				rows[y][x].rgbtGreen = img[y][x].rgbtGreen;	
				rows[y][x].rgbtRed = img[y][x].rgbtRed;	
			}
		}
	}
	void CDibDoc:: Erosion (RGBTRIPLE* rows[], int width, int height) {
		RGBTRIPLE* img[ 512 ];
		for( int i = 0; i < 512; ++i ) {
			img[ i ] = new RGBTRIPLE[ 512 ];
		}
		for (int y = 1; y < height - 1; ++ y) {
			for (int x = 1; x < width - 1; ++ x) {
				bool one = false;
				for (int yy = y - 1; yy < y + 2; ++ yy) {
					for (int xx = x - 1; xx < x + 2; ++ xx) {
						if(rows[yy][xx].rgbtBlue == 0) 
							one = true;
					}
				}
				if(one) {
					img[y][x].rgbtBlue = 0;
					img[y][x].rgbtGreen = 0;
					img[y][x].rgbtRed = 0;
				}
				else {
					img[y][x].rgbtBlue = 255;
					img[y][x].rgbtGreen = 255;
					img[y][x].rgbtRed = 255;
				}
			}
		}

		for (int y = 0; y < height; ++ y) {
			for (int x = 0; x < width; ++ x) {
				rows[y][x].rgbtBlue = img[y][x].rgbtBlue;		
				rows[y][x].rgbtGreen = img[y][x].rgbtGreen;	
				rows[y][x].rgbtRed = img[y][x].rgbtRed;	
			}
		}
	}
	void CDibDoc:: BinaryImage(RGBTRIPLE* src[], HSVTRIPLE* hsvImg[],int width, int height, int minH, int maxH, double minS, double maxS) {
		if(maxH == minH || minS >= maxS)
			return;
		if(maxH  < minH) {
			for (int y = 0; y < height; ++ y) {
				for (int x = 0; x < width; ++ x) {
					//if(hsvImg[y][x].hue < 9 || hsvImg[y][x].hue > 349) {
					if((hsvImg[y][x].hue < maxH || hsvImg[y][x].hue > minH) && hsvImg[y][x].sat >= minS && hsvImg[y][x].sat <= maxS) {
						//if(hsvImg[y][x].hue > 185 && hsvImg[y][x].hue < 220) {
						src[y][x].rgbtGreen = 255;
						src[y][x].rgbtBlue = 255;
						src[y][x].rgbtRed = 255;
					}
					else {
						src[y][x].rgbtGreen = 0;
						src[y][x].rgbtBlue = 0;
						src[y][x].rgbtRed = 0;
					}
				}
			}
		}
		else {
			for (int y = 0; y < height; ++ y) {
				for (int x = 0; x < width; ++ x) {
					//if(hsvImg[y][x].hue < 9 || hsvImg[y][x].hue > 349) {
					if(hsvImg[y][x].hue < maxH && hsvImg[y][x].hue > minH && hsvImg[y][x].sat >= minS && hsvImg[y][x].sat <= maxS) {
						//if(hsvImg[y][x].hue > 185 && hsvImg[y][x].hue < 220) {
						src[y][x].rgbtGreen = 255;
						src[y][x].rgbtBlue = 255;
						src[y][x].rgbtRed = 255;
					}
					else {
						src[y][x].rgbtGreen = 0;
						src[y][x].rgbtBlue = 0;
						src[y][x].rgbtRed = 0;
					}
				}
			}
		}
	}
	void CDibDoc:: MedianFilter (RGBTRIPLE* rows[], RGBTRIPLE* img[], int width, int height) {
		trace("start MedianFilter\r\n");

		for (int x = 1; x < width - 1; ++ x) {
			for (int y = 1; y < height - 1; ++ y) {

				std::vector<std::pair<int,int>> greyValues;
				int idx = 0;


				for (int xx = x - 1; xx < x + 2; ++ xx) {
					for (int yy = y - 1; yy < y + 2; ++ yy) {
						std::pair <int,int> input;
						int index = idx ++;
						int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
						input = std::make_pair(index,content);
						greyValues.push_back(input);
					}
				}

				std::sort (greyValues.begin(), greyValues.end(), compare);
				idx = (greyValues.at(4)).first; //mediana
				int medianX = x + idx/3 - 1;
				int medianY = y + idx%3 - 1;

				img[y][x] = rows [medianY][medianX];
			}
		}
		//gora
		for (int x = 1; x < width; ++ x) {
			int idx = 0;
			//int* input = new int[2];
			std::pair<int,int> input;
			std::vector<std::pair<int,int>> greyValues;
			for(int xx = x - 1; xx < x + 1; ++ xx) {
				for (int yy = 0; yy < 2; ++ yy) {
					int index = idx ++;
					int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
					std::make_pair(index, content);
					greyValues.push_back(input);
				}
			}
			std::sort (greyValues.begin(), greyValues.end(), compare);
			idx = ((int) 0.5*(greyValues.at(2).first + greyValues.at(3).first)); //mediana
			int medianX = x + idx/3 - 1;
			int medianY = 0 + idx%3;

			img[0][x] = rows [medianY][medianX];
			//delete input;
		}
		//dol
		for (int x = 1; x < width; ++ x) {
			std::vector<std::pair<int,int>> greyValues;
			int idx = 0;
			std::pair<int,int> input;
			for(int xx = x - 1; xx < x + 1; ++ xx) {
				for (int yy = height - 2; yy < height; ++ yy) {
					int index = idx ++;
					int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
					std::make_pair(index, content);
					greyValues.push_back(input);
				}
			}

			std::sort (greyValues.begin(), greyValues.end(), compare);

			idx = ((int) 0.5*(greyValues.at(2).first + greyValues.at(3).first)); //mediana
			int medianX = x + idx/3 - 1;
			int medianY = height - 1 + idx%3 - 1;

			img[height - 1][x] = rows [medianY][medianX];
			//delete input;
		}
		//lewo
		for (int y = 1; y < height; ++ y) {
			std::vector<std::pair<int,int>> greyValues;
			int idx = 0;
			std::pair<int,int> input;
			for(int xx = 0; xx < 2; ++ xx) {
				for (int yy = y - 1; yy < y + 1; ++ yy) {
					int index = idx ++;
					int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
					std::make_pair(index, content);
					greyValues.push_back(input);
				}
			}

			std::sort (greyValues.begin(), greyValues.end(), compare);

			idx = ((int) 0.5*(greyValues.at(2).first + greyValues.at(3).first)); //mediana
			int medianX = 0 + idx/3;
			int medianY = y + idx%3 - 1;

			img[y][0] = rows [medianY][medianX];
			//delete input;
		}
		//prawo
		for (int y = 1; y < height; ++ y) {
			std::vector<std::pair<int,int>> greyValues;
			int idx = 0;
			std::pair<int,int> input;
			for(int xx = width - 2; xx < width ; ++ xx) {
				for (int yy = y - 1; yy < y + 1; ++ yy) {
					int index = idx ++;
					int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
					std::make_pair(index, content);
					greyValues.push_back(input);
				}
			}

			std::sort (greyValues.begin(), greyValues.end(), compare);

			idx = ((int) 0.5*(greyValues.at(2).first + greyValues.at(3).first)); //mediana
			int medianX = width - 1 + idx/3 - 1;
			int medianY = y + idx%3 - 1;

			img[y][0] = rows [medianY][medianX];
			//delete input;
		}
		//rogi
		//lewy gorny
		std::vector<std::pair<int,int>> greyValues;
		int idx = 0;
		std::pair<int,int> input;
		for (int xx = 0; xx < 2; ++ xx) {
			for (int yy = 0; yy < 2; ++ yy) {
				int index = idx ++;
				int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
				std::make_pair(index, content);
				greyValues.push_back(input);
			}
		}
		std::sort (greyValues.begin(), greyValues.end(), compare);

		idx = ((int) 0.5*(greyValues.at(1).first + greyValues.at(2).first)); //mediana
		int medianX = idx/2;
		int medianY = idx%2;

		img[0][0] = rows [medianY][medianX];
		//delete input;
		//lewy dolny
		greyValues.clear();
		idx = 0;
		//std::pair<int,int> input;
		for (int xx = 0; xx < 2; ++ xx) {
			for (int yy = height - 2; yy < height; ++ yy) {
				int index = idx ++;
				int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
				std::make_pair(index, content);
				greyValues.push_back(input);
			}
		}
		std::sort (greyValues.begin(), greyValues.end(), compare);

		idx = ((int) 0.5*(greyValues.at(1).first + greyValues.at(2).first)); //mediana
		medianX = idx/2;
		medianY = height - 2 + idx%2;

		img[height - 1][0] = rows [medianY][medianX];
		//delete input;
		//prawy dolny
		greyValues.clear();
		idx = 0;
		//std::pair<int,int> input;
		for (int xx = width - 2; xx < width; ++ xx) {
			for (int yy = height - 2; yy < height; ++ yy) {
				int index = idx ++;
				int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
				std::make_pair(index, content);
				greyValues.push_back(input);
			}
		}
		std::sort (greyValues.begin(), greyValues.end(), compare);

		idx = ((int) 0.5*(greyValues.at(1).first + greyValues.at(2).first)); //mediana
		medianX = width - 2 + idx/2;
		medianY = height - 2 + idx%2;

		img[height - 1][ width - 1] = rows [medianY][medianX];
		//delete input;
		//prawy gorny
		greyValues.clear();
		idx = 0;
		//std::pair<int,int> input;
		for (int xx = width - 2; xx < width; ++ xx) {
			for (int yy = 0; yy < 2; ++ yy) {
				int index = idx ++;
				int content = rows[yy][xx].rgbtBlue + rows[yy][xx].rgbtGreen + rows[yy][xx].rgbtRed;
				std::make_pair(index, content);
				greyValues.push_back(input);
			}
		}
		std::sort (greyValues.begin(), greyValues.end(), compare);

		idx = ((int) 0.5*(greyValues.at(1).first + greyValues.at(2).first)); //mediana
		medianX = width - 2 + idx/2;
		medianY = 0 + idx%2;

		img[0][ width - 1] = rows [medianY][medianX];
		//delete input;
		/*for (int y = 0; y < height; ++ y) {
		for (int x = 0; x < width; ++ x) {
		rows[y][x] = img[y][x];		
		}
		}*/
	}
	void CDibDoc:: DrawRectangle(RGBTRIPLE* src[], int width, int height, int minX, int maxX, int minY, int maxY) {
		if(minX < 0 || minY < 0 || maxX > width - 1 || maxY > height - 1 || minX > maxX || minY > maxY)
			return;
		//y = minY
		for (int x = minX; x < maxX + 1; ++ x) {
			src[minY][x].rgbtGreen = 255;
			src[minY][x].rgbtBlue = 0;
			src[minY][x].rgbtRed = 0;
			if(minY) {
				src[minY - 1][x].rgbtGreen = 255;
				src[minY - 1][x].rgbtBlue = 0;
				src[minY - 1][x].rgbtRed = 0;
			}
		}
		//y = maxY
		for (int x = minX; x < maxX + 1; ++ x) {
			src[maxY][x].rgbtGreen = 255;
			src[maxY][x].rgbtBlue = 0;
			src[maxY][x].rgbtRed = 0;
			if(maxY != height - 1) {
				src[maxY + 1][x].rgbtGreen = 255;
				src[maxY + 1][x].rgbtBlue = 0;
				src[maxY + 1][x].rgbtRed = 0;
			}
		}
		//x = minX
		for (int y = minY; y < maxY + 1; ++ y) {
			src[y][minX].rgbtGreen = 255;
			src[y][minX].rgbtBlue = 0;
			src[y][minX].rgbtRed = 0;
			if(minX) {
				src[y][minX - 1].rgbtGreen = 255;
				src[y][minX - 1].rgbtBlue = 0;
				src[y][minX - 1].rgbtRed = 0;
			}
		}
		//x = maxX
		for (int y = minY; y < maxY + 1; ++ y) {
			src[y][maxX].rgbtGreen = 255;
			src[y][maxX].rgbtBlue = 0;
			src[y][maxX].rgbtRed = 0;
			if(maxX != width - 1) {
				src[y][maxX + 1].rgbtGreen = 255;
				src[y][maxX + 1].rgbtBlue = 0;
				src[y][maxX + 1].rgbtRed = 0;
			}
		}
	}
	//momenty
	long double CDibDoc:: CalculateM1(RGBTRIPLE* src[], int width, int height, int et) {
		long double M1 = 0;
		long double M20 = 0;
		long double M02 = 0;
		unsigned long m00 = 0;
		unsigned long m01 = 0;
		unsigned long m10 = 0;
		unsigned long m02 = 0;
		unsigned long m20 = 0;

		m00 = calcm(src, 0, 0, width, height, et);
		m01 = calcm(src, 0, 1, width, height, et);
		m10 = calcm(src, 1, 0, width, height, et);
		m02 = calcm(src, 0, 2, width, height, et);
		m20 = calcm(src, 2, 0, width, height, et);

		if (m00 < 15) //zerowe pole
			return NULL;

		M20 = m20 - (double)m10*(double)m10/(double)m00;
		M02 = m02 - (double)m01*(double)m01/(double)m00;

		M1 = (M20 + M02)/(m00*m00);

		return M1;
	}
	long double CDibDoc:: CalculateW3(RGBTRIPLE* src[], int width, int height, int et) {
		long double W3 = 0;
		long L = 0;
		long S = calcm(src, 0, 0, width, height, et);
		for (int y = 1; y < height - 1; ++ y) {
			for (int x = 1; x < width - 1; ++ x) {
				if(src[y][x].rgbtBlue == et) {
					if(!src[y-1][x-1].rgbtBlue || !src[y-1][x].rgbtBlue || !src[y-1][x + 1].rgbtBlue || !src[y][x -1].rgbtBlue || !src[y][x + 1].rgbtBlue || !src[y+1][x-1].rgbtBlue || !src[y+1][x].rgbtBlue || !src[y+1][x+1].rgbtBlue) {
						++ L;
					}
				}
			}
		}
		W3 = (long double) L/(long double) (2*sqrt(3.14159265359*S)) - 1;
		return W3;
	}
	double CDibDoc:: CalculateW7(RGBTRIPLE* src[], int width, int height, int et) {
		double W7 = 0;
		long m10 = calcm(src, 1, 0, width, height, et);
		long m01 = calcm(src, 0, 1, width, height, et);
		long m00 = calcm(src, 0, 0, width, height, et);
		int ic = (int)((double)m10/(double)m00); //srodek ciezkosci
		int jc = (int)((double)m01/(double)m00);

		int maxDist = 0;
		int minDist = width + height;
		for (int y = 0; y < height; ++ y) {
			for (int x = 0; x < width; ++ x) {
				if(src[y][x].rgbtBlue == et) {
					int dist = sqrt(std::pow(y - jc, 2) + std::pow(x - ic,2));
					if(dist < minDist)
						minDist = dist;
					if(dist > maxDist)
						maxDist = dist;
				}
			}
		}

		W7 = (double)minDist/(double)maxDist;
		return W7;
	}
	int CDibDoc:: CalculateMaxX(RGBTRIPLE* src[], int width, int height, int et) {

		for(int x = width - 1; x > -1; -- x) {
			for (int y = 0; y < height; ++ y) {
				if(src[y][x].rgbtBlue == et)
					return x;
			}
		}
		return -1;
	}
	int CDibDoc:: CalculateMaxY(RGBTRIPLE* src[], int width, int height, int et) {

		for(int y = height - 1; y > -1; -- y) {
			for (int x = 0; x < width; ++ x) {
				if(src[y][x].rgbtBlue == et)
					return y;
			}
		}
		return -1;
	}
	int CDibDoc:: CalculateMinX(RGBTRIPLE* src[], int width, int height, int et) {

		for(int x = 0; x < width; ++ x) {
			for (int y = 0; y < height; ++ y) {
				if(src[y][x].rgbtBlue == et)
					return x;
			}
		}
		return -1;
	}
	int CDibDoc:: CalculateMinY(RGBTRIPLE* src[], int width, int height, int et) {

		for(int y = 0; y < height; ++ y) {
			for (int x = 0; x < width; ++ x) {
				if(src[y][x].rgbtBlue == et)
					return y;
			}
		}
		return -1;
	}