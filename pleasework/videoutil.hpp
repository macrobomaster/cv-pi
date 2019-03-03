#ifndef VIDEOUTIL_HPP_INCLUDED
#define VIDEOUTIL_HPP_INCLUDED



#include "analysis_help.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include <stdio.h>
using namespace cv;

class videoutil : public james::analysis_help{

public:
    int videocap();


};




#endif // VIDEOUTIL_HPP_INCLUDED
