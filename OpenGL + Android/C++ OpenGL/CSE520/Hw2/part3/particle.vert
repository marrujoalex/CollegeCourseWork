//particle.vert

uniform float time;			//value provided by application program
attribute vec3 v;			//value provided by application program
varying vec3 color;

void main(void)
{
  
  float s = 1000.0;			//scale factor
  float g = -10.0;
  float t;
  float h, h0;      //h0 = initial height
  float t0;
  float c = 0.9;
  float bounce = 40.0;
  float pi = 3.1415926535897932384626433;
  float angle = 360.0;
  float radius_angle = (angle*pi/(angle/2.0));
  t =  time / s; 			//time in ms
  vec4 object_pos = gl_Vertex;		//starting position
  float red = 0.0;
  float green = 0.0;
  float blue = 1.0;
  float j = 5.0;
  float k = j/2.0;
  h0 = gl_Vertex.y;   //initial height of ball
  vec3 norm = vec3 ( 0, 1, 0 );
  vec3 v1, v2;

  t0 = sqrt ( 2.0 * h0 / g ); //time to reach ground
  
  v1.x = v.x;
  v1.y = v.y - g * t0;
  v1.z = v.z;

  //initial height is gl_vertex.y  
  h =  h0 - g/(2.0)*t*t; //height of ball at time t
  /*
  object_pos.x = object_pos.x + v.x*t;
  object_pos.y = object_pos.y + v.y*t + g/(2.0)*t*t;
  object_pos.z = object_pos.z + v.z*t;
*/
  while ( h <= 0.0 ){       //ball should always be above ground
    v2 = c * reflect( v1, norm );    //bouncing vocity reduced
    t = t - t0;
    h = v2.y * t - g/(2.0) * t * t;
    h0 = c * h0;        //reduced bouncing height
    t0 = 2.0 * sqrt ( 2.0 * h0 / g );   //time for one bounce
    v1.y = v2.y - g * t0;

  }

  color = vec3(red,green,blue);
  gl_Position = gl_ModelViewProjectionMatrix * vec4(gl_Vertex.x, h, gl_Vertex.z,1);

}
