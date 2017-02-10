#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
/*对比度亮度

int main(int argc,char *argv[])
{
	Mat image = imread(argv[1]);
	Mat NewImage = Mat::zeros(image.size(),image.type());
	double a, b;
	cout << "对比度";
	cin >> a;
	cout << "亮度";
	cin >> b;
	image.convertTo(NewImage, -1, a, b);
	//namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
	//namedWindow("Newimage", CV_WINDOW_AUTOSIZE);
	imshow(argv[1], image);
	imshow("Newimage", NewImage);
	waitKey();
}
*/
