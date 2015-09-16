//display.cpp
#include "mesh.h"
#include <SDL/SDL.h>

#define DATA_FILE	"data.txt"

void display(void)
{
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho(-5.0, 5.0, -5.0, 5.0, 0.1, 100 );
  glMatrixMode(GL_MODELVIEW); // position and aim the camera
  glLoadIdentity();
  gluLookAt(8.0, 8.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glClear(GL_COLOR_BUFFER_BIT);
  Mesh msh;
  msh.readFile( DATA_FILE );  
  msh.drawMesh();
  glFlush();
  SDL_Delay ( 1000 );
  glClear(GL_COLOR_BUFFER_BIT);
  //glPushMatrix();		//save current matrix M
  //glTranslatef ( 0.0, 0, 0 );	//move in x-direction
  glRotatef( 90, 0, 1, 0 );
  msh.drawMesh();
  glFlush();
  SDL_Delay ( 1000 );
  glClear(GL_COLOR_BUFFER_BIT);
  glRotatef ( 90, 0, 1, 0 );	//rotate about  y-axis for 90 
  msh.drawMesh();		//rotate then translate
  glFlush();
  SDL_Delay ( 1000 );
  glPopMatrix();		//restore maxtrix M
  glClear(GL_COLOR_BUFFER_BIT);
  glRotatef ( 90, 0, 1, 0 );
  glTranslatef (0.0, 0, 0 );	//translate then rotate
  msh.drawMesh();
  glFlush();
  SDL_Delay(1000);
}
