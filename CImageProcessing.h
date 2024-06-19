#

#pragma once
class CImageProcessing
{
	pair<int, int>findMaxGrayLevelCoordinate(const cv::Mat&);

public:
	//灰度图像处理
	void RGB_2_Gray(Mat&,Mat&);//彩色图像灰度化
	void Show_Histogram(Mat&);//显示灰度直方图
	void EqualizeHist(Mat&,Mat&);//灰度直方图均衡化
	void grayLinearTransform(Mat&, Mat&,double alpha=1.5,double beta=30);//灰度线性变换
	void logTransform(Mat&, Mat&, double);//对数变换
	void gammaCorrection(Mat&, Mat&, double);//伽马变换
	void invertImage(Mat&, Mat&);//反色
	void cropGrayImage(Mat&, Mat&,int,int,int,int);//裁剪


	//形态学操作
	void erodeImage(Mat&, Mat&,int,int);//腐蚀
	void dilateImage(Mat&, Mat&, int, int);//膨胀
	void morphologyOpen(Mat&, Mat&, int,int);//开运算
	void morphologyClose(Mat&, Mat&, int, int);//闭运算

	//图像分割操作
	void fixedThresholdSegmentation(Mat&, Mat&, int);//固定阈值分割
	void adaptiveThresholdSegmentation(Mat&, Mat&, int,double);//全局自适应阈值分割
	void regionGrowing(Mat&, Mat&, int, int, int);//区域生长
	void SobelEdgeDetection(Mat&, Mat&);//Sobel边缘检测
	void CannyEdgeDetection(Mat&, Mat&,int,int);//Canny边缘检测
	void LaplacianEdgeDetection(Mat&, Mat&, int);//Laplace边缘检测
	void OTSUThresholdSegmentation(Mat&, Mat&);//OTSU
	void detectPoints(Mat&, Mat&);//点检测
	void lineDetection(Mat&, Mat&, int);//线检测


	//图像滤波操作

	void meanFilter(Mat&, Mat&, int);//均值滤波
	void medianFilter(Mat&, Mat&, int);//中值滤波
	void gaussianFilter(Mat&, Mat&, int);//高斯滤波
	void sobelShapen(Mat&, Mat&);//sobel滤波

	//其他操作
	void rotateImage(Mat&, Mat&,double);//旋转操作
	void flipImage(Mat&, Mat&,int);//翻转操作
	void changeSize(Mat&, Mat&,double);//放大缩小操作
	
};

