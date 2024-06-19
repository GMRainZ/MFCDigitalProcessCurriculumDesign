#

#pragma once
class CImageProcessing
{
	pair<int, int>findMaxGrayLevelCoordinate(const cv::Mat&);

public:
	//�Ҷ�ͼ����
	void RGB_2_Gray(Mat&,Mat&);//��ɫͼ��ҶȻ�
	void Show_Histogram(Mat&);//��ʾ�Ҷ�ֱ��ͼ
	void EqualizeHist(Mat&,Mat&);//�Ҷ�ֱ��ͼ���⻯
	void grayLinearTransform(Mat&, Mat&,double alpha=1.5,double beta=30);//�Ҷ����Ա任
	void logTransform(Mat&, Mat&, double);//�����任
	void gammaCorrection(Mat&, Mat&, double);//٤��任
	void invertImage(Mat&, Mat&);//��ɫ
	void cropGrayImage(Mat&, Mat&,int,int,int,int);//�ü�


	//��̬ѧ����
	void erodeImage(Mat&, Mat&,int,int);//��ʴ
	void dilateImage(Mat&, Mat&, int, int);//����
	void morphologyOpen(Mat&, Mat&, int,int);//������
	void morphologyClose(Mat&, Mat&, int, int);//������

	//ͼ��ָ����
	void fixedThresholdSegmentation(Mat&, Mat&, int);//�̶���ֵ�ָ�
	void adaptiveThresholdSegmentation(Mat&, Mat&, int,double);//ȫ������Ӧ��ֵ�ָ�
	void regionGrowing(Mat&, Mat&, int, int, int);//��������
	void SobelEdgeDetection(Mat&, Mat&);//Sobel��Ե���
	void CannyEdgeDetection(Mat&, Mat&,int,int);//Canny��Ե���
	void LaplacianEdgeDetection(Mat&, Mat&, int);//Laplace��Ե���
	void OTSUThresholdSegmentation(Mat&, Mat&);//OTSU
	void detectPoints(Mat&, Mat&);//����
	void lineDetection(Mat&, Mat&, int);//�߼��


	//ͼ���˲�����

	void meanFilter(Mat&, Mat&, int);//��ֵ�˲�
	void medianFilter(Mat&, Mat&, int);//��ֵ�˲�
	void gaussianFilter(Mat&, Mat&, int);//��˹�˲�
	void sobelShapen(Mat&, Mat&);//sobel�˲�

	//��������
	void rotateImage(Mat&, Mat&,double);//��ת����
	void flipImage(Mat&, Mat&,int);//��ת����
	void changeSize(Mat&, Mat&,double);//�Ŵ���С����
	
};

