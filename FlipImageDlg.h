﻿#pragma once


// FlipImageDlg 对话框

class FlipImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FlipImageDlg)

public:
	FlipImageDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FlipImageDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_x;
};
