
#include <iostream>
#include <stdio.h>
#include "x64/LightDetect.h"
#include <vector>

using namespace std;
using namespace cv;


int main()
{
	Mat src;
	Mat inHSV;
	Mat input;
	Mat resultFilter, After_dilate, withrect;
	cv::VideoCapture cap(0);
	auto i = cap.get(CV_CAP_PROP_EXPOSURE);
	std::cout << "Exposure \n" << i << std::endl;
	int exposure = -7;
	cap.set(CV_CAP_PROP_EXPOSURE, exposure);
	std::cout << "new Exposure " << cap.get(CV_CAP_PROP_EXPOSURE) << std::endl;
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
		char c = cvWaitKey(50);
		if (c == 27)
			break;
	}
	return 0;
}

// Arthor: Chengxin Liu Haowen Zhang
// This is the HSVGUI Development tool for McMaster Robomaster Team to determine the HSV value of the pixel at cursor position
//
//
//#include <iostream>
//#include <stdio.h>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
////#include <unistd.h>
//#include <thread>
//using namespace std;
//using namespace cv;
//int ix;
//int iy;
//Mat src;
//
//
//void call_back(int event, int x, int y, int flag, void* param) {  //SetMouseCallBack Function
//	if (event == EVENT_MOUSEMOVE) {                               //Stores mouse position in globals on movement
//		ix = x;
//		iy = y;
//	}
//}
//
//
//void cam_up()
//{
//	Mat frame; //create frame of images
//
//	VideoCapture capture(0); //constructor for capture
//	namedWindow("HSV GUI", WINDOW_AUTOSIZE); //display window
//	for (;;)
//	{
//		setMouseCallback("HSV GUI", call_back); //mouse position update
//		// wait for a new frame from camera and store it into 'frame'
//		capture.read(frame); //read captured frame
//		// check if we succeeded
//		if (frame.empty()) {
//			cerr << "ERROR! blank frame grabbed\n";
//			break;
//		}
//		int exposure = -7;
//		capture.set(CV_CAP_PROP_EXPOSURE, exposure);
//		capture >> src;
//		Mat image = src.clone();
//		Mat HSV;
//		Mat RGB = frame(Rect(ix, iy, 1, 1));
//		cvtColor(RGB, HSV, CV_BGR2HSV);
//
//		Vec3b hsv = HSV.at<Vec3b>(0, 0);
//		int H = hsv.val[0];
//		int S = hsv.val[1];
//		int V = hsv.val[2];
//
//		char name[30];
//		sprintf_s(name, "H=%d", H);
//		putText(frame, name, Point(25, 40), FONT_HERSHEY_SIMPLEX, .7, Scalar(0, 255, 0), 2, 8, false);
//
//		sprintf_s(name, "S=%d", S);
//		putText(frame, name, Point(25, 80), FONT_HERSHEY_SIMPLEX, .7, Scalar(0, 255, 0), 2, 8, false);
//
//		sprintf_s(name, "V=%d", V);
//		putText(frame, name, Point(25, 120), FONT_HERSHEY_SIMPLEX, .7, Scalar(0, 255, 0), 2, 8, false);
//
//		sprintf_s(name, "X=%d", ix);
//		putText(frame, name, Point(25, 300), FONT_HERSHEY_SIMPLEX, .7, Scalar(0, 0, 255), 2, 8, false);
//
//		sprintf_s(name, "Y=%d", iy);
//		putText(frame, name, Point(25, 340), FONT_HERSHEY_SIMPLEX, .7, Scalar(0, 0, 255), 2, 8, false);
//
//		// show live and wait for a key with timeout long enough to show images
//		imshow("HSV GUI", frame); //display modified frame
//		if (waitKey(5) >= 0)
//			break;
//	}
//
//}
//int main()
//{
//	/*
//	cv::VideoCapture cap(0);
//	if(!cap.isOpened())
//		std::cout<<"check camera";
//	*/
//	//Mat frame;
//	//namedWindow("HSV GUI", WINDOW_AUTOSIZE);
//	//thread t(mouse_up);
//	cam_up();
//	//t.join();
//	//mouse_up();
// /*
//	for (;;) {
//		// cap>>src;
//		setMouseCallback( "HSV GUI", HSVGUI);
//		char c = cvWaitKey(50);
//		if (c == 27)
//			break;
//	}
//	*/
//
//	return 0;
//}