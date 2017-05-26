// MainDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Console.h"
#include "MainDialog.h"
#include "afxdialogex.h"
#include "ShareMemoryService.h"

// CMainDialog �Ի���

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)
END_MESSAGE_MAP()


// CMainDialog ��Ϣ�������


void CMainDialog::PreInitDialog()
{
	// TODO: ���������ڴ�
	if (!CShareMemoryService::GetInstance()->CreateShareMemory()) {
		AfxMessageBox("ͨ��ʧ�ܣ�����ϵ���߸��³��򣬻����������ԣ�");
		return;
	}
		
	CDialogEx::PreInitDialog();
}


BOOL CMainDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ����Լ��ĳ�ʼ������


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
