// MeanFilterDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "MeanFilterDlg.h"
#include "afxdialogex.h"


// MeanFilterDlg 对话框

IMPLEMENT_DYNAMIC(MeanFilterDlg, CDialogEx)

MeanFilterDlg::MeanFilterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MeanFilterDlg, pParent)
	, m_kernelSize(0)
{

}

MeanFilterDlg::~MeanFilterDlg()
{
}

void MeanFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernelSize);
}


BEGIN_MESSAGE_MAP(MeanFilterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MeanFilterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MeanFilterDlg 消息处理程序


void MeanFilterDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
