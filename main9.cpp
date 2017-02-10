#include "stdafx.h"
#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion

#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace std;
using namespace cv;


/*
int main()
{
	const string path = "";
	VideoCapture video(0);
	namedWindow("test",CV_WINDOW_AUTOSIZE);
	Mat frame;
	while (1)
	{
		video >> frame;
		
		imshow("test", frame);
	    char c = waitKey(40);
		if (c == 27)
			break;
	}

}

*/