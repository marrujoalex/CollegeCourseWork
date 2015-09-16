/*
  particlie.cpp
  Sample program showing how to write GL shader programs.
  Shader sources are in files "particle.vert" and "tests.frag".
  @Author: T.L. Yu, 2009
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>


using namespace std;

/*
   Global handles for the currently active program object, with its two shader objects
*/
GLuint programObject = 0;
GLuint vertexShaderObject = 0;
GLuint fragmentShaderObject = 0;
static GLint win = 0;

GLuint timeParam;		//parameters for sending to vertex shader
GLuint velParam;		//parameters for sending to vertex shader

int readShaderSource(char *fileName, GLchar **shader )
{
    // Allocate memory to hold the source of our shaders.
    FILE *fp;
    int count, pos, shaderSize;
     
    fp = fopen( fileName, "r");
    if ( !fp )
        return 0;

    pos = (int) ftell ( fp );
    fseek ( fp, 0, SEEK_END );			//move to end
    shaderSize = ( int ) ftell ( fp ) - pos;	//calculates file size	
    fseek ( fp, 0, SEEK_SET ); 			//rewind to beginning
     
    if ( shaderSize <= 0 ){
        printf("Shader %s empty\n", fileName);
        return 0;
    }

    *shader = (GLchar *) malloc( shaderSize + 1);
    
    // Read the source code
   
    count = (int) fread(*shader, 1, shaderSize, fp);
    (*shader)[count] = '\0';

    if (ferror(fp))
        count = 0;

    fclose(fp);
    
    return 1;
}


//  public 
int installShaders(const GLchar *vertex, const GLchar *fragment)
{
    GLint  vertCompiled, fragCompiled;  // status values
    GLint  linked;
    
    // Create a vertex shader object and a fragment shader object

    vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    
    // Load source code strings into shaders, compile and link

    glShaderSource(vertexShaderObject, 1, &vertex, NULL);
    glShaderSource(fragmentShaderObject, 1, &fragment, NULL);

    glCompileShader(vertexShaderObject);
    glGetShaderiv(vertexShaderObject, GL_COMPILE_STATUS, &vertCompiled);

    glCompileShader( fragmentShaderObject );
    glGetShaderiv( fragmentShaderObject, GL_COMPILE_STATUS, &fragCompiled);

    if (!vertCompiled || !fragCompiled)
        return 0;

    // Create a program object and attach the two compiled shaders

    programObject = glCreateProgram();
    glAttachShader( programObject, vertexShaderObject);
    glAttachShader( programObject, fragmentShaderObject);

    // Link the program object 

    glLinkProgram(programObject);
    glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

    if (!linked)
        return 0;

    // Install program object as part of current state

    glUseProgram(programObject);

    //check log
    GLchar log[1000];
    GLsizei len;
    glGetShaderInfoLog(vertexShaderObject, 1000, &len, log);
    printf("Vert Shader Info Log: %s\n", log);
    glGetProgramInfoLog(programObject, 1000, &len, log);
    printf("Program Info Log: %s\n", log);

   GLchar names[][20] = { "low", "high", "lowtemp",
  "range" };
    GLint loc[10];
    for ( int i = 0; i < 4; ++i ) {
      loc[i] =  glGetUniformLocation(programObject, names[i]);
      if (loc[i] == -1) 
        printf("No such uniform named %s\n", names[i]);
    }
    
    glUniform3f(loc[0], 0.0, 1.0, 0.0);
    glUniform3f(loc[1], 1.0, 0.0, 0.0);
    glUniform1f(loc[2], 0.3);
    glUniform1f(loc[3], 1.0);
    glUniform1f(loc[4], 1.0);
    glUniform1f(loc[5], 0.7);
    glUniform1f(loc[6], 0.3);

    return 1;
}


