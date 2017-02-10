
#include "stdafx.h"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "getface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "recoface.h"

using namespace cv;
using namespace std;




int main(int argc, const char*argv[]) {
	/*
	if (argc != 2) {
		cout << "usage: " << argv[0] << " <csv.ext>" << endl;
		exit(1);
	}
	string fn_csv = string(argv[1]);
	*/
	Reco recognizer;
	try {
		recognizer.init_detector();
	}
	catch (cv::Exception& e) {
		cerr << "Error opening file \"" << "\". Reason: " << e.msg << endl;
		// nothing more we can do
		exit(1);
	}

	vector<Mat> images = recognizer.getimages();
	vector<int> labels = recognizer.getlabels();

	if (images.size() <= 1) {
		string error_message = "This demo needs at least 2 images to work. Please add more images to your data set!";
		CV_Error(CV_StsError, error_message);
	}
	//int height = images[0].rows;
	//cout << images[2].rows << " " << images[3].cols;
	//Mat testSample = images[images.size() - 1];
	//Mat testSample = imread("C:/Users/f_w_k/Desktop/11.jpg",0);
	Mat Sample = imread("C:/Users/f_w_k/Desktop/pyy/te2.jpg", 0);
	
	Trans t;
	Mat testSample;
	testSample = t.transimage(Sample);
	int testLabel = labels[labels.size() - 1];
	//images.pop_back();
	//labels.pop_back();
	// TLBPHFaceRecognizer ʹ������չ��LBP
	// �������������������ܺ����ױ���չ
	// ������Ĭ�ϲ���
	//      radius = 1
	//      neighbors = 8
	//      grid_x = 8
	//      grid_y = 8
	//
	// �����Ҫ���� LBPH FaceRecognizer �뾶��2��16������
	//      cv::createLBPHFaceRecognizer(2, 16);
	//
	// �������Ҫһ����ֵ������ʹ��Ĭ�ϲ���:
	//      cv::createLBPHFaceRecognizer(1,8,8,8,123.0)
	//

	int predictedLabel = 0;
	if (testSample.size() == Size(92, 112))
	{
		predictedLabel = recognizer.predictor(testSample);
	}
	else
	{
		cout << "no result" << endl;
		return 0;
	}
	
	//      int predictedLabel = -1;
	//      double confidence = 0.0;
	//      model->predict(testSample, predictedLabel, confidence);
	//
	//string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);
	cout << "Predicted class = "<< predictedLabel <<" Actual class = "<<testLabel << endl;

	if (predictedLabel != testLabel)
	{
		labels.push_back(testLabel);
		images.push_back(testSample);
		//model->update(images,labels);
		//model->save("E:/ConsoleApplication1/ConsoleApplication1/detect.xml");
	}
	
	if (predictedLabel != -1)
	{
		namedWindow("face",CV_WINDOW_AUTOSIZE);
		imshow("face",testSample);
		imwrite("C:\\Users\\f_w_k\\Desktop\\roi.jpg", testSample);
		
		waitKey();
	}
	// ��ʱ����Ҫ���û��߻�ȡ�ڲ�����ģ��,
	// �����ܱ���¶�� cv::FaceRecognizer����.
	//
	// �������Ƕ�FaceRecognizer����ֵ���õ�0.0����������дѵ��ģ��
	// �������¹���ģ��ʱ����Ҫ 
	//
	
	//model->set("threshold", 100.0);
	//predictedLabel = model->predict(testSample);
	//cout << "Predicted class = " << predictedLabel << endl;
	// ����ȷ����Ч�ʣ�LBPͼû�б��洢��ģ�����档D
	//cout << "Model Information:" << endl;
	
	//string model_info = format("\tLBPH(radius=%i, neighbors=%i, grid_x=%i, grid_y=%i, threshold=%.2f)",
		//model->getInt("radius"),
		//model->getInt("neighbors"),
		//model->getInt("grid_x"),
		//model->getInt("grid_y"),
		//model->getDouble("threshold"));
		
	
	// ���ǿ��Ի�ȡ������ֱ��ͼ:
	//vector<Mat> histograms = model->getMatVector("histograms");
	// ����Ҫ��ʵ����? �������ĳ��Ȳ������Ǹ���Ȥ��:
	//cout << "Size of the histograms: " << histograms[0].total() << endl;
	
	return 0;
}


/*
int main(int argc,char** argv)
{
	int i = 1;
	for (; i < 8; i++)
	{
		Mat m = imread("C:/Users/f_w_k/Desktop/pyy/"+to_string(i*11)+".jpg", 0);
		Trans t;
		Mat re(Size(92, 112), 0);
		re = t.transimage(m);

		if (re.size() == Size(92, 112))
		{
			imwrite("C:/Users/f_w_k/Desktop/pyy/"+to_string(i)+".jpg", re);
			cout <<i<< " success" << endl;
		}
	}
	
	return 0;
}

*/