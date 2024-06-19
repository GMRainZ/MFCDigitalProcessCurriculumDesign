// RotateImageDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "RotateImageDlg.h"
#include "afxdialogex.h"


// RotateImageDlg 对话框

IMPLEMENT_DYNAMIC(RotateImageDlg, CDialogEx)

RotateImageDlg::RotateImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RotateImageDlg, pParent)
	, m_angle(0)
{

}

RotateImageDlg::~RotateImageDlg()
{
}

void RotateImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_angle);
}


BEGIN_MESSAGE_MAP(RotateImageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RotateImageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// RotateImageDlg 消息处理程序


void RotateImageDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
