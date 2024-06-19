#include "pch.h"
#include "CImageProcessing.h"

pair<int, int> CImageProcessing::findMaxGrayLevelCoordinate(const cv::Mat&src)
{
	Mat image = src.clone();
	cvtColor(image, image, COLOR_BGR2GRAY);
	int maxVal = 0;
	std::pair<int, int> maxCoordinate = { -1, -1 };

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			uchar val = image.at<uchar>(i, j);
			if (val > maxVal) {
				maxVal = val;
				maxCoordinate = { i, j };
			}
		}
	}

	return maxCoordinate;
}

void CImageProcessing::RGB_2_Gray(Mat&src,Mat&res)
{
	cvtColor(src, res, cv::COLOR_BGR2GRAY);
}

void CImageProcessing::Show_Histogram(Mat&src)
{
	Mat image=src, image_gray, hist;   //定义输入图像，灰度图像, 直方图


	cvtColor(image, image_gray, COLOR_BGR2GRAY);  //灰度化

	//获取图像直方图
	int histsize = 256;
	float ranges[] = { 0,256 };
	const float* histRanges = { ranges };
	calcHist(&image_gray, 1, 0, Mat(), hist, 1, &histsize, &histRanges, true, false);

	//创建直方图显示图像
	int hist_h = 300;//直方图的图像的高
	int hist_w = 512; //直方图的图像的宽
	int bin_w = hist_w / histsize;//直方图的等级
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));//绘制直方图显示的图像

	//绘制并显示直方图
	normalize(hist, hist, 0, hist_h, NORM_MINMAX, -1, Mat());//归一化直方图
	for (int i = 1; i < histsize; i++)
	{
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
	}
	imshow("histImage", histImage);

	waitKey(0);  //暂停，保持图像显示，等待按键结束

}

void CImageProcessing::EqualizeHist(Mat&src,Mat&dst)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);
	equalizeHist(dst, dst);
}

void CImageProcessing::grayLinearTransform(Mat&src, Mat&dst, double alpha, double beta)
{
	cv::Mat grayImage(src.rows, src.cols, CV_8UC1);

	// 将RGB图像转换为灰度图像
	cv::cvtColor(src, grayImage, cv::COLOR_BGR2GRAY);

	// 对灰度图像进行线性变换
	for (int i = 0; i < grayImage.rows; ++i) {
		for (int j = 0; j < grayImage.cols; ++j) {
			grayImage.at<uchar>(i, j) = cv::saturate_cast<uchar>(alpha * grayImage.at<uchar>(i, j) + beta);
		}
	}

	dst = grayImage;
}

void CImageProcessing::logTransform(Mat&inputImage, Mat&dst, double c)
{
	cv::Mat grayImage(inputImage.rows, inputImage.cols, CV_8UC1);

	// 将RGB图像转换为灰度图像
	cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	// 对灰度图像进行对数变换
	for (int i = 0; i < grayImage.rows; ++i) {
		for (int j = 0; j < grayImage.cols; ++j) {
			int originalPixelValue =static_cast<int>(grayImage.at<uchar>(i, j));
			int newPixelVale = saturate_cast<uchar>(c * log(1 + originalPixelValue));
			
			grayImage.at<uchar>(i, j) = newPixelVale;
		}
	}

	dst = grayImage;
}

void CImageProcessing::gammaCorrection(Mat&src, Mat&dst, double gamma)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);
	//dst.convertTo(dst, CV_32F); // 转换为浮点数

	Mat TransformedImage = Mat::zeros(dst.size(), CV_8U);

	// 对每个像素应用伽马校正
	for (int y = 0; y < dst.rows; y++) {
		for (int x = 0; x < dst.cols; x++) {
			int originalPixelValue = static_cast<int>(dst.at<uchar>(y, x));
			int newPixelVale = saturate_cast<uchar>(255*pow(originalPixelValue/255.0,gamma));

			TransformedImage.at<uchar>(y, x) = newPixelVale;
		}
	}

	// 将结果转换回8位无符号整数
	dst = TransformedImage;

}

void CImageProcessing::invertImage(Mat&src, Mat&dst)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);
	bitwise_not(dst, dst);
}

void CImageProcessing::cropGrayImage(Mat&src, Mat&dst,
	int x,int y,int width,int height)
{
	dst = src(cv::Rect(x, y, width, height));
}

void CImageProcessing::erodeImage(Mat&inputImage, Mat&dst, int kernelSize,int times=1)
{
	dst = inputImage.clone();
	// 定义一个结构元素
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernelSize, kernelSize));
	// 使用腐蚀操作
	while(times--)
		cv::erode(dst, dst, kernel);


}

void CImageProcessing::dilateImage(Mat&inputImage, Mat&dst, int kernelSize, int times)
{
	dst = inputImage.clone();
	// 定义一个结构元素
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernelSize, kernelSize));
	// 使用腐蚀操作
	while (times--)
		cv::dilate(dst, dst, kernel);
}

