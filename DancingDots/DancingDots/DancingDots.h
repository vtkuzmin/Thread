
// DancingDots.h : главный файл заголовка для приложения DancingDots
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CDancingDotsApp:
// О реализации данного класса см. DancingDots.cpp
//

class CDancingDotsApp : public CWinApp
{
public:
	CDancingDotsApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDancingDotsApp theApp;
