//bline.cpp : Bresenham Line algorithm, works for |m| <= 1, |m| > 1

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

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
  int x0 = 20, y0 = 20, xn = -300, yn = 60, x, y;
  double dx, dy,		//deltas
	 pk,		//decision parameter
  	 k;		//looping variable
  double m, n;

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 0.5 , 0.5, 0);  
  setPixel(x0, y0);	//plot first point
  
  // difference between starting and ending points
  dx = xn - x0; //-320
  dy = yn - y0; //40
  pk = 2 * dy - dx; 
  x = x0;	y = y0; 
  m = dy/dx; // 40/-320 = -1/8
  n = abs(m);
  
  if (n <= 1) {
    if (dx > 0) {
      for ( k = 0; k < dx-1; ++k ) {
        if ( pk < 0 ) {
          if (xn > 0 && yn > 0)
            pk = pk + 2 * dy;
          else            			//calculate next pk
            pk = pk - 2 * dy;     	      				//next pixel: (x+1, y )
        } 
        else {
       		        			//next pixel: (x+1, y+1)
          pk = pk + 2*dy - 2*dx;  		//calculate next pk
          if (yn > 0)
            ++y;
          else
            --y;
        }
        if (xn > 0)
          ++x;
        else
          --x;
        setPixel( x, y );
      }
    }
    else {
      for ( k = 0; k < -dx-1; ++k ) {
        if ( pk < 0 ) {
          if (xn > 0 && yn > 0)
            pk = pk + 2 * dy;
          else            			//calculate next pk
            pk = pk - 2 * dy;     	      				//next pixel: (x+1, y )
        } 
        else {
       	  if (xn > 0)	        			//next pixel: (x+1, y+1)
            pk = pk + 2*dy - 2*dx;      	        //calculate next pk 
          else
            pk = pk - 2*dy - 2*dx;
          if (yn > 0)
            ++y;
          else
            --y;
        }
        if (xn > 0)
          ++x;
        else
          --x;
        setPixel( x, y );
      }
    }
  }
  else if (n > 1) {
    for ( k = 0; k < dy-1; ++k ) {
      if ( pk < 0 ) {
        if (xn > 0 && yn > 0)
          pk = pk + 2 * dx;
        else
          pk = pk - 2 * dx;
      
      } 
      else {
        
        pk = pk + 2*dx - 2*dy;
        if (xn > 0)
          ++x;
        else
          --x;
      }
      if (yn > 0)
        ++y;
      else
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

