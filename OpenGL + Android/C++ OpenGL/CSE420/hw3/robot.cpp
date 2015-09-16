//robot.cpp
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

 
/*
  glutWireCube ( 1.0 )  
  produces a cube: -0.5 to 0.5
*/
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();				  //Save M0
   glTranslatef (-1.0, 0.0, 0.0);		  //M1 = T-1
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0); //M2 = T-1Rs
   glTranslatef (1.0, 0.0, 0.0);		  //M3 = T-1RsT+1
   glPushMatrix();				  //Save M3
   glScalef (2.0, 0.4, 1.0);			  //M4 = T-1RsT+1S
   glutWireCube (1.0);				  //P' =  T-1RsT+1S P
   glPopMatrix();				  //Restore M3 = T-1RsT+1
   glTranslatef (1.0, 0.0, 0.0);		  //M5 = T-1RsT+1T+1
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);	  //M6 = T-1RsT+1T+1Re
   glTranslatef (1.0, 0.0, 0.0);		  //M7 = T-1RsT+1T+1ReT+1
   glPushMatrix();				  //Save M7
   glScalef (2.0, 0.4, 1.0);			  //M8 = T-1RsT+1T+1ReT+1S
   glutWireCube (1.0);				  //P' = T-1RsT+1T+1ReT+1S P
   glPopMatrix();				  //Restore M7 

   glPopMatrix();				  //Restore M0
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':
         elbow = (elbow + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
         elbow = (elbow - 5) % 360;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
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
   
