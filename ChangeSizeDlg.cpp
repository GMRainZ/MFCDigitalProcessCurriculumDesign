// ChangeSizeDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "ChangeSizeDlg.h"
#include "afxdialogex.h"


// ChangeSizeDlg 对话框

IMPLEMENT_DYNAMIC(ChangeSizeDlg, CDialogEx)

ChangeSizeDlg::ChangeSizeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangeSizeDlg, pParent)
	, m_scale(0)
{

}

ChangeSizeDlg::~ChangeSizeDlg()
{
}

void ChangeSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_scale);
}


BEGIN_MESSAGE_MAP(ChangeSizeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChangeSizeDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &ChangeSizeDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// ChangeSizeDlg 消息处理程序


void ChangeSizeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void ChangeSizeDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
