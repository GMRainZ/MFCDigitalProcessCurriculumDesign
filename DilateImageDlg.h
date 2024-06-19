#pragma once


// DilateImageDlg 对话框

class DilateImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DilateImageDlg)

public:
	DilateImageDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DilateImageDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DilateImageDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_kernelSize;
	int m_times;
};
