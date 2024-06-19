﻿#pragma once


// GaussianFilterDlg 对话框

class GaussianFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(GaussianFilterDlg)

public:
	GaussianFilterDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GaussianFilterDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GaussianFilterDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_kernelSize;
};
