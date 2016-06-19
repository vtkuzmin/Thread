
// ChildView.h : ��������� ������ CChildView
//


#pragma once


// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:
	CBitmap* m_pBMP;
	COLORREF m_clr;
	CDC* m_pDC;
	CWinThread *m_pThread;
	bool m_bContinue;

// ��������
public:
	void SetPixel(int x, int y);

// ���������������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnColor();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

