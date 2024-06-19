
// MFCDigitalProcessCurriculumDesignDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCDigitalProcessCurriculumDesign.h"
#include "MFCDigitalProcessCurriculumDesignDlg.h"
#include "afxdialogex.h"
#include "LinearTransformDlg.h"
#include "LogTransformDlg.h"
#include "GammaCorrectionDlg.h"
#include "ErodeImageDlg.h"
#include "DilateImageDlg.h"
#include "FixedThresholdSegmentationDlg.h"
#include "RegionGrowingDlg.h"
#include "CannyEdgeDetectiondlg.h"
#include "MeanFilterDlg.h"
#include "MedianFilterDlg.h"
#include "GaussianFilterDlg.h"
#include "CropGrayImageDlg.h"
#include "MorphologyOpenDlg.h"
#include "MorphologyCloseDlg.h"
#include "RotateImageDlg.h"
#include "FlipImageDlg.h"
#include "ChangeSizeDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDigitalProcessCurriculumDesignDlg 对话框



CMFCDigitalProcessCurriculumDesignDlg::CMFCDigitalProcessCurriculumDesignDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDIGITALPROCESSCURRICULUMDESIGN_DIALOG, pParent)
	, LineWidth(0)
	, m_text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDigitalProcessCurriculumDesignDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_picture1, m_p1);
	DDX_Control(pDX, IDC_picture2, m_p2);

	DDX_Text(pDX, IDC_EDIT6, LineWidth);
	DDV_MinMaxInt(pDX, LineWidth, 0, 20);
	DDX_Radio(pDX, IDC_RADIO1, LineType);
	DDX_Control(pDX, IDC_COMBO2, m_fill);
	DDX_Control(pDX, IDC_COMBO3, m_Mode);
	DDX_Text(pDX, IDC_EDIT7, m_text);
}

