#include"CImageProcessing.h"

// MFCDigitalProcessCurriculumDesignDlg.h: 头文件
//

#pragma once

enum DrawingMode 
{
	PointMode,
	LineMode,
	EllipseMode,
	RectMode,
	TextMode,
	OwnerDrawingMode
};
// CMFCDigitalProcessCurriculumDesignDlg 对话框
class CMFCDigitalProcessCurriculumDesignDlg : public CDialogEx
{
// 构造
public:
	CMFCDigitalProcessCurriculumDesignDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDIGITALPROCESSCURRICULUMDESIGN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_p1;
	CStatic m_p2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();


	void ShowDst();

	//original & destination
	Mat src, dst;
	CImage srcImage;

	stack<Mat>copy;

	CImageProcessing ImageProcessing;
	afx_msg void OnRGB_2_Gray();
	afx_msg void OnStnClickedpicture2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnEqualizeHist();
	afx_msg void OnGrayLinearTransform();
	afx_msg void OnLogTransform();
	afx_msg void OnGammaCorrection();
	afx_msg void OnErodeImage();
	afx_msg void OnDilateImage();
	afx_msg void OnFixedThresholdSegmentation();
	afx_msg void OnAdaptiveThresholdSegmentation();
	afx_msg void OnRegionGrowing();
	afx_msg void OnSobelEdgeDetection();
	afx_msg void OnCannyEdgeDetection();
	afx_msg void OnMeanFilter();
	afx_msg void OnMedianFilter();
	afx_msg void OnGaussianFilter();

	bool isopen;
	afx_msg void OnInvertImage();
	afx_msg void OnCropGrayImage();
	afx_msg void onMorphologyOpen();
	afx_msg void On32793();
	afx_msg void OnOTSU();
	afx_msg void OnDetectPoints();
	afx_msg void OnRotateImage();
	afx_msg void OnFlipImage();
	afx_msg void OnChangeSize();
	afx_msg void OnHorizontalDetection();
	afx_msg void OnNumericalDetection();
	afx_msg void OnFFDegreeLineDetection();
	afx_msg void OnMinusOnFFDegreeLineDetection();


protected:
	//const int maxGoBackN = 20;
	//int curGoBackN = 0;
	

	COLORREF LineColor;
	COLORREF ShapeColor;

	int LineType;
	bool isfilled;

	CPoint DownPoint,lastPoint;
	int Mode;
	bool startDrawing;

	bool isDrawingMode;
	bool isErase;
	bool isCrop;
public:
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();

	int LineWidth;
	afx_msg void OnEnChangeEdit6();
	//int m_LineType;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	CComboBox m_fill;

	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnStnClickedpicture1();
	CComboBox m_Mode;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CString m_text;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnLaplacianEdgeDetection();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnGoBack();

//protected:
//	CImage t_img;
//	BOOL move_flag;
//	BOOL down_flag;
//	BOOL up_flag;
//	int show_width;
//	int show_height;
//	double rect_width;
//	double rect_height;
//	double img_width;
//	double img_height;
//	double xscale;
//	double yscale;
//	CRect show_rect;
//	CRect pic_rect;
//	CPoint sel_pos;
//	CPoint prevPoint;
//	//CvPoint pointROI1;
//	CPoint startPoint;
//	//CvPoint pointROI4;
//	CPoint movePoint;
//	CPoint endPoint;
//	CvRect roi_rect;
//	int roi_width;
//	int roi_height;

	afx_msg void OnLaplacianShapen();
	afx_msg void OnSobelShapen();
};
