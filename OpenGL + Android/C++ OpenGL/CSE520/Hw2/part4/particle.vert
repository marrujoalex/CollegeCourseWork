//particle.vert

uniform float time;			//value provided by application program
attribute vec3 vel;			//value provided by application program
varying vec3 color;
varying float temp;
uniform float lowtemp;
uniform float range;
attribute float vtemp;

void main(void)
{
  
  float s = 1000.0;			//scale factor
  float g = -10.0;
  float t;
  float pi = 3.1415926535897932384626433;
  float angle = 360.0;
  float radius_angle = (angle*pi/(angle/2));
  t =  time / s; 			//time in ms
  vec4 object_pos = gl_Vertex;		//starting position
  float red = 0.0;
  float green = 0.0;
  float blue = 1.0;
  float j = 5.0;
  float k = j/2.0;
  temp = (vtemp/2.0 - lowtemp) / range;
  color = vec3(red,green,blue);
  gl_Position = gl_ModelViewProjectionMatrix * object_pos;

}