BEGIN_MESSAGE_MAP(CMFCDigitalProcessCurriculumDesignDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CMFCDigitalProcessCurriculumDesignDlg::OnRGB_2_Gray)
	ON_STN_CLICKED(IDC_picture2, &CMFCDigitalProcessCurriculumDesignDlg::OnStnClickedpicture2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton6)
	ON_COMMAND(ID_32773, &CMFCDigitalProcessCurriculumDesignDlg::OnEqualizeHist)
	ON_COMMAND(ID_32775, &CMFCDigitalProcessCurriculumDesignDlg::OnGrayLinearTransform)
	ON_COMMAND(ID_32777, &CMFCDigitalProcessCurriculumDesignDlg::OnLogTransform)
	ON_COMMAND(ID_32778, &CMFCDigitalProcessCurriculumDesignDlg::OnGammaCorrection)
	ON_COMMAND(ID_32779, &CMFCDigitalProcessCurriculumDesignDlg::OnErodeImage)
	ON_COMMAND(ID_32780, &CMFCDigitalProcessCurriculumDesignDlg::OnDilateImage)
	ON_COMMAND(ID_32781, &CMFCDigitalProcessCurriculumDesignDlg::OnFixedThresholdSegmentation)
	ON_COMMAND(ID_32784, &CMFCDigitalProcessCurriculumDesignDlg::OnAdaptiveThresholdSegmentation)
	ON_COMMAND(ID_32785, &CMFCDigitalProcessCurriculumDesignDlg::OnRegionGrowing)
	ON_COMMAND(ID_32787, &CMFCDigitalProcessCurriculumDesignDlg::OnSobelEdgeDetection)
	ON_COMMAND(ID_32788, &CMFCDigitalProcessCurriculumDesignDlg::OnCannyEdgeDetection)
	ON_COMMAND(ID_32789, &CMFCDigitalProcessCurriculumDesignDlg::OnMeanFilter)
	ON_COMMAND(ID_32791, &CMFCDigitalProcessCurriculumDesignDlg::OnMedianFilter)
	ON_COMMAND(ID_32790, &CMFCDigitalProcessCurriculumDesignDlg::OnGaussianFilter)
	ON_COMMAND(ID_32805, &CMFCDigitalProcessCurriculumDesignDlg::OnInvertImage)
	ON_COMMAND(ID_32806, &CMFCDigitalProcessCurriculumDesignDlg::OnCropGrayImage)
	ON_COMMAND(ID_32792, &CMFCDigitalProcessCurriculumDesignDlg::onMorphologyOpen)
	ON_COMMAND(ID_32793, &CMFCDigitalProcessCurriculumDesignDlg::On32793)
	ON_COMMAND(ID_32797, &CMFCDigitalProcessCurriculumDesignDlg::OnOTSU)
	ON_COMMAND(ID_32798, &CMFCDigitalProcessCurriculumDesignDlg::OnDetectPoints)
	ON_COMMAND(ID_32807, &CMFCDigitalProcessCurriculumDesignDlg::OnRotateImage)
	ON_COMMAND(ID_32808, &CMFCDigitalProcessCurriculumDesignDlg::OnFlipImage)
	ON_COMMAND(ID_32809, &CMFCDigitalProcessCurriculumDesignDlg::OnChangeSize)
	ON_COMMAND(ID_32811, &CMFCDigitalProcessCurriculumDesignDlg::OnHorizontalDetection)
	ON_COMMAND(ID_32812, &CMFCDigitalProcessCurriculumDesignDlg::OnNumericalDetection)
	ON_COMMAND(ID_32813, &CMFCDigitalProcessCurriculumDesignDlg::OnFFDegreeLineDetection)
	ON_COMMAND(ID_32814, &CMFCDigitalProcessCurriculumDesignDlg::OnMinusOnFFDegreeLineDetection)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton8)
	ON_EN_CHANGE(IDC_EDIT6, &CMFCDigitalProcessCurriculumDesignDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedRadio3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCDigitalProcessCurriculumDesignDlg::OnCbnSelchangeCombo2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_STN_CLICKED(IDC_picture1, &CMFCDigitalProcessCurriculumDesignDlg::OnStnClickedpicture1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMFCDigitalProcessCurriculumDesignDlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton9)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton12)
	ON_COMMAND(ID_32820, &CMFCDigitalProcessCurriculumDesignDlg::OnLaplacianEdgeDetection)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCDigitalProcessCurriculumDesignDlg::OnGoBack)
	ON_COMMAND(ID_32825, &CMFCDigitalProcessCurriculumDesignDlg::OnLaplacianShapen)
	ON_COMMAND(ID_32826, &CMFCDigitalProcessCurriculumDesignDlg::OnSobelShapen)
END_MESSAGE_MAP()


// CMFCDigitalProcessCurriculumDesignDlg 消息处理程序

BOOL CMFCDigitalProcessCurriculumDesignDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	isopen = false;
	isDrawingMode = false;
	isErase = false;
	isCrop = false;


	LineColor = RGB(0, 0, 255);
	ShapeColor = RGB(255, 0, 0);
	LineWidth = 5;
	LineType = false;

	Mode = LineMode;
	startDrawing = false;
	UpdateData(FALSE);

	m_fill.AddString(TEXT("有填充"));
	m_fill.AddString(TEXT("无填充"));

	m_Mode.AddString(TEXT("点"));
	m_Mode.AddString(TEXT("直线"));
	m_Mode.AddString(TEXT("椭圆"));
	m_Mode.AddString(TEXT("矩形"));
	m_Mode.AddString(TEXT("文字"));
	m_Mode.AddString(TEXT("自由绘图"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCDigitalProcessCurriculumDesignDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CPaintDC dc(this);
		//dc.SetPixel(50, 50, RGB(0, 255, 0));


		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCDigitalProcessCurriculumDesignDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码


	UINT i;
	i = MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		//你自己的代码
		exit(0);
	}

	
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CString fileName;
	TCHAR szFilter[] = _T("JPEG文件(*.jpg)|*.jpg|GIF文件(*.gif)|*.gif|bmp文件(*.bmp)|*.bmp||");
	CFileDialog fileDlg(TRUE, _T("jpg"), NULL, 0, szFilter, this);

	if (fileDlg.DoModal() != IDOK)     //没有点确定按钮，返回
		return;

	fileName = fileDlg.GetPathName();

	//CImage image;
	srcImage.Load(fileName);
	CRect rectControl;
	m_p1.GetClientRect(rectControl);
	CDC* pDc = m_p1.GetDC();
	srcImage.Draw(pDc->m_hDC, rectControl);
	//srcImage.Destroy();
	m_p1.ReleaseDC(pDc);

	src = imread(fileName.GetBuffer());
	isopen = true;
}

