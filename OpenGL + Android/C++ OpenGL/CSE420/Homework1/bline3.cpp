//bline.cpp : Bresenham Line algorithm, works only for |m| < 1

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,400.0,0.0,400.0);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}

void line()
{
  int x0 = 20, y0 = 20, xn = 300, yn = -60, x, y;
  double dx, dy,		//deltas
	 pk,		//decision parameter
  	 k;		//looping variable
  double m;

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 0.5 , 0.5, 0);  
  setPixel(x0, y0);	//plot first point
  
  // difference between starting and ending points
  dx = xn - x0; //280
  dy = yn - y0; //-80
  pk = 2 * dy - dx; 
  x = x0;	y = y0; 
  m = dy/dx; // -80/280 = -2/7
  
  if (m <= 1 && m > 0) {
    for ( k = 0; k < dx-1; ++k ) {
      if ( pk < 0 ) {
        pk = pk + 2 * dy;			//calculate next pk
               	      				//next pixel: (x+1, y )
      } else {
       		        			//next pixel: (x+1, y+1)
        pk = pk + 2*dy - 2*dx;  		//calculate next pk
        ++y;
      }
      ++x;
      setPixel( x, y );
    }
  }
  else if (m > 1) {
    for ( k = 0; k < dy-1; ++k ) {
      if ( pk < 0 ) {
        pk = pk + 2 * dx;
      
      } else {
        
        pk = pk + 2*dx - 2*dy;
        ++x;
      }
      ++y;
      setPixel( x, y);
    }
  }
  else if (m < 0 && m >= -1) {
    pk = -2*dy-dx;
    for ( k = 0; k < dx-1; ++k ) {
      if ( pk < 0 ) {
        pk = pk - 2 * dy;			//calculate next pk
               	      				//next pixel: (x+1, y )
      } else {
       		        			//next pixel: (x+1, y-1)
        pk = pk + 2*dy - 2*dx;  		//calculate next pk
        --y;
      }
      ++x;
      setPixel( x, y );
    }
  }
  else {
    pk = -2*dy-dx;
    for ( k = 0; k < dy-1; ++k ) {
      if ( pk < 0 ) {
        pk = pk - 2 * dx;
      
      } else {
        
        pk = pk + 2*dx - 2*dy;
        --x;
      }
      --y;
      setPixel( x, y);
    }
  }

  glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc( line );
    glutMainLoop();
    return 0;
}