void CImageProcessing::morphologyOpen(Mat&inputImage, Mat&dst, int kernelSize, int times)
{
	dst = inputImage.clone();
	// 定义一个结构元素
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernelSize, kernelSize));
	// 使用腐蚀操作
	while (times--)
	{
		cv::erode(dst, dst, kernel);
		cv::dilate(dst, dst, kernel);
	}
		
}

void CImageProcessing::morphologyClose(Mat& inputImage, Mat& dst, int kernelSize, int times)
{
	dst = inputImage.clone();
	// 定义一个结构元素
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernelSize, kernelSize));
	// 使用腐蚀操作
	while (times--)
	{
		cv::dilate(dst, dst, kernel);
		cv::erode(dst, dst, kernel);
	}
}

void CImageProcessing::fixedThresholdSegmentation(Mat&inputImage, Mat&dst, int thresholdValue)
{

	// 转换为灰度图像
	cv::cvtColor(inputImage, dst, cv::COLOR_BGR2GRAY);

	// 应用固定阈值进行二值化
	cv::threshold(dst, dst, thresholdValue, 255, cv::THRESH_BINARY);


}

void CImageProcessing::adaptiveThresholdSegmentation(Mat&inputImage, Mat&dst, 
	int blockSize, double constant)
{
	//cv::Mat grayImage, binaryImage;

	// 转换为灰度图像
	cv::cvtColor(inputImage, dst, cv::COLOR_BGR2GRAY);

	// 应用自适应阈值进行二值化
	cv::adaptiveThreshold(dst, dst, 255, 
		cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, blockSize, constant);
	/*
	adaptiveMethod：自适应方法，有以下几种选择：

    ADAPTIVE_THRESH_MEAN_C：阈值等于邻域内像素值的平均值加上常数C。
    ADAPTIVE_THRESH_GAUSSIAN_C：阈值等于邻域内像素值的高斯加权和加上常数C。

thresholdType：阈值类型，有以下几种选择：

    THRESH_BINARY：大于阈值的像素设置为maxValue，小于阈值的像素设置为0。
    THRESH_BINARY_INV：大于阈值的像素设置为0，小于阈值的像素设置为maxValue。
    THRESH_TRUNC：大于阈值的像素设置为阈值，小于阈值的像素设置为0。
    THRESH_TOZERO：大于阈值的像素设置为0，小于阈值的像素保持不变。
    THRESH_TOZERO_INV：大于阈值的像素保持不变，小于阈值的像素设置为0。

	blockSize：邻域大小，必须是奇数。
	*/
}

void CImageProcessing::regionGrowing(Mat& img, Mat& result, int x, int y, int threshold)
{
	result = Mat::zeros(img.size(), CV_8UC1);
	// 设置种子点范围条件
	auto temp = findMaxGrayLevelCoordinate(img);
	Point2i seed(temp.first, temp.second);
	// 种子点集
	vector<Point2i> seeds;
	// 压入初始种子点
	seeds.push_back(seed);
	// 种子点设置为白
	result.ptr<uchar>(seed.y)[seed.x] = 255;
	// 8连接生长方向
	int growDirections[8][2] = { {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1} };


	// 开始生长
	while (!seeds.empty()) {
		// 取出一个种子点作为现在循环的初始种子点
		Point2i seed_current = seeds.back();
		seeds.pop_back();


		// 遍历各生长方向的邻点
		for (int i = 0; i < 8; i++) {
			Point2i neighborPoint = { seed_current.x + growDirections[i][0], seed_current.y + growDirections[i][1] }; // 邻点
			if (neighborPoint.x < 0 || neighborPoint.y < 0 || neighborPoint.x > img.cols - 1 || neighborPoint.y > img.rows - 1) { // 邻点超出范围
				continue;
			}
			if ((result.ptr<uchar>(neighborPoint.y)[neighborPoint.x] == 0) && abs(img.ptr<uchar>(neighborPoint.y)[neighborPoint.x] - img.ptr<uchar>(seed.y)[seed.x]) < threshold) {
				// 设置为种子点
				result.ptr<uchar>(neighborPoint.y)[neighborPoint.x] = 255; // 设置为白色
				seeds.push_back(neighborPoint); // 压入种子集
			}
		}
	}
}

void CImageProcessing::SobelEdgeDetection(Mat&inputImage, Mat&dst)
{
	Mat src;
	cvtColor(inputImage, src, COLOR_BGR2GRAY);
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;

	// 计算X方向的梯度
	cv::Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_x, abs_grad_x);

	// 计算Y方向的梯度
	cv::Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 0, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	// 合并梯度
	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
}

void CImageProcessing::CannyEdgeDetection(Mat&src, Mat&dst, int lowThreshold,int highThreshold)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);
	Canny(src, dst, lowThreshold, highThreshold);
}

