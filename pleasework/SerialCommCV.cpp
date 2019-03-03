#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <limits>
#include<vector>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.hpp"



using namespace std;
using namespace cv;
using namespace mn::CppLinuxSerial;


struct centerint{
	int x;
	int y;
};

centerint PointtoInt(cv::Point2f center) {
	float centerx = center.x;
	float centery = center.y;
	int centerxint = int (centerx+0.5);
	int centeryint = int (centery+0.5);
	centerint pointinint = { centerxint, centeryint };
	return pointinint;
}



/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "/dev/ttyS0";

//
//    string d_to_b(int mal){
//
//        	while (num > 0)
//	{
//		bin = mal % 2;
//		cout << bin;
//		bin_num = bin_num + to_string(bin);
//		num /= 2;
//	}
//
//    return
//    }
//	string bin_num = "";
//	cout << "Enter the number : ";
//	cin >> num;
//	cout << "The binary equivalent of " << num << " is ";
//
//	cout << "\n";
//	cout << bin_num;


void serialcomm(cv::Point2f point1) {
	// replace with corresponding port

    mn::CppLinuxSerial::SerialPort port(port_name,BaudRate::B_9600);
    port.Open();

//        point1.x = 300;
//        point1.y = 300;

        bool xs = point1.x>0 ? 0 : 1;
        bool ys = point1.y>0 ? 0 : 1;
        int16_t xpos = abs(point1.x);
		int16_t ypos = abs(point1.y);
        unsigned char x2 = (xpos & 63) + 64;
        unsigned char x1 = (xpos>>6) + xs*32;
        unsigned char y2 = (ypos & 63)+ 192;
        unsigned char y1 = (ypos>>6) + ys*32+128;


       // printf("x1 is = %u \n", x1);
       // printf("x2 is = %u \n", x2);
      //  printf("x1 is = %u \n", y1);
      //  printf("x2 is = %u \n", y2);

		port.Write(&x1);
		port.Write(&x2);
		port.Write(&y1);
		port.Write(&y2);
//		port.Write("456");
//		port.Write("789");
//		port.Write("78");

//	}
}


