// RickMine.h : main header file for the RICKMINE application
//

#if !defined(AFX_RICKMINE_H__C0F806CD_CAFA_47E2_80AF_365C84B6B27C__INCLUDED_)
#define AFX_RICKMINE_H__C0F806CD_CAFA_47E2_80AF_365C84B6B27C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRickMineApp:
// See RickMine.cpp for the implementation of this class
//

class CRickMineApp : public CWinApp
{
public:
	CRickMineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRickMineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CRickMineApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICKMINE_H__C0F806CD_CAFA_47E2_80AF_365C84B6B27C__INCLUDED_)
