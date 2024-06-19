#pragma once


// CropGrayImageDlg 对话框

class CropGrayImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CropGrayImageDlg)

public:
	CropGrayImageDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CropGrayImageDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CropGrayImageDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_x;
	int m_y;
	int m_height;
	int m_width;
};
