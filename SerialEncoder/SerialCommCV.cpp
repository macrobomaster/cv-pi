#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <limits>
#include<vector>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"

using namespace std;
using namespace cv;

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

//String for getting the output from arduino
char output[MAX_DATA_LENGTH];

/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "\\\\.\\COM20";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

void serialcomm(cv::Point2f point1) {
	// replace with corresponding port
	SerialPort port(port_name);
	// if (port.isConnected()) cout << "Connection Established" << endl;
	// else cout << "ERROR, check port name";
	while (port.isConnected()) {
		//get the disired point
		centerint centerpoint = PointtoInt(point1);
		int xpos = centerpoint.x;
		int ypos = centerpoint.y; 
		char xbinary[9];
		char xbinary1[4];
		char xbinary2[5];
		for (size_t i = 0; i < 4; i++)
		{
			xbinary1[i] = xbinary[i];
		}
		for (size_t i = 0; i < 5; i++)
		{
			xbinary2[i] = xbinary[i+4];
		}
		char ybinary[9];
		char ybinary1[4];
		char ybinary2[5];
		for (size_t i = 0; i < 4; i++)
		{
			ybinary1[i] = ybinary[i];
		}
		for (size_t i = 0; i < 5; i++)
		{
			ybinary2[i] = ybinary[i + 4];
		}
		itoa(xpos, xbinary, 2);
		itoa(ypos, ybinary, 2);
		//constrcuting comm serial 
		char commx1[8]; char commx2[8]; char commy1[8]; char commy2[8];
		commx1[0] = 0; commx1[1] = 0; commx2[0] = 0; commx2[1] = 1; commy1[0] = 1; commy1[1] = 0; commy2[0] = 1; commy2[1] = 1;
		if (xpos < 0) {
			commx1[2] = 1;
		}
		else {
			commx1[2] = 0;
		}
		if (ypos < 0) {
			commy1[2] = 1;
		}
		else {
			commy1[2] = 0;
		}
		for (size_t i = 0; i < 3; i++)
		{
			commx1[i+3] = xbinary1[i];
			commx2[i] = xbinary[i + 2];
			commy1[i+3] = ybinary1[i];
			commy2[i] = ybinary[i + 2];
		} 
		for (size_t i = 0; i < 4; i++)
		{
			commx2[i] = xbinary2[i];
			commy2[i] = ybinary2[i];
		}
		//Creating a c string
		//Writing string to arduino
		cout << commx1 << endl;
		cout << commx2 << endl;
		cout << commy1 << endl;
		cout << commy2 << endl;
		port.writeSerialPort(commx1, MAX_DATA_LENGTH);
		port.writeSerialPort(commx2, MAX_DATA_LENGTH);
		port.writeSerialPort(commy1, MAX_DATA_LENGTH);
		port.writeSerialPort(commy2, MAX_DATA_LENGTH);
	}
}

int main{
	
}
