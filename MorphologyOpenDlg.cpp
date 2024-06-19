// MorphologyOpenDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "MorphologyOpenDlg.h"
#include "afxdialogex.h"


// MorphologyOpenDlg 对话框

IMPLEMENT_DYNAMIC(MorphologyOpenDlg, CDialogEx)

MorphologyOpenDlg::MorphologyOpenDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_kernelSize(0)
	, m_times(0)
{

}

MorphologyOpenDlg::~MorphologyOpenDlg()
{
}

void MorphologyOpenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernelSize);
	DDX_Text(pDX, IDC_EDIT2, m_times);
}


BEGIN_MESSAGE_MAP(MorphologyOpenDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MorphologyOpenDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MorphologyOpenDlg 消息处理程序


void MorphologyOpenDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
