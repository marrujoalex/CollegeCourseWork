//tests.frag
//a minimal fragment shader
varying vec3 color;
uniform vec3 low;
uniform vec3 high;
varying float temp;

void main(void)
{
  vec3 final = mix(low, high, temp);	
  gl_FragColor = vec4( final, 1 );	
  //gl_FragColor = vec3( 0, 0, 1);	// vec3 no longer works
  //gl_FragColor = vec3( 1, 0, 0);	//red color
}
