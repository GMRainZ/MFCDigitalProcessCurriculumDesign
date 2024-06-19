#pragma once


// ErodeImageDlg 对话框

class ErodeImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ErodeImageDlg)

public:
	ErodeImageDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ErodeImageDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ErodeImageDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_kernelSize;
	int m_times;
};
