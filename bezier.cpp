#include <cmath>
#include "bezier.h"
#include "glut.h"
#include "graphics.h"


Bezier::Bezier(Point2 p1, Point2 p2, Point2 p3, Point2 p4, double red, double green, double blue)
{
	mp1 = p1;
	mp2 = p2;
	mp3 = p3;
	mp4 = p4;
	mred = red;
	mgreen = green;
	mblue = blue;
}

Bezier::Bezier(Point2 p1, Point2 p2, Point2 p3, Point2 p4, Point2 p5, double red, double green, double blue)
{
	mp1 = p1;
	mp2 = p2;
	mp3 = p3;
	mp4 = p4;
	mp5 = p5;
	mred = red;
	mgreen = green;
	mblue = blue;
}

void Bezier::Draw(bool selected)
{
	if (fourCurves == 0) {
		glColor3d(mred, mgreen, mblue);
		glBegin(GL_LINE_STRIP);
		for (int t = 0; t < 10; t++) {
			double tmpt = t / 10.0;
			double x = (mp1.mx * pow(1 - tmpt, 3)) + ((3 * mp2.mx) * pow(1 - tmpt, 2) * tmpt) + ((3 * mp3.mx) * (1 - tmpt) * pow(tmpt, 2)) + (mp4.mx * pow(tmpt, 3));
			double y = (mp1.my * pow(1 - tmpt, 3)) + ((3 * mp2.my) * pow(1 - tmpt, 2) * tmpt) + ((3 * mp3.my) * (1 - tmpt) * pow(tmpt, 2)) + (mp4.my * pow(tmpt, 3));
			glVertex2d(x, y);

		}
		glEnd();

		if (selected) {
			glColor3d(mred, mgreen, mblue);
		}
		else {
			glColor3d(0, 0, 0);
		}

		mp1.Draw();
		mp2.Draw();
		mp3.Draw();
		mp4.Draw();
	}
	else if (fourCurves == 1) {
		glColor3d(mred, mgreen, mblue);
		glBegin(GL_LINE_STRIP);
		for (int t = 0; t < 10; t++) {
			double tmpt = t / 10.0;
			double x = (mp1.mx * pow(1 - tmpt, 4)) + ((4 * mp2.mx) * pow(1 - tmpt, 3) * tmpt) + ((6 * mp3.mx) * pow(1 - tmpt, 2) * pow(tmpt, 2)) + (4 * mp4.mx * (1-tmpt) * pow(tmpt, 3)) + mp5.mx * pow(tmpt, 4);
			double y = (mp1.my * pow(1 - tmpt, 4)) + ((4 * mp2.my) * pow(1 - tmpt, 3) * tmpt) + ((6 * mp3.my) * pow(1 - tmpt, 2) * pow(tmpt, 2)) + (4 * mp4.my * (1 - tmpt) * pow(tmpt, 3)) + mp5.my * pow(tmpt, 4);
			glVertex2d(x, y);

		}
		glEnd();

		if (selected) {
			glColor3d(mred, mgreen, mblue);
		}
		else {
			glColor3d(0, 0, 0);
		}

		mp1.Draw();
		mp2.Draw();
		mp3.Draw();
		mp4.Draw();
		mp5.Draw();
	}

}



