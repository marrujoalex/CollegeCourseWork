#include "canvas.h"

Canvas cvs ( 800, 800, "Turtle" );

void parabola()
{
  cvs.setWindow ( -200, 200, -200, 200 );
  double a = 8, t, x, y;
  
  t = -4;
  y = a * t * t;
  x = 2 * a * t;
  cvs.moveTo ( x, y );

  for ( t = -4; t <= 4; t += 0.1 ) {
    y = a * t * t;
    x = 2 * a * t;
    cvs.lineTo ( x, y );
  }
}


void parabola_two()
{
  cvs.setWindow ( -200, 200, -200, 200 );
  double a = -8, t, x, y;
  
  t = -4;
  y = a * t * t;
  x = 2 * a * t;
  cvs.moveTo ( x, y );

  for ( t = -4; t <= 4; t += 0.1 ) {
    y = a * t * t;
    x = 2 * a * t;
    cvs.lineTo ( x, y );
  }
} 


void ellipse()
{
  cvs.setWindow ( -200, 200, -200, 200 );
  double W = 120, H = 80, t, x, y;
  double pi = 3.14159265389;

  t = 0;
  x = W * cos ( t );
  y = H * sin ( t );
  cvs.moveTo ( x, y );

  for ( t = 0; t <= 2.1 * pi; t += 0.1 ) {
    x = W * cos ( t );
    y = H * sin ( t );
    cvs.lineTo ( x, y );
  }
}

void spiral ( double K )
{
  cvs.setWindow ( -100, 100, -100, 100 );
  double a = 0.35, x, y, f, theta;
  const double pi = 3.14159;
  theta = 0;
  f = K * exp ( a * theta );
  x = f * cos ( theta );
  y = f * sin ( theta );
  cvs.moveTo ( x, y );
  for ( theta = 0; theta <= 8 * pi; theta += 0.1 ) {
    f = K * exp ( a * theta );
    x = f * cos ( theta );
    y = f * sin ( theta );
    cvs.lineTo ( x, y );
  }
}
 
void display(void)
{
  cvs.clearScreen();
 
  cvs.moveTo(0.0, 0.0); //starts at center
  cvs.turnTo ( 0.0 );   //points horizontally
  glLineWidth ( 6 );
  cvs.setColor(1.0,0.0,0.0);
  parabola();
  parabola_two();
  cvs.setColor(0,0,0);
  ellipse();
  cvs.setColor(0,1,0);
  spiral(0.8);
  cvs.setColor(0,0,0);

}
  
