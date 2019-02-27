
#include "videoutil.hpp"


using namespace cv;

int videoutil::videocap()
{



    cv::VideoCapture cap(0);
    if(!cap.isOpened())
        return -1;

    cv::Mat edges;
    cv::namedWindow("edges",1);
    cv::Point2f ptm;
    cv::Point2f pts;

    james::analysis_help ah;

    for(;;){

    cv::Mat frame;
    cap >> frame;
   //cv::cvtColor(frame,edges, COLOR_BGR2GRAY);

    edges = ah.identify_color(frame);
    edges = ah.find_rec(edges);
    ptm = ah.find_target_center();
    pts = ah.values_to_send(ptm);


    printf("center point %f %f \n", pts.x, pts.y);


   //cv::GaussianBlur(edges,edges,Size(7,7),1.5,1.5);
   //cv::Canny(edges,edges,0,30,3);
    cv::imshow("edges", edges);
    cv::imshow("orgin", frame);
    if(waitKey(30) >= 0) break;


    }

    return 0;
}

