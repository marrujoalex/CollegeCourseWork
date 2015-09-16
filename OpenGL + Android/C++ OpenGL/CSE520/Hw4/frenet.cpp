// frenet.cpp
#include <SDL/SDL.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "LinearR4.h"

using namespace std;

int angle_x= 0, angle_y = 0, angle_z = 0;
int window;

void init(void) {
	glClearColor(0.9, 0.9, 0.9, 1.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, 0.1, 100 );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( 0, 0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void getC(float C[4], float t, float b) {
	C[0] = (1 + b * cos(7*t))*cos(t);
	C[1] = (1 + b * cos(7*t))*sin(t);
	C[2] = b*sin(7*t);
	C[3] = 1;
}

void setM( LinearMapR4 &Mat, float t, float b ) {

	float c = 1.0 / sqrt(1 + b*b);
	Mat.SetColumn1(-cos(t)*(1 -b * cos ( 7*t )), -sin(t)*(-b * cos(7*t)), 0, 0 );
	Mat.SetColumn2(c*b*sin(t)*(1 + b*cos(7*t)), -c*b*cos(t)*(1 - b*cos(7*t)), c, 0 );
	Mat.SetColumn3(-c*sin(t)*(1 + b*cos(7*t)), c*cos(t)*( 1 + b*cos(7*t)), b*c, 0);
	Mat.SetColumn4(cos(t)*(1 + b*cos(7*t)), sin(t)*(1 + b*cos(7*t)), b*sin(7*t), 1);

}
void print_M ( LinearMapR4 &Mat ) {
	cout << "(" << Mat.m11 << ",\t" << Mat.m12 << ",\t" << Mat.m13 << ",\t" << Mat.m14 << ")" << endl;
	cout << "(" << Mat.m21 << ",\t" << Mat.m22 << ",\t" << Mat.m23 << ",\t" << Mat.m24 << ")" << endl;
	cout << "(" << Mat.m31 << ",\t" << Mat.m32 << ",\t" << Mat.m33 << ",\t" << Mat.m34 << ")" << endl;
	cout << "(" << Mat.m41 << ",\t" << Mat.m42 << ",\t" << Mat.m43 << ",\t" << Mat.m44 << ")" << endl;
}

class Cfloat3 {
	public:
		float p3[3];
};

const float b = 0.5;
double H = 6.0;
LinearMapR4 Mat;
const int N = 4;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	vector<Cfloat3>vp0(N), vp1(N);
	VectorR4 p_1;
	VectorR4 points[4];

	points[0] = VectorR4 (-0.1, -0.1, 0, 1 );
	points[1] = VectorR4 ( 0.1, -0.1, 0, 1 );
	points[2] = VectorR4 ( 0.1, 0.1, 0, 1 );
	points[3] = VectorR4 ( -0.1, 0.1, 0, 1 );
	glColor3f ( 0.2, 1.0, 0 );
	glPushMatrix();
	glRotatef(angle_x, 1.0, 0.0, 0.0);
	glRotatef(angle_y, 0.0, 1.0, 0.0);
	glRotatef(angle_z, 0.0, 0.0, 1.0);

	float C[4];
	glLineWidth(3);
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_LINE);

	glBegin(GL_LINE_STRIP);
	for(float t = 0; t <= 26; t += 0.2) {
		getC(C, t, b);
		glVertex4fv(C);
	}
	glColor3f(0.1, 0.3, 0.8);
	glEnd();
	float p3[3];


	setM(Mat, 0, b);

	for (int i = 0; i < 4; ++i) {
		p_1 = Mat * points[i];
		p_1.Dump(vp0[i].p3);
	}
	glBegin(GL_QUADS);

	for (float t = 0.2; t <= 26; t += 0.2) {
		setM (Mat, t, b);
		for (int i = 0; i < N; ++i) {
			p_1 = Mat * points[i];
		
			p_1.Dump(vp1[i].p3);
		}
		for (int i = 0; i < N; ++i) {
			int j = (i+1) % N;
			glVertex3fv(vp0[i].p3);
			glVertex3fv(vp0[j].p3);
			glVertex3fv(vp1[j].p3);
			glVertex3fv(vp1[i].p3);
		}
		copy (vp1.begin(), vp1.end(), vp0.begin());
	}
	glEnd();
	glPopMatrix();
	glFlush();
}

void keyboard ( unsigned char key, int x, int y ) {
	switch (key) {
		case 27:
			glutDestroyWindow(window);
			exit (0);
		case 'x':
			angle_x = (angle_x + 3) % 360;
			break;
		case 'X':
			angle_x = (angle_x - 3) % 360;
			break;
		case 'y':
			angle_y = (angle_y + 3) % 360;
			break;
		case 'Y':
			angle_y = (angle_y - 3) % 360;
			break;
		case 'z':
			angle_z = (angle_z + 3) % 360;
			break;
		case 'Z':
			angle_z = (angle_z - 3) % 360;
			break;
		case 'r':
		case 'R':
			angle_z = angle_y = angle_x = 0; //resets the angles
			break;
	}
	glutPostRedisplay();
}

int main( int argc, char *argv[] ) {
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( 500, 500 );
	glutInitWindowPosition( 100, 100 );
	window = glutCreateWindow("tube");
	glutDisplayFunc(display);
	glutKeyboardFunc( keyboard );
	glClearColor( 0.9f, 0.9f, 0.9f, 0.0f ); //light gray background
	glViewport ( 0, 0, 500, 500 );
	init ();
	glutMainLoop();
	return 0;
}