void CMFCDigitalProcessCurriculumDesignDlg::ShowDst()
{
	CImage image;
	image.Load(TEXT("result.png"));
	CRect rectControl;
	m_p2.GetClientRect(rectControl);
	CDC* pDc = m_p2.GetDC();
	image.Draw(pDc->m_hDC, rectControl);
	image.Destroy();
	m_p2.ReleaseDC(pDc);

}


void CMFCDigitalProcessCurriculumDesignDlg::OnRGB_2_Gray()
{
	// TODO: 在此添加命令处理程序代码

	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.RGB_2_Gray(src, dst);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnStnClickedpicture2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd* bmpShow = GetDlgItem(IDC_picture2);
	CDC* pdc = bmpShow->GetDC();
	CImage  imag;
	CRect rect;

	GetClientRect(&rect);        //获取画布大小
	bmpShow->GetWindowRect(&rect);
	imag.Create(rect.Width(), rect.Height(), 32);
	::BitBlt(imag.GetDC(), 0, 0, rect.Width(), rect.Height(), pdc->m_hDC, 0, 0, SRCCOPY);

	TCHAR szFilter[] = _T("jpg file(*.jpg)|*.jpg|bmp file(*.bmp)|*.bmp|所有文件(*.*)|*.*||");  //文件格式过滤
	// 构造保存文件对话框    
	CFileDialog fileDlg(FALSE, _T("jpg"), _T("*.jpg"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	fileDlg.m_ofn.lpstrTitle = _T("保存图片");  //保存对话窗口标题名
	CString picturePath;
	if (IDOK == fileDlg.DoModal())  //按下确认键
	{
		picturePath = fileDlg.GetPathName();  //文件路径
	}

	HRESULT hResult = imag.Save(picturePath); //保存图片
	ReleaseDC(pdc);
	imag.ReleaseDC();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.Show_Histogram(src);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	dst = imread("result.png");
	ImageProcessing.Show_Histogram(dst);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnEqualizeHist()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.EqualizeHist(src, dst);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnGrayLinearTransform()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	double alpha = 1.5, beta = 30;


	LinearTransformDlg LTDlg;
	LTDlg.m_k = alpha, LTDlg.m_b = beta;
	
	if (LTDlg.DoModal() == IDOK)
	{
		alpha = LTDlg.m_k;
		beta = LTDlg.m_b;
	}

	ImageProcessing.grayLinearTransform(src, dst, alpha, beta);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnLogTransform()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	double c = 40;

	LogTransformDlg LTDlg;
	LTDlg.m_c = c;
	if (LTDlg.DoModal() == IDOK)
	{
		c = LTDlg.m_c;
	}

	ImageProcessing.logTransform(src, dst, c);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnGammaCorrection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	double gamma = 0.5;

	GammaCorrectionDlg GCDlg;
	GCDlg.m_gamma = gamma;
	if (GCDlg.DoModal() == IDOK)
	{
		gamma = GCDlg.m_gamma;
	}

	ImageProcessing.gammaCorrection(src, dst, gamma);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnErodeImage()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize = 3, times = 1;

	ErodeImageDlg EIDlg;
	EIDlg.m_kernelSize = kernelSize, EIDlg.m_times = times;
	if (EIDlg.DoModal() == IDOK)
	{
		kernelSize = EIDlg.m_kernelSize;
		times = EIDlg.m_times;
	}

	ImageProcessing.erodeImage(src, dst, kernelSize, times);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnDilateImage()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize=3, times=1;

	DilateImageDlg DIDlg;
	DIDlg.m_kernelSize = kernelSize, DIDlg.m_times = times;
	if (DIDlg.DoModal() == IDOK)
	{
		kernelSize = DIDlg.m_kernelSize;
		times = DIDlg.m_times;
	}

	ImageProcessing.dilateImage(src, dst, kernelSize, times);
	imwrite("result.png", dst);
	ShowDst();

}


void CMFCDigitalProcessCurriculumDesignDlg::OnFixedThresholdSegmentation()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int thresholdValue = 127;

	FixedThresholdSegmentationDlg FTSDlg;
	FTSDlg.m_thresholdValue = thresholdValue;
	if (FTSDlg.DoModal() == IDOK)
	{
		thresholdValue = FTSDlg.m_thresholdValue;
	}


	ImageProcessing.fixedThresholdSegmentation(src, dst, thresholdValue);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnAdaptiveThresholdSegmentation()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int blockSize = 11; double constant = 2.0;

	ImageProcessing.adaptiveThresholdSegmentation(src, dst, blockSize, constant);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnRegionGrowing()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int threshold = 50;
	RegionGrowingDlg RGDlg;
	RGDlg.m_threshold = threshold;
	if (RGDlg.DoModal() == IDOK)
	{
		threshold = RGDlg.m_threshold;
	}

	//dst = Mat::zeros(src.size(), CV_8UC1);
	ImageProcessing.regionGrowing(src, dst, src.rows >> 1, src.cols >> 1, threshold);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnSobelEdgeDetection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.SobelEdgeDetection(src, dst);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnCannyEdgeDetection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int lowThreshold = 20, highThreshold = 200;

	CannyEdgeDetectiondlg CEDDlg;
	CEDDlg.m_lowThreshold = lowThreshold, CEDDlg.m_highThreshold = highThreshold;

	if (CEDDlg.DoModal() == IDOK)
	{
		lowThreshold = CEDDlg.m_lowThreshold;
		highThreshold = CEDDlg.m_highThreshold;
	}

	ImageProcessing.CannyEdgeDetection(src, dst, lowThreshold, highThreshold);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnMeanFilter()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize = 3;

	MeanFilterDlg MFDlg;
	MFDlg.m_kernelSize = kernelSize;
	if (MFDlg.DoModal() == IDOK)
	{
		kernelSize = MFDlg.m_kernelSize;
	}

	ImageProcessing.meanFilter(src, dst, kernelSize);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnMedianFilter()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize = 3;

	MedianFilterDlg MFDlg;
	MFDlg.m_kernelSize = kernelSize;
	if (MFDlg.DoModal() == IDOK)
	{
		kernelSize = MFDlg.m_kernelSize;
	}

	ImageProcessing.medianFilter(src, dst, kernelSize);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnGaussianFilter()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize = 3;

	GaussianFilterDlg GFDlg;
	GFDlg.m_kernelSize = kernelSize;
	if (GFDlg.DoModal() == IDOK)
	{
		kernelSize = GFDlg.m_kernelSize;
	}

	ImageProcessing.gaussianFilter(src, dst, kernelSize);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnInvertImage()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.invertImage(src, dst);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnCropGrayImage()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	isCrop = true;

	//const int row = src.rows, col = src.cols;
	//int x=col>>1, y=row>>1, height=y, width=x;

	//CropGrayImageDlg CGDlg;
	//CGDlg.m_x = x, CGDlg.m_y = y;
	//CGDlg.m_height = height, CGDlg.m_width = width;
	//if (CGDlg.DoModal() == IDOK)
	//{
	//	x = CGDlg.m_x, y = CGDlg.m_y;
	//	height = CGDlg.m_height;
	//	width = CGDlg.m_width;
	//}

	//if (x < 0 || y < 0 || x + width > col || y + height > row)
	//{
	//	MessageBox(TEXT("裁剪区域越界！"), TEXT("提示"));
	//	return;
	//}

	//ImageProcessing.cropGrayImage(src, dst,x,y,width,height);
	//imwrite("result.png", dst);
	//ShowDst();


	//OnRButtonDown();
	//OnRButtonUp();

	//const int row = src.rows, col = src.cols;
	//int sx=lastPoint.x, sy=lastPoint.y, ex=DownPoint.x, ey=DownPoint.y;
	//int height = ey-sy, width = ex-sy;

	//height *= row * 1.0f / 813, width *= col * 1.0f / 513;
	//sx += 20, sy += 430;
	////CropGrayImageDlg CGDlg;
	////CGDlg.m_x = x, CGDlg.m_y = y;
	////CGDlg.m_height = height, CGDlg.m_width = width;
	////if (CGDlg.DoModal() == IDOK)
	////{
	////	x = CGDlg.m_x, y = CGDlg.m_y;
	////	height = CGDlg.m_height;
	////	width = CGDlg.m_width;
	////}

	//if (sx < 0 || sy < 0 || sy + width > col ||sx + height > row)
	//{
	//	MessageBox(TEXT("裁剪区域越界！"), TEXT("提示"));
	//	return;
	//}

	//ImageProcessing.cropGrayImage(src, dst,sy,sx,width,height);
	//imwrite("result.png", dst);
	//ShowDst();
	//CPaintDC dc(this); // 用于绘制对话框的设备上下文

	//// 创建与窗口兼容的设备上下文和位图
	//HDC hdc = CreateCompatibleDC(dc.GetSafeHdc());
	//CBitmap* pBitmap = new CBitmap();

	//CRect rectControl;
	//GetClientRect(rectControl);
	//pBitmap->CreateCompatibleBitmap(dc.GetSafeHdc(), rectControl.Width(), rectControl.Height());

	//
	//// 释放资源
	//delete pBitmap;
	//DeleteDC(hdc);

}


void CMFCDigitalProcessCurriculumDesignDlg::onMorphologyOpen()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize = 3, times = 1;

	MorphologyOpenDlg MODlg;
	MODlg.m_kernelSize = kernelSize;
	MODlg.m_times = times;
	if (MODlg.DoModal() == IDOK)
	{
		kernelSize = MODlg.m_kernelSize;
		times = MODlg.m_times;
	}

	ImageProcessing.morphologyOpen(src, dst, kernelSize, times);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::On32793()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize = 3, times = 1;

	MorphologyOpenDlg MODlg;
	MODlg.m_kernelSize = kernelSize;
	MODlg.m_times = times;
	if (MODlg.DoModal() == IDOK)
	{
		kernelSize = MODlg.m_kernelSize;
		times = MODlg.m_times;
	}

	ImageProcessing.morphologyOpen(src, dst, kernelSize, times);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnOTSU()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}


	ImageProcessing.OTSUThresholdSegmentation(src, dst);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnDetectPoints()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}


	ImageProcessing.detectPoints(src, dst);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnRotateImage()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}

	double angle=45;

	RotateImageDlg RDlg;
	RDlg.m_angle = angle;
	if (RDlg.DoModal() == IDOK)
	{
		angle = RDlg.m_angle;
	}

	ImageProcessing.rotateImage(src, dst, angle);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnFlipImage()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int x = 1;

	FlipImageDlg FDlg;
	FDlg.m_x = x;
	if (FDlg.DoModal() == IDOK)
	{
		x = FDlg.m_x;
	}

	ImageProcessing.flipImage(src, dst,x);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnChangeSize()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}

	double scale = 1;
	ChangeSizeDlg CSDlg;
	CSDlg.m_scale = scale;
	if (CSDlg.DoModal() == IDOK)
	{
		scale = CSDlg.m_scale;
	}

	ImageProcessing.changeSize(src, dst, scale);
	imshow("变换后的尺寸", dst);
	waitKey(0);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnHorizontalDetection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.lineDetection(src, dst, 0);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnNumericalDetection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.lineDetection(src, dst, 1);
	imwrite("result.png", dst);
	ShowDst();
}



