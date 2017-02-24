// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "RickMine.h"
#include "ChildView.h"
#include <stdlib.h>
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
	srand( (unsigned) time(NULL) ) ;
	BMP_BG = new CBitmap ;
	BMP_0 = new CBitmap;
	BMP_1 = new CBitmap;
	BMP_2 = new CBitmap;
	BMP_3 = new CBitmap;
	BMP_4 = new CBitmap;
	BMP_5 = new CBitmap;
	BMP_6 = new CBitmap;
	BMP_7 = new CBitmap;
	BMP_8 = new CBitmap;
	BMP_Bomb = new CBitmap;
	BMP_Flag = new CBitmap;
	BMP_Select = new CBitmap;

	BMP_BG->m_hObject = (HBITMAP)::LoadImage(NULL,"bg.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_0 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_0.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_1 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_1.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_2 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_2.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_3 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_3.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_4 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_4.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_5 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_5.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_6 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_6.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_7 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_7.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_8 ->m_hObject = (HBITMAP)::LoadImage(NULL,"num_8.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_Flag->m_hObject = (HBITMAP)::LoadImage(NULL,"red_flag.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_Bomb->m_hObject = (HBITMAP)::LoadImage(NULL,"num_9.bmp",IMAGE_BITMAP,
						30,30,LR_LOADFROMFILE) ;
	BMP_Select->m_hObject = (HBITMAP)::LoadImage(NULL,"cursor.bmp",IMAGE_BITMAP,
						38,38,LR_LOADFROMFILE) ;
	sX = sY = -1 ;
	Reset() ;
}

CChildView::~CChildView()
{
	delete BMP_BG ;
	delete BMP_0 ;
	delete BMP_1 ;
	delete BMP_2 ;
	delete BMP_3 ;
	delete BMP_4 ;
	delete BMP_5 ;
	delete BMP_6 ;
	delete BMP_7 ;
	delete BMP_8 ;
	delete BMP_Bomb ;
	delete BMP_Flag ;
	delete BMP_Select ;
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	MyPaint() ;
	
	// Do not call CWnd::OnPaint() for painting messages
}

void CChildView::MyPaint()
{
	CClientDC dc(this) ;

	CDC *mdc = new CDC ;

	mdc->CreateCompatibleDC(&dc) ;

	for( int i=1 ; i<HEIGHT+1 ; i++)
	{
		for( int j=1 ; j<WIDTH+1 ; j++ )
		{
			if( map[i][j] == 0 || (map[i][j] == -1 && !bBoom) )
			{
				mdc->SelectObject( BMP_BG ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if( map[i][j] == -1 && bBoom)
			{
				mdc->SelectObject( BMP_Bomb ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			} 
			else if(map[i][j] == 1 )
			{
				mdc->SelectObject( BMP_1 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 2)
			{
				mdc->SelectObject( BMP_2 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 3)
			{
				mdc->SelectObject( BMP_3 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 4)
			{
				mdc->SelectObject( BMP_4 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 5)
			{
				mdc->SelectObject( BMP_5 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 6)
			{
				mdc->SelectObject( BMP_6 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 7)
			{
				mdc->SelectObject( BMP_7 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 8)
			{
				mdc->SelectObject( BMP_8 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if(map[i][j] == 10)
			{
				mdc->SelectObject( BMP_0 ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;
			}
			else if( map[i][j] == -2 || map[i][j]<=-100)
			{
				mdc->SelectObject( BMP_Flag ) ;
				dc.BitBlt((i-1)*30,(j-1)*30,30,30,mdc,0,0,SRCCOPY) ;

			}
		}
	}

	if( sX >=0 && sY>=0)
	{
		mdc->SelectObject( BMP_Select ) ;
		dc.BitBlt((sX)*30-4,(sY)*30-4,38,38,mdc,0,0,SRCAND) ;
	}

	delete mdc ;
}


void CChildView::Reset()
{
	bRunning = true ;
	bBoom = false ;

	usedB = 0 ;
	remainB = MINE ;

	for( int i=0 ; i<HEIGHT+2 ; i++)
	{
		for( int j=0 ; j<WIDTH+2 ; j++)
		{
			if( i==0 || i==HEIGHT+1 || j==0 || j==WIDTH+1 )
				map[i][j] = 100 ;
			else
				map[i][j] = 0 ;
		}
	}

	int k=MINE ;

	while(k>0)
	{
		int ii = rand()%HEIGHT+1 ;
		int jj = rand()%WIDTH+1 ;

		if( map[ii][jj] != -1 )
		{
			map[ii][jj] = -1 ;
			k-- ;
		}
	}
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	sX = point.x /30 ;
	sY = point.y /30 ;
	CWnd::OnMouseMove(nFlags, point);
	MyPaint() ;
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if( bBoom || !bRunning)
		return ;

	int x = point.x / 30 +1 ;
	int y = point.y / 30 +1 ;

	extend(x,y) ;
	MyPaint() ;

	CWnd::OnLButtonUp(nFlags, point);
}

void CChildView::extend(int x,int y)
{
	int k=0 ;
	if( map[x][y] == 0 )
	{
		if( map[x-1][y-1] == -1 || map[x-1][y-1] == -2)
			k++ ;
		if( map[x-1][y] == -1 || map[x-1][y] == -2 )
			k++ ;
		if( map[x-1][y+1] == -1 || map[x-1][y+1] == -2 )
			k++ ;
		if( map[x][y+1] == -1 || map[x][y+1] == -2 )
			k++ ;
		if( map[x][y-1] == -1 || map[x][y-1] == -2)
			k++ ;
		if( map[x+1][y-1] == -1 || map[x+1][y-1] == -2 )
			k++ ;
		if( map[x+1][y] == -1 || map[x+1][y] == -2)
			k++ ;
		if( map[x+1][y+1] == -1 || map[x+1][y+1] == -2)
			k++ ;

		map[x][y] = k ;

		if( k==0 )
			map[x][y] = 10 ;

		if( k==0 )
		{
			extend(x-1,y-1) ;
			extend(x-1,y) ;
			extend(x-1,y+1) ;
			extend(x,y-1) ;
			extend(x,y+1) ;
			extend(x+1,y-1) ;
			extend(x+1,y) ;
			extend(x+1,y+1) ;
		}

	}
	else if(map[x][y] == -1 )
	{
		bRunning = false ;
		bBoom = true ;
	}
}

void CChildView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if( bBoom || !bRunning)
		return ;

	int x = point.x / 30 +1 ;
	int y = point.y / 30 +1 ;

	if( map[x][y] == 0 )
	{
		map[x][y] = -100 ;
		usedB++ ;
	}
	else if(map[x][y] == -100)
	{
		map[x][y] = 0 ;
		usedB-- ;
	}
	else if( map[x][y] == -1 )
	{
		map[x][y] = -2 ;
		remainB-- ;
		usedB++ ;
	}
	else if( map[x][y] == -2 )
	{
		map[x][y] = -1 ;
		remainB++;
		usedB-- ;
	}	

	MyPaint() ;

	if( remainB ==0 && usedB == MINE)
	{
		bRunning = false ;
		MyPaint() ;
		AfxMessageBox("YES") ;
	}

	CWnd::OnRButtonUp(nFlags, point);
}

void CChildView::OnReset() 
{
	// TODO: Add your command handler code here
	Reset() ;	
	MyPaint() ;
}
