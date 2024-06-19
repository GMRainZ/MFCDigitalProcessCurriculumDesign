// FlipImageDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "FlipImageDlg.h"
#include "afxdialogex.h"


// FlipImageDlg 对话框

IMPLEMENT_DYNAMIC(FlipImageDlg, CDialogEx)

FlipImageDlg::FlipImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_x(0)
{

}

FlipImageDlg::~FlipImageDlg()
{
}

void FlipImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x);
}


BEGIN_MESSAGE_MAP(FlipImageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &FlipImageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// FlipImageDlg 消息处理程序


void FlipImageDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
