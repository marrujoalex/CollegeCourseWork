//bounce.vert

uniform float time;		//value provided by application program
attribute vec3 vel;		//value provided by application program

void main(void)
{
  float s = 1000.0;		//scale factor
  float g = 10.0;		//gravitational acceleration	
  float t;
  float h, h0;			//h0 = initial height
  float t0;
  float c = 0.9;		//coefficient of restitution
  t =  time / s; 		//time in ms

  h0 = gl_Vertex.y;		//initial height of ball
  vec3 norm = vec3 ( 0, 1, 0 );
  vec3 vel1;
  vec3 vel2;
  
  t0 = sqrt ( 2 * h0 / g );	//time to reach ground
  
  vel1.x = vel.x;
  vel1.y = vel.y - g * t0;
  vel1.z = vel.z;

  //initial height is gl_vertex.y  
  h =  h0 -  g/(2.0)*t*t;	//height of ball at time t

  while ( h1 <= 0 ){				//ball should always be above ground
    vel2 = c * reflect ( vel1, norm );  	//bouncing velocity reduced
    t = t - t0;
    h = vel2.y * t - g/(2.0) * t * t;
    h0 = c * h0;				//reduced bouncing height
    t0 = 2 * sqrt ( 2 * h0 / g );		//time for one bounce
    vel1.y = vel2.y - g * t0;
  }
  gl_Position = gl_ModelViewProjectionMatrix * vec4( gl_Vertex.x, h, gl_Vertex.z, 1 );	//object_pos;
}
