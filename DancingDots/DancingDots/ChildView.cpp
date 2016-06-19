
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "DancingDots.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_pDC = NULL;
	m_pBMP = NULL;
	m_clr = RGB(255, 255, 255);
	m_pThread = NULL;
	m_bContinue =false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_START, &CChildView::OnStart)
	ON_COMMAND(ID_STOP, &CChildView::OnStop)
	ON_COMMAND(ID_COLOR, &CChildView::OnColor)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	
	if (!m_pDC) {
		m_pDC = new CDC;
		m_pDC->CreateCompatibleDC(&dc);
		CBitmap* pNewBMP = new CBitmap;
		pNewBMP->CreateCompatibleBitmap(&dc, 2000, 2000);
		m_pBMP = m_pDC->SelectObject(pNewBMP);
	}

	CRect rect;
	GetClientRect(rect);

	CCriticalSection cs;
	cs.Lock();
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), m_pDC, 0, 0, SRCCOPY);
	cs.Unlock();

	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}

UINT __cdecl ThreadProc( LPVOID pParam ){
	CChildView *pView = (CChildView *)pParam;
	while(pView->m_bContinue){
		pView->SetPixel(rand()%2000, rand()%2000);
		pView->Invalidate();
	}
	return 0;
}


void CChildView::OnStart(){
	m_bContinue = true;
	m_pThread = AfxBeginThread(ThreadProc, (LPVOID)this);
}


void CChildView::OnStop(){
	m_bContinue = false;
	WaitForSingleObject(m_pThread->m_hThread, INFINITE);
}


void CChildView::OnColor()
{
	CColorDialog ColorDLG;
	if (ColorDLG.DoModal() == IDOK) {
		m_clr = ColorDLG.GetColor();
		Invalidate();
	}
	// TODO: добавьте свой код обработчика команд
}


void CChildView::SetPixel(int x, int y){
	CCriticalSection cs;
	cs.Lock();
	m_pDC->SetPixel(x,y,m_clr);
	cs.Unlock();
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	return 0;//CWnd::OnEraseBkgnd(pDC);
}
