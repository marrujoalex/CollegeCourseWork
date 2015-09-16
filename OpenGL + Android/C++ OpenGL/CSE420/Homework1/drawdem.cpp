/*
  drawdem.cpp
  SDL effect Animation
  line through the center of the screen

  Author: Marrujo, Samuel Alex

*/
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "draw.h"
#include "surface.h"

//draw a hook
void draw_hook ( Surface &surf, int L )
{
  surf.forward ( L, 1 );
  surf.turn( 90 );
  surf.forward ( L/5, 1 );
  surf.turn ( 90 );
  surf.forward ( L/3, 1 );
}


//draw an n-sided regular polygon
void draw_polygon ( Surface &surf, int n,  int radius, float rotAngle )
{
  if ( n < 3 ) return;				//bad number of sides
  int cx = surf.getCP().x;
  int cy = surf.getCP().y;
  double angle = rotAngle * 3.14159265 / 180;	//initial angle
  double angleInc = 2 * 3.14159265 / n;		//angle increment
  surf.moveTo ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  for ( int k = 0; k < n; k++ ) {		//repeat n times
    angle += angleInc;
    surf.lineTo ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  }
} //draw_polygon

//draw rosette with N-sided polygon
void rosette (Surface &surf,  int N, int radius )
{
  if ( N < 3 ) return;
  Point pt[N+1];

  int cx = surf.getCP().x;
  int cy = surf.getCP().y;
  double angle = 0;				//initial angle
  double angleInc = 2 * 3.14159265 / N;		//angle increment
  pt[0] = Point ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  for ( int k = 1; k < N; k++ ) {		//repeat n times
    angle += angleInc;
    pt[k] = Point ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  }
  for ( int i = 0; i < N - 1; i++ ) {
    for ( int j = i + 1; j < N; j++ ) {
    	surf.moveTo ( pt[i] );	//connect all vertices
    	surf.lineTo ( pt[j] );
    }
  }
} //rosette
 
int main()
{
 
#ifndef ARM
    const int VWIDTH = 640;
    const int VHEIGHT = 480;
#else
    const int VWIDTH = 320;
    const int VHEIGHT = 240;
#endif

  const Point center ( VWIDTH/2, VHEIGHT/2 );	//center of screen
  Surface surf( VWIDTH, VHEIGHT, "Draw_demo" );

  surf.clearScreen();			//clear screen
  surf.updateSurface();
  SDL_Delay ( 1000 );			//dealy one second, just for demo

  surf.setBackgroundColor ( 0xe0, 0xe0, 0xe0 );	//set background to grey
/*
  //draw a hook
  surf.setColor ( 0xff, 0, 0 );		//using red color
  surf.moveTo ( center );		//move to center of screen
  surf.turnTo ( 0 );			//points horizontally
  draw_hook ( surf, 60 );

  //draw a star
  surf.setColor ( 0, 0xff, 0 );		//using green color
  surf.moveTo ( center.x + 90, center.y  );
  surf.turnTo ( 0 );			//points horizontally
  draw_star ( surf, 50 );

  //draw an octagon
  surf.setColor ( 0, 0, 0xff );		//using blue color
  surf.moveTo ( center.x, center.y - 90  );
  draw_polygon ( surf, 8, 40, 0 );	//draw an octagon

  //draw an 8-sided rosette
  surf.setColor ( 0, 0, 0 );		//using black color
  surf.moveTo ( center.x - 90, center.y + 90  );
  rosette ( surf, 8, 50 );
*/

  surf.moveTo( center.x, center.y );
  surf.lineTo( center.x+100, center.y);
  surf.lineTo( center.x-200, center.y);
  SDL_Delay ( 500 );
  surf.clearScreen();
  surf.moveTo( center.x, center.y );
  surf.lineTo( center.x+100, center.y-50);
  surf.lineTo( center.x-200, center.y+100);
  SDL_Delay ( 500 );
  surf.clearScreen();
  surf.moveTo( center.x, center.y );
  surf.lineTo( center.x+100, center.y-70);
  surf.lineTo( center.x-200, center.y+120);
  SDL_Delay ( 500 );
  surf.clearScreen();
  surf.moveTo( center.x, center.y );
  surf.lineTo( center.x+100, center.y-90);
  surf.lineTo( center.x-200, center.y+140);
  SDL_Delay ( 500 );
  surf.clearScreen();
  surf.moveTo( center.x, center.y );
  surf.lineTo( center.x+100, center.y-110);
  surf.lineTo( center.x-200, center.y+160);
  SDL_Delay ( 500 );
  surf.clearScreen();
  surf.moveTo( center.x, center.y );
  surf.lineTo( center.x+100, center.y-130);
  surf.lineTo( center.x-200, center.y+180);
  
  surf.updateSurface();
  SDL_Delay ( 10000 );		//display 10 seconds before exit
  return 1;
}
