//particle.vert

uniform float time;			//value provided by application program
attribute vec3 vel;			//value provided by application program
attribute bool temp;
varying vec3 color;

void main(void)
{
  
  float s = 1000.0;			//scale factor
  float g = -10.0;
  float t;

  t =  time / s; 			//time in ms
  vec4 object_pos = gl_Vertex;		//starting position
  vec4 object2_pos = gl_Vertex;
  float red = 0;
  float green = 0;
  float blue = 0;
  float k = 5/2;
  float j = 5;

  if (temp) {
    if (t <= k) {
        red = (t)/k;
        green = (k-t)/k;
    }
    else {
        red = (j-t)/k;
        green = (t-k)/k;
    }
  }
  else {
    red = 0;
    green = 0;
  }
  object_pos.x = object_pos.x + vel.x*t;
  object_pos.y = object_pos.y + vel.y*t  + g*t;
  object_pos.z = object_pos.z + vel.z*t;
  color = vec3(red,green,blue);
  gl_Position = gl_ModelViewProjectionMatrix * object_pos;

}
