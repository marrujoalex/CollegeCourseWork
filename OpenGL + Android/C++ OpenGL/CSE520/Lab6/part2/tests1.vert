//tests1.vert
//a vertex shader showing use of mat4
/*
    We may regard mat4 M as array of 4 column vectors.  So M[0], M[1]  are  4x1 vectors ( vec4 )
    e.g.
    mat4 M;
    M[2] = vec4( 6.0 );		//sets the third column to all 6;
    M[0][0] = 1.0;		//sets the upper left element to 1.o
    M[1][3] = 8.0;		//sets the 4-the element of the second column to 8.0
    M = mat4(1.0);		//sets all elements to 1.0
*/
void main(void)
{
  const float pi = 3.1415926;
  float a = pi / 6.0;		//30 degrees

  mat4 M= mat4( 1.0, 0.0, 0.0, 0.0,	//first column   
		0.0, 1.0, 0.0, 0.0,  	//second column 
		0.0, 0.0, 1.0, 0.0, 	//third column
		1.0, 0.5, -8.0, 0.0 );	//fourth column

  //translation
  mat4 T = mat4( 1.0, 0.0, 0.0, 0.0,	//first column   
		0.0, 1.0, 0.0, 0.0,  	//second column 
		0.0, 0.0, 1.0, 0.0, 	//third column
		0.0, 0.0, -10.0, 1.0 );	//fourth column
  //Rotation
  mat4 R = mat4( cos(a),     sin(a), 0.0, 0.0,	//first column   
		-sin(a) ,   cos(a), 0.0, 0.0,  	//second column 
		0.0, 0.0, 1.0, 0.0, 	//third column
		0.0, 0.0, 0.0, 1.0 );	//fourth column
   mat4 TR;
  // TR = T * R; 
   TR = M * R;
    gl_Position = gl_ModelViewProjectionMatrix * (  gl_Vertex );
//    gl_Position = gl_ModelViewProjectionMatrix * ( M * gl_Vertex );
//    gl_Position = gl_ModelViewProjectionMatrix * ( TR * gl_Vertex );
}
