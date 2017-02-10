#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "getface.h"

using namespace cv;
using namespace std;

void Trans::init_faces()
{
	faces = new vector<Rect>;
}

//给一张图片，寻找人脸并保存到桌面
void Trans::writeface(Mat m)
{
	Mat re(Size(92, 112), 0);
	//re保存人脸，如果存在人脸
	re = transimage(m);

	if (re.size() == Size(92, 112))
	{
		cout << "please input image name:" << endl;
		string name;
		cin >> name;
		imwrite("C:/Users/f_w_k/Desktop/pyy/" + name + ".jpg", re);
		cout << name << " success" << endl;
	}
	else
	{
		cout << "no face finded..."<<endl;
	}
}
//给一张图片，寻找并返回人脸或空Mat
Mat Trans::transimage(Mat& image)
{

	init_faces();
	Mat img = image;
	Mat result;
	CascadeClassifier faceCascade;
	faceCascade.load(face_cascade_name);

	if (img.empty())
	{
		cout << "??????" << endl;
	}
	Mat imgGray;
	if (img.channels() == 3)
	{
		cvtColor(img, imgGray, CV_RGB2GRAY);
	}
	else
	{
		imgGray = img;
	}

	equalizeHist(imgGray, imgGray);

	faceCascade.detectMultiScale(imgGray, *faces, 1.2, 2, 0, Size(0, 0));

	
	if ((*faces).size()>0)
	{
		for (int i = 0; i<(*faces).size(); i++)
		{
			//rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
			//Scalar(0, 255, 0), 1, 8);    //框出人脸位置
			Mat newimg(Size((*faces)[i].width, (*faces)[i].height),0);

			imgGray((*faces)[i]).copyTo(newimg);
			
			resize(newimg,result,Size(92,112));
			//equalizeHist(result,result);
			return result;
			//imwrite("C:\\Users\\f_w_k\\Desktop\\roi.jpg",result);
		}
	
	}
	
	return Mat(Size(0,0),0);
}

