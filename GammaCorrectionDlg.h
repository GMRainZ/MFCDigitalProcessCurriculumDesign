#pragma once


// GammaCorrectionDlg 对话框

class GammaCorrectionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(GammaCorrectionDlg)

public:
	GammaCorrectionDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GammaCorrectionDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GammaCorrectionDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	double m_gamma;
	afx_msg void OnBnClickedOk();
};
