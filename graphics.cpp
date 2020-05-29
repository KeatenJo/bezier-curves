// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <vector>	
#include <iostream>
#include "glut.h"
#include "Point2.h"
#include "bezier.h"


std::vector<Bezier> curves;
int fourCurves = 0;

unsigned int selectedCurve = 0;


// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 500;


// 
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}

void DrawRectangle(double x1, double y1, double x2, double y2)
{
	glBegin(GL_QUADS);
	glVertex2d(x1,y1);
	glVertex2d(x2,y1);
	glVertex2d(x2,y2);
	glVertex2d(x1,y2);
	glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, const char *string)
{
	void *font = GLUT_BITMAP_9_BY_15;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	
	int len, i;
	glRasterPos2d(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) 
	{
		glutBitmapCharacter(font, string[i]);
	}

    glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Test lines that draw all three shapes and some text.
	// Delete these when you get your code working.
	glColor3d(0,0,1);
	for (unsigned int i = 0; i < curves.size(); ++i) {
		if (selectedCurve == i) {
			curves[i].Draw(true);
		}
		else {
			curves[i].Draw(false);
		}
	}

	glutSwapBuffers();
	glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
	switch (c) 
	{
		case 27: // escape character means to quit the program
			exit(0);
			break;
		case 'b':
			// do something when 'b' character is hit.
			break;
		default:
			return; // if we don't care, return without glutPostRedisplay()
	}

	glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
	// Reset our global variables to the new width and height.
	screen_x = w;
	screen_y = h;

	// Set the pixel resolution of the final picture (Screen coordinates).
	glViewport(0, 0, w, h);

	// Set the projection mode to 2D orthographic, and set the world coordinates:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
	{
	}
	glutPostRedisplay();
}
void color_menu(int options) {

	switch (options) {
	case 1:
		curves[selectedCurve].mred = 1;
		curves[selectedCurve].mblue = 0;
		curves[selectedCurve].mgreen = 0;
		break;
	case 2:
		curves[selectedCurve].mred = 1;
		curves[selectedCurve].mblue = 1;
		curves[selectedCurve].mgreen = 0;
		break;
	case 3:
		curves[selectedCurve].mred = 0;
		curves[selectedCurve].mblue = 1;
		curves[selectedCurve].mgreen = 0;
		break;
	case 4:
		curves[selectedCurve].mred = 0;
		curves[selectedCurve].mblue = 0;
		curves[selectedCurve].mgreen = 1;
		break;
	case 5:
		curves[selectedCurve].mred = 1;
		curves[selectedCurve].mblue = 0;
		curves[selectedCurve].mgreen = 1;
		break;
	case 6:
		curves[selectedCurve].mred = 0;
		curves[selectedCurve].mblue = 1;
		curves[selectedCurve].mgreen = 1;
		break;
	default:
		break;
	}
}
void createCurve() {

	// create bezier curve in default location
	/*Point2 p0 = Point2(50.0, 50.0);
	Point2 p1 = Point2(60, 60);
	Point2 p2 = Point2(80, 20);
	Point2 p3 = Point2(80, 50);*/
	if (fourCurves == 0) {
		double tmpx = rand() % 80;
		double tmpy = rand() % 80;
		Point2 p0 = Point2(tmpx + 10, tmpy + 10);
		tmpx = rand() % 70;
		tmpy = rand() % 70;
		Point2 p1 = Point2(tmpx + 10, tmpy + 10);
		tmpx = rand() % 70;
		tmpy = rand() % 70;
		Point2 p2 = Point2(tmpx + 10, tmpy + 10);
		tmpx = rand() % 70;
		tmpy = rand() % 70;
		Point2 p3 = Point2(tmpx + 10, tmpy + 10);
		double r = rand() % 100 / 100.0;
		double g = rand() % 100 / 100.0;
		double b = rand() % 100 / 100.0;
		Bezier tmp = Bezier(p0, p1, p2, p3, r, g, b);
		curves.push_back(tmp);
	} else if (fourCurves == 1) {
		double tmpx = rand() % 80;
		double tmpy = rand() % 80;
		Point2 p0 = Point2(tmpx + 10, tmpy + 10);
		tmpx = rand() % 70;
		tmpy = rand() % 70;
		Point2 p1 = Point2(tmpx + 10, tmpy + 10);
		tmpx = rand() % 70;
		tmpy = rand() % 70;
		Point2 p2 = Point2(tmpx + 10, tmpy + 10);
		tmpx = rand() % 70;
		tmpy = rand() % 70;
		Point2 p3 = Point2(tmpx + 10, tmpy + 10);
		tmpx = rand() % 70;
		tmpy = rand() % 70;
		Point2 p4 = Point2(tmpx + 10, tmpy + 10);

		double r = rand() % 100 / 100.0;
		double g = rand() % 100 / 100.0;
		double b = rand() % 100 / 100.0;
		Bezier tmp = Bezier(p0, p1, p2, p3, p4, r, g, b);
		curves.push_back(tmp);
	}
}

