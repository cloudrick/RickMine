// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__E4627544_4D42_4AB8_AFE8_7E63DA88C3A0__INCLUDED_)
#define AFX_CHILDVIEW_H__E4627544_4D42_4AB8_AFE8_7E63DA88C3A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

const int WIDTH = 18  ;
const int HEIGHT= 18  ;
const int MINE  = 50 ;

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	void Reset() ;
	void MyPaint() ;
	void extend(int x,int y) ;

	int sX ;
	int sY ;

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);	
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnReset();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected :
	CBitmap *BMP_BG ;
	CBitmap *BMP_0 ;
	CBitmap *BMP_1 ;
	CBitmap *BMP_2 ;
	CBitmap *BMP_3 ;
	CBitmap *BMP_4 ;
	CBitmap *BMP_5 ;
	CBitmap *BMP_6 ;
	CBitmap *BMP_7 ;
	CBitmap *BMP_8 ;
	CBitmap *BMP_Bomb ;
	CBitmap *BMP_Flag ;
	CBitmap *BMP_Select ;

	int map[HEIGHT+2][WIDTH+2] ;
	int remainB ;
	int usedB ;
	bool bRunning ;
	bool bBoom ;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__E4627544_4D42_4AB8_AFE8_7E63DA88C3A0__INCLUDED_)
