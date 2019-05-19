#ifndef LIGHTDETECT_H_INCLUDED
#define LIGHTDETECT_H_INCLUDED

#include <stdio.h>
#include "opencv2/opencv.hpp"
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <vector>
#include <list>

//james: define your max rec here
#define MAX_REC 1

using namespace cv;

class LightDetect{

	public:
	    cv::Point2f center;
		cv::Mat toHSV(cv::Mat InputMat);

		cv::Mat FilterColor(cv::Mat InputMat, int enemycolor);

		cv::Mat erode_dilate(cv::Mat InputMat);

		double angle(Point pt1, Point pt2, Point pt0);

		cv::Mat findRec(cv::Mat InputMat);
		cv::Point2f returncenter();
	private:


	protected:

		std::vector<Point> my_rect[MAX_REC];
		int num_Rects=0;
		void rect_setter(std::vector<Point> rect, int index = 0);
		std::vector<Point> rect_getter(int index = 0);

};

#endif // LIGHTDETECT_H_INCLUDED
