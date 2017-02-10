#pragma once
#pragma once
#ifndef RECO
#define RECO

#include "stdafx.h"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

class Reco
{
public:
	void init_detector(string xmlpath);
	void init_detector();
	void updatelist(string filename, int flags);
	void read_csv(const string& filename, char separator);
	int predictor(Mat);
	vector<Mat> getimages() { return images; }
	vector<int> getlabels() { return labels; }
private:
	vector<Mat> images;
	vector<int> labels;
	Ptr<FaceRecognizer> model;
};


//读取csv/txt文件
void Reco::read_csv(const string& filename, char separator = ';')
{
	std::ifstream file(filename.c_str(), ifstream::in);
	if (!file) {
		string error_message = "No valid input file was given, please check the given filename.";
		CV_Error(CV_StsBadArg, error_message);
	}
	images.clear();
	labels.clear();
	string line, path, classlabel;
	while (getline(file, line)) {
		stringstream liness(line);
		getline(liness, path, separator);
		getline(liness, classlabel);
		if (!path.empty() && !classlabel.empty()) {
			images.push_back(imread(path, 0));
			labels.push_back(atoi(classlabel.c_str()));
		}
	}
}

void Reco::init_detector()
{
	read_csv("E:/list.txt");
	model = createLBPHFaceRecognizer();
	model->train(images,labels);
}

//通过保存的训练好的xml来初始化
void Reco::init_detector(string xmlpath)
{
	//model->train(images, labels);
	//默认的xml位置
	model = createLBPHFaceRecognizer();
	model->load("E:/ConsoleApplication1/ConsoleApplication1/detect.xml");
}

int Reco::predictor(Mat testSample)
{
	return model->predict(testSample);
}


//updata file list.txt if a new face need to be added
//flags mean new face(1) or old face(0)
void Reco::updatelist(string filename = "E:/list.txt",int flags = 1)
{

	ofstream file("filename", ofstream::app);
	int oldlab = labels[labels.size() - 1];
	int facecount = count(labels.begin(), labels.end(), oldlab);
	
	int newlab;
	string newline;
	if (flags)
	{
		newlab = oldlab + 1;
		newline = "E:/att_faces/s" + to_string(newlab+1) + "/1.jpg;"+to_string(oldlab);
	}
	else
	{
		newlab = oldlab;
		newline = "E:/att_faces/s" + to_string(newlab) + "/" + to_string(facecount+1) + ".jpg;" + to_string(oldlab);
	}
	file.close();
}

#endif