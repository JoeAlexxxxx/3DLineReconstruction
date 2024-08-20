/** Label for pixels with undefined gradient. */
#ifndef GENFUN
#define GENFUN


#include<math.h>
#include<iostream>
#include <io.h>
#include <string>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
//#include"BaseLine.h"
#include"fastatan2.h"
#include<math.h>
#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#define NOTDEF -1024.0
#define PI_8 0.3927
#define PI_16 0.1963495408
#define PI_32 0.0981747704246
#define M_PI   3.1415926535
#define PI_2 1.570796
#define M_2__PI  6.28318530718
/** 3/2 pi */
#define M_3_2_PI 4.71238898038
#define NOTUSED 0
#define USED 1
#define GRADE_2 27.0400
#define SQRT_MAGIC_F 0x5f3759df

double angle_diff(double a, double b);
int round_my(float number);
float mean(float* value, int ed);
void sdeviation(float* value, int ed, float* std, float* m);
void getAllFiles(std::string path, std::vector<std::string>& files, std::string fileType);
void getPixels4Dir(float theta, float* xxs, float* yys);
int direction(double regang);
void Bresenham(int x1,
	int y1,
	int const x2,
	int const y2, cv::Point3i* linereg, int* size);

bool goVertical(float regang);
void EnumerateRectPoints1(double sx, double sy, double ex, double ey, cv::Point3i* linereg, int* pNoPoints, double width, int xsize);

class BaseLine {
	float c1, c2, c3, c4, t;
	cv::Mat pt, v1, v2;//for line_point distance calculation
	/*
	[c1 c2
	 c3 c4]
	*/
	float a, a_1, x1_mx, y1_my, x1_mx_y1_my, len;
	float l_min, l_max, w_min, w_max, l, w;
	float sumdx, sumdy, lambda;//line parameters
	double get_theta(cv::Point3i* reg, int ed1, int ed2, int ed3, int ed4, double x, double y,
		double reg_angle, double prec);


public:
	int counter, xsize, ysize, minlength;
	float xxs[3];
	float yys[3];
	float pdense[3];
	float mx, my, dx, dy, segang, theta, sx, sy, x1, y1, x2, y2, length, midcounter, sxx, syy, ui, uj, uk, sqrtab;
	BaseLine(int m, int n, int minl, float p1, float p2, float p3);
	~BaseLine(void);
	//initial the line parameter

	void initial(int cx, int cy, float pang);
	void updateAnglePrams(float angle);
	void updateLinePrams(int x1, int y1);
	void getLine(cv::Point3i* reg);
	float pt_line_dis(float xx, float yy);
	void getlength();
	void region2line(cv::Point3i* reg, int ed1, int ed2, int ed3, int ed4,
		double prec);
	void newValidationPixel(int i);

	bool lengthSatisfy();

	float getAnchorThreshold();
	void newValidationPixel2(int i);
	float withinLength(float x, float y);
	float distance_global(float x, float y);
	void reverseDir(int cx, int cy);
	float xy_error(float s_x2, float s_y2, float s_xy, float s_x, float s_y);
};

void getRoundPixels(BaseLine*bl, cv::Point3i*reg,int *size);

 float  sqrt2(const float x);


#endif // !GENFUN