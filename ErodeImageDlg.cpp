// ErodeImageDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "ErodeImageDlg.h"
#include "afxdialogex.h"


// ErodeImageDlg 对话框

IMPLEMENT_DYNAMIC(ErodeImageDlg, CDialogEx)

ErodeImageDlg::ErodeImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ErodeImageDlg, pParent)
	, m_kernelSize(0)
	, m_times(0)
{

}

ErodeImageDlg::~ErodeImageDlg()
{
}

void ErodeImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernelSize);
	DDX_Text(pDX, IDC_EDIT2, m_times);
}


BEGIN_MESSAGE_MAP(ErodeImageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ErodeImageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ErodeImageDlg 消息处理程序


void ErodeImageDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
