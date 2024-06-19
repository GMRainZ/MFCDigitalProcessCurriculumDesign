#pragma once


// FixedThresholdSegmentationDlg 对话框

class FixedThresholdSegmentationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FixedThresholdSegmentationDlg)

public:
	FixedThresholdSegmentationDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FixedThresholdSegmentationDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FixedThresholdSegmentationDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_thresholdValue;
	afx_msg void OnEnChangeEdit1();
};
