//draw.cpp : demo program for drawing 3 dots, two lines, ploylines, rectangles
#include <GL/glut.h>

//initialization
void init( void )
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 );	//get white background color
  glColor3f( 0.0f, 1.0f, 0.0f );	//set drawing color
  glPointSize( 8.0 );			//a dot is 4x4
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();			//replace current matrix with identity matrix
  gluOrtho2D( 0.0, 500.0, 0.0, 500.0 );
}

void display( void )
{
  glClear( GL_COLOR_BUFFER_BIT );	//clear screen
  

  glColor3f ( 0.2, 0.2, 0.6 );
  glBegin( GL_LINE_STRIP );
    glVertex2i( 30, 30 );
    glVertex2i( 120, 120 );
    glVertex2i( 210, 30 );
    glVertex2i( 30, 30 );
  glEnd();

  glColor3f( 0.8, 0.3, 0.8 );		//bright grey
  glRecti( 200, 200, 350, 380 );
  glFlush();				//send all output to screen
}