int init(void)
{
   
   const char *version;
   GLchar *VertexShaderSource, *FragmentShaderSource;
   int loadstatus = 0;

   version = (const char *) glGetString(GL_VERSION);
   if (version[0] != '2' || version[1] != '.') {
      printf("This program requires OpenGL 2.x, found %s\n", version);
//      exit(1);
   }
   readShaderSource( (char *) "particle.vert", &VertexShaderSource );
   readShaderSource((char *) "tests.frag", &FragmentShaderSource );
   loadstatus = installShaders(VertexShaderSource, FragmentShaderSource);
  
   timeParam = glGetUniformLocation ( programObject, "time" ); 
   velParam = glGetAttribLocation ( programObject, "vel" ); 
   return loadstatus;
}

static void Reshape(int width, int height)
{
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 25.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0f, 0.0f, -15.0f);
}

void CleanUp(void)
{
   glDeleteShader(vertexShaderObject);
   glDeleteShader(fragmentShaderObject);
   glDeleteProgram(programObject);
   glutDestroyWindow(win);
}

static void Idle(void)
{
   float t = glutGet ( GLUT_ELAPSED_TIME );
   while ( t > 5000 ) t -= 5000;
   glUniform1f( timeParam, t );
   glutPostRedisplay();
}


static void Key(unsigned char key, int x, int y)
{
   switch(key) {
   case 27:
      CleanUp();
      exit(0);
      break;
   }
   glutPostRedisplay();
}

void display(void)
{
   //float t = glutGet ( GLUT_ELAPSED_TIME );
   GLfloat vec[4];
   int loc = glGetAttribLocation(programObject, "color");
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor(1.0, 1.0, 1.0, 0.0);		//get white background color
   glColor3f(1, 0, 0);  			//red, this will have no effect if shader is loaded
   glPointSize(20);
   //"shoot" a particle at 45 degrees
   glBegin (GL_POLYGON);  
     glVertex3f(-11.0,0,0);	
     glVertex3f(-10.9,4,0);
     glVertex3f(-10.8,7,0);
     glVertex3f(-10,6.8,0);
     glVertex3f(-2,6.1,0);
     glVertex3f(0,6,0);
     glVertex3f(3,6.6,0);
     glVertex3f(5,6.9,0);
     glVertex3f(7,7,0);
     glVertex3f(8,7.2,0);
     glVertexAttrib3f(loc,0.8,0,0);
     glVertex3f(10,8.9,0);
     glVertex3f(10.2,8.2,0);
     glVertex3f(10,7.8,0);
     glVertex3f(9.8,7,0);
     glVertex3f(9.5,6,0);
     glVertex3f(9.6,5.5,0);
     glVertex3f(9,4,0);
     glVertex3f(8,0,0);
     glVertex3f(8.2,-2,0);
     glVertex3f(8.3,-3,0);
     glVertex3f(8,-5,0);
     glVertex3f(8.5,-6,0);
     glVertex3f(9,-7.8,0);
     glVertex3f(8.8,-8,0);
     glVertex3f(8.5,-9,0);
     glVertex3f(8.25,-9.5,0);
     glVertex3f(8,-10,0);
     glVertex3f(7.5,-9,0);
     glVertex3f(7,-8,0);
     glVertex3f(6.5,-5,0);
     glVertex3f(7,-3,0);
     glVertex3f(5,-8,0);
     glVertex3f(4,-8,0);
     glVertex3f(3,-7.5,0);
     glVertex3f(2,-8,0);
     glVertex3f(1,-9,0);
     glVertexAttrib3f(loc,0.8,0,0);
     glVertex3f(-0.5,-10,0);
     glVertex3f(-2,-8,0);
     glVertex3f(-3,-8,0);
     glVertex3f(-5,-7,0);
     glVertexAttrib3f(loc,0.8,0,0);
     glVertex3f(-8,-6,0);
   glEnd();

   glutSwapBuffers();
   glFlush();

}


int main(int argc, char *argv[])
{
   int success = 0;

   glutInit(&argc, argv);
   glutInitWindowPosition( 0, 0);
   glutInitWindowSize(500, 500);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   win = glutCreateWindow(argv[0]);
   glutReshapeFunc(Reshape);
   glutKeyboardFunc(Key);
   glutDisplayFunc(display);
   glutIdleFunc(Idle);

   // Initialize the "OpenGL Extension Wrangler" library
    glewInit();

   success = init();
   if ( success )
     glutMainLoop();
   return 0;
}