void CMFCDigitalProcessCurriculumDesignDlg::OnFFDegreeLineDetection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.lineDetection(src, dst, 2);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnMinusOnFFDegreeLineDetection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.lineDetection(src, dst, 3);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	CColorDialog colorDlg(LineColor);
	if (colorDlg.DoModal() == IDOK)
	{
		LineColor = colorDlg.GetColor();
	}
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	CColorDialog colorDlg(ShapeColor);
	if (colorDlg.DoModal() == IDOK)
	{
		ShapeColor = colorDlg.GetColor();
	}

}


void CMFCDigitalProcessCurriculumDesignDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	UpdateData(TRUE);

}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	LineType = false;
	UpdateData(TRUE);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	LineType = true;
	UpdateData(TRUE);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	int index = m_fill.GetCurSel();
	if (index)isfilled = true;
	else isfilled = false;
}


void CMFCDigitalProcessCurriculumDesignDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (isDrawingMode)
	{
		CClientDC dc(this);

		Mat temp = imread("result.png");
		copy.push(temp);
		//curGoBackN = (curGoBackN + 1) % maxGoBackN;

		if (Mode == PointMode)
		{

			dc.SetPixel(point.x, point.y, LineColor);
		}
		else if (Mode == OwnerDrawingMode)startDrawing = true;
		else if (Mode == TextMode)
		{
			dc.TextOut(point.x, point.y, m_text);
			//OnCbnSelchangeCombo3();
			CWnd* bmpShow = GetDlgItem(IDC_picture2);
			CDC* pdc = bmpShow->GetDC();
			CImage  imag;
			CRect rect;

			GetClientRect(&rect);        //获取画布大小
			bmpShow->GetWindowRect(&rect);
			imag.Create(rect.Width(), rect.Height(), 32);
			::BitBlt(imag.GetDC(), 0, 0, rect.Width(), rect.Height(), pdc->m_hDC, 0, 0, SRCCOPY);
			HRESULT hResult = imag.Save("result.png"); //保存图片
			ShowDst();
			ReleaseDC(pdc);
			imag.ReleaseDC();
		}
		lastPoint = DownPoint = point;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if (!isDrawingMode)return;

	CClientDC dc(this);

	CPen pen(LineType?PS_DASH:PS_SOLID, LineWidth, LineColor);	
	CPen* pOldPen = dc.SelectObject(&pen);
	CBrush brush(ShapeColor),transparent;
	transparent.CreateStockObject(NULL_BRUSH);
	CBrush* oldBrush=nullptr;
	if (isfilled)
	{
		oldBrush = dc.SelectObject(&brush);
	}
	else
	{
		oldBrush = dc.SelectObject(&transparent);
	}

	if (Mode == EllipseMode)
	{
		dc.Ellipse(DownPoint.x, DownPoint.y, point.x, point.y);
	}
	if (Mode == RectMode)
	{
		dc.Rectangle(DownPoint.x, DownPoint.y, point.x, point.y);

	}
	//CString str1 = "绘制圆 半径=";
	//int r = 50;
	//CString data;
	//data.Format("%s %d", str1, r);
	//dc.TextOut(105, 105, data);

	if (Mode == LineMode)
	{
		dc.MoveTo(DownPoint.x, DownPoint.y);
		dc.LineTo(point.x, point.y);
	}

	if (Mode == OwnerDrawingMode)startDrawing = false;


	//copy=imread("")

	CWnd* bmpShow = GetDlgItem(IDC_picture2);
	CDC* pdc = bmpShow->GetDC();
	CImage  imag;
	CRect rect;

	GetClientRect(&rect);        //获取画布大小
	bmpShow->GetWindowRect(&rect);
	imag.Create(rect.Width(), rect.Height(), 32);
	::BitBlt(imag.GetDC(), 0, 0, rect.Width(), rect.Height(), pdc->m_hDC, 0, 0, SRCCOPY);
	HRESULT hResult = imag.Save("result.png"); //保存图片
	ShowDst();
	ReleaseDC(pdc);
	imag.ReleaseDC();

	if(isfilled)dc.SelectObject(oldBrush);
	dc.SelectObject(pOldPen);
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnStnClickedpicture1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCDigitalProcessCurriculumDesignDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	Mode=m_Mode.GetCurSel();



	/*
	m_Mode.AddString(TEXT("点"));
	m_Mode.AddString(TEXT("直线"));
	m_Mode.AddString(TEXT("矩形"));
	m_Mode.AddString(TEXT("椭圆"));
	m_Mode.AddString(TEXT("文字"));
	*/

}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	//CWnd* pPictureControl = GetDlgItem(IDC_picture2);

	//CRect rect;
	//pPictureControl->GetClientRect(&rect);
	//pPictureControl->InvalidateRect(&rect, TRUE);
	//GetDlgItem(IDC_picture2)->ShowWindow(FALSE);
	Invalidate();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (isDrawingMode && startDrawing)
	{
		CClientDC dc(this);

		CPen pen(LineType ? PS_DASH : PS_SOLID, LineWidth, LineColor);
		CPen* pOldPen = dc.SelectObject(&pen);

		dc.MoveTo(lastPoint.x, lastPoint.y);
		dc.LineTo(point.x, point.y);

		lastPoint = point;

		dc.SelectObject(pOldPen);
	}


	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	UpdateData(TRUE);
	MessageBox(TEXT("请左键点击对话框，选择插入文字的位置"), TEXT("提示"));

}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	isDrawingMode = true;
	MessageBox(TEXT("已经打开绘图模式"), TEXT("提示"));
}


void CMFCDigitalProcessCurriculumDesignDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}
	isDrawingMode = false;
	MessageBox(TEXT("已经关闭绘图模式"), TEXT("提示"));
}


void CMFCDigitalProcessCurriculumDesignDlg::OnLaplacianEdgeDetection()
{
	// TODO: 在此添加命令处理程序代码
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}

	int kernelSize=3;

	ImageProcessing.LaplacianEdgeDetection(src, dst, kernelSize);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (isCrop)
	{
		DownPoint = lastPoint = point;
	}
}


void CMFCDigitalProcessCurriculumDesignDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (isCrop)
	{
		isCrop = false;

		DownPoint = point;

		const int row = src.rows, col = src.cols;
		int sx=lastPoint.x, sy=lastPoint.y, ex=DownPoint.x, ey=DownPoint.y;
		int height = ey-sy, width = ex-sx;

		height *= row * 1.0f / 813, width *= col * 1.0f / 513;
		sx -= 20, sy -= 430;

		if (sx<0 || sy<0 || sx + height > row || sy + width > col)
		{
			MessageBox(TEXT("你所截取的区域越界"), TEXT("警告"));
			return;
		}

		ImageProcessing.cropGrayImage(src, dst,sx,sy,width,height);
		imwrite("result.png", dst);
		ShowDst();


	}
}


void CMFCDigitalProcessCurriculumDesignDlg::OnGoBack()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isDrawingMode)
	{
		MessageBox(TEXT("请先打开绘图模式"), TEXT("提示"));
		return;
	}

	if (!copy.empty())
	{
		dst = copy.top();
		copy.pop();
	}

	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnLaplacianShapen()
{
	// TODO: 在此添加命令处理程序代码

	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	int kernelSize = 3;

	ImageProcessing.LaplacianEdgeDetection(src, dst, kernelSize);
	cv::addWeighted(src, 0.7, dst, 0.3, 0, dst);
	imwrite("result.png", dst);
	ShowDst();
}


void CMFCDigitalProcessCurriculumDesignDlg::OnSobelShapen()
{
	// TODO: 在此添加命令处理程序代码	int kernelSize = 3;
	if (!isopen)
	{
		MessageBox(TEXT("请先打开图片"), TEXT("提示"));
		return;
	}
	ImageProcessing.sobelShapen(src,dst);
	imwrite("result.png", dst);
	ShowDst();
}
