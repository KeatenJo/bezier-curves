#pragma once
#include "Point2.h"
class Bezier
{
public:
	Bezier(Point2 p1, Point2 p2, Point2 p3, Point2 p4, double red, double green, double blue);
	Bezier(Point2 p1, Point2 p2, Point2 p3, Point2 p4, Point2 p5, double red, double green, double blue);
	void Draw(bool selected);
	Point2 mp1, mp2, mp3, mp4, mp5;
	double mred, mgreen, mblue;
};

