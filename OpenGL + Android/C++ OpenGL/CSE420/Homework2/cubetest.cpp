#include <stdlib.h>
#include <GL/glut.h>

float cubeVert[8][3] = {{-1.0, -1.0, 1.0}, {-1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
						  {1.0, -1.0, 1.0}, {-1.0, -1.0, -1.0}, {-1.0, 1.0, -1.0}, 
						  {1.0, 1.0, -1.0}, {1.0, -1.0, -1.0}};

float cubeColor[8][3] = {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0},
						   {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, 
						   {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}};

int cubeIndices[24] =  {0, 3, 2, 1,
						2, 3, 7, 6, 
						0, 4, 7, 3, 
						1, 2, 6, 5, 
						4, 5, 6, 7, 
						0, 1, 5, 4};

Following two functions create the color cube via 60+ OpenGL calls
void polygon(int a, int b, int c, int d)
{

//draw a polygon via list of vertices 

 glBegin(GL_POLYGON);
 glColor3fv(cubeColor[a]);
 glVertex3fv(cubeVert[a]);
 glColor3fv(cubeColor[b]);
 glVertex3fv(cubeVert[b]);
 glColor3fv(cubeColor[c]);
 glVertex3fv(cubeVert[c]);
 glColor3fv(cubeColor[d]);
 glVertex3fv(cubeVert[d]);
 glEnd();
}

void colorcube()
{

//map vertices to faces

polygon(0,3,2,1);
polygon(2,3,7,6);
polygon(0,4,7,3);
polygon(1,2,6,5);
polygon(4,5,6,7);
polygon(0,1,5,4);
}



void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//Set the vertex and color pointers
	glVertexPointer(3, GL_FLOAT, 0, cubeVert);
	glColorPointer(3, GL_FLOAT, 0, cubeColor);

	//Draw the cube using the previously specified vertices & colors, and the specified cube indices
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
	
	
	//Create color cube with multiple calls
	//colorcube();

	glFlush();
	glutSwapBuffers();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);

	glutCreateWindow("colorcube");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glEnable(GL_DEPTH_TEST);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glutMainLoop();
}
