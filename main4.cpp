#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
/*
RNG rng(0xFFFFFFFF);

const int w = 600;
const int NUMBER =100;
void MyFilledCircle(Mat img,RNG rng)
{
	for (int i = 0; i < NUMBER; i++)
	{
		circle(
			img,
			Point(rng.uniform(0, 600), rng.uniform(0, 600)),//坐标
			rng.uniform(0, 300),//半径
			Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),//颜色
			rng.uniform(0, 50),//线条粗细
			rng.uniform(0, 8)//linetype
		);
	}
}

int main()
{
	Mat image = Mat::zeros(w, w, CV_8UC3);
	char* window = "Randow Window";
	namedWindow(window, 1);
	MyFilledCircle(image, rng);
	imshow(window, image);
	MyFilledCircle(image, rng);
	waitKey();

}

*/