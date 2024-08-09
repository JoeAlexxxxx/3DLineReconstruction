#ifndef SIMG__H
#define SIMG__H



#include <iostream>
#include <vector>
#include<string>
#include <opencv2/core.hpp>
#include "SfMManager.h"
#include "knncuda.h"
#include <thread>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

#include "lsd.hpp"
#include "BasicMath.h"
#include <fstream>
#include "Parameters.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "IO.h"

#include "ag3line_go.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>

#include"EDLineDetector.h"

void parallel_2lines(float* lines, int size, float costhre, float distmin, float distmax, cv::Mat& ppl_);

void callCrossPt(cv::Mat* lp_Mf, float* lines, int size, float costhre, float dist);

int processImage(SfMManager* sfm, int i,
	float costhre, float dist, int inter_support_num, int maxwidth, int uselsd,int maxlineNum, std::string lineFolder = "", std::string lineExt = "");

#endif // !SIMG__H