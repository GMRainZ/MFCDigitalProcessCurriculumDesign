// GammaCorrectionDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "GammaCorrectionDlg.h"
#include "afxdialogex.h"


// GammaCorrectionDlg 对话框

IMPLEMENT_DYNAMIC(GammaCorrectionDlg, CDialogEx)

GammaCorrectionDlg::GammaCorrectionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GammaCorrectionDlg, pParent)
	, m_gamma(0)
{

}

GammaCorrectionDlg::~GammaCorrectionDlg()
{
}

void GammaCorrectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_gamma);
}


BEGIN_MESSAGE_MAP(GammaCorrectionDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &GammaCorrectionDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &GammaCorrectionDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// GammaCorrectionDlg 消息处理程序


void GammaCorrectionDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void GammaCorrectionDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