void deleteCurve() {
	curves.erase(curves.begin() + selectedCurve);
}

void top_menu(int options) {
	switch (options) {
	case 1:
		createCurve();
		break;
	case 2:
		deleteCurve();
		break;
	case 3:
		if (fourCurves == 1) {
			fourCurves = 0;
		}
		else {
			fourCurves = 1;
			createCurve();
		}
		break;

	default:
		break;
	}
}

void createMenus() {
	int submenu = glutCreateMenu(color_menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Purple", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Green", 4);
	glutAddMenuEntry("Yellow", 5);
	glutAddMenuEntry("Turquois", 6);
	glutCreateMenu(top_menu);
	glutAddSubMenu("Set Color", submenu);
	glutAddMenuEntry("Add Curve", 1);
	glutAddMenuEntry("Add 4 Curve", 3);
	glutAddMenuEntry("Delete Curve", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Your initialization code goes here.
void InitializeMyStuff()
{

	Point2 point1 = Point2(5, 5, 1, 0, 0);
	Point2 point2 = Point2(25, 25, 1, 0, 0);
	Point2 point3 = Point2(50, 35, 1, 0, 0);
	Point2 point4 = Point2(60, 30, 1, 0, 0);
	Bezier bezier1 = Bezier(point1, point2, point3, point4, 1, 0, 1);
	curves.push_back(bezier1);
	createMenus();
	
}

void motion (int x, int y){
	y = screen_y - y;
	double xratio = x / screen_x;
	double yratio = y / screen_y;

	double xw = 100 * xratio;
	double yw = 100 * yratio;

	for (unsigned int i = 0; i < curves.size(); ++i) {
		if (xw > curves[i].mp1.mx - 1.5 && xw < curves[i].mp1.mx + 1.5) {
			if (yw > curves[i].mp1.my - 1.5 && yw < curves[i].mp1.my + 1.5) {
				curves[i].mp1.mx = xw;
				curves[i].mp1.my = yw;
				selectedCurve = i;
			}
		}
		if (xw > curves[i].mp2.mx - 1.5 && xw < curves[i].mp2.mx + 1.5) {
			if (yw > curves[i].mp2.my - 1.5 && yw < curves[i].mp2.my + 1.5) {
				curves[i].mp2.mx = xw;
				curves[i].mp2.my = yw;
				selectedCurve = i;
			}
		}
		if (xw > curves[i].mp3.mx - 1.5 && xw < curves[i].mp3.mx + 1.5) {
			if (yw > curves[i].mp3.my - 1.5 && yw < curves[i].mp3.my + 1.5) {
				curves[i].mp3.mx = xw;
				curves[i].mp3.my = yw;
				selectedCurve = i;
			}
		}
		if (xw > curves[i].mp4.mx - 1.5 && xw < curves[i].mp4.mx + 1.5) {
			if (yw > curves[i].mp4.my - 1.5 && yw < curves[i].mp4.my + 1.5) {
				curves[i].mp4.mx = xw;
				curves[i].mp4.my = yw;
				selectedCurve = i;
			}
		}
		if (xw > curves[i].mp5.mx - 1.5 && xw < curves[i].mp5.mx + 1.5) {
			if (yw > curves[i].mp5.my - 1.5 && yw < curves[i].mp5.my + 1.5) {
				curves[i].mp5.mx = xw;
				curves[i].mp5.my = yw;
				selectedCurve = i;
			}
		}
	}
}


int main(int argc, char **argv)
{
	srand(time(0));
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(50, 50);

	int fullscreen = 0;
	if (fullscreen) 
	{
		glutGameModeString("800x600:32");
		glutEnterGameMode();
	} 
	else 
	{
		glutCreateWindow("This appears in the title bar");
	}

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glColor3d(0,0,0); // forground color
	glClearColor(1, 1, 1, 0); // background color
	InitializeMyStuff();

	glutMainLoop();

	return 0;
}
