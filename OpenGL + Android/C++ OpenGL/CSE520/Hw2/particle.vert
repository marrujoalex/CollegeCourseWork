//particle.vert

uniform float time;			//value provided by application program
attribute vec3 vel;			//value provided by application program
varying vec3 color;

void main(void)
{
  
  float s = 1000.0;			//scale factor
  float g = -10.0;
  float t;

  t =  time / s; 			//time in ms
  vec4 object_pos = gl_Vertex;		//starting position
  float red = 0.0;
  float green = 0.0;
  float blue = 1.0;
  float j = 5.0;
  float k = j/2.0;



    if (t < k) {
        red = (t)/k;
        blue = (k-t)/k;
        object_pos.x = object_pos.x + ( (vel.x - object_pos.x) / k ) * t;
        object_pos.y = object_pos.y + ( (vel.y - object_pos.y) / k ) * t;
        object_pos.z = object_pos.z + ( (vel.z - object_pos.z) / k ) * t;
    }
    else {
        red = (j-t)/k;
        blue = (t-k)/k;
        object_pos.x = vel.x + ( (object_pos.x - vel.x) / k ) * (t - k);
        object_pos.y = vel.y + ( (object_pos.y - vel.y) / k ) * (t - k);
        object_pos.z = vel.z + ( (object_pos.z - vel.z) / k ) * (t - k);
    }
    
  color = vec3(red,green,blue);
  gl_Position = gl_ModelViewProjectionMatrix * object_pos;

}
