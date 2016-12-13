// MAIN FUNCTION

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

#include "malaga_test.hpp"
#define WIDTH 320
#define HEIGHT 400


using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
        FILE *fp_left,*fp_right;
        char left_image[300]; // Left Image names
        char right_image[300]; // Right Image names
        char nameL[500];                 // Direct path from build folder to our Left Images in Malaga_Urban_Dataset folder.
        char nameR[500];                 // Direct path from build folder to our Right Images in Malaga_Urban_Dataset folder.

        fp_left=fopen("../list_left_camera.txt","r");
        fp_right=fopen("../list_right_camera.txt","r");

        if(fp_left==NULL || fp_right==NULL)
          { 
                  cout << "\nFile not found" << endl;
                  return 0;  
          }

        Size image_size(HEIGHT,WIDTH);                      // This depends on the Dataset                      
        disparity dispObj(image_size,atoi(argv[1]));   // argv[0] : ./malaga_test , argv[1] : number disparity level

        while(fscanf(fp_left,"%s",left_image)==1 && fscanf(fp_right,"%s",right_image)==1)
         {
                sprintf(nameL,"../Malaga_Urban_Dataset/Left_Image/%s",left_image);
                sprintf(nameR,"../Malaga_Urban_Dataset/Right_Image/%s",right_image);

        	dispObj.show_disparity(image_size,nameL,nameR);
	        
         }
  
         fclose(fp_left);
         fclose(fp_right);
         return 0;
} 
