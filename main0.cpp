// study_opencv.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/nonfree/features2d.hpp>

using namespace std;
using namespace cv;



/** @function readme */

/*
int main(int argc,char *argv[])
{
if (argc != 2)
{
printf("useage: %s <imagefile>\n ", argv[0]);
return -2;
}
char* imageName = argv[1];

Mat image;
image = imread(imageName, CV_LOAD_IMAGE_COLOR);

if (!image.data)
{
printf(" No image data \n ");
return -3;
}

Mat gray_image;
cvtColor(image, gray_image, CV_BGR2GRAY);


//imwrite("./Gray_Image.jpg", gray_image);

namedWindow(imageName, CV_WINDOW_AUTOSIZE);
namedWindow("Gray image", CV_WINDOW_AUTOSIZE);

imshow(imageName, image);
imshow("Gray image", gray_image);

waitKey(3000);

return 0;

}

*/
//遍历像素值
/*
int main()
{
	Mat I(2, 3, CV_8UC3, Scalar(1, 2, 3));
	int channels = I.channels();
	cout << I.rows << "  " <<endl;
	int nRows = I.rows ;
	int nCols = I.cols* channels;

	if (I.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i)
	{
		p = I.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			cout << p[j]<<endl;
		}
	}
	
	for (int y = 0; y < I.rows; y++)
	{
		for (int x = 0; x < I.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				cout <<I.at<Vec3b>(y, x)[c];
			}
		}
		cout << endl;
	}
	waitKey(0);
}


*/