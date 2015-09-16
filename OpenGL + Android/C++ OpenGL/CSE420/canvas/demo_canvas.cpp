//demo_canvas.cpp
#include "canvas.h"

Canvas cvs(500, 400, "CSE 420 Canvas"); //global canvas object

void display()
{
  cvs.setViewport(0, 200, 0, 200);
  cvs.getViewport();
  cvs.clearScreen();	//clear screen
  cvs.setColor ( 0.0, 0.0, 1.0 );
  cvs.setBackgroundColor( 1,1,1 );
  cvs.moveTo( 0, 0.0 ); //draw line
  cvs.lineTo( 10, 0.0 );
  cvs.lineTo( 2, 6.0);
  cvs.lineTo( 5, -4.0);
  cvs.lineTo( 8, 6.0);
  cvs.lineTo( 0, 0.0 );
  cvs.getWindowAspectRatio();
  cvs.setColor ( 1.0, 1.0, 0.0 );
  cvs.setViewport(300, 200, 0, 200);
  RealRect box( -1.0, 1.0, -1.0, 2.0 );	//construct a box
  box.draw();		//draw box
  glFlush();
}