void CImageProcessing::LaplacianEdgeDetection(Mat&src, Mat&dst, int kernelSize)
{
	//cvtColor(src, dst, COLOR_BGR2GRAY);
	Laplacian(src, dst, CV_16S, kernelSize);
	convertScaleAbs(dst, dst);
}

void CImageProcessing::OTSUThresholdSegmentation(Mat&src, Mat&dst)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);
	threshold(dst, dst, 0, 255, THRESH_BINARY | THRESH_OTSU);
}

void CImageProcessing::detectPoints(Mat&src, Mat&dst)
{

	Mat dst_norm, dst_norm_scaled,grayImage;
	cvtColor(src, grayImage, COLOR_BGR2GRAY);

	int blockSize = 2;
	int apertureSize = 3;
	double k = 0.04;

	cornerHarris(grayImage, dst, blockSize, apertureSize, k);

	// 归一化结果
	normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(dst_norm, dst_norm_scaled);

	// 绘制角点
	for (int i = 0; i < dst_norm.rows; i++) {
		for (int j = 0; j < dst_norm.cols; j++) {
			if ((int)dst_norm.at<float>(i, j) > 100) {
				circle(dst_norm_scaled, Point(j, i), 5, Scalar(0), 2, 8, 0);
			}
		}
	}

	dst = dst_norm_scaled;
	//imshow("Detected Points", dst);
	//waitKey(0);
}

void CImageProcessing::meanFilter(Mat&src, Mat&dst, int kernelSize)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);;
	cv::blur(dst, dst, cv::Size(kernelSize, kernelSize));
}

void CImageProcessing::medianFilter(Mat& src, Mat& dst, int kernelSize)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);
	cv::medianBlur(dst, dst, kernelSize);
}

void CImageProcessing::gaussianFilter(Mat&src, Mat&dst, int kernelSize)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);
	cv::GaussianBlur(dst, dst, cv::Size(kernelSize, kernelSize), 0);
}

void CImageProcessing::sobelShapen(Mat&src, Mat&dst)
{
	cvtColor(src, dst, COLOR_BGR2GRAY);

	Mat Xkernel= (Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1) ,
		Ykernel= (Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);;

	Mat Xgray, Ygray;

	filter2D(dst, Xgray, -1, Xkernel);
	filter2D(dst, Ygray, -1, Xkernel);

	addWeighted(Xgray, 0.5, Ygray, 0.5, 0, dst);
	//addWeighted(src, 0.7, dst, 0.3, 0, dst);

}

void CImageProcessing::rotateImage(Mat&src, Mat&dst,double angle)
{
	// 获取图像的中心点
	cv::Point2f center(src.cols / 2.0, src.rows / 2.0);
	// 计算旋转矩阵
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
	// 应用旋转矩阵
	cv::warpAffine(src, dst, rot, src.size());
}

void CImageProcessing::flipImage(Mat&src, Mat&dst,int x)
{
	cv::flip(src, dst, x); // 1表示水平翻转 0表示垂直翻转
}

void CImageProcessing::changeSize(Mat&src, Mat&dst,double scale)
{
	resize(src, dst, Size(src.cols*scale,src.rows*scale));

}

void CImageProcessing::lineDetection(Mat&src, Mat&dst, int classification)
{
	const int row = src.rows, col = src.cols;
	cvtColor(src, dst, COLOR_BGR2GRAY);
	classification %= 4;

	Mat kernel;
	if (!classification)//水平检测
	{
		//(Mat_<float>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);
		kernel =(Mat_<float>(3,3) << -1, -1, -1 , 2, 2, 2, -1, -1, -1 );
	}
	if (classification == 1)//竖直检测
	{
		kernel = (Mat_<float>(3, 3) <<- 1, 2, -1, -1, 2, -1, -1, 2, -1);
	}
	if (classification == 2)//45°检测
	{
		kernel = (Mat_<float>(3, 3) << 2, -1, -1, -1, 2, -1, -1, -1, 2);
	}
	if (classification == 3)//-45°检测
	{
		kernel = (Mat_<float>(3, 3) << -1, -1, 2, -1, 2, -1, 2, -1, -1);
	}


	//int r, c,i,j;
	//double sum;

	//for (r = 0; r < row; ++r)
	//{
	//	for (c = 0; c < col; ++c)
	//	{
	//		sum = 0.;
	//		for (i = -1; i <= 1; ++i)
	//		{
	//			for (j = -1; j <= 1; ++j)
	//			{
	//				if (r + i < row && c + j < col && r + i >= 0 && c + j >= 0)
	//				{
	//					sum += src.at<uchar>(r + i, c + j) * kernel.at<float>(i + 1, j + 1);
	//				}
	//			}
	//		}
	//		dst.at<uchar>(i, j) = saturate_cast<uchar>(sum);
	//	}
	//}
	filter2D(dst, dst, -1, kernel);
}
