#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
/*ÂË²¨Æ÷ÑÚÂë
int main(int argc,char **argv)
{
	Mat kern = (Mat_<char>(3, 3) << 0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
	char* imageName = argv[1];

	Mat image;
	image = imread(imageName, CV_LOAD_IMAGE_COLOR);
	Mat R;
	R.create(image.size(), image.type());
	filter2D(image, R, image.depth(), kern);
	//show
	namedWindow(imageName, CV_WINDOW_AUTOSIZE);
	namedWindow("New image", CV_WINDOW_AUTOSIZE);

	imshow(imageName, image);
	imshow("New image", R);

	waitKey();

	return 0;
}

*/