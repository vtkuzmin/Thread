
// ChildView.h : интерфейс класса CChildView
//


#pragma once


// окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
public:
	CBitmap* m_pBMP;
	COLORREF m_clr;
	CDC* m_pDC;
	CWinThread *m_pThread;
	bool m_bContinue;

// Операции
public:
	void SetPixel(int x, int y);

// Переопределение
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnColor();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

