// MedianFilterDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "MedianFilterDlg.h"
#include "afxdialogex.h"


// MedianFilterDlg 对话框

IMPLEMENT_DYNAMIC(MedianFilterDlg, CDialogEx)

MedianFilterDlg::MedianFilterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MedianFilterDlg, pParent)
	, m_kernelSize(0)
{

}

MedianFilterDlg::~MedianFilterDlg()
{
}

void MedianFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernelSize);
}


BEGIN_MESSAGE_MAP(MedianFilterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MedianFilterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MedianFilterDlg 消息处理程序


void MedianFilterDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
