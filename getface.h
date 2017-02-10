#pragma once
#ifndef TRANS
#define TRANS

#include "stdafx.h"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

class Trans
{
public:
	Mat transimage(Mat&);
	void writeface(Mat);
	void init_faces();
private:
	string face_cascade_name = "D:/opencv/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml";
	vector<Rect> *faces;
};


#endif