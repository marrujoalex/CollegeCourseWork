//mouse_key.cpp 
#include <GL/glut.h>
#include <stdlib.h>

#define   screenHeight  500

bool connect = true;
GLint x_1 = -1, y_1 = -1;

//initialization
void init( void )
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 );	//get white background color
  glColor3f( 0.0f, 0.0f, 0.0f );	//set drawing color
  glPointSize( 4.0 );			//a dot is 4x4
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluOrtho2D( 0.0, 500.0, 0.0, 500.0 );
} //init

void display()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glFlush();
}

void drawDot( int x, int y )
{
  glBegin( GL_POINTS );			
    glVertex2i( x, y );		//draw a point
  glEnd();
} //drawDot

void drawLine(int x_1, int y_1, int x_2, int y_2) {
    glBegin(GL_LINES);
        glVertex2i(x_1, y_1);
        glVertex2i(x_2, y_2);
    glEnd();
}//drawLine

void myMouse( int button, int state, int msx, int msy )
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    GLint x = msx;
    GLint y = screenHeight - msy;
    drawDot(x, y);
    if (x_1 > -1 && y_1 > -1 && connect)
        drawLine(x_1,y_1,x,y);
    x_1=x;
    y_1=y; 
  glFlush();				//send all output to screen
  }
}

void myMovedMouse(  int mouseX, int mouseY)
{
  GLint x = mouseX;
  GLint y = screenHeight - mouseY;
  GLint brushsize = 6;
  glColor3f( 1.0, 0.0, 0.0 );
  glRecti ( x, y, x + brushsize, y + brushsize );
  glFlush();
} //myMovedMouse

void myKeyboard ( unsigned char key, int mouseX, int mouseY )
{
  GLint x = mouseX;
  GLint y = screenHeight - mouseY;
  switch( key )
  {
    case 'o':
        connect = !connect; //Turn on/off switch
        break;
    case 'p':
 	drawDot(x,y);
	break;
    case 27:
	exit(-1);
    default:
	break;
  }  
}

//mouse_key_main.cpp: main loop of drawing program

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//initialization
void init(void);
void myMouse( int button, int state, int x, int y);
void myMovedMouse(  int mouseX, int mouseY);
void myKeyboard ( unsigned char key, int x, int y );
void display( void );

/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGBA display mode, depth buffer.
 */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);	//initialize toolkit
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );	//set display mode
  glutInitWindowSize(500, 500);		//set window size on screen
  glutInitWindowPosition( 100, 150 ); 	//set window position on screen
  glutCreateWindow(argv[0]);		//open screen widow
  init();
  glutMouseFunc( myMouse );
  glutMotionFunc( myMovedMouse );
  glutKeyboardFunc( myKeyboard );
  glutDisplayFunc( display );
  glutMainLoop();			//go into perpetual loop
  return 0;
}
