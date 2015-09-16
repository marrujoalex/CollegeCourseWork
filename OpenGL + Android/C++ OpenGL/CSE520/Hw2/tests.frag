//tests.frag
//a minimal fragment shader
varying vec3 color;

void main(void)
{
  gl_FragColor = vec4( color, 1 );	
  //gl_FragColor = vec3( 0, 0, 1);	// vec3 no longer works
  //gl_FragColor = vec3( 1, 0, 0);	//red color
}
