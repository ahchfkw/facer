#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

void detectAndDisplay(Mat frame);

/** 全局变量 */
string face_cascade_name = "D:/opencv/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml";
string eyes_cascade_name = "D:/opencv/opencv/sources/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";

/** @主函数 */

/*
int main(int argc, const char** argv)
{
	VideoCapture cap;
	cap.open(0);
	Mat frame;

	//-- 1. 加载级联分类器文件
	

	//-- 2. 打开内置摄像头视频流
	//capture = cvCaptureFromCAM(-1);
	if (!cap.isOpened())
	{
		return 1;
	}
	while (true)
	{
		cap >> frame;

		//-- 3. 对当前帧使用分类器进行检测
		if (!frame.empty())
		{
			detectAndDisplay(frame);
			
		}
		else
		{
			printf(" --(!) No captured frame -- Break!"); break;
		}

		int c = waitKey(1);
		if ((char)c == 'c') { break; }
	}

	return 0;
}

*/

/*
CascadeClassifier faceCascade;
CascadeClassifier eyes_cascade;
int main()
{
	faceCascade.load(face_cascade_name);   //加载分类器，注意文件路径
	eyes_cascade.load(eyes_cascade_name);
	VideoCapture cap;
	cap.open(0);   //打开摄像头
				   //cap.open("../data/test.avi");   //打开视频
	Mat img, imgGray;
	vector<Rect> faces;
	int c = 0;

	if (!cap.isOpened())
	{
		return 1;
	}

	while (c != 27)
	{
		cap >> img;
		if (img.empty())
		{
			cout << "??????" << endl;
			break;
		}
		if (img.channels() == 3)
		{
			cvtColor(img, imgGray, CV_RGB2GRAY);
		}
		else
		{
			imgGray = img;
		}

		faceCascade.detectMultiScale(imgGray, faces, 1.2, 6, 0, Size(0, 0));   //检测人脸
		
		if (faces.size()>0)
		{
			for (int i = 0; i<faces.size(); i++)
			{
				rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
				Scalar(0, 255, 0), 1, 8);    //框出人脸位置
				Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
				ellipse(img, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
			}	
		}
		
		imshow("Camera", img);
		c = waitKey(10);
	}
	return 0;
}
*/



/** @函数 detectAndDisplay */
/*
void detectAndDisplay(Mat frame)
{
	
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading\n"); return ; };
	if (!eyes_cascade.load(eyes_cascade_name)) { printf("--(!)Error loading\n"); return ; };
	string window_name = "Capture - Face detection";
	vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_RGB2GRAY);
	//equalizeHist(frame_gray, frame_gray);

	//-- 多尺寸检测人脸
	//face_cascade.detectMultiScale(frame_gray, faces);
	face_cascade.detectMultiScale(frame_gray, faces, 1.2, 6, 0, Size(0, 0));
	for (int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;

		//-- 在每张人脸上检测双眼
		eyes_cascade.detectMultiScale(faceROI, eyes);

		for (int j = 0; j < eyes.size(); j++)
		{
			Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
			int radius = cvRound((eyes[j].width + eyes[i].height)*0.25);
			circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
		}
	}
	
	//-- 显示结果图像
	imshow(window_name, frame);
}
*/