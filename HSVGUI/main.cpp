// Arthor: Chengxin Liu Haowen Zhang
// This is the HSVGUI Development tool for McMaster Robomaster Team to determine the HSV value of the pixel at cursor position


#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <unistd.h>
#include <thread>
using namespace std;
using namespace cv;
int ix;
int iy;
Mat src;


void call_back(int event,int x,int y,int flag, void* param){  //SetMouseCallBack Function
    if(event==EVENT_MOUSEMOVE){                               //Stores mouse position in globals on movement
    ix = x;
    iy = y;
    }
}


void cam_up()
{
       Mat frame; //create frame of images

       VideoCapture capture("red-front-ev--3.MOV"); //constructor for capture
       namedWindow("HSV GUI", WINDOW_AUTOSIZE); //display window
       for (;;)
    {
        setMouseCallback("HSV GUI",call_back); //mouse position update
        // wait for a new frame from camera and store it into 'frame'
        capture.read(frame); //read captured frame
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // int exposure=-7;
        capture.set(CV_CAP_PROP_POS_FRAMES, 290);
        capture>>src;
        Mat image=src.clone();
        Mat HSV;
        Mat RGB=frame(Rect(ix,iy,1,1));
        cvtColor(RGB, HSV,CV_BGR2HSV);

        Vec3b hsv=HSV.at<Vec3b>(0,0);
        int H=hsv.val[0];
        int S=hsv.val[1];
        int V=hsv.val[2];

        char name[30];
        sprintf(name,"H=%d",H);
        putText(frame,name, Point(25,40) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );

        sprintf(name,"S=%d",S);
        putText(frame,name, Point(25,80) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );

        sprintf(name,"V=%d",V);
        putText(frame,name, Point(25,120) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );

        sprintf(name,"X=%d",ix);
        putText(frame,name, Point(25,300) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,0,255), 2,8,false );

        sprintf(name,"Y=%d",iy);
        putText(frame,name, Point(25,340) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,0,255), 2,8,false );

        // show live and wait for a key with timeout long enough to show images
        imshow("HSV GUI", frame); //display modified frame
        if (waitKey(5) >= 0)
            break;
    }

}
int main()
{
    /*
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
        std::cout<<"check camera";
    */
    //Mat frame;
    //namedWindow("HSV GUI", WINDOW_AUTOSIZE);
    //thread t(mouse_up);
    cam_up();
    //t.join();
    //mouse_up();
 /*
    for (;;) {
        // cap>>src;
        setMouseCallback( "HSV GUI", HSVGUI);

        char c = cvWaitKey(50);
        if (c == 27)
            break;
	}
    */

	return 0;
}
