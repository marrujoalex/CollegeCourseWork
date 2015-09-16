//bcircle.cpp : Bresenham Circle algorithm

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,500.0,0.0,500.0);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}

void Circle( int xCenter, int yCenter, int r )
{
  int x=0,y=r;
  int d = 3/2 - r;				// = 1 - r
  while(x<=y){
    setPixel(xCenter+x,yCenter+y);
    setPixel(xCenter+y,yCenter+x);		//find other points by symmetry
    setPixel(xCenter-x,yCenter+y);
    setPixel(xCenter+y,yCenter-x);
    setPixel(xCenter-x,yCenter-y);
    setPixel(xCenter-y,yCenter-x);
    setPixel(xCenter+x,yCenter-y);
    setPixel(xCenter-y,yCenter+x);

    if (d<0)
 	d += (2*x)+3;
    else {
	d += (2*(x-y))+5;
	y -= 1;
    }
    x++;
  }

}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1 ,0, 0);  
  Circle ( 100, 100, 50 );
  glColor3f( 0 ,1, 0);  
  Circle ( 100, 200, 50 );
  glColor3f( 0 ,0, 1);  
  Circle ( 200, 200, 80 );
  glColor3f( 0 ,0, 0);  
  Circle ( 300, 300, 20 );
  
  glFlush();

}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}

