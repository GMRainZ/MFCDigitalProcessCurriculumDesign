// MorphologyCloseDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "MorphologyCloseDlg.h"
#include "afxdialogex.h"


// MorphologyCloseDlg 对话框

IMPLEMENT_DYNAMIC(MorphologyCloseDlg, CDialogEx)

MorphologyCloseDlg::MorphologyCloseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MorphologyCloseDlg, pParent)
	, m_kernelSize(0)
	, m_times(0)
{

}

MorphologyCloseDlg::~MorphologyCloseDlg()
{
}

void MorphologyCloseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernelSize);
	DDX_Text(pDX, IDC_EDIT2, m_times);
}


BEGIN_MESSAGE_MAP(MorphologyCloseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MorphologyCloseDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MorphologyCloseDlg 消息处理程序


void MorphologyCloseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
