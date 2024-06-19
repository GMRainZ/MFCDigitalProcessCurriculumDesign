#pragma once


// RotateImageDlg 对话框

class RotateImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RotateImageDlg)

public:
	RotateImageDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RotateImageDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RotateImageDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_angle;
};
