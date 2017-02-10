#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

/*
//»­Ô­×Ó
const int w = 300;
void MyEllipse(Mat img, double angle)
{
	int thickness = 1;
	int lineType = 1;
	ellipse(
		img,
		Point(w / 2.0, w / 2.0),
		Size(w / 4.0, w / 16.0),
		angle,
		0,
		360,
		Scalar(210, 0, 0),
		thickness,
		lineType
	);
}

void MyFilledCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;
	circle(
		img,
		center,
		w / 32.0,
		Scalar(0, 0, 100),
		thickness,
		lineType
	);
}
int main(int argc,char** argv)
{
	char* atom = "Atom Window";
	Mat atomImage = imread(argv[1]);
	//Mat atomImage = Mat::zeros(w,w,CV_8UC3);
	MyEllipse(atomImage, 90);
	MyEllipse(atomImage, 0);
	MyEllipse(atomImage, 45);
	MyEllipse(atomImage, -45);
	MyFilledCircle(atomImage, Point(w / 2.0, w / 2.0));
	imshow(atom,atomImage);
	waitKey();
}
*/