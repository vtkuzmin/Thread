
// DancingDots.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "DancingDots.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDancingDotsApp

BEGIN_MESSAGE_MAP(CDancingDotsApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CDancingDotsApp::OnAppAbout)
END_MESSAGE_MAP()


// �������� CDancingDotsApp

CDancingDotsApp::CDancingDotsApp()
{
	// TODO: �������� ���� ������ �������������� ���������� ������� ����������� ��������������; �������������
	// ������ ��� ������: �����������.�����������.����������.���������������
	SetAppID(_T("DancingDots.AppID.NoVersion"));

	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}

// ������������ ������ CDancingDotsApp

CDancingDotsApp theApp;


// ������������� CDancingDotsApp

BOOL CDancingDotsApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// ��� ������������� �������� ���������� RichEdit ��������� ����� AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ����������
	// ���������� ��������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));


	// ����� ������� ������� ����, ���� ��� ������� ����� ������ ����
	// �����, � ����� ������ ��� ��� ������ ��������� ���� ����������
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// �������� � ��������� ����� � ��� ���������
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);






	// ���� � ������ ���� ���� ���� ����������������, ������� ���������� � �������� ���
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	// ����� DragAcceptFiles ������ ��� ������� ��������
	//  � ���������� SDI ��� ������ ��������� ����� ProcessShellCommand
	return TRUE;
}

int CDancingDotsApp::ExitInstance()
{
	//TODO: ����������� �������������� �������, ������� ����� ���� ���������
	return CWinApp::ExitInstance();
}

// ����������� ��������� CDancingDotsApp


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// ������� ���������� ��� ������� �������
void CDancingDotsApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// ����������� ��������� CDancingDotsApp



