#include<cmath>
#include "Point2.h"
#include "glut.h"


void Point2::Draw()
{
	//glColor3d(mred, mgreen, mblue);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 32; i++)
	{
		double theta = (double)i / 32.0 * 2.0 * 3.1415926;
		double x = mx + 1 * cos(theta);
		double y = my + 1 * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}

Point2::Point2(double x, double y, double red, double green, double blue)
{
	mx = x;
	my = y;
	mred = red;
	mgreen = green;
	mblue = blue;
}

Point2::Point2(double x, double y)
{
	mx = x;
	my = y;
	mred = 0;
	mblue = 0;
	mgreen = 0;
}

Point2::Point2()
{
	mx = 0;
	my = 0;
	mred = 1;
	mblue = 0;
	mgreen = 0;
}
