#include <GL/glut.h>
#include <stdlib.h>

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void) {
 	glEnable( GL_CULL_FACE );
  	glCullFace ( GL_BACK );
  	glColor3f( 1.0, 0.0, 0.0 );           //red
   	glFrontFace ( GL_CCW );
  	glPolygonMode( GL_FRONT, GL_FILL );
  	glBegin( GL_POLYGON );                //draw solid polygon
    	  glVertex2i( 0, 0 );
    	  glVertex2i( 100, 0 );
    	  glVertex2i( 100, 100 );
    	  glVertex2i( 0, 100 );
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

int main(int argc, char** argv) {

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (400, 150); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
return 1;
}
