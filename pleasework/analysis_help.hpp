#ifndef ANALYSIS_HELP_HPP_INCLUDED
#define ANALYSIS_HELP_HPP_INCLUDED

#include <stdio.h>
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include <math.h>


using namespace cv;

namespace james{
class analysis_help{

    cv::Point2f p1;
    cv::Point2f p2;
    cv::Point2f p3;
    cv::Point2f p4;
    float minx;
    float miny;



public:


    cv::Mat find_rec(Mat mat);
    cv::Mat identify_color(Mat mat);
    cv::Point2f find_target_center();
    cv::Point2f values_to_send(cv::Point2f);

};


}


#endif // ANALYSIS_HELP_HPP_INCLUDED
