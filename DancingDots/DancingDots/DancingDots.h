
// DancingDots.h : ������� ���� ��������� ��� ���������� DancingDots
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CDancingDotsApp:
// � ���������� ������� ������ ��. DancingDots.cpp
//

class CDancingDotsApp : public CWinApp
{
public:
	CDancingDotsApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDancingDotsApp theApp;
