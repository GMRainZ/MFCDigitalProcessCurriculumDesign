// CropGrayImageDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "CropGrayImageDlg.h"
#include "afxdialogex.h"


// CropGrayImageDlg 对话框

IMPLEMENT_DYNAMIC(CropGrayImageDlg, CDialogEx)

CropGrayImageDlg::CropGrayImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CropGrayImageDlg, pParent)
	, m_x(0)
	, m_y(0)
	, m_height(0)
	, m_width(0)
{

}

CropGrayImageDlg::~CropGrayImageDlg()
{
}

void CropGrayImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_height);
	DDX_Text(pDX, IDC_EDIT4, m_width);
}


BEGIN_MESSAGE_MAP(CropGrayImageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CropGrayImageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CropGrayImageDlg 消息处理程序


void CropGrayImageDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
