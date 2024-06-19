// GaussianFilterDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "GaussianFilterDlg.h"
#include "afxdialogex.h"


// GaussianFilterDlg 对话框

IMPLEMENT_DYNAMIC(GaussianFilterDlg, CDialogEx)

GaussianFilterDlg::GaussianFilterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GaussianFilterDlg, pParent)
	, m_kernelSize(0)
{

}

GaussianFilterDlg::~GaussianFilterDlg()
{
}

void GaussianFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernelSize);
}


BEGIN_MESSAGE_MAP(GaussianFilterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &GaussianFilterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// GaussianFilterDlg 消息处理程序


void GaussianFilterDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
