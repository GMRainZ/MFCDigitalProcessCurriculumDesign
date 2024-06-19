// RegionGrowingDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "RegionGrowingDlg.h"
#include "afxdialogex.h"


// RegionGrowingDlg 对话框

IMPLEMENT_DYNAMIC(RegionGrowingDlg, CDialogEx)

RegionGrowingDlg::RegionGrowingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RegionGrowingDlg, pParent)
	, m_threshold(0)
{

}

RegionGrowingDlg::~RegionGrowingDlg()
{
}

void RegionGrowingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_threshold);
}


BEGIN_MESSAGE_MAP(RegionGrowingDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RegionGrowingDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// RegionGrowingDlg 消息处理程序


void RegionGrowingDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
