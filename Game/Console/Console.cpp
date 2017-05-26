
// Console.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Console.h"
#include "ConsoleDlg.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CConsoleApp

BEGIN_MESSAGE_MAP(CConsoleApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CConsoleApp ����

CConsoleApp::CConsoleApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CConsoleApp ����

CConsoleApp theApp;


// CConsoleApp ��ʼ��

BOOL CConsoleApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));


	// TODO: �Լ��Ĺ���

	//�ж��Ƿ�࿪
	if (BMoreOpen())
		return FALSE;

	//�ͷ���Դ��ָ����Ŀ¼ ����ע����Դ
	if (!ReleaseResoureToFilePath())
	{
		AfxMessageBox("�ͷ���Դ��ָ��Ŀ¼ʧ�ܣ�");
		return FALSE;
	}

	::CoInitialize(NULL);
	pAuth.CreateInstance(__uuidof(CurrencyAuth));

	//�ڴ����VNC�ļ�
	if (!LoadVNCFromMemory())
	{
		AfxMessageBox("���ڴ����ͨ���ļ�ʧ�ܣ�");
		return FALSE;
	}

	auto result = pAuth->Initialize("{C1E14188-7629-4B10-B2B5-E03B523C90E6}");//��֤�����ʼ��

	if (result == -1)
	{
		pAuth.Release();
		::CoUninitialize();
		return FALSE;
	}



	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CConsoleDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

bool CConsoleApp::BMoreOpen()
{
	auto temp = ::CreateMutex(NULL, FALSE, "Console_hxl");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(temp);
		return true;
	}
	return false;
}

bool CConsoleApp::ReleaseResoureToFilePath()
{
	HRSRC HIdrDllAllP = ::FindResource(NULL, MAKEINTRESOURCE(IDR_DLL_ALLP), "dll");
	if (!HIdrDllAllP)
	{
		return false;
	}

	auto IdrSize = SizeofResource(NULL, HIdrDllAllP);
	if (!IdrSize)
	{
		return false;
	}

	HGLOBAL hGlobal = LoadResource(NULL, HIdrDllAllP);
	if (!hGlobal)
	{
		return false;
	}

	LPVOID pBuffer = LockResource(hGlobal);
	if (!pBuffer)
	{
		return false;
	}

	auto hFile =  CreateFile("c:\\AllpurAuthentic.dll", GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (!hFile)
		return false;
	DWORD dwWriteSize;
	WriteFile(hFile, hGlobal, IdrSize, &dwWriteSize, NULL);
	CloseHandle(hFile);

	WinExec("regsvr32  \"c:\\AllpurAuthentic.dll\" ", SW_HIDE);

	return true;
}

bool CConsoleApp::LoadVNCFromMemory()
{
	HRSRC hRsrc = ::FindResource(NULL, MAKEINTRESOURCE(IDR_VNC_VSGROUP), "vnc");
	if (!hRsrc)
	{
		return FALSE;
	}
	DWORD dwSize = SizeofResource(NULL, hRsrc);
	if (!dwSize)
	{
		return FALSE;
	}
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);
	if (!hGlobal)
	{
		return FALSE;
	}
	LPVOID pBuffer = LockResource(hGlobal);
	if (NULL == pBuffer)
		return FALSE;

	pAuth->InputVNC((int)pBuffer, dwSize);
	return true;
}

