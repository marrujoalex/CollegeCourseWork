/* TesselatedTriangle.c */

#include <GL/glut.h>
#include <math.h>

/* initial triangle */

GLfloat v1[3][2]={{0.0, 0.5}, {0.5, -0.5}, {-0.5, -0.5}};

int n;

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
   glBegin(GL_TRIANGLES);
      glVertex2fv(a);
      glVertex2fv(b);
      glVertex2fv(c);
   glEnd();      
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{

/* triangle subdivision using vertex numbers */
   GLfloat v[3][2];
   int j;
   if(m > 0) 
   {
      for(j=0; j<2; j++)
         v[0][j] = (a[j] + b[j]) / 2;  
      for(j=0; j<2; j++)   
         v[1][j] = (a[j] + c[j]) / 2;
      for(j=0; j<2; j++)   
         v[2][j] = (b[j] + c[j]) / 2;
      divide_triangle(a, v[0], v[1], m-1);
      divide_triangle(v[0], b, v[2], m-1);
      divide_triangle(v[1], v[2], c, m-1);
      divide_triangle(v[0], v[1], v[2], m-1);
   }
   else(triangle(a,b,c)); /* draw triangle at end of recursion */
}


void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   divide_triangle(v1[0], v1[1], v1[2], n);
   glFlush();
   
}

int main(int argc, char** argv)
{
   n = 3;
   glutInit(&argc, argv);
   glutCreateWindow("Tesselated Triangle");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}


