 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace cv;
using namespace std;
 
class disparity 
{
	private:
	StereoSGBM stereo;   // stereo matching object for disparity computation
	int min_disp, num_disp;  // parameters of StereoSGBM

        public:

	disparity(Size, int numDisp);     // Constructor

	void show_disparity(Size,char *name1,char *name2);

};

