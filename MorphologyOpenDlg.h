﻿#pragma once


// MorphologyOpenDlg 对话框

class MorphologyOpenDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MorphologyOpenDlg)

public:
	MorphologyOpenDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MorphologyOpenDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_kernelSize;
	int m_times;
};
