#ifndef LIGHTDETECT_H_INCLUDED
#define LIGHTDETECT_H_INCLUDED

#include <stdio.h>
#include "opencv2/opencv.hpp"
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <vector>
#include <list>

using namespace cv;

class LightDetect{

	public:
		cv::Mat toHSV(cv::Mat InputMat);

		cv::Mat FilterColor(cv::Mat InputMat, int enemycolor);

		cv::Mat erode_dilate(cv::Mat InputMat);

		double angle(Point pt1, Point pt2, Point pt0);

		cv::Mat findRec(cv::Mat InputMat);

	private:

	protected:
		double x1[4];
		double y1[4];
};

#endif // LIGHTDETECT_H_INCLUDED
