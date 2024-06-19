#pragma once


// CannyEdgeDetectiondlg 对话框

class CannyEdgeDetectiondlg : public CDialogEx
{
	DECLARE_DYNAMIC(CannyEdgeDetectiondlg)

public:
	CannyEdgeDetectiondlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CannyEdgeDetectiondlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CannyEdgeDetectionDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	int m_lowThreshold;
	int m_highThreshold;
	afx_msg void OnBnClickedCancel();
};
