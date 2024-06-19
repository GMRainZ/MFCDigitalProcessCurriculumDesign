#pragma once


// ChangeSizeDlg 对话框

class ChangeSizeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeSizeDlg)

public:
	ChangeSizeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangeSizeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChangeSizeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	double m_scale;
	afx_msg void OnEnChangeEdit1();
};
