//mesh2.cpp
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


void display(void) 	// use OpenGL to draw this mesh
{
  // draw each face of this mesh using OpenGL: draw each polygon
    static GLubyte allIndices[] = {4, 5, 6, 7, 1, 2, 6, 5, 
	0, 1, 5, 4, 0, 3, 2, 1, 
	0, 4, 7, 3, 2, 3, 7, 6};

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices); 

    glFlush();
} //drawMesh 

int main( int argc, char *argv[] )
{
  glutInit( &argc, argv );
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize( 500, 500 );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow("Mesh ");
  glutDisplayFunc(display);
  glClearColor( 1.0f, 1.0f, 1.0f, 0.0f ); //white background
  glViewport ( 0, 0, 500, 500 );

  glutMainLoop();

  return 0;
}

