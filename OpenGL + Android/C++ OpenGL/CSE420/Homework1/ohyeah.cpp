/*
 *  ohyeah.cpp
 *  This program draws geometric primitives and
 *  their attributes.
 */
#include <GL/glut.h>
#include <stdlib.h>

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
  
   glColor3f(0,0,1);
   glPolygonMode( GL_FRONT, GL_FILL );
   glBegin (GL_POLYGON);
       glVertex2i(200,200);
       glVertex2i(250,225);
       glVertex2i(250,275);
       glVertex2i(200,300);
       glVertex2i(150,275);
       glVertex2i(150,225);
       glVertex2i(200,200);
   glEnd();
   glColor3f(1, 1, 0);
   glPolygonMode(GL_FRONT, GL_FILL);
   glBegin (GL_POLYGON);
       glVertex2i(200,300);
       glVertex2i(250,325);
       glVertex2i(250,375);
       glVertex2i(200,400);
       glVertex2i(150,375);
       glVertex2i(150,325);
       glVertex2i(200,300);
   glEnd();
   glColor3f(1, 0, 0);
   glBegin (GL_POLYGON);
       glVertex2i(200,100);
       glVertex2i(250,125);
       glVertex2i(250,175);
       glVertex2i(200,200);
       glVertex2i(150,175);
       glVertex2i(150,125);
       glVertex2i(200,100);
   glEnd();
   glColor3f(1, 1, 0);
   glBegin (GL_POLYGON);
       glVertex2i(250,175);
       glVertex2i(250,225);
       glVertex2i(300,250);
       glVertex2i(350,225);
       glVertex2i(350,175);
       glVertex2i(300,150);
       glVertex2i(250,175);
   glEnd();
   glColor3f(1, 1, 0);
   glBegin (GL_POLYGON);
       glVertex2i(150,175);
       glVertex2i(150,225);
       glVertex2i(100,250);
       glVertex2i(50,225);
       glVertex2i(50,175);
       glVertex2i(100,150);
       glVertex2i(150,175);
   glEnd();
   glColor3f(1, 0, 0);
   glBegin (GL_POLYGON);
       glVertex2i(100,250);
       glVertex2i(150,275);
       glVertex2i(150,325);
       glVertex2i(100,350);
       glVertex2i(50,325);
       glVertex2i(50,275);
       glVertex2i(100,250);
   glEnd();
   glColor3f(1, 0, 0);
   glBegin (GL_POLYGON);
       glVertex2i(300,250);
       glVertex2i(350,275);
       glVertex2i(350,325);
       glVertex2i(300,350);
       glVertex2i(250,325);
       glVertex2i(250,275);
       glVertex2i(300,250);
   glEnd();
   glColor3f(0, 1, 0);
   glBegin (GL_POLYGON);
       glVertex2i(250,325);
       glVertex2i(250,275);
       glVertex2i(200,300);
       glVertex2i(250,325);
   glEnd();
   glBegin (GL_POLYGON);
       glVertex2i(200,300);
       glVertex2i(150,275);
       glVertex2i(150,325);
       glVertex2i(200,300);
   glEnd();
   glBegin (GL_POLYGON);
       glVertex2i(150,275);
       glVertex2i(100,250);
       glVertex2i(150,225);
       glVertex2i(150,275);
   glEnd();
   glBegin (GL_POLYGON);
       glVertex2i(150,225);
       glVertex2i(200,200);
       glVertex2i(150,175);
       glVertex2i(150,225);
   glEnd();
   glBegin (GL_POLYGON);
       glVertex2i(200,200);
       glVertex2i(250,225);
       glVertex2i(250,175);
       glVertex2i(200,200);
   glEnd();
   glBegin (GL_POLYGON);
       glVertex2i(250,225);
       glVertex2i(300,250);
       glVertex2i(250,275);
       glVertex2i(250,225);
   glEnd();
   glFlush();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

