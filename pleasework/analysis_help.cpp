
#include "analysis_help.hpp"
using namespace cv;


cv::Point2f james::analysis_help::values_to_send(cv::Point2f ip){


    cv::Point2f o_point;
    o_point.x = ip.x - 320.0;


    o_point.y = ip.y - 240.0;

    return o_point;


}



cv::Point2f james::analysis_help::find_target_center(){


   // printf("min point %f  %f \n", james::analysis_help::p1.x, james::analysis_help::p1.y);
     //printf("max point %f  %f \n", james::analysis_help::p4.x, james::analysis_help::p4.y);

//algorithm: sums up all the x/y coordinates and compute the average then it is the center coordination
cv::Point2f o_point;

float sumx = 0;
float sumy = 0;
james::analysis_help::minx = 640;
james::analysis_help::miny = 480;
for(int i = 0;i < 4; i++){
    if(i == 0){


        if(p1.x < james::analysis_help::minx){
            james::analysis_help::minx = p1.x;
        }

        if(p1.y < james::analysis_help::miny){
            james::analysis_help::minx = p1.x;
        }

        sumx += p1.x;
        sumy += p1.y;

    }else if(i == 1){


        if(p2.x < james::analysis_help::minx){
            james::analysis_help::minx = p2.x;
        }

        if(p2.y < james::analysis_help::miny){
            james::analysis_help::minx = p2.x;
        }


            sumx += p2.x;
            sumy += p2.y;

    }else if(i == 2){



        if(p3.x < james::analysis_help::minx){
            james::analysis_help::minx = p3.x;
        }

        if(p3.y < james::analysis_help::miny){
            james::analysis_help::minx = p3.x;
        }

        sumx += p3.x;
        sumy += p3.y;
    }else{


        if(p4.x < james::analysis_help::minx){
            james::analysis_help::minx = p4.x;
        }

        if(p4.y < james::analysis_help::miny){
            james::analysis_help::minx = p4.x;
        }

        sumx += p4.x;
        sumy += p4.y;
    }

}

    o_point.x = sumx/4.0;
    o_point.y = sumy/4.0;



    return o_point;
}


cv::Mat james::analysis_help::find_rec(Mat mat){

    Mat ouput = mat;

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierachy;

    cv::findContours(ouput,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);

    int biggestid = -1;
    float biggestconarea = 0;

    Mat drawing = cv::Mat::zeros(ouput.size(), CV_8UC3);


    //draw the biggest shape on the diagram
    for( int i = 0; i < contours.size();i++){

    cv::Scalar color = cv::Scalar(0,100,0);
    drawContours( drawing,contours,i,color,1,8,hierachy,0,cv::Point());

    float ctArea = cv::contourArea(contours[i]);
    if(ctArea > biggestconarea){
        biggestconarea = ctArea;
        biggestid = i;

    }

    }


    if(biggestid < 0){
    std::cout << "nothing is found " << std::endl;
    return mat;

    }

    cv::RotatedRect boundingbox = cv::minAreaRect(contours[biggestid]);

    cv::Point2f corners[4];
    boundingbox.points(corners);


//setting the point to be stored in class
    james::analysis_help::p1 = corners[0];
    james::analysis_help::p2 = corners[1];
    james::analysis_help::p3 = corners[2];
    james::analysis_help::p4 = corners[3];

//outputing lines from points
    cv::line(drawing, corners[0],corners[1],cv::Scalar(255,255,255));
    cv::line(drawing, corners[1],corners[2],cv::Scalar(255,255,255));
    cv::line(drawing, corners[2],corners[3],cv::Scalar(255,255,255));
    cv::line(drawing, corners[3],corners[0],cv::Scalar(255,255,255));



    return drawing;



}





cv::Mat james::analysis_help::identify_color(Mat mat){

    Mat ouput;

    //threshold(mat,ouput,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);

    cv::cvtColor(mat,ouput,COLOR_BGR2HSV);

    cv::inRange(ouput,Scalar(0,0,0,0),Scalar(188,255,30,0), ouput);

    return ouput;



}
