// FixedThresholdSegmentationDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "FixedThresholdSegmentationDlg.h"
#include "afxdialogex.h"


// FixedThresholdSegmentationDlg 对话框

IMPLEMENT_DYNAMIC(FixedThresholdSegmentationDlg, CDialogEx)

FixedThresholdSegmentationDlg::FixedThresholdSegmentationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FixedThresholdSegmentationDlg, pParent)
	, m_thresholdValue(0)
{

}

FixedThresholdSegmentationDlg::~FixedThresholdSegmentationDlg()
{
}

void FixedThresholdSegmentationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_thresholdValue);
}


BEGIN_MESSAGE_MAP(FixedThresholdSegmentationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &FixedThresholdSegmentationDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &FixedThresholdSegmentationDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// FixedThresholdSegmentationDlg 消息处理程序


void FixedThresholdSegmentationDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void FixedThresholdSegmentationDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
