#pragma once


// RegionGrowingDlg 对话框

class RegionGrowingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RegionGrowingDlg)

public:
	RegionGrowingDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RegionGrowingDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RegionGrowingDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_threshold;
};
