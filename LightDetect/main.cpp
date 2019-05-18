#include <iostream>
#include <stdio.h>
#include "LightDetect.h"
#include <vector>

using namespace std;
using namespace cv;


int main()
{
	Mat src;
	Mat inHSV;
	Mat input;
	Mat resultFilter, After_dilate, withrect;
	cv::VideoCapture cap("red-back-ev--3.MOV");
	cap.set(CV_CAP_PROP_POS_FRAMES, 200);
	// auto i = cap.get(CV_CAP_PROP_EXPOSURE);
	// std::cout << "Exposure \n" << i << std::endl;
	// int exposure = -7;
	// cap.set(CV_CAP_PROP_EXPOSURE, exposure);
	// std::cout << "new Exposure " << cap.get(CV_CAP_PROP_EXPOSURE) << std::endl;
	//james: light detect class added
	LightDetect sth;
	for (;;) {
		Mat frame;

		//double fps = cap.get(CV_CAP_PROP_FPS);
		// If you do not care about backward compatibility
		// You can use the following instead for OpenCV 3
		// double fps = video.get(CAP_PROP_FPS);
		//cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;
		cap >> frame;
		cv::imshow("Original feed", frame);
		inHSV = sth.toHSV(frame);
    	resultFilter = sth.FilterColor(inHSV, 0);
		After_dilate = sth.erode_dilate(resultFilter);
		withrect = sth.findRec(After_dilate);
		cv::imshow("Filter Prototype I", withrect);
		Point2f center=sth.returncenter();
		char c = cvWaitKey(50);
		if (c == 27)
			break;
	}
	return 0;
}
