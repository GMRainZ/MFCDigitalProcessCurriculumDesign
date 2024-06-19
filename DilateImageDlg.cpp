// DilateImageDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "DilateImageDlg.h"
#include "afxdialogex.h"


// DilateImageDlg 对话框

IMPLEMENT_DYNAMIC(DilateImageDlg, CDialogEx)

DilateImageDlg::DilateImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DilateImageDlg, pParent)
	, m_kernelSize(0)
	, m_times(0)
{

}

DilateImageDlg::~DilateImageDlg()
{
}

void DilateImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernelSize);
	DDX_Text(pDX, IDC_EDIT3, m_times);
}


BEGIN_MESSAGE_MAP(DilateImageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DilateImageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// DilateImageDlg 消息处理程序


void DilateImageDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
