// CannyEdgeDetectiondlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "CannyEdgeDetectiondlg.h"
#include "afxdialogex.h"


// CannyEdgeDetectiondlg 对话框

IMPLEMENT_DYNAMIC(CannyEdgeDetectiondlg, CDialogEx)

CannyEdgeDetectiondlg::CannyEdgeDetectiondlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CannyEdgeDetectionDlg, pParent)
	, m_lowThreshold(0)
	, m_highThreshold(0)
{

}

CannyEdgeDetectiondlg::~CannyEdgeDetectiondlg()
{
}

void CannyEdgeDetectiondlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_lowThreshold);
	DDX_Text(pDX, IDC_EDIT2, m_highThreshold);
}


BEGIN_MESSAGE_MAP(CannyEdgeDetectiondlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CannyEdgeDetectiondlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CannyEdgeDetectiondlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDCANCEL, &CannyEdgeDetectiondlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CannyEdgeDetectiondlg 消息处理程序


void CannyEdgeDetectiondlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void CannyEdgeDetectiondlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CannyEdgeDetectiondlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
