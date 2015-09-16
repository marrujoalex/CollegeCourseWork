//mesh.cpp
#include "mesh.h"
#include <GL/glut.h>

using namespace std;

Mesh::Mesh()	//constructor
{
  numVerts = numFaces = numNormals = 0;
  pt = NULL; 
  norm  =  NULL; 
  face = NULL;
}

bool Mesh::isEmpty()
{
  return (numVerts == 0) || (numFaces == 0) || (numNormals == 0);
}

void Mesh::setColor( int n )
{
  if ( n == 1 )
    glColor3f( 0, 1, 0 );
  else if ( n == 2 )
    glColor3f( 1, 0, 0 );
  else if ( n == 3 )
    glColor3f( 0.3, 0.3, 0.3 );
  else if ( n == 4 )
    glColor3f( 1, 1, 0 );
  else if ( n == 5 )
    glColor3f( 0.2, 0.2, 0.2 );
  else if ( n == 6 )
    glColor3f( 0, 1, 1 );
  else
    glColor3f( 0, 0, 0 );
}

void Mesh::drawMesh() 	// use OpenGL to draw this mesh
{
  // draw each face of this mesh using OpenGL: draw each polygon.
  if( isEmpty() ) return; // mesh is empty

static GLubyte allIndices[] = {4, 5, 6, 7, 1, 2, 6, 5, 
	0, 1, 5, 4, 0, 3, 2, 1, 
	0, 4, 7, 3, 2, 3, 7, 6};

glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices); 

} //drawMesh 

//read Mesh data from file
int Mesh:: readFile(char * fileName)
{
  fstream infile;
  infile.open(fileName, ios::in);
  cout << "opening file " << endl;
  if(infile.fail()) return -1; // error - can't open file
  if(infile.eof())  return -1; // error - empty file
  infile >> numVerts >> numNormals >> numFaces;
  pt = new Point3[numVerts];
  norm = new Vector3[numNormals];
  face = new Face[numFaces];
  //check that enough memory was found:
  if( !pt || !norm || !face)return -1; // out of memory
  cout << "file open O.K. " << endl;

  for(int p = 0; p < numVerts; p++) // read the vertices
    infile >> pt[p].x >> pt[p].y >> pt[p].z;
  for(int n = 0; n < numNormals; n++) // read the normals
    infile >> norm[n].x >> norm[n].y >> norm[n].z;
  cout << "numFaces = " << numFaces << endl;
  for(int f = 0; f < numFaces; f++)// read the faces
  {
    infile >> face[f].nVerts;
   
    face[f].vert = new VertexID[face[f].nVerts];
    for(int i = 0; i < face[f].nVerts; i++)
	infile >> face[f].vert[i].vertIndex;
    for(int i = 0; i < face[f].nVerts; i++)
	infile  >> face[f].vert[i].normIndex;
  } 
  return 0; // success
} //readFile 
