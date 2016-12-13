// Program illustrate distance measurement using a stereo camera
 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include "malaga_test.hpp"

using namespace cv;
using namespace std;
 
//----------------------------------------------------------------------------------------------------------------------

disparity::disparity(Size image_size,int numDisp) // Constructor
{

        // Set SGBM parameters (from OpenCV stereo_match.cpp demo)

	stereo.preFilterCap = 63;
	stereo.SADWindowSize = 3;
	stereo.P1 = 8 * 3 * stereo.SADWindowSize * stereo.SADWindowSize;
	stereo.P2 = 32 * 3 * stereo.SADWindowSize * stereo.SADWindowSize;
	stereo.uniquenessRatio = 10;
	stereo.speckleWindowSize = 100;
	stereo.speckleRange = 32;
	stereo.disp12MaxDiff = 1;
	stereo.fullDP = true;
        stereo.numberOfDisparities = numDisp; 
        stereo.minDisparity = 0; 
}

//--------------------SHOW DISPARITY----------------------------------------------------------------------------------------------------

void disparity::show_disparity(Size image_size,char *name1,char *name2) // Function
{

        // Declaration of the Images
        Mat framel, framer;  
        Mat disp, disp_show;
        char ch;

        // Reading the Images
        framel = imread(name1,CV_LOAD_IMAGE_COLOR); 
        framer = imread(name2, CV_LOAD_IMAGE_COLOR);

        // Checking if the Images were found
        if(framel.empty() || framer.empty()) 	
         {
             cout << "\nInput Images not found\n" << endl;
             exit(0);                 
         } 

 	// Calculate disparity
   	stereo(framel, framer, disp);

	// Convert disparity to a form easy for visualization
	disp.convertTo(disp_show, CV_8U, 255/(stereo.numberOfDisparities * 16.));

        // Resizing the Images to the Same Size

        resize(framel,framel,image_size);//resize left image
        resize(framer,framer,image_size);//resize right image
        resize(disp_show,disp_show,image_size);//resize disp_show image

       // Writing Text into the Image

        putText(disp_show,"Disparity_Map",cvPoint(100,100),1,1,cvScalar(255),2,8,false );	 
        putText(framel,"Left_Camera",cvPoint(100,100),1,1,cvScalar(255,0,0),2,8,false );
        putText(framer,"Right_Camera",cvPoint(100,100),1,1,cvScalar(255,0,0),2,8,false );

      // Showing Disparity Image

        namedWindow( "Disparity", WINDOW_AUTOSIZE);  
        imshow("Disparity", disp_show);

     // Showing Left Image

        namedWindow( "Left", WINDOW_AUTOSIZE);
        imshow("Left", framel);   

     // Showing Right Image

        namedWindow( "Right", WINDOW_AUTOSIZE); 
        imshow("Right", framer);


        int key=cvWaitKey(1);

        if(key==27)                // ESC button
        exit(0);

        else if(key==32)           // Space button
         {
           scanf("%c",&ch);
           key=0;
         }

        return;
}

